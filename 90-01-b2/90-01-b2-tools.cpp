/*大数据 刘博洋 2153538*/
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<iomanip>
#include"90-01-b2.h"
#include"../include/cmd_console_tools.h"
using namespace std;
//本cpp放一些内部数组/图形方式公用的函数，如判断结束等
/***************************************************************************
  函数名称：input_rowcol
  功    能：输入行列
  返 回 值：
  说    明：
***************************************************************************/
void input_rowcol(int& row, int& col)
{
	while (1)
	{
		cout << "请输入行数(7-9)：" << endl;
		cin >> row;
		if (cin.good() == 1 && row >= 7 && row <= 9)
			break;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	while (1)
	{
		cout << "请输入列数(7-9)：" << endl;
		cin >> col;
		if (cin.good() == 1 && col >= 7 && col <= 9)
			break;
		cin.clear();
		cin.ignore(1024, '\n');
	}
}
/***************************************************************************
  函数名称： is_full
  功    能：判断地图是否已经满
  返 回 值：
  说    明：
***************************************************************************/
bool is_full(int map[9][9], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
			if (map[i][j] == 0)
				return false;
	}
	return true;
}
/***************************************************************************
  函数名称：end
  功    能：判断输入end结束
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void end()
{
	cout << endl << "本小题结束，请输入End继续...";
	while (1)
	{
		char str[10];
		int n = 0;
		while (1)
		{
			str[n] = _getch();
			if (str[n] == '\r')
				break;
			cout << str[n];
			n++;
		}
		if (strncmp(str, "end", 3) == 0 || strncmp(str, "End", 3) == 0 || strncmp(str, "END", 3) == 0)
			return;
		int x;
		int y;
		cct_getxy(x, y);
		cct_showch(28, y, ' ', COLOR_BLACK, COLOR_WHITE, 100);
		cct_gotoxy(0, y + 1);
		cout << "输入错误，请重新输入";
		cct_gotoxy(28, y);
	}
}
/***************************************************************************
  函数名称：randball_color
  功    能：随机生成内部数组行列和颜色
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void randball_color(int row, int col, int map[9][9], int color[], int menu)
{
	srand((unsigned)time(NULL));
	if (menu == 1)
	{
		for (int i = 0;i < 5;i++)
		{
			while (1) {
				int i = rand() % row;
				int j = rand() % col;
				if (is_full(map, row, col) == 1)
					break;
				if (map[i][j] == 0)
				{
					map[i][j] = rand() % 7 + 1;
					break;
				}
			}
		}
	}
	else if (menu == 2)
	{
		for (int i = 0;i < row * col * 0.6;i++)
		{
			while (1) {
				int i = rand() % row;
				int j = rand() % col;
				if (is_full(map, row, col) == 1)
					break;
				if (map[i][j] == 0)
				{
					map[i][j] = rand() % 7 + 1;
					break;
				}
			}
		}
		for (int i = 0;i < 3;i++)
		{
			color[i] = rand() % 7 + 1;
		}
	}
	else if (menu == 3)
	{
		for (int i = 0;i < 5;i++)
		{
			while (1) {
				int i = rand() % row;
				int j = rand() % col;
				if (is_full(map, row, col) == 1)
					break;
				if (map[i][j] == 0)
				{
					map[i][j] = rand() % 7 + 1;
					break;
				}
			}
		}
		for (int i = 0;i < 3;i++)
		{
			color[i] = rand() % 7 + 1;
		}
	}
	else if (menu == 4)
	{
		int cnt = 0;
		for (int i = 0;i < 3;i++)
		{
			while (1) {
				int i = rand() % row;
				int j = rand() % col;
				if (is_full(map, row, col) == 1)
					break;
				if (map[i][j] == 0)
				{
					map[i][j] = color[cnt++];
					break;
				}
			}
		}
		for (int i = 0;i < 3;i++)
			color[i] = rand() % 7 + 1;
	}

}
/***************************************************************************
  函数名称：bfs
  功    能：广度优先搜索查找路径
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
bool bfs(int x, int y, int map[9][9], Node path[100], int mark[9][9], int row, int col, const int dstx, const int dsty, int& step)
{
	Node queue[100] = { 0 };
	int tail = 1, head = 0;
	queue[tail].x = x;
	queue[tail].y = y;
	queue[tail].px = -1;
	queue[tail].py = -1;
	mark[x][y] = 1;
	while (head < tail)
	{
		head++;
		for (int i = 0;i < 4;i++)
		{
			int current_x = queue[head].x + mov[i].dx;
			int current_y = queue[head].y + mov[i].dy;
			if (current_x >= 0 && current_x < row && current_y >= 0 && current_y < col && map[current_x][current_y] == 0 && mark[current_x][current_y] == 0)
			{
				tail++;
				mark[current_x][current_y] = 1;
				queue[tail].x = current_x;
				queue[tail].y = current_y;
				queue[tail].px = queue[head].x;
				queue[tail].py = queue[head].y;
				if (current_x == dstx && current_y == dsty)
				{
					path[step] = queue[tail];
					step++;
					while (1)
					{
						for (int m = 1;m <= tail;m++)//从终点开始找前驱
						{
							if (queue[m].x == path[step - 1].px && queue[m].y == path[step - 1].py)
							{
								path[step] = queue[m];
								step++;
							}
						}
						if (path[step - 1].x == x && path[step - 1].y == y)
							break;
					}
					return true;
				}
			}
		}

	}
	return false;
}

/***************************************************************************
  函数名称：score_cal
  功    能：计算每次的得分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int score_cal(int map[9][9], int row, int col, int clearnum[])
{
	int score = 0;
	int mark[9][9] = { 0 };
	int cnt = 0;
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (map[i][j] != 0 && mark[i][j] == 0)
			{

				int di1 = 1;
				int di2 = 1;
				int cnt1 = 1;
				while (map[i][j] != 0)
				{
					int flag = 2;
					if (i + di1 >= 0 && i + di1 < row && map[i + di1][j] == map[i][j] && mark[i + di1][j] == 0)
					{

						cnt1++;
						di1++;
						continue;
					}
					else flag--;
					if (i - di2 >= 0 && map[i - di2][j] == map[i][j] && mark[i - di2][j] == 0)
					{

						cnt1++;
						di2++;
						continue;
					}
					else flag--;
					if (i + di1 >= row && i - di2 < 0)
						break;
					if (flag == 0)
						break;
				}
				if (cnt1 >= 5)
				{
					cnt += cnt1;
					for (int m = i - di2 + 1;m <= i + di1 - 1;m++)
					{
						mark[m][j] = 1;
					}//先搜竖直方向
				}


				int dj1 = 1;
				int dj2 = 1;
				int cnt2 = 1;
				while (map[i][j] != 0)
				{
					int flag = 2;
					if (j + dj1 < col && map[i][j + dj1] == map[i][j] && mark[i][j + dj1] == 0)
					{

						cnt2++;
						dj1++;
						continue;
					}
					else flag--;
					if (j - dj2 >= 0 && map[i][j - dj2] == map[i][j] && mark[i][j - dj2] == 0)
					{
						cnt2++;
						dj2++;
						continue;

					}
					else flag--;
					if (j + dj1 >= col && j - dj2 < 0)
						break;
					if (flag == 0)
						break;
				}

				if (cnt2 >= 5)
				{
					cnt += cnt2;
					for (int m = j - dj2 + 1;m <= j + dj1 - 1;m++)
					{
						mark[i][m] = 1;
					}//搜水平方向
				}

				int dy1 = 1;
				int dy2 = 1;
				int dx1 = 1;
				int dx2 = 1;
				int cnt3 = 1;
				while (map[i][j] != 0)
				{
					int flag = 2;
					if (i + dy1 < row && j + dx1 < col && map[i + dy1][j + dx1] == map[i][j] && mark[i + dy1][j + dx1] == 0)
					{
						cnt3++;
						dy1++;
						dx1++;
						continue;
					}
					else flag--;
					if (i - dy2 >= 0 && j - dx2 >= 0 && map[i - dy2][j - dx2] == map[i][j] && mark[i - dy2][j - dx2] == 0)
					{
						cnt3++;
						dy2++;
						dx2++;
						continue;
					}
					else flag--;
					if (!((i + dy1 < row && j + dx1 < col) || (i - dy2 >= 0 && j - dx2 >= 0)))
						break;
					if (flag == 0)
						break;
				}

				if (cnt3 >= 5)
				{
					cnt += cnt3;
					int m, n;
					for (m = i - dy2 + 1, n = j - dx2 + 1;m <= i + dy1 - 1 && n <= j + dx1 - 1;m++, n++)
					{
						mark[m][n] = 1;
					}//搜左上——右下方向
				}

				int dyy1 = 1;
				int dyy2 = 1;
				int dxx1 = 1;
				int dxx2 = 1;
				int cnt4 = 1;
				while (map[i][j] != 0)
				{
					int flag = 2;
					if (i + dyy1 < row && j - dxx1 >= 0 && map[i + dyy1][j - dxx1] == map[i][j] && mark[i + dyy1][j - dxx1] == 0)
					{
						cnt4++;
						dyy1++;
						dxx1++;
						continue;
					}
					else flag--;
					if (i - dyy2 >= 0 && j + dxx2 < col && map[i - dyy2][j + dxx2] == map[i][j] && mark[i - dyy2][j + dxx2] == 0)
					{
						cnt4++;
						dyy2++;
						dxx2++;
						continue;
					}
					else flag--;
					if (!((i + dyy1 < row && j - dxx1 >= 0) || (i - dyy2 >= 0 && j + dxx2 < col)))
						break;
					if (flag == 0)
						break;
				}

				if (cnt4 >= 5)
				{
					cnt += cnt4;
					int m, n;
					for (m = i - dyy2 + 1, n = j + dxx2 - 1;m <= i + dyy1 - 1 && n >= j - dxx1 + 1;m++, n--)
					{
						mark[m][n] = 1;
					}//左下——右上方向
				}
			}
		}
	}
	if (cnt != 0)
	{
		score += (cnt - 1) * (cnt - 2);
	}
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (mark[i][j] == 1)
			{
				clearnum[map[i][j]]++;
				map[i][j] = 0;//在map中消去球
			}

		}
	}
	return score;
}

