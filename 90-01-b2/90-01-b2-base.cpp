/*������ ������ 2153538*/
#include<iostream>
#include<conio.h>
#include<cstring>
#include<iomanip>
#include<Windows.h>
#include<time.h>
#include"90-01-b2.h"
#include"../include/cmd_console_tools.h"
using namespace std;

//��cpp��һЩ�ڲ����鷽ʽʵ�ֵĺ���
/***************************************************************************
  �������ƣ�printmap
  ��    �ܣ���ӡ�ڲ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void printmap(int row, int col, int map[9][9], int func, int result[9][9])
{
	cout << "  |  ";
	for (int i = 0;i < col;i++)
		cout << i + 1 << "  ";
	cout << endl;
	cout << "--+-";
	for (int i = 0;i < col;i++)
		cout << "---";
	cout << endl;
	for (int i = 0;i < row;i++)
	{
		cout << char(i + 65) << " |  ";
		for (int j = 0;j < col;j++)
		{
			if (func == RESULT_COLOR)
			{
				if (result[i][j] == 0)
					cout << 0 << "  ";
				else {
					int x, y;
					cct_getxy(x, y);
					cct_showch(x, y, map[i][j] + 48, 14, 1, 1);
					cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << "  ";
				}
			}
			else if (func == RESULT) {
				if (result[i][j] == 0)
					cout << 0 << "  ";
				else
					cout << "*" << "  ";

			}
			else if (func == WITH_COLOR)
			{
				if (map[i][j] == 0)
				{
					cout << 0 << "  ";
				}
				else
				{
					int x, y;
					cct_getxy(x, y);
					cct_showch(x, y, map[i][j] + 48, 14, map[i][j], 1);
					cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << "  ";
				}


			}

		}
		cout << endl;
	}

}
/***************************************************************************
  �������ƣ�input_src_dst
  ��    �ܣ������ƶ������ʼ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input_src_dst(int& i1, int& j1, int& i2, int& j2, int map[9][9], int row, int col)
{
	cout << "������ĸ + ������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
	int x, y;
	char a, b;
	while (1)
	{
		cct_getxy(x, y);
		a = getchar();
		if (a >= 'a' && a <= 'z')
			a -= 32;
		if (!(a >= 'A' && a <= ('A' + row - 1)))
		{
			cout << "�����������������" << endl;
			cct_gotoxy(x, y);
			cout << setw(30) << " ";
			cct_gotoxy(x, y);
			continue;
		}
		b = getchar();
		if (b >= 'a' && b <= 'z')
			b -= 32;
		if (!(b > '0' && b <= '0' + col))
		{
			cout << "�����������������" << endl;
			cct_gotoxy(x, y);
			cout << setw(30) << " ";
			cct_gotoxy(x, y);
			continue;
		}
		if (map[int(a - 65)][int(b - 48) - 1] == 0)
		{
			cout << "��ʼλ��Ϊ�գ�����������." << endl;
			cout << "������ĸ + ������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
			continue;
		}
		else
		{
			i1 = a - 65;
			j1 = b - 48 - 1;
			cout << "����Ϊ" << a << "��" << b << "��" << setw(20) << " " << endl;
			break;
		}

	}
	cout << "������ĸ + ������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
	while (1)
	{
		cct_getxy(x, y);
		a = getchar();
		if (a >= 'a' && a <= 'z')
			a -= 32;
		if (!(a >= 'A' && a <= ('A' + row - 1)))
		{
			cout << "�����������������" << endl;
			cct_gotoxy(x, y);
			cout << setw(30) << " ";
			cct_gotoxy(x, y);
			continue;
		}
		b = getchar();
		cin.ignore(1024, '\n');
		if (b >= 'a' && b <= 'z')
			b -= 32;
		if (!(b > '0' && b <= '0' + col))
		{
			cout << "�����������������" << endl;
			cct_gotoxy(x, y);
			cout << setw(30) << " ";
			cct_gotoxy(x, y);
			continue;
		}
		if (map[int(a - 65)][int(b - 48) - 1] != 0)
		{
			cout << "Ŀ��λ�÷ǿգ�����������." << endl;
			cout << "������ĸ + ������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
			continue;
		}
		else
		{
			i2 = a - 65;
			j2 = b - 48 - 1;
			cout << "����Ϊ" << a << "��" << b << "��" << setw(20) << " " << endl;
			break;
		}

	}
}

/***************************************************************************
  �������ƣ�rand_array
  ��    �ܣ���ͼ�ν�������ɺ�����ͨ���˵�ѡ����ɲ�ͬ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void rand_array(int menu)
{
	int row, col;

	int color[3] = { 0 };
	input_rowcol(row, col);
	srand((unsigned int)time(NULL));
	int map[9][9] = { 0 };
	if (menu == 1)//���ɳ�ʼ5����
	{
		randball_color(row, col, map, color, 1);
		cout << endl << "��ʼ���飺" << endl;
		printmap(row, col, map, WITH_COLOR, NULL);
		end();
		return;
	}
	else if (menu == 2)
	{
		Node path[100] = { 0 };//���·���Ľ������
		int mark[9][9] = { 0 };//���������ı������
		int step = 0;
		randball_color(row, col, map, color, 2);
		cout << endl << "��ǰ���飺" << endl;
		printmap(row, col, map, WITH_COLOR, NULL);
		cout << "��3���������ɫ�ֱ��ǣ�";
		for (int i = 0;i < 3;i++)
		{
			cout << color[i] << " ";
		}
		cout << endl;
		int i1, j1, i2, j2;//�洢�����յ�
		input_src_dst(i1, j1, i2, j2, map, row, col);
		mark[i1][j1] = 1;//��ʼ��mark���
		int ret = bfs(i1, j1, map, path, mark, row, col, i2, j2, step);
		if (ret == 1)
		{
			int result[9][9] = { 0 };
			for (int i = step - 1;i >= 0;i--)
			{
				result[path[i].x][path[i].y] = -1;
			}
			cout << "���ҽ������Ϊ��" << endl;
			printmap(row, col, map, RESULT, result);
			cout << endl << endl;
			cout << " �ƶ�·��(��ͬɫ��ʶ)��" << endl;
			printmap(row, col, map, RESULT_COLOR, result);
			cout << endl << endl;
		}
		else
			cout << "�޷��ҵ��ƶ�·��" << endl;
		end();
	}
	else if (menu == 3)
	{
		int total_score = 0;//�ܵ÷�
		randball_color(row, col, map, color, 3);
		while (1)
		{
			Node path[100] = { 0 };//���·���Ľ������
			int mark[9][9] = { 0 };//���������ı������
			int score = 0;//ÿ�ε÷�
			int step = 0;
			cout << endl << "��ǰ���飺" << endl;
			printmap(row, col, map, WITH_COLOR, NULL);
			cout << endl << "��3���������ɫ�ֱ��ǣ�";
			for (int i = 0;i < 3;i++)
			{
				cout << color[i] << " ";
			}
			cout << endl;
			int i1, j1, i2, j2;//�洢�����յ�
			input_src_dst(i1, j1, i2, j2, map, row, col);
			mark[i1][j1] = 1;//��ʼ��mark���
			int ret = bfs(i1, j1, map, path, mark, row, col, i2, j2, step);
			if (ret == 1)
			{
				map[i2][j2] = map[i1][j1];
				map[i1][j1] = 0;
				int clearnum[9] = { 0 };
				score = score_cal(map, row, col, clearnum);
				if (score == 0)
					randball_color(row, col, map, color, 4);
				cout << endl << " �ƶ��������(��ͬɫ��ʶ)��" << endl;
				printmap(row, col, map, WITH_COLOR, NULL);
				cout << endl;
				total_score += score;
				cout << "���ε÷֣�" << score << " " << "�ܵ÷֣�" << total_score << endl;
			}
			else
			{
				cout << "�޷��ҵ��ƶ�·��" << endl;
				continue;
			}
			if (is_full(map, row, col) == 1)
			{
				cout << "��Ϸ����!" << endl;
				end();
			}
		}

	}

}
