/* 2153538 大数据 刘博洋 */
#include <iostream>
#include "../include/cmd_console_tools.h"
#include"../include/commen_menu.h"
#include"90-02-b1.h"
#include <conio.h>
using namespace std;
int main()
{
	cct_setconsoleborder(200, 80,500,500);
	cct_setfontsize("新宋体", 14);
	while (1)
	{
		int a = menu(bigHW_no);
		switch (a)
		{
		case 0:
			return 0;
		case 1:
		{
			cct_cls();
			console_main_fun(1);
			break;
		}
		break;
		case 2:
			console_main_fun(2);
			cct_setcolor();
			cct_gotoxy(0, 70);
			end();
			break;
			cct_cls();
		case 3:
			console_main_fun(3);
			cct_setcolor();
			cct_gotoxy(0, 70);
			end();
			break;
		case 4:
			console_main_fun(4);
			cct_setcolor();
			cct_gotoxy(0, 70);
			end();
			break;
		case 5:

			console_main_fun(5);
			cct_setcolor();
			cct_gotoxy(0, 70);
			end();
			break;
		case 6:
			console_main_fun(6);
			cct_setcolor();
			cct_gotoxy(0, 70);
			end();
			break;
		}
		cct_cls();
	}
		
	
	return 0;
}
