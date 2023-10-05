/*大数据 刘博洋 2153538*/
#include<iostream>
#include<conio.h>
#include<cstring>
#include<iomanip>
#include<Windows.h>
#include<time.h>
#include"90-01-b2.h"
#include"../include/cmd_console_tools.h"
using namespace std;

//本cpp放一些内部数组方式实现的函数
/***************************************************************************
  函数名称：printmap
  功    能：打印内部数组
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：input_src_dst
  功    能：输入移动球的起始和
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input_src_dst(int& i1, int& j1, int& i2, int& j2, int map[9][9], int row, int col)
{
	cout << "请以字母 + 数字形式[例：c2]输入要移动球的矩阵坐标：";
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
			cout << "输入错误，请重新输入" << endl;
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
			cout << "输入错误，请重新输入" << endl;
			cct_gotoxy(x, y);
			cout << setw(30) << " ";
			cct_gotoxy(x, y);
			continue;
		}
		if (map[int(a - 65)][int(b - 48) - 1] == 0)
		{
			cout << "起始位置为空，请重新输入." << endl;
			cout << "请以字母 + 数字形式[例：c2]输入要移动球的矩阵坐标：";
			continue;
		}
		else
		{
			i1 = a - 65;
			j1 = b - 48 - 1;
			cout << "输入为" << a << "行" << b << "列" << setw(20) << " " << endl;
			break;
		}

	}
	cout << "请以字母 + 数字形式[例：c2]输入要移动球的目的坐标：";
	while (1)
	{
		cct_getxy(x, y);
		a = getchar();
		if (a >= 'a' && a <= 'z')
			a -= 32;
		if (!(a >= 'A' && a <= ('A' + row - 1)))
		{
			cout << "输入错误，请重新输入" << endl;
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
			cout << "输入错误，请重新输入" << endl;
			cct_gotoxy(x, y);
			cout << setw(30) << " ";
			cct_gotoxy(x, y);
			continue;
		}
		if (map[int(a - 65)][int(b - 48) - 1] != 0)
		{
			cout << "目标位置非空，请重新输入." << endl;
			cout << "请以字母 + 数字形式[例：c2]输入要移动球的目的坐标：";
			continue;
		}
		else
		{
			i2 = a - 65;
			j2 = b - 48 - 1;
			cout << "输入为" << a << "行" << b << "列" << setw(20) << " " << endl;
			break;
		}

	}
}

/***************************************************************************
  函数名称：rand_array
  功    能：非图形界面的主干函数，通过菜单选择完成不同功能
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void rand_array(int menu)
{
	int row, col;

	int color[3] = { 0 };
	input_rowcol(row, col);
	srand((unsigned int)time(NULL));
	int map[9][9] = { 0 };
	if (menu == 1)//生成初始5个球
	{
		randball_color(row, col, map, color, 1);
		cout << endl << "初始数组：" << endl;
		printmap(row, col, map, WITH_COLOR, NULL);
		end();
		return;
	}
	else if (menu == 2)
	{
		Node path[100] = { 0 };//存放路径的结果数组
		int mark[9][9] = { 0 };//用于搜索的标记数组
		int step = 0;
		randball_color(row, col, map, color, 2);
		cout << endl << "当前数组：" << endl;
		printmap(row, col, map, WITH_COLOR, NULL);
		cout << "下3个彩球的颜色分别是：";
		for (int i = 0;i < 3;i++)
		{
			cout << color[i] << " ";
		}
		cout << endl;
		int i1, j1, i2, j2;//存储起点和终点
		input_src_dst(i1, j1, i2, j2, map, row, col);
		mark[i1][j1] = 1;//初始化mark标记
		int ret = bfs(i1, j1, map, path, mark, row, col, i2, j2, step);
		if (ret == 1)
		{
			int result[9][9] = { 0 };
			for (int i = step - 1;i >= 0;i--)
			{
				result[path[i].x][path[i].y] = -1;
			}
			cout << "查找结果数组为：" << endl;
			printmap(row, col, map, RESULT, result);
			cout << endl << endl;
			cout << " 移动路径(不同色标识)：" << endl;
			printmap(row, col, map, RESULT_COLOR, result);
			cout << endl << endl;
		}
		else
			cout << "无法找到移动路径" << endl;
		end();
	}
	else if (menu == 3)
	{
		int total_score = 0;//总得分
		randball_color(row, col, map, color, 3);
		while (1)
		{
			Node path[100] = { 0 };//存放路径的结果数组
			int mark[9][9] = { 0 };//用于搜索的标记数组
			int score = 0;//每次得分
			int step = 0;
			cout << endl << "当前数组：" << endl;
			printmap(row, col, map, WITH_COLOR, NULL);
			cout << endl << "下3个彩球的颜色分别是：";
			for (int i = 0;i < 3;i++)
			{
				cout << color[i] << " ";
			}
			cout << endl;
			int i1, j1, i2, j2;//存储起点和终点
			input_src_dst(i1, j1, i2, j2, map, row, col);
			mark[i1][j1] = 1;//初始化mark标记
			int ret = bfs(i1, j1, map, path, mark, row, col, i2, j2, step);
			if (ret == 1)
			{
				map[i2][j2] = map[i1][j1];
				map[i1][j1] = 0;
				int clearnum[9] = { 0 };
				score = score_cal(map, row, col, clearnum);
				if (score == 0)
					randball_color(row, col, map, color, 4);
				cout << endl << " 移动后的数组(不同色标识)：" << endl;
				printmap(row, col, map, WITH_COLOR, NULL);
				cout << endl;
				total_score += score;
				cout << "本次得分：" << score << " " << "总得分：" << total_score << endl;
			}
			else
			{
				cout << "无法找到移动路径" << endl;
				continue;
			}
			if (is_full(map, row, col) == 1)
			{
				cout << "游戏结束!" << endl;
				end();
			}
		}

	}

}
