#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main()
{
	int width = 800; // ������
	int height = 600; // ����߶�
	float g = 0.3; // �������ٶ�
	float x = width / 6; // С��x����
	float y = height / 3; // С��y����
	float vy = 0; // С��y�����ٶ�
	int radius = 20; // С��뾶
	initgraph(width, height); // �¿�һ������

	while (1) // һֱѭ��
	{
		// �����������ٶȣ�����С��y������ٶ�
		vy = vy + g;

		// �����ٶȣ�����С���λ��
		y = y + vy;

		// С���������±߽磬y�ٶȷ���
		if (y <= radius)
			vy = -vy;
		if (y >= height - radius)
			vy = -vy;

		cleardevice(); // ����
		fillcircle(x, y, radius); // ��С��
		Sleep(3); // ��ͣ���ɺ���
	}
	return 0;
}

