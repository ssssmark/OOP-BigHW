/* 大数据 2153538 刘博洋 */
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include"../include/cmd_console_tools.h"
using namespace std;
extern int t;
int step = 1;
int M[3][10] = { 0 };
int top[3] = { 0,0,0 };
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
void sleep_s(int t)
{
	switch (t)
	{
	case 0:
		while (_getch() != '\r')
			;
		break;
	case 1:Sleep(300);
		break;
	case 2:Sleep(150);
		break;
	case 3:Sleep(100);
		break;
	case 4:Sleep(50);
		break;
	case 5:Sleep(0);
		break;
	}
}
/***************************************************************************
  函数名称：input
  功    能：输入
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input(int& n, char& src, char& tmp, char& dst, int menu)
{
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;
		if (n >= 1 && n <= 10 && cin.good() == 1)
		{
			cin.ignore(1024, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1024, '\n');
	}
	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if ((src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c') && cin.good() == 1)
		{
			cin.ignore(1024, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1024, '\n');
	}
	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;

		cin >> dst;
		if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && dst != src && cin.good() == 1)
		{
			cin.ignore(1024, '\n');
			break;
		}
		cin.clear();
		cin.ignore(1024, '\n');
	}

	if (src == 'a' || src == 'b' || src == 'c')
		src = src - 32;
	if (dst == 'a' || dst == 'b' || dst == 'c')
		dst = dst - 32;
	if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
		tmp = 'C';
	else if (src == 'A' && dst == 'C' || (src == 'C' && dst == 'A'))
		tmp = 'B';
	else if ((src == 'B' && dst == 'C') || (src == 'C' && dst == 'B'))
		tmp = 'A';
	if (src == 'A')
	{
		for (int i = 0;i < n;i++)
			M[0][i] = n - i;
		top[0] = n;
	}
	else if (src == 'B')
	{
		for (int i = 0;i < n;i++)
			M[1][i] = n - i;
		top[1] = n;
	}
	else if (src == 'C')
	{
		for (int i = 0;i < n;i++)
			M[2][i] = n - i;
		top[2] = n;
	}
	if (menu == 4 || menu == 8)
	{
		while (1)
		{
			cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
			cin >> t;
			if (t >= 0 && t <= 5 && cin.good() == 1)
				break;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		cct_cls();
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << t;
		cct_gotoxy(0, 17);
	}
}
/***************************************************************************
  函数名称：print_y
  功    能：打印纵向底座
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_y(int Y)
{
	cct_gotoxy(10, Y + 1);
	cout << "=========================";
	cct_gotoxy(12, Y + 2);
	cout << "A         B         C";
	for (int y = Y, i = 0;i < 10;y--, i++)
	{
		cct_gotoxy(12, y);
		cout << " ";
	}
	for (int y = Y, i = 0;i < 10;y--, i++)
	{
		cct_gotoxy(22, y);
		cout << " ";
	}
	for (int y = Y, i = 0;i < 10;y--, i++)
	{
		cct_gotoxy(32, y);
		cout << " ";
	}
	for (int y = Y, i = 0;i < top[0];y--, i++)
	{
		cct_gotoxy(12, y);
		cout << M[0][i];
	}
	for (int y = Y, j = 0;j < top[1];y--, j++)
	{
		cct_gotoxy(22, y);
		cout << M[1][j];
	}
	for (int y = Y, k = 0;k < top[2];y--, k++)
	{
		cct_gotoxy(32, y);
		cout << M[2][k];
	}


}
/***************************************************************************
  函数名称：location
  功    能：更新数组元素
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void location(char src, char dst)
{
	if (src == 'A')
	{
		if (dst == 'B')
		{
			M[1][top[1]] = M[0][--top[0]];
			top[1]++;

		}
		else if (dst == 'C')
		{
			M[2][top[2]] = M[0][--top[0]];
			top[2]++;

		}
	}
	else if (src == 'B')
	{
		if (dst == 'A')
		{
			M[0][top[0]] = M[1][--top[1]];
			top[0]++;

		}
		else if (dst == 'C')
		{
			M[2][top[2]] = M[1][--top[1]];
			top[2]++;

		}
	}
	else if (src == 'C')
	{
		if (dst == 'B')
		{
			M[1][top[1]] = M[2][--top[2]];
			top[1]++;

		}
		else if (dst == 'A')
		{
			M[0][top[0]] = M[2][--top[2]];
			top[0]++;

		}
	}

}
/***************************************************************************
  函数名称：print_x
  功    能：打印横向数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_x()
{
	cout << "A:";
	for (int i = 0;i < top[0];i++)
		cout << setw(2) << M[0][i];
	for (int i = 0;i < 10 - top[0];i++)
		cout << "  ";
	cout << " B:";
	for (int i = 0;i < top[1];i++)
		cout << setw(2) << M[1][i];
	for (int i = 0;i < 10 - top[1];i++)
		cout << "  ";
	cout << " C:";
	for (int i = 0;i < top[2];i++)
		cout << setw(2) << M[2][i];
	cout << endl;
}
/***************************************************************************
  函数名称：reset
  功    能：重置参数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void reset()
{
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 10;j++)
		{
			M[i][j] = 0;
		}
	for (int i = 0;i < 3;i++)
		top[i] = 0;
	step = 1;
}
/***************************************************************************
 函数名称：printpillar
 功    能：打印三根柱子
 输入参数：
 返 回 值：
 说    明：
***************************************************************************/
void printpillar()
{
	const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
	const int fg_color = COLOR_HBLUE;		//前景为亮蓝色
	const char ch = ' ';        //字符为*(注意：如果是空格，则前景色无法显示)
	const int LENGTH = 23;

	cct_showch(1, 15, ch, bg_color, fg_color, LENGTH);
	cct_showch(33, 15, ch, bg_color, fg_color, LENGTH);
	cct_showch(65, 15, ch, bg_color, fg_color, LENGTH);
	for (int i = 14;i > 2;i--)
	{
		cct_showch(12, i, ch, bg_color, fg_color, 1);
		Sleep(100);
		cct_showch(44, i, ch, bg_color, fg_color, 1);
		Sleep(100);
		cct_showch(76, i, ch, bg_color, fg_color, 1);
	}
}
/***************************************************************************
 函数名称：printplate
 功    能：在起始柱上打印n个盘子
 输入参数：
 返 回 值：
 说    明：
***************************************************************************/
void printplate(char src, int n)
{
	int bg_color = n;	//背景
	int fg_color = COLOR_HBLUE;//前景
	const char ch = ' ';        //字符为*(注意：如果是空格，则前景色无法显示)
	int LENGTH = 2 * n + 1;
	int k = n;
	if (src == 'A')
		for (int i = 14;i > 14 - n;i--, bg_color--, LENGTH -= 2)
		{
			cct_showch(12 - k, i, ch, bg_color, fg_color, LENGTH);
			k--;
			Sleep(100);
		}
	else if (src == 'B')
		for (int i = 14;i > 14 - n;i--, bg_color--, LENGTH -= 2)
		{
			cct_showch(44 - k, i, ch, bg_color, fg_color, LENGTH);
			k--;
			Sleep(100);
		}
	else if (src == 'C')
		for (int i = 14;i > 14 - n;i--, bg_color--, LENGTH -= 2)
		{
			cct_showch(76 - k, i, ch, bg_color, fg_color, LENGTH);
			k--;
			Sleep(100);
		}
}
/***************************************************************************
 函数名称：move_plate
 功    能：移动盘子
 输入参数：
 返 回 值：
 说    明：
***************************************************************************/
void move_plate(char src, char dst)
{
	int bg_color = 0;
	int fg_color = 7;
	int a[3] = { 12,44,76 };
	const char ch = ' ';
	int LENGTH = 0;
	int y;
	int flag = 0;
	if (dst < src)
		flag = 1;
	bg_color = M[src - 'A'][top[src - 'A']];
	LENGTH = 2 * M[src - 'A'][top[src - 'A']] + 1;
	cct_showch(a[src - 'A'] - M[src - 'A'][top[src - 'A']], 14 - top[src - 'A'], ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
	cct_showch(a[src - 'A'], 14 - top[src - 'A'], ch, COLOR_HYELLOW, COLOR_WHITE, 1);
	for (y = 14 - top[src - 'A']; y > 1; y--) {

		cct_showch(a[src - 'A'] - M[src - 'A'][top[src - 'A']], y, ch, bg_color, fg_color, LENGTH);
		if (t == 0)
		{
			Sleep(20);
		}
		else
			sleep_s(t);

		if (y > 2) {
			cct_showch(a[src - 'A'] - M[src - 'A'][top[src - 'A']], y, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
			cct_showch(a[src - 'A'], y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);

		}
		if (t == 0)
		{
			Sleep(20);
		}
		else
			sleep_s(t);
	}
	int x;
	if (flag == 0)
	{
		bg_color = M[src - 'A'][top[src - 'A']];
		LENGTH = 2 * M[src - 'A'][top[src - 'A']] + 1;
		cct_showch(a[src - 'A'] - M[src - 'A'][top[src - 'A']], y + 1, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
		cct_showch(a[src - 'A'] - M[src - 'A'][top[src - 'A']], y, ch, bg_color, fg_color, LENGTH);
		for (x = a[src - 'A'] - M[src - 'A'][top[src - 'A']]; x < a[dst - 'A'] + 1 - M[src - 'A'][top[src - 'A']]; x++)
		{
			cct_showch(x, y, ch, bg_color, fg_color, LENGTH);
			if (t == 0)
			{
				Sleep(20);
			}
			else
				sleep_s(t);
			if (x < a[dst - 'A'] - M[src - 'A'][top[src - 'A']])
			{
				cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
			}
			if (t == 0)
			{
				Sleep(20);
			}
			else
				sleep_s(t);
		}
	}
	else if (flag == 1)
	{
		bg_color = M[src - 'A'][top[src - 'A']];
		LENGTH = 2 * M[src - 'A'][top[src - 'A']] + 1;
		cct_showch(a[src - 'A'] - M[src - 'A'][top[src - 'A']], y + 1, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
		cct_showch(a[src - 'A'] - M[src - 'A'][top[src - 'A']], y, ch, bg_color, fg_color, LENGTH);
		for (x = a[src - 'A'] - M[src - 'A'][top[src - 'A']]; x > a[dst - 'A'] + 1 - M[src - 'A'][top[src - 'A']]; x--)
		{
			cct_showch(x, y, ch, bg_color, fg_color, LENGTH);
			if (t == 0)
			{
				Sleep(20);
			}
			else
				sleep_s(t);
			if (x > a[dst - 'A'] - M[src - 'A'][top[src - 'A']])
			{
				cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
			}
			if (t == 0)
			{
				Sleep(20);
			}
			else
				sleep_s(t);
		}
	}

	cct_showch(a[dst - 'A'] - M[src - 'A'][top[src - 'A']], y, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
	cct_showch(a[dst - 'A'] - M[src - 'A'][top[src - 'A']], y + 1, ch, bg_color, fg_color, LENGTH);
	if (t == 0)
	{
		Sleep(20);
	}
	else
		sleep_s(t);
	cct_showch(a[dst - 'A'] - M[src - 'A'][top[src - 'A']], y + 1, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
	for (y = 3;y < 16 - top[dst - 'A']; y++)
	{
		cct_showch(a[dst - 'A'] - M[src - 'A'][top[src - 'A']], y, ch, bg_color, fg_color, LENGTH);
		if (t == 0)
		{
			Sleep(20);
		}
		else
			sleep_s(t);
		if (y < 15 - top[dst - 'A']) {
			cct_showch(a[dst - 'A'] - M[src - 'A'][top[src - 'A']], y, ch, COLOR_BLACK, COLOR_WHITE, LENGTH);
			cct_showch(a[dst - 'A'], y, ch, COLOR_HYELLOW, COLOR_WHITE, 1);

		}
		if (t == 0)
		{
			Sleep(20);
		}
		else
			sleep_s(t);
	}
}
int is_error(char src, char dst)
{
	if (M[src - 'A'][top[src - 'A'] - 1] == 0)
		return 1;
	else if (M[dst - 'A'][top[dst - 'A'] - 1] != 0 && M[src - 'A'][top[src - 'A'] - 1] > M[dst - 'A'][top[dst - 'A'] - 1])
		return 2;
	else return 0;
}
int cingame(char& a, char& b)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	while (1)
	{
		while (1)
		{
			char str[20] = { 0 };
			for (int i = 0; i < 20; i++) {
				str[i] = _getch();
				if (str[i] == 8) {
					i--;
					continue;
				}
				cout << str[i];
				if (str[i] == 13) {
					break;
				}

			}
			cct_gotoxy(59, 35);
			char s = str[0];
			if ((s == 'q' || s == 'Q') && str[1] == 13) {
				cout << endl << "游戏中止!!!!!";
				return 1;
			}
			if (s == '\n') {
				continue;
			}
			char d = str[1];
			if (d == '\n') {
				cct_gotoxy(59, 35);
				cout << setw(20) << "";
				continue;
			}
			if (str[2] != 13) {
				cct_gotoxy(59, 35);
				cout << setw(20) << "";
				cct_gotoxy(59, 35);
				continue;
			}
			a = str[0];
			b = str[1];
			if ((a == 'A' || a == 'B' || a == 'C' || a == 'a' || a == 'b' || a == 'c') && (b == 'A' || b == 'B' || b == 'C' || b == 'a' || b == 'b' || b == 'c'))
			{
				if (a == 'a')
					a = 'A';
				if (a == 'b')
					a = 'B';
				if (a == 'c')
					a = 'C';
				if (b == 'a')
					b = 'A';
				if (b == 'b')
					b = 'B';
				if (b == 'c')
					b = 'C';
				if (b != a)
					break;
			}
			cct_showch(59, 35, ' ', 0, 7, 10);
			cct_gotoxy(59, 35);
		}
		int judge = is_error(a, b);
		if (judge == 0)
			break;
		else if (judge == 1)
		{
			cout << "源柱为空!" << endl;
			Sleep(1000);
			cct_showch(59, 35, ' ', 0, 7, 10);
			cct_showch(0, 36, ' ', 0, 7, 50);
			cct_gotoxy(59, 35);
			continue;
		}
		else if (judge == 2)
		{
			cout << "大盘压小盘，非法移动!" << endl;
			Sleep(1000);
			cct_showch(59, 35, ' ', 0, 7, 10);
			cct_showch(0, 36, ' ', 0, 7, 50);
			cct_gotoxy(59, 35);
			continue;
		}
	}
	cct_setcursor(CURSOR_INVISIBLE);
	return 0;
}
/***************************************************************************
  函数名称：func_by_menu
  功    能：根据菜单选项执行功能
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void func_by_menu(int menu, int n, char src, char tmp, char dst)
{
	switch (menu)
	{
	case 1:cout << n << "# " << src << "---->" << dst << endl;
		break;
	case 2:cout << "第" << setw(4) << step << " 步( " << n << "#:" << src << "---->" << dst << ")" << endl;
		break;
	case 3:cout << "第" << setw(4) << step << " 步( " << n << "#:" << src << "---->" << dst << ")" << "  ";
		location(src, dst);
		print_x();
		break;
	case 4:location(src, dst);
		sleep_s(t);
		print_y(11);
		cct_gotoxy(0, 17);
		cout << "第" << setw(4) << step << " 步( " << n << "#:" << src << "---->" << dst << ")" << "  ";
		print_x();
		break;
	case 5:printpillar();
		break;
	case 6:
		printpillar();
		printplate(src, n);
		break;
	case 7:
		t = 3;
		printpillar();
		printplate(src, n);
		Sleep(1000);
		if (n % 2 == 1)
		{
			location(src, dst);
			move_plate(src, dst);
		}

		else
		{
			location(src, tmp);
			move_plate(src, tmp);
		}

		break;
	case 8:

		location(src, dst);
		sleep_s(t);
		print_y(28);
		cct_gotoxy(0, 33);
		cout << "第" << setw(4) << step << " 步( " << n << "#:" << src << "---->" << dst << ")" << "  ";
		print_x();
		move_plate(src, dst);
		cct_setcolor(0, 7);
		break;
	case 9:
		cct_gotoxy(0, 35);
		t = 4;
		char a, b;
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出)：";

		while (1)
		{
			if (cingame(a, b) == 1)
				break;
			location(a, b);
			sleep_s(t);
			print_y(28);
			cct_gotoxy(0, 33);
			cout << "第" << setw(4) << step << " 步( " << n << "#:" << src << "---->" << dst << ")" << "  ";
			print_x();
			move_plate(a, b);
			step++;
			cct_setcolor(0, 7);
			cct_showch(59, 35, ' ', 0, 7, 2);
			cct_gotoxy(59, 35);
			if (top[dst - 'A'] == n)
			{
				cout << endl;
				cout << "游戏结束!!!!!";
				break;
			}
		}
	}

}
/***************************************************************************
  函数名称：pause
  功    能：停顿并按回车继续
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void pause(int x, int y)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(x, y);
	cout << "按回车键继续";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	cct_cls();
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst, int menu)
{
	if (n == 1)
		func_by_menu(menu, n, src, tmp, dst);
	else {
		hanoi(n - 1, src, dst, tmp, menu);
		step++;
		func_by_menu(menu, n, src, tmp, dst);
		step++;
		hanoi(n - 1, tmp, src, dst, menu);
	}
}
