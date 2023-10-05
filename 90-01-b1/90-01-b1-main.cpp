/* ������ 215358 ������ */
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

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
int main()
{
	int n = 0;
	char src = ' ', tmp = ' ', dst = ' ';
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
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
			cout << "���س�������...";
			while (_getch() != '\r')
				;
			cct_cls();
			break;
		case 2:input(n, src, tmp, dst, 2);
			hanoi(n, src, tmp, dst, 2);
			reset();
			cout << endl;
			cout << "���س�������";
			while (_getch() != '\r')
				;
			cct_cls();
			break;
		case 3:input(n, src, tmp, dst, 3);
			hanoi(n, src, tmp, dst, 3);
			reset();
			cout << endl;
			cout << "���س�������";
			while (_getch() != '\r')
				;
			cct_cls();
			break;
		case 4:input(n, src, tmp, dst, 4);
			print_y(11);
			cct_gotoxy(0, 17);
			cout << "��ʼ:  ";
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
			cout << "��ʼ:  ";
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
			cout << "��ʼ:  ";
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
