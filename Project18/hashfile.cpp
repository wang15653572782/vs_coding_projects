//hashfile.c
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"HashFile.h"

int hashfile_creat(const char* filename, mode_t mode, int reclen, int total_rec_num)//�����ļ�
{
	struct HashFileHeader hfh;
	int fd;
	int rtn;
	char* buf;
	int i = 0;
	//��ֵhashfileheader
	hfh.sig = 31415926;//Hash�ļ�ӡ��
	hfh.reclen = reclen;//��¼����
	hfh.total_rec_num = total_rec_num;//�ܼ�¼��
	hfh.current_rec_num = 0;//��ǰ��¼��


	fd = creat(filename, mode);//ϵͳ���ô����ļ�
	if (fd != -1)//�����ɹ�
	{
		rtn = write(fd, &hfh, sizeof(struct HashFileHeader));//��������hashͷд���ļ�
		//lseek(fd,sizeof(struct HashFileHeader),SEEK_SET);
		if (rtn != -1)//�����ɹ�
		{
			buf = (char*)malloc((reclen + sizeof(struct CFTag)) * total_rec_num);//������ʱbuf
			memset(buf, 0, (reclen + sizeof(struct CFTag)) * total_rec_num);//�������
			rtn = write(fd, buf, (reclen + sizeof(struct CFTag)) * total_rec_num);//д���ļ�
			free(buf);//�ͷ�buf
		}
		close(fd);
		return rtn;
	}
	else {
		close(fd);
		return -1;
	}
}

int hashfile_open(const char* filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);
	struct HashFileHeader hfh;
	if (read(fd, &hfh, sizeof(struct HashFileHeader)) != -1)//��hashͷ����hfh
	{
		lseek(fd, 0, SEEK_SET);//��ָ��ָ���ļ�ͷ
		if (hfh.sig == 31415926)//�ļ�ӡ��
			return fd;
		else
			return -1;
	}
	else return -1;
}
int hashfile_close(int fd)
{
	return close(fd);
}
int hashfile_read(int fd, int keyoffset, int keylen, void* buf)
{
	struct HashFileHeader hfh;
	readHashFileHeader(fd, &hfh); //��hashͷ����hfh��ָ���ԭ��
	int offset = hashfile_findrec(fd, keyoffset, keylen, buf);
	if (offset != -1)
	{
		lseek(fd, offset + sizeof(struct CFTag), SEEK_SET);
		return read(fd, buf, hfh.reclen);
	}
	else
	{
		return -1;
	}
}
int hashfile_write(int fd, int keyoffset, int keylen, void* buf)
{
	return hashfile_saverec(fd, keyoffset, keylen, buf);
	//return -1;
}
int hashfile_delrec(int fd, int keyoffset, int keylen, void* buf)
{
	int offset;
	offset = hashfile_findrec(fd, keyoffset, keylen, buf);//buf��λ��
	if (offset != -1)
	{
		struct CFTag tag;
		read(fd, &tag, sizeof(struct CFTag));
		tag.free = 0; //�ÿ��б�־ 
		lseek(fd, offset, SEEK_SET);
		write(fd, &tag, sizeof(struct CFTag));//����tag
		struct HashFileHeader hfh;
		readHashFileHeader(fd, &hfh);
		int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);//���ϣƫ��
		offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));
		if (lseek(fd, offset, SEEK_SET) == -1)
			return -1;
		read(fd, &tag, sizeof(struct CFTag));
		tag.collision--; //��ͻ������1
		lseek(fd, offset, SEEK_SET);
		write(fd, &tag, sizeof(struct CFTag));//д���ļ���
		hfh.current_rec_num--; //��ǰ��¼����1
		lseek(fd, 0, SEEK_SET);
		write(fd, &hfh, sizeof(struct HashFileHeader));//д���ļ���
	}
	else {
		return -1;
	}
}

int hashfile_findrec(int fd, int keyoffset, int keylen, void* buf)
{
	struct HashFileHeader hfh;
	readHashFileHeader(fd, &hfh);
	int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);//�ҵ���ϣֵ
	int offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));//��ϣƫ��
	if (lseek(fd, offset, SEEK_SET) == -1)//����Խ��
		return -1;
	struct CFTag tag;
	read(fd, &tag, sizeof(struct CFTag));
	char count = tag.collision;//��ͻ����
	if (count == 0)
		return -1; //������
recfree:
	if (tag.free == 0)//���б�־Ϊ�գ�������
	{
		offset += hfh.reclen + sizeof(struct CFTag);
		if (lseek(fd, offset, SEEK_SET) == -1)
			return -1;
		read(fd, &tag, sizeof(struct CFTag));
		goto recfree;
	}
	else {//������
		char* p = (char*)malloc(hfh.reclen * sizeof(char));
		read(fd, p, hfh.reclen);
		//printf("Record is {%d , %s}\n",((struct jtRecord *)p)->key,((struct jtRecord *p)->other);
		char* p1, * p2;
		p1 = (char*)buf + keyoffset;
		p2 = p + keyoffset;
		int j = 0;
		while ((*p1 == *p2) && (j < keylen))
		{
			p1++;
			p2++;
			j++;
		}//�ж��Ƿ����
		if (j == keylen)
		{
			free(p);
			p = NULL;
			return(offset);//����ƫ����
		}
		else {
			if (addr == hash(keyoffset, keylen, p, hfh.total_rec_num))
			{
				count--;
				if (count == 0)
				{
					free(p);
					p = NULL;
					return -1;//������ 
				}
			}
			free(p);
			p = NULL;
			offset += hfh.reclen + sizeof(struct CFTag);
			if (lseek(fd, offset, SEEK_SET) == -1)
				return -1;
			read(fd, &tag, sizeof(struct CFTag));
			goto recfree;
		}
	}
}
int hashfile_saverec(int fd, int keyoffset, int keylen, void* buf)//����
{
	if (checkHashFileFull(fd))
	{
		return -1;
	}
	struct HashFileHeader hfh;
	readHashFileHeader(fd, &hfh);
	int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);
	int offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));
	if (lseek(fd, offset, SEEK_SET) == -1)//Խ��
		return -1;
	struct CFTag tag;
	read(fd, &tag, sizeof(struct CFTag));//����tag
	tag.collision++;//�޸ĳ�ͻ����
	lseek(fd, sizeof(struct CFTag) * (-1), SEEK_CUR);//ָ��ظ���ȥ
	write(fd, &tag, sizeof(struct CFTag));//����д��
	while (tag.free != 0) //��ͻ��˳��̽��
	{
		offset += hfh.reclen + sizeof(struct CFTag);
		if (offset >= lseek(fd, 0, SEEK_END))
			offset = sizeof(struct HashFileHeader); //reach at and,then rewind
		if (lseek(fd, offset, SEEK_SET) == -1)
			return -1;
		read(fd, &tag, sizeof(struct CFTag));
	}
	tag.free = -1;
	lseek(fd, sizeof(struct CFTag) * (-1), SEEK_CUR);
	write(fd, &tag, sizeof(struct CFTag));
	write(fd, buf, hfh.reclen);
	hfh.current_rec_num++;//��ǰ��¼��һ
	lseek(fd, 0, SEEK_SET);//ָ���Ƶ�ͷ
	return write(fd, &hfh, sizeof(struct HashFileHeader));  //�����¼ 
}

int hash(int keyoffset, int keylen, void* buf, int total_rec_num)
{
	int i = 0;
	char* p = (char*)buf + keyoffset;
	int addr = 0;
	for (i = 0; i < keylen; i++)
	{
		addr += (int)(*p);
		p++;
	}
	return addr % (int)(total_rec_num * COLLISIONFACTOR);
}

int checkHashFileFull(int fd)
{
	struct HashFileHeader hfh;
	readHashFileHeader(fd, &hfh);
	if (hfh.current_rec_num < hfh.total_rec_num)
		return 0;
	else
		return 1;
}
int readHashFileHeader(int fd, struct HashFileHeader* hfh)
{
	lseek(fd, 0, SEEK_SET);
	return read(fd, hfh, sizeof(struct HashFileHeader));
}