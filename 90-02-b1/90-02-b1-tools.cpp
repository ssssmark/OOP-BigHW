/* 2153538 大数据 刘博洋 */
#include <iostream>
#include "../include/cmd_console_tools.h"
#include"../include/commen_menu.h"
#include"90-02-b1.h"
#include <conio.h>
using namespace std;
void end()
{
	cout << endl << "按回车键继续...";
	while (_getch() != '\r')
		;
	cct_cls();
}
void inputrow_col(int &M,int&N)
{
	while (1)
	{
		cout << "请输入游戏区域的高M[18-26]：" << endl;
		cin >> M;
		if (cin.good() && M >= 18 && M <= 26)
		{
			cin.clear();
			break;
		}
	}
	while (1)
	{
		cout << "请输入游戏区域的宽M[12-21]（必须是3的倍数）：" << endl;
		cin >> N;
		if (cin.good() && N >= 12 && N <= 21 && N % 3 == 0)
		{
			cin.clear();
			break;
		}
	}
}