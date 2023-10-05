/*大数据 刘博洋 2153538*/
#include<iostream>
#include<cstring>
#include<conio.h>
#include"90-01-b2.h"
#include"../include/cmd_console_tools.h"
#include"../include/commen_menu.h"
using namespace std;
//本cpp放一些主函数即菜单函数
int main()
{

	while (1)
	{
		cct_setconsoleborder(120, 35, 120, 1000);
		cct_setfontsize("点阵字体", 16);
		int i = menu(bigHW_no);
		switch (i)
		{
		case 0:return 0;
			break;
		case 1:
			cct_cls();
			rand_array(1);
			break;
		case 2:
			cct_cls();
			rand_array(2);
			break;
		case 3:
			cct_cls();
			rand_array(3);
			break;
		case 4:
			cct_cls();
			func(1);
			break;
		case 5:
			cct_cls();
			func(2);
			break;
		case 6:
			cct_cls();
			func(3);
			break;
		case 7:
			cct_cls();
			func(4);
			break;
		}
		cct_cls();

	}

	return 0;
}