/*������ ������ 2153538*/
#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
//��cpp��һЩ���������˵�����
int deal_input(int range)
{
	while (1)
	{
		char a = _getch();
		for (char i = '0';i <= '0' + range;i++)
		{
			if (a == i)
			{
				cout << a << endl;
				cout << endl;
				return a - 48;
			}
		}
		continue;
	}
	return -1;
}
int menu(int bigHW_no)
{
	if (bigHW_no == 1)
	{
		cout << "-------------------------------------" << endl;
		cout << "1.������" << endl;
		cout << "2.������(������¼)" << endl;
		cout << "3.�ڲ�������ʾ(����)" << endl;
		cout << "4.�ڲ�������ʾ(���� + ����)" << endl;
		cout << "5.ͼ�ν� - Ԥ�� - ������Բ��" << endl;
		cout << "6.ͼ�ν� - Ԥ�� - ����ʼ���ϻ�n������" << endl;
		cout << "7.ͼ�ν� - Ԥ�� - ��һ���ƶ�" << endl;
		cout << "8.ͼ�ν� - �Զ��ƶ��汾" << endl;
		cout << "9.ͼ�ν� - ��Ϸ��" << endl;
		cout << "0.�˳�" << endl;
		cout << "-------------------------------------" << endl;
		cout << "[��ѡ��:] ";
		return deal_input(9);
	}
	else if (bigHW_no == 2)
	{
		cout << "--------------------------------------------" << endl;
		cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
		cout << "2.�ڲ����飬�������60 % ����Ѱ���ƶ�·��" << endl;
		cout << "3.�ڲ����飬������" << endl;
		cout << "4.����n * n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
		cout << "5.����n * n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
		cout << "6.n * n�Ŀ�ܣ�60 % ����֧����꣬���һ���ƶ�" << endl;
		cout << "7.cmdͼ�ν���������" << endl;
		cout << "0.�˳�" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "[��ѡ��:]";
		return deal_input(7);
	}
	else if(bigHW_no==3)
	{
		cout<<"--------------------------------------------" << endl;
		cout << "1.�������뻭��9�����ֵ���״" << endl;
		cout << "2.������Ϸ��ͼ�����Ϸ��������������ʾ" << endl;
		cout << "3.�޲��������Զ�����" << endl;
		cout << "4.���������ʵ�ּ��̿������ֵ���ת��ƽ��" << endl;
		cout << "5.���5�������������䣬���ܹ�ͨ���·�������������ٶ�" << endl;
		cout << "6.cmdͼ�ν���������" << endl;
		cout << "0.�˳�" << endl;
		cout << "--------------------------------------------" << endl;
		return deal_input(7);
	}
	return 0;
}