/* 2153538 ������ ������ */
#include <iostream>
#include "../include/cmd_console_tools.h"
#include"../include/commen_menu.h"
#include"90-02-b1.h"
#include <conio.h>
using namespace std;
void end()
{
	cout << endl << "���س�������...";
	while (_getch() != '\r')
		;
	cct_cls();
}
void inputrow_col(int &M,int&N)
{
	while (1)
	{
		cout << "��������Ϸ����ĸ�M[18-26]��" << endl;
		cin >> M;
		if (cin.good() && M >= 18 && M <= 26)
		{
			cin.clear();
			break;
		}
	}
	while (1)
	{
		cout << "��������Ϸ����Ŀ�M[12-21]��������3�ı�������" << endl;
		cin >> N;
		if (cin.good() && N >= 12 && N <= 21 && N % 3 == 0)
		{
			cin.clear();
			break;
		}
	}
}