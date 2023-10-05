/*������ ������ 2153538*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<cstring>
#include"90-02-b1.h"
#include"../include/cmd_console_tools.h"
#include "../include/commen_menu.h"
using namespace std;
void console_main_fun(int menu)
{
	int game[max_height][max_width] = {};//game������Ѿ���������Ŀ飬���ڿ��еĿ���n.map������
	for (int i = 0;i < max_height;i++)
		for (int j = 0;j < max_width;j++)
			game[i][j] = -1;
	if (menu == 1)
	{
		int num;
		cout << "��������Ҫչʾ������(0-9)��" << endl;
		num = deal_input(9);
		block n;
		n.num = num;
		fillmap(n.num, n.map);
		drawnum(X, Y,n);
		cct_setcolor();
		end();
	}
	if (menu == 2||menu==3||menu==4)
	{
		int M, N;
		inputrow_col(M,N);
		int num = get_next_num(true, (unsigned int)time(0));
		block n;
		n.cur_x = N / 2;
		n.cur_y = Y;
		n.num = num;
		fillmap(n.num, n.map);
		drawmap(M, N, game);
		updatemap(M, N, game, n);
		
		if (menu == 3)
		{
			while (n.cur_y < N - 3)
			{
				Sleep(500);
				down(n, game, M, N);
			}
		}
		if (menu == 4)
		{
			while (moveable(n,game,M,N,0))
			{
				
				if (_kbhit())
				{
					char a = _getch();
					if (a == -32)
					{
						move(n, game, M, N);
					}
				}
				else{
					down(n, game, M, N);
				}			
			}
		}
		
		
	}
	if (menu == 5)
	{

		int M, N;
		int score = 0, linenum = 0;
		inputrow_col(M, N);
		int times = 5;
		drawmap(M, N, game);
		while (times--)
		{
			int num = get_next_num(false, (unsigned int)time(0));
			block n;
			n.cur_x = N / 2;
			n.cur_y = Y;
			n.num = num;
			fillmap(n.num, n.map);
			
			while (moveable(n, game, M, N, 0))
			{

				if (_kbhit())
				{
					char a = _getch();
					if (a == -32)
					{
						move(n, game, M, N);
					}
				}
				else {
					Sleep(100);
					down(n, game, M, N);
				}
			}
			mergeinto_gamemap(game, n, M, N);
			clearline(game, M, N,score,linenum);
			cct_setcolor();
			
		}
		
	}
	if (menu == 6)
	{
		int M, N;
		int v = 1000;
		int score = 0, linenum = 0;
		inputrow_col(M, N);
		drawmap(M, N, game);		
		int num, nextnum;
		num = get_next_num(true, (unsigned int)time(0));
		nextnum = -1;
		while (!isover(game,M,N))
		{
			if (nextnum != -1)
			{
				num = nextnum;
			}			
			nextnum = get_next_num(true, 2*(unsigned int)time(0));
			block n;
			n.cur_x = N / 2;
			n.cur_y = Y;
			n.num = num;
			block next;
			next.num = nextnum;
			fillmap(n.num, n.map);
			fillmap(next.num, next.map);
			draw_scoreboard(next,score,linenum);
			while (moveable(n, game, M, N, 0))
			{
				updatemap(M, N, game, n);
				//���������ٶ�
				if (score < 120)
				{
					v = 1000 - score / 15 * 100;
				}
				else {
					v = 300;
				}
				if (_kbhit())
				{
					char a = _getch();
					if (a == -32)
					{
						move(n, game, M, N);
					}
				}
				else {
					Sleep(v);
					down(n, game, M, N);
				}
			}
			mergeinto_gamemap(game, n, M, N);
			clearline(game, M, N,score,linenum);
			cct_setcolor();

		}
		cct_gotoxy(0, M*3+4);
		cout << "��Ϸ������";
	}


}
/***************************************************************************
  �������ƣ�drawsquare
  ��    �ܣ�����һ������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void draw_square(int cen_x, int cen_y,int num)
{
	cct_showstr(cen_x, cen_y, "��", num+1, COLOR_BLACK);
	cct_showstr(cen_x - 2, cen_y - 1, "�X", num+1, COLOR_BLACK);
	cct_showstr(cen_x, cen_y - 1, "�T", num+1, COLOR_BLACK);
	cct_showstr(cen_x + 2, cen_y - 1, "�[", num+1, COLOR_BLACK);
	cct_showstr(cen_x - 2, cen_y, "�U", num+1, COLOR_BLACK);
	cct_showstr(cen_x + 2, cen_y, "�U", num+1, COLOR_BLACK);
	cct_showstr(cen_x - 2, cen_y + 1, "�^", num+1, COLOR_BLACK);
	cct_showstr(cen_x, cen_y + 1, "�T", num+1, COLOR_BLACK);
	cct_showstr(cen_x + 2, cen_y + 1, "�a", num+1, COLOR_BLACK);
}
/***************************************************************************
�������ƣ�drawnum
��    �ܣ�����0-9����
�� �� ֵ��
˵    ����
***************************************************************************/
void drawnum(int centx,int centy,block n)
{
	for (int i = 0;i < numheight;i++)
	{
		for (int j = 0;j < numheight;j++)
		{
			if (n.map[i][j] == 1)
			{
				draw_square(j*numsquare+numsquare/2+centx*numsquare, centy * numsquare/2+i*numsquare/2+numsquare/2,n.num);
			}
		}
	}
}
/***************************************************************************
�������ƣ�draw_scoreboard
��    �ܣ�����0-9����
�� �� ֵ��
˵    ����
***************************************************************************/
void draw_scoreboard(block n,int score,int linenum)
{
	cct_showstr(150, 1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(150, 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(150, 3, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(150, 4, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 0;i < 10;i++)
	{
		cct_showstr(152 + 2 * i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(152 + 2 * i, 2, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(152 + 2 * i, 3, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(152 + 2 * i, 4, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
	}
	cct_showstr(172, 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(172, 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(172, 3, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(172, 4, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(155, 2, "�÷֣�", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showint(162, 2, score, COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(155, 3, "������������", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showint(167, 3, linenum, COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(150, 7, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 0;i < 18;i++)
	{
		cct_showstr(150, 8+i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(152, 8 + i, "  ", COLOR_HWHITE, COLOR_BLACK, 20);
	}
	
	cct_showstr(150, 25, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 0;i < 40;)
	{
		cct_showstr(152 + i, 7, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
	}
	cct_showstr(190, 7, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 0;i < 18;i++)
	{
		cct_showstr(190, 8 + i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	}
	for (int i = 0;i < 40;)
	{
		cct_showstr(152 + i, 25, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
	}
	cct_showstr(190, 25, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (n.map[j][i] != 0)
			{
				draw_square(6*i + 158, j*3 + 10, n.num);
			}
		}
	}
}


/***************************************************************************
  �������ƣ�drawmap
  ��    �ܣ�������Ϸ������Ѿ������Ŀ�
  �� �� ֵ��
  ˵    ����������M*N�����ӵ���Ϸ����
***************************************************************************/
void drawmap(int row,int col, int game[max_height][max_width])
{
	cct_cls();
	cct_showstr(0, 1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
	int i;
	for (i = 2;i < 6 * col - 6;)
	{
		cct_showstr(i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
		cct_showstr(i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
		cct_showstr(i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
	}
	cct_showstr(i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
	i += 2;
	cct_showstr(i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
	i += 2;
	cct_showstr(i, 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
	int j;
	for (j = 2;j < 3 * row;)
	{
		int m;
		
		for (m = 0;m < 6 * col;m += 6)
		{
			cct_showstr(m, j, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(m + 2, j, "    ", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_showstr(0, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(m, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		j++;
	}
	int m;
	
	for (m = 0;m < 6 * col;m += 6)
	{
		cct_showstr(m, j, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(m + 2, j, "    ", COLOR_HWHITE, COLOR_BLACK, 1);
	}
	cct_showstr(0, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_showstr(m, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
	j++;
	cct_showstr(0, j, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
	i = 0;
	for (i = 2;i < 6 * col - 6;)
	{
		cct_showstr(i, j, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
		cct_showstr(i, j, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
		cct_showstr(i, j, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
	}
	cct_showstr(i, j, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
	i += 2;
	cct_showstr(i, j, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
	i += 2;
	cct_showstr(i, j, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
	cct_setcolor();
}

/***************************************************************************
�������ƣ�updateblock
��    �ܣ����¿��״̬
�� �� ֵ��
˵    ����
***************************************************************************/
void updateblock(int row, int col, int game[max_height][max_width], block n)
{
	int maxlen = max(n.block_height, n.block_width);
	for (int j = n.cur_x - n.block_width / 2;j <= n.cur_x + n.block_width / 2;j++)
	{
		for (int i = n.cur_y - n.block_height / 2;i <= n.cur_y + n.block_height / 2;i++)
		{
			if(n.map[i - (n.cur_y - maxlen / 2)][j - (n.cur_x - maxlen / 2)] != 0)
				draw_square(j * numsquare + numsquare / 2, i * numsquare / 2 + 3, n.num);
		}
	}
}
/***************************************************************************
�������ƣ�updatemap
��    �ܣ������ڲ�����Ϳ�λ�ø��µ�ͼ
�� �� ֵ��
˵    ����
***************************************************************************/
void updatemap(int row, int col, int game[max_height][max_width],block n)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (game[i][j] != -1)
			{
				draw_square(j * numsquare + numsquare / 2, i * numsquare / 2 + 3, game[i][j]);
			}
			else if (isin_block(i,j,n))
			{
				draw_square(j * numsquare + numsquare / 2, i * numsquare / 2 + 3, n.num);
			}
			else {
				//�����ð�ɫ����
				if (i != row - 1)
				{
					if (j != 0 && j != col - 1)
					{
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 2, "      ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 3, "      ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 4, "      ", COLOR_HWHITE, COLOR_BLACK, 1);
					}
					else if (j == 0)
					{
						cct_showstr(j * numsquare + numsquare / 2-3, i * numsquare / 2 + 2, "�U     ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2-3, i * numsquare / 2 + 3, "�U     ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2-3, i * numsquare / 2 + 4, "�U     ", COLOR_HWHITE, COLOR_BLACK, 1);
					}
					else if (j == col - 1)
					{
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 2, "     �U", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 3, "     �U", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 4, "     �U", COLOR_HWHITE, COLOR_BLACK, 1);
					}
				}
				else {
					if (j != 0 && j != col - 1)
					{
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 2, "      ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 3, "      ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 4, "�T�T�T", COLOR_HWHITE, COLOR_BLACK, 1);
					}
					else if (j == 0)
					{
						cct_showstr(j * numsquare + numsquare / 2 - 3, i * numsquare / 2 + 2, "�U     ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 3, i * numsquare / 2 + 3, "�U     ", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 3, i * numsquare / 2 + 4, "�^�T �T", COLOR_HWHITE, COLOR_BLACK, 1);
					}
					else if (j == col - 1)
					{
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 2, "     �U", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 3, "     �U", COLOR_HWHITE, COLOR_BLACK, 1);
						cct_showstr(j * numsquare + numsquare / 2 - 2, i * numsquare / 2 + 4, "�T �T�a", COLOR_HWHITE, COLOR_BLACK, 1);
					}
				}
				
			}
		}
	}
}
