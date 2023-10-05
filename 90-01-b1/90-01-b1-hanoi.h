/* 2153538 刘博洋 大数据 */
#pragma once
const int bigHW_no = 1;
void input(int& n, char& src, char& tmp, char& dst, int menu);//输入
void hanoi(int n, char src, char tmp, char dst, int menu);//主要递归函数
void print_y(int Y);//打印纵向数组
void sleep_s(int t);//延时操作
void print_x();//打印横向数组
void reset();//重置参数表
void pause(int x, int y);//等待按回车继续
void func_by_menu(int menu, int n, char src, char tmp, char dst);//根据菜单选择递归函数中执行的操作
void printplate(char src, int n);//打印圆盘
void printpillar();//打印柱子
/* ------------------------------------------------------------------------------------------------------

	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

