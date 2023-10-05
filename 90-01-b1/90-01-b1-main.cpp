/* 刘博洋 215358 大数据 */
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include"../include/cmd_console_tools.h"
#include"90-01-b1-hanoi.h"
#include"../include/commen_menu.h"
using namespace std;
int t;
extern int step;
extern int M[3][10];
extern int top[3];
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
int main()
{
	int n = 0;
	char src = ' ', tmp = ' ', dst = ' ';
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);

	while (1)
	{
		int a = menu(bigHW_no);
		switch (a)
		{
		case 0:return 0;
			break;
		case 1:input(n, src, tmp, dst, 1);
			hanoi(n, src, tmp, dst, 1);
			reset();
			cout << endl;
			cout << "按回车键继续...";
			while (_getch() != '\r')
				;
			cct_cls();
			break;
		case 2:input(n, src, tmp, dst, 2);
			hanoi(n, src, tmp, dst, 2);
			reset();
			cout << endl;
			cout << "按回车键继续";
			while (_getch() != '\r')
				;
			cct_cls();
			break;
		case 3:input(n, src, tmp, dst, 3);
			hanoi(n, src, tmp, dst, 3);
			reset();
			cout << endl;
			cout << "按回车键继续";
			while (_getch() != '\r')
				;
			cct_cls();
			break;
		case 4:input(n, src, tmp, dst, 4);
			print_y(11);
			cct_gotoxy(0, 17);
			cout << "初始:  ";
			print_x();
			cct_setcursor(CURSOR_INVISIBLE);
			sleep_s(t);
			hanoi(n, src, tmp, dst, 4);
			reset();
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			pause(0, 38);
			break;
		case 5:cct_cls();
			cct_setcursor(CURSOR_INVISIBLE);
			func_by_menu(5, n, src, tmp, dst);
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			pause(0, 38);
			break;
		case 6:input(n, src, tmp, dst, 6);
			cct_cls();
			cct_setcursor(CURSOR_INVISIBLE);
			func_by_menu(6, n, src, tmp, dst);
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			pause(0, 38);
			break;
		case 7:
			input(n, src, tmp, dst, 6);
			cct_cls();
			cct_setcursor(CURSOR_INVISIBLE);
			func_by_menu(7, n, src, tmp, dst);
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			pause(0, 38);
			break;
		case 8:
			input(n, src, tmp, dst, 8);
			print_y(28);
			cct_gotoxy(0, 33);
			cout << "初始:  ";
			print_x();
			cct_setcursor(CURSOR_INVISIBLE);
			printpillar();
			printplate(src, n);
			cct_setcolor(0, 7);
			if (t != 0)
			{
				sleep_s(1000);
			}
			hanoi(n, src, tmp, dst, 8);
			reset();
			while (_getch() != '\r')
				;
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			pause(0, 38);
			break;
		case 9:
			input(n, src, tmp, dst, 9);
			cct_cls();
			print_y(28);
			cct_gotoxy(0, 33);
			cout << "初始:  ";
			print_x();
			cct_setcursor(CURSOR_INVISIBLE);
			printpillar();
			printplate(src, n);
			cct_setcolor(0, 7);

			if (t != 0)
			{
				sleep_s(1000);
			}
			func_by_menu(9, n, src, tmp, dst);
			while (_getch() != '\r')
				;
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			reset();
			pause(0, 38);
			break;
		}

	}


	return 0;
}
