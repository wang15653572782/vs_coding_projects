//hashfile.c
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"HashFile.h"

int hashfile_creat(const char* filename, mode_t mode, int reclen, int total_rec_num)//创建文件
{
	struct HashFileHeader hfh;
	int fd;
	int rtn;
	char* buf;
	int i = 0;
	//赋值hashfileheader
	hfh.sig = 31415926;//Hash文件印鉴
	hfh.reclen = reclen;//记录长度
	hfh.total_rec_num = total_rec_num;//总记录数
	hfh.current_rec_num = 0;//当前记录数


	fd = creat(filename, mode);//系统调用创建文件
	if (fd != -1)//创建成功
	{
		rtn = write(fd, &hfh, sizeof(struct HashFileHeader));//将创建的hash头写入文件
		//lseek(fd,sizeof(struct HashFileHeader),SEEK_SET);
		if (rtn != -1)//操作成功
		{
			buf = (char*)malloc((reclen + sizeof(struct CFTag)) * total_rec_num);//创建临时buf
			memset(buf, 0, (reclen + sizeof(struct CFTag)) * total_rec_num);//置零清空
			rtn = write(fd, buf, (reclen + sizeof(struct CFTag)) * total_rec_num);//写入文件
			free(buf);//释放buf
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
	if (read(fd, &hfh, sizeof(struct HashFileHeader)) != -1)//把hash头读入hfh
	{
		lseek(fd, 0, SEEK_SET);//将指针指向文件头
		if (hfh.sig == 31415926)//文件印鉴
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
	readHashFileHeader(fd, &hfh); //把hash头读入hfh，指针归原处
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
	offset = hashfile_findrec(fd, keyoffset, keylen, buf);//buf的位置
	if (offset != -1)
	{
		struct CFTag tag;
		read(fd, &tag, sizeof(struct CFTag));
		tag.free = 0; //置空闲标志 
		lseek(fd, offset, SEEK_SET);
		write(fd, &tag, sizeof(struct CFTag));//读入tag
		struct HashFileHeader hfh;
		readHashFileHeader(fd, &hfh);
		int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);//求哈希偏移
		offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));
		if (lseek(fd, offset, SEEK_SET) == -1)
			return -1;
		read(fd, &tag, sizeof(struct CFTag));
		tag.collision--; //冲突计数减1
		lseek(fd, offset, SEEK_SET);
		write(fd, &tag, sizeof(struct CFTag));//写入文件里
		hfh.current_rec_num--; //当前记录数减1
		lseek(fd, 0, SEEK_SET);
		write(fd, &hfh, sizeof(struct HashFileHeader));//写入文件里
	}
	else {
		return -1;
	}
}

int hashfile_findrec(int fd, int keyoffset, int keylen, void* buf)
{
	struct HashFileHeader hfh;
	readHashFileHeader(fd, &hfh);
	int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);//找到哈希值
	int offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));//哈希偏移
	if (lseek(fd, offset, SEEK_SET) == -1)//查找越界
		return -1;
	struct CFTag tag;
	read(fd, &tag, sizeof(struct CFTag));
	char count = tag.collision;//冲突计数
	if (count == 0)
		return -1; //不存在
recfree:
	if (tag.free == 0)//空闲标志为空，接着找
	{
		offset += hfh.reclen + sizeof(struct CFTag);
		if (lseek(fd, offset, SEEK_SET) == -1)
			return -1;
		read(fd, &tag, sizeof(struct CFTag));
		goto recfree;
	}
	else {//不空闲
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
		}//判断是否相等
		if (j == keylen)
		{
			free(p);
			p = NULL;
			return(offset);//返回偏移量
		}
		else {
			if (addr == hash(keyoffset, keylen, p, hfh.total_rec_num))
			{
				count--;
				if (count == 0)
				{
					free(p);
					p = NULL;
					return -1;//不存在 
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
int hashfile_saverec(int fd, int keyoffset, int keylen, void* buf)//储存
{
	if (checkHashFileFull(fd))
	{
		return -1;
	}
	struct HashFileHeader hfh;
	readHashFileHeader(fd, &hfh);
	int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);
	int offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));
	if (lseek(fd, offset, SEEK_SET) == -1)//越界
		return -1;
	struct CFTag tag;
	read(fd, &tag, sizeof(struct CFTag));//读入tag
	tag.collision++;//修改冲突计数
	lseek(fd, sizeof(struct CFTag) * (-1), SEEK_CUR);//指针回复回去
	write(fd, &tag, sizeof(struct CFTag));//重新写入
	while (tag.free != 0) //冲突，顺序探查
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
	hfh.current_rec_num++;//当前记录加一
	lseek(fd, 0, SEEK_SET);//指针移到头
	return write(fd, &hfh, sizeof(struct HashFileHeader));  //存入记录 
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