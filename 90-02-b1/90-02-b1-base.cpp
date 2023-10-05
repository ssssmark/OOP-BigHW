/*2153538 大数据 刘博洋*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include <time.h>
#include<cstring>
#include"90-02-b1.h"
#include"../include/cmd_console_tools.h"
using namespace std;
/***************************************************************************
  函数名称：fillmap
  功    能：完善每个数字的内部数组
  返 回 值：
  说    明：
***************************************************************************/
void fillmap(int num,int map[numheight][numheight])
{
	switch (num)
	{
	case 0:
		for (int i = 0;i < numheight;i++)
		{
			map[i][X - 1] = 1;
			map[i][X + 1] = 1;
		}
		map[0][X] = 1;
		map[4][X] = 1;
		break;
	case 1:
		for (int i = 0;i < numheight;i++)
		{
			map[i][X] = 1;
		}
		break;
	case 2:
		for (int i = 1;i <= 3;i++)
		{
			map[0][i] = 1;
			map[2][i] = 1;
			map[4][i] = 1;
		}
		map[1][3] = 1;
		map[3][1] = 1;
		break;
	case 3:
		for (int i = 1;i <= 3;i++)
		{
			map[0][i] = 1;
			map[2][i] = 1;
			map[4][i] = 1;
		}
		map[1][3] = 1;
		map[3][3] = 1;
		break;
	case 4:
		for (int i = 0;i < 3;i++)
		{
			map[i][X - 1] = 1;
		}
		for (int i = 0;i < numheight;i++)
		{
			map[i][X + 1] = 1;
		}
		map[Y][X] = 1;
		break;
	case 5:
		for (int i = 1;i <= 3;i++)
		{
			map[0][i] = 1;
			map[2][i] = 1;
			map[4][i] = 1;
		}
		map[1][1] = 1;
		map[3][3] = 1;
		break;
	case 6:
		for (int i = 1;i <= 3;i++)
		{
			map[0][i] = 1;
			map[2][i] = 1;
			map[4][i] = 1;
		}
		map[1][1] = 1;
		map[3][1] = 1;
		map[3][3] = 1;
		break;
	case 7:
		for (int i = 0;i < numheight;i++)
		{
			map[i][X + 1] = 1;
		}
		map[0][X - 1] = 1;
		map[0][X] = 1;
		break;
	case 8:
		for (int i = 1;i <= 3;i++)
		{
			map[0][i] = 1;
			map[2][i] = 1;
			map[4][i] = 1;
		}
		map[1][3] = 1;
		map[3][1] = 1;
		map[3][3] = 1;
		map[1][1] = 1;
		break;
	case 9:
		for (int i = 1;i <= 3;i++)
		{
			map[0][i] = 1;
			map[2][i] = 1;
			map[4][i] = 1;
		}
		map[1][3] = 1;
		map[1][1] = 1;
		map[3][3] = 1;
		break;
	}
}
/***************************************************************************
  函数名称：get_next_num
  功    能：得到下个数字
  返 回 值：
  说    明：
***************************************************************************/
int get_next_num(const bool new_seed = false, const unsigned int seed = 0)
{
	if (new_seed)
		srand(seed);

	return rand() % 10;
}
/***************************************************************************
  函数名称：mergeinto_gamemap
  功    能：数字下落结束后将数字的数组融入游戏地图数组
  返 回 值：
  说    明：
***************************************************************************/
void mergeinto_gamemap(int game[max_height][max_width], block& n,int M,int N)
{
	int centcol = N / 2;
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (n.map[i][j] == 1)
			{
				game[n.cur_y-2+i][n.cur_x-2+j] = n.num;
			}
		}
	}
	n.cur_x = centcol;
	n.cur_y = Y;
}
/***************************************************************************
  函数名称：clearline
  功    能：检查满行并消除
  返 回 值：
  说    明：
***************************************************************************/
void clearline(int game[max_height][max_width],int row,int col,int &score,int& linenum)
{
	int oncenum = 0;
	//由上而下检查是否存在满行
	for (int i = 0;i < row;i++)
	{
		int flag = 1;
		for (int j = 0;j < col;j++)
		{
			if (game[i][j] == -1)
			{
				flag = 0;
			}
		}
		if (flag == 1)//本行满了,消除本行并把上方所有块下移一行,第一行全空
		{
			for (int j = 0;j < col;j++)
			{	
				game[i][j] = -1;
				game[0][j] = -1;
			}
			for (int k = i;k >=0;k--)
			{
				for (int j = 0;j < col;j++)
				{
					game[k + 1][j] = game[k][j];
				}
			}
			linenum++;
			oncenum++;
		}
	}
	switch (oncenum) {
	case 1:
		score += 1;
		break;
	case 2:
		score += 3;
		break;
	case 3:
		score += 6;
		break;
	case 4:
		score += 10;
		break;
	case 5:
		score += 15;
		break;
	}
}
/***************************************************************************
函数名称：moveable
功    能：判断是否能向指定方向移动
返 回 值：
说    明：direction=-1向左，1向右，0向下
***************************************************************************/
bool moveable(block n, int game[max_height][max_width], int row, int col, int direction)
{
	int leftbound, rightbound, lowerbound;//左右下边界
	if (n.num == 1)
	{
		if (n.direction == 0 || n.direction == 2)
		{
			leftbound = n.cur_x;
			rightbound = n.cur_x;
			lowerbound = n.cur_y + n.block_height / 2;
		}
		else {
			leftbound = n.cur_x - n.block_width / 2;
			rightbound = n.cur_x + n.block_width / 2;
			lowerbound = n.cur_y;
		}
	}
	else {
		leftbound = n.cur_x - n.block_width / 2;
		rightbound = n.cur_x + n.block_width / 2;
		lowerbound = n.cur_y + n.block_height / 2;
	}

	if (direction == -1)//向左不能运动的条件：实心方块已经达到左边界(),或者左边已有方块
	{
		if (leftbound <= 0)
		{
			return false;
		}
		// 检查左边是否已有方块
		for (int i = leftbound; i <= rightbound; i++) {
			for (int j = n.cur_y - n.block_height / 2; j <= lowerbound; j++) {
				if (n.map[j - (n.cur_y - 2)][i - (n.cur_x - 2)] == 1)
				{
					if (game[j][i - 1] != -1) {
						return false;
					}
				}

			}
		}
	}
	else if (direction == 1)
	{
		if (rightbound >= col - 1)
		{
			return false;
		}
		// 检查左边是否已有方块
		for (int i = leftbound; i <= rightbound; i++) {
			for (int j = n.cur_y - n.block_height / 2; j <= lowerbound; j++) {
				if (n.map[j - (n.cur_y - 2)][i - (n.cur_x - 2)] == 1)
				{
					if (game[j][i + 1] != -1) {
						return false;
					}
				}

			}
		}
	}
	else if (direction == 0)
	{
		if (lowerbound >= row - 1) {
			return false;
		}

		// 检查方块底部是否与其他方块或障碍物发生碰撞
		for (int i = leftbound; i <= rightbound; i++) {
			for (int j = n.cur_y - n.block_height / 2; j <= lowerbound; j++) {
				if (n.map[j - (n.cur_y - 2)][i - (n.cur_x - 2)] == 1)
				{
					if (game[j + 1][i] != -1) {
						return false;
					}
				}

			}
		}
	}
	return true;

}
/***************************************************************************
函数名称：rotatable
功    能：判断是否能逆时针旋转
返 回 值：
说    明：
***************************************************************************/
bool rotatable(block n, int game[max_height][max_width], int row, int col)
{
	int newBlockWidth = n.block_height,
		newBlockHeight = n.block_width;
	// 计算旋转后的左边界和右边界
	int leftBound = n.cur_x - newBlockWidth / 2;
	int rightBound = n.cur_x + newBlockWidth / 2;

	// 计算旋转后的下边界
	int lowerBound = n.cur_y + newBlockHeight / 2;

	// 检查是否越界
	if (leftBound < 0 || rightBound >= col || lowerBound >= row) {
		return false;
	}

	// 检查旋转后的方块与其他方块是否重叠
	for (int i = leftBound; i <= rightBound; i++) {
		for (int j = n.cur_y - newBlockHeight / 2; j <= lowerBound; j++) {
			if (game[j][i] != -1) {
				return false;
			}
		}
	}

	return true;
}

/***************************************************************************
函数名称：down
功    能：下移一格
返 回 值：
说    明：
***************************************************************************/
void down(block& n, int game[max_height][max_width], int row, int col) {
	if (moveable(n, game, row, col, 0))
	{
		n.cur_y++;
		updatemap(row, col, game, n);
	}
}
/***************************************************************************
函数名称：rotate
功    能：逆时针旋转
返 回 值：
说    明：
***************************************************************************/
void rotate(block& n, int game[max_height][max_width], int row, int col)
{
	int rotated_block[5][5] = {};
	int maxlen = max(n.block_height, n.block_width);
	if (rotatable(n, game, row, col))
	{
		for (int i = 0;i < maxlen;i++)
		{
			for (int j = 0;j < maxlen;j++)
			{
				int new_i = maxlen - 1 - j;
				int new_j = i;
				rotated_block[new_i][new_j] = n.map[i][j];
			}
		}
		for (int i = 0; i < maxlen; i++)
		{
			for (int j = 0; j < maxlen; j++)
			{
				n.map[i][j] = rotated_block[i][j];
			}
		}
		int temp = n.block_width;
		n.block_width = n.block_height;
		n.block_height = temp;
		if (n.direction == 0)
			n.direction = 1;
		else if (n.direction == 2)
			n.direction = 3;

	}
}

/***************************************************************************
函数名称：move
功    能：左右平移、旋转
返 回 值：
说    明：
***************************************************************************/
void move(block& n, int game[max_height][max_width], int row, int col)
{
	char  a = _getch();
	if (a == 75)
	{
		if (moveable(n, game, row, col, -1))
			n.cur_x--;
	}
	else if (a == 77) {
		if (moveable(n, game, row, col, 1))
			n.cur_x++;
	}
	else if (a == 72)
	{
		if (rotatable(n, game, row, col))
			rotate(n, game, row, col);
	}
	else if (a == 80)
	{
		down(n, game, row, col);
	}
	updatemap(row, col, game, n);
}
/***************************************************************************
函数名称：isin_block
功    能：
返 回 值：
说    明：
***************************************************************************/
bool isin_block(int i, int j, block n)
{
	int maxlen = max(n.block_height, n.block_width);
	if (j >= n.cur_x - n.block_width / 2 && j <= n.cur_x + n.block_width / 2 && i >= n.cur_y - n.block_height / 2 && i <= n.cur_y + n.block_height / 2)
	{
		if (n.map[i - (n.cur_y - maxlen / 2)][j - (n.cur_x - maxlen / 2)] != 0)
			return true;
	}
	return false;
}
/***************************************************************************
函数名称：isover
功    能：判断游戏是否结束
返 回 值：
说    明：
***************************************************************************/
bool isover(int game[max_height][max_width], int row, int col)
{
	// 检查游戏界面的顶行是否被占满
	for (int i = 0; i < col; i++) {
		if (game[0][i] != -1) {
			return true; 
		}
	}
	int cent = col / 2;
	// 检查是否无法放置新的方块
	for (int i = 0; i <5; i++)
	{
		for(int j=cent-2;j<=cent+2;j++)
			if (j >= 0)
			{
				if (game[i][j] != -1)
					return true;
			}
			
	}
	return false;
}