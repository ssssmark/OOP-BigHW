/*������ ������ 2153538*/
//��cpp��cmdͼ�ν��淽ʽʵ�ֵĺ���
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
#include"90-01-b2.h"
#include"../include/cmd_console_tools.h"
using namespace std;
/***************************************************************************
  �������ƣ�printshape
  ��    �ܣ�ѡ��ͬ���ܴ�ӡͼ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void printshape(int map[9][9], int row, int col, int mode, int color[])
{
	if (mode == 1)
	{
		cct_showstr(0, 1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
		Sleep(50);
		for (int i = 0;i < 2 * col;i += 2)
		{
			cct_showstr(2 + i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			Sleep(50);
		}
		cct_showstr(2 * col + 2, 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int i = 0;i < row;i++)
		{
			cct_showstr(0, i + 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(2 * (col + 1), i + 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			Sleep(50);
		}
		cct_showstr(2 * col + 2, row + 2, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_showstr(0, row + 2, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
		Sleep(50);
		for (int i = 0;i < 2 * col;i += 2)
		{
			cct_showstr(2 + i, row + 2, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			Sleep(50);
		}
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < 2 * col;j += 2)
			{
				if (map[i][j / 2] != 0)
				{
					cct_showstr(2 + j, 2 + i, "��", map[i][j / 2], COLOR_HWHITE, 1, -1);
				}
				else
					cct_showstr(2 + j, 2 + i, "  ", COLOR_HWHITE, COLOR_HBLACK, 1, -1);
				Sleep(50);
			}
		}

	}
	else if (mode == 2 || mode == 3 || mode == 4)
	{
		cct_showstr(0, 1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
		int i;
		for (i = 2;i < 4 * col - 4;)
		{
			cct_showstr(i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
			i += 2;
			cct_showstr(i, 1, "�j", COLOR_HWHITE, COLOR_BLACK, 1);
			i += 2;
		}
		cct_showstr(i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
		cct_showstr(i, 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
		int j;
		for (j = 2;j < 2 * row - 1;)
		{
			int m;
			for (m = 0;m < 4 * col;m += 4)
			{
				cct_showstr(m, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
				if (map[j / 2 - 1][m / 4] != 0)
				{
					cct_showstr(m + 2, j, "��", map[j / 2 - 1][m / 4], COLOR_HWHITE, 1, -1);
				}
				else
					cct_showstr(m + 2, j, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_showstr(m, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			j++;
			int n = 0;
			cct_showstr(n, j, "�d", COLOR_HWHITE, COLOR_BLACK, 1);
			for (n = 2;n < 4 * col;)
			{
				cct_showstr(n, j, "�T�p", COLOR_HWHITE, COLOR_BLACK, 1);
				n += 4;
			}
			cct_showstr(n - 5, j, " �T�g", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(n - 6, j, "�p", COLOR_HWHITE, COLOR_BLACK, 1);
			j++;
		}
		int m;
		for (m = 0;m < 4 * col;m += 4)
		{
			cct_showstr(m, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			if (map[j / 2 - 1][m / 4] != 0)
			{
				cct_showstr(m + 2, j, "��", map[j / 2 - 1][m / 4], COLOR_HWHITE, 1, -1);
			}
			else
				cct_showstr(m + 2, j, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_showstr(m, j, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		j++;
		cct_showstr(0, j, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
		i = 0;
		for (i = 2;i < 4 * col - 4;)
		{
			cct_showstr(i, j, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
			i += 2;
			cct_showstr(i, j, "�m", COLOR_HWHITE, COLOR_BLACK, 1);
			i += 2;
		}
		cct_showstr(i, j, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		i += 2;
		cct_showstr(i, j, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
		if (mode == 4)
		{   //��ӡ�÷ֿ�
			cct_showstr(40, 1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(40, 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(40, 3, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int i = 0;i < 5;i++)
			{
				cct_showstr(42 + 2 * i, 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(42 + 2 * i, 2, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(42 + 2 * i, 3, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_showstr(52, 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(52, 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(52, 3, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(42, 2, "�÷֣�0", COLOR_HWHITE, COLOR_BLACK, 1);
			//��ӡԤ������������ɫ��
			cct_showstr(40, 5, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(40, 6, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(40, 7, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int i = 0;i < 8;)
			{
				cct_showstr(42 + i, 5, "�T", COLOR_HWHITE, COLOR_BLACK, 1);

				cct_showstr(42 + i, 7, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
				i += 2;
				cct_showstr(42 + i, 5, "�j", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(42 + i, 6, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(42 + i, 7, "�m", COLOR_HWHITE, COLOR_BLACK, 1);
				i += 2;
			}
			cct_showstr(50, 5, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int j = 0;j < 3;j++)
			{
				cct_showstr(42 + 4 * j, 6, "��", color[j], COLOR_HWHITE, 1);
			}
			cct_showstr(50, 7, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(52, 5, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(52, 6, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(52, 7, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
			//��ӡ����ɫ��ֲ���ͳ�ƿ�
			cct_showstr(40, 9, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(66, 9, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int m = 0;m < 8;m++)
			{
				cct_showstr(40, 10 + m, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
				cct_showstr(66, 10 + m, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			cct_showstr(40, 18, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_showstr(66, 18, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
			for (int i = 0;i < 12;i++)
			{
				cct_showstr(42 + 2 * i, 9, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
				for (int n = 0;n < 8;n++)
				{
					cct_showstr(42 + 2 * i, 10 + n, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
				}
				cct_showstr(42 + 2 * i, 18, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
			}
			for (int j = 0;j < 8;j++)
			{
				if (j != 0)
					cct_showstr(42, 10 + j, "��", j, COLOR_HWHITE, 1);
				cct_showstr(44, 10 + j, ":00/( 0.00%) ����-0", COLOR_HWHITE, COLOR_BLACK, 1);
			}
		}
	}
	cout << endl;
	cct_setcolor();
}
/***************************************************************************
  �������ƣ� movexy
  ��    �ܣ����������յ���ͼ�ν�������ƶ�
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int movexy(int startx, int starty, int dstx, int dsty, int map[9][9], int row, int col)
{
	int step = 0;
	Node path[100] = { 0 };
	int mark[9][9] = { 0 };
	int ret = bfs(starty, startx, map, path, mark, row, col, dsty, dstx, step);
	if (ret == 1)
	{
		for (int i = step - 2;i >= 0;i--)
		{
			int my = 2 * path[i].x - 2 * path[i].px;
			int mx = 4 * path[i].y - 4 * path[i].py;
			if (mx == 0)
			{
				cct_showstr(int(4 * path[i].py + 2), int(2 * path[i].px + 2 + 0.5 * my), "��", map[starty][startx], COLOR_HWHITE, 1);
				cct_showstr(4 * path[i].py + 2, 2 * path[i].px + 2, "  ", COLOR_HWHITE, COLOR_HWHITE, 1);
				Sleep(200);
				cct_showstr(4 * path[i].py + 2, 2 * path[i].px + 2 + my, "��", map[starty][startx], COLOR_HWHITE, 1);
				cct_showstr(int(4 * path[i].py + 2), int(2 * path[i].px + 2 + 0.5 * my), "��", COLOR_HWHITE, COLOR_BLACK, 1);
				Sleep(200);
			}
			else if (my == 0)
			{
				cct_showstr(int(4 * path[i].py + 2 + 0.5 * mx), 2 * path[i].px + 2, "��", map[starty][startx], COLOR_HWHITE, 1);
				cct_showstr(4 * path[i].py + 2, 2 * path[i].px + 2, "  ", COLOR_HWHITE, COLOR_HWHITE, 1);
				Sleep(200);
				cct_showstr(4 * path[i].py + 2 + mx, 2 * path[i].px + 2, "��", map[starty][startx], COLOR_HWHITE, 1);
				cct_showstr(int(4 * path[i].py + 2 + 0.5 * mx), 2 * path[i].px + 2, "��", COLOR_HWHITE, COLOR_BLACK, 1);
				Sleep(200);
			}


		}
		return 1;
	}
	else
		return 0;

}
/***************************************************************************
  �������ƣ� mouse
  ��    �ܣ���������ѡ����Ч�ͱ�������յ㣩
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int mouse(int row, int col, int map[9][9], int& endx, int& endy)
{
	cct_enable_mouse();

	int MX = 0, MY = 0;
	int MAction = MOUSE_NO_ACTION;
	int keycode1, keycode2;
	cct_setcursor(CURSOR_INVISIBLE);
	int old_x = endx, old_y = endy;

	while (1)
	{
		int ret = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		cct_showstr(0, 2 * row + 2, " ", 0, 7, 30);
		if (ret == CCT_MOUSE_EVENT)
		{
			int x, y;
			x = MX / 4;
			y = MY / 2 - 1;
			if (MAction == MOUSE_RIGHT_BUTTON_CLICK)
			{
				cct_disable_mouse();
				cct_setcolor();
				cct_setcursor(CURSOR_VISIBLE_NORMAL);
				cct_gotoxy(0, 2 * row + 1);
				return -1;
			}
			if ((MX == 4 * x + 2 || MX == 4 * x + 3) && MY == 2 * y + 2 && y >= 0 && y < row && x >= 0 && x < col)
			{

				cct_gotoxy(0, 2 * row + 2);
				cout << "[��ǰ���]" << char('A' + y) << "��" << x + 1 << "��";
				if (MAction == MOUSE_LEFT_BUTTON_CLICK && map[y][x] != 0)
				{
					if (old_x != -1 && old_y != -1 && map[old_y][old_x] != 0)
					{
						cct_showstr(4 * old_x + 2, 2 * old_y + 2, "��", map[old_y][old_x], COLOR_HWHITE, 1);
					}
					cct_showstr(4 * x + 2, 2 * y + 2, "��", map[y][x], COLOR_HWHITE, 1);
					old_x = x;
					old_y = y;
				}
				else if (MAction == MOUSE_LEFT_BUTTON_CLICK && map[y][x] == 0)
				{
					endx = x;
					endy = y;
					if (old_x != -1 && old_y != -1)
					{
						if (movexy(old_x, old_y, endx, endy, map, row, col) == 1)
						{
							map[endy][endx] = map[old_y][old_x];
							map[old_y][old_x] = 0;
							break;
						}

						else
						{
							cct_gotoxy(0, 2 * row + 2);
							cout << "[����]�޷���[" << char('A' + old_y) << old_x + 1 << "]�Ƶ�[" << char('A' + y) << x + 1 << "]";
							continue;
						}
					}
				}


				cct_setcolor();
			}
		}

	}
	cct_disable_mouse();
	cct_setcolor();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_gotoxy(0, 2 * row + 1);
	return 0;
}
/***************************************************************************
  �������ƣ�update
  ��    �ܣ����һ���������ɫ���÷֡������������Ȳ���ӡ
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void update(int map[9][9], int row, int col, int color[], int score, int clearnum[])
{
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cct_gotoxy(48, 2);
	cout << score;
	for (int j = 0;j < 3;j++)
	{
		cct_showstr(42 + 4 * j, 6, "��", color[j], COLOR_HWHITE, 1);
	}
	int num[100] = { 0 };
	int totalnum = row * col;
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (map[i][j] == 0)
			{
				num[0]++;
			}
			else num[map[i][j]]++;
		}
	}
	for (int i = 0;i < 8;i++)
	{
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cct_gotoxy(45, 10 + i);
		cout << setfill('0') << setw(2) << num[i];
		cct_gotoxy(49, 10 + i);
		double cal = 100.0 * num[i] / totalnum;
		cout << setiosflags(ios::fixed) << setfill(' ') << setw(5) << setprecision(2) << cal;
		cct_gotoxy(62, 10 + i);
		cout << clearnum[i];
	}
}
/***************************************************************************
  �������ƣ�func
  ��    �ܣ�ͼ�ν�������ɺ�������������������Ĳ�ͬ����ֵ����ִ��
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void func(int mode)
{
	int row, col;
	int color[3] = { 0 };
	int result[9][9] = { 0 };
	int map[9][9] = { 0 };
	input_rowcol(row, col);
	if (mode == 1 || mode == 2 || mode == 4)
		randball_color(row, col, map, color, 3);
	else if (mode == 3)
	{
		randball_color(row, col, map, color, 2);
	}
	cout << "��ʼ���飺" << endl;
	if (mode != 3 && mode != 4)
	{
		printmap(row, col, map, WITH_COLOR, result);
		cout << "���س�����ʾͼ��";
		while (1)
		{
			char ch = _getch();
			if (ch != '\r')
			{
				continue;
			}
			else {
				break;
			}
		}
	}

	if (mode == 1)
	{
		if (row == 9)
		{
			cct_setconsoleborder(35, 15, 50, 50);
			cct_setfontsize("������", 28);
		}
		else if (row == 8)
		{
			cct_setconsoleborder(35, 14, 50, 50);
			cct_setfontsize("������", 28);
		}
		else if (row == 7)
		{
			cct_setconsoleborder(35, 13, 50, 50);
			cct_setfontsize("������", 28);
		}

	}
	else if (mode == 2 || mode == 3)
	{
		cct_setconsoleborder(39, 23, 50, 50);
		cct_setfontsize("������", 28);
	}
	else if (mode == 4)
	{
		cct_setconsoleborder(70, 23, 50, 50);
		cct_setfontsize("������", 24);
	}
	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
	cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
	if (mode == 1)
		printshape(map, row, col, 1, color);
	else if (mode == 2)
		printshape(map, row, col, 2, color);
	else if (mode == 3)
	{
		int endx = -1;
		int endy = -1;
		printshape(map, row, col, 3, color);
		mouse(row, col, map, endx, endy);
		cct_gotoxy(0, 2 * row + 1);
	}
	else if (mode == 4)
	{
		int totalscore = 0;
		int endx = -1;
		int endy = -1;//ά����һ�ε����λ��
		printshape(map, row, col, 4, color);
		int clearnum[8] = { 0 };
		update(map, row, col, color, totalscore, clearnum);
		while (1)
		{
			int score = 0;
			if (mouse(row, col, map, endx, endy) == -1)
			{
				cct_gotoxy(0, 19);
				break;
			}
			score = score_cal(map, row, col, clearnum);
			totalscore += score;
			if (score == 0)
				randball_color(row, col, map, color, 4);
			printshape(map, row, col, 3, color);
			if (is_full(map, row, col) == 1)
			{
				cct_showstr(0, 2 * row + 2, " ", 0, 7, 30);
				cct_gotoxy(0, 2 * row + 2);
				cout << "��Ϸ����";
				break;
			}
			update(map, row, col, color, totalscore, clearnum);
			if (map[endy][endx] != 0)
			{
				cct_showstr(4 * endx + 2, 2 * endy + 2, "��", map[endy][endx], COLOR_HWHITE, 1);//ά����һ�ε����λ��Ϊѡ��״̬
			}

		}
	}
	end();
}