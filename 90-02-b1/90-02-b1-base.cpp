/*2153538 ������ ������*/
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
  �������ƣ�fillmap
  ��    �ܣ�����ÿ�����ֵ��ڲ�����
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�get_next_num
  ��    �ܣ��õ��¸�����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int get_next_num(const bool new_seed = false, const unsigned int seed = 0)
{
	if (new_seed)
		srand(seed);

	return rand() % 10;
}
/***************************************************************************
  �������ƣ�mergeinto_gamemap
  ��    �ܣ�����������������ֵ�����������Ϸ��ͼ����
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�clearline
  ��    �ܣ�������в�����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void clearline(int game[max_height][max_width],int row,int col,int &score,int& linenum)
{
	int oncenum = 0;
	//���϶��¼���Ƿ��������
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
		if (flag == 1)//��������,�������в����Ϸ����п�����һ��,��һ��ȫ��
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
�������ƣ�moveable
��    �ܣ��ж��Ƿ�����ָ�������ƶ�
�� �� ֵ��
˵    ����direction=-1����1���ң�0����
***************************************************************************/
bool moveable(block n, int game[max_height][max_width], int row, int col, int direction)
{
	int leftbound, rightbound, lowerbound;//�����±߽�
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

	if (direction == -1)//�������˶���������ʵ�ķ����Ѿ��ﵽ��߽�(),����������з���
	{
		if (leftbound <= 0)
		{
			return false;
		}
		// �������Ƿ����з���
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
		// �������Ƿ����з���
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

		// ��鷽��ײ��Ƿ�������������ϰ��﷢����ײ
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
�������ƣ�rotatable
��    �ܣ��ж��Ƿ�����ʱ����ת
�� �� ֵ��
˵    ����
***************************************************************************/
bool rotatable(block n, int game[max_height][max_width], int row, int col)
{
	int newBlockWidth = n.block_height,
		newBlockHeight = n.block_width;
	// ������ת�����߽���ұ߽�
	int leftBound = n.cur_x - newBlockWidth / 2;
	int rightBound = n.cur_x + newBlockWidth / 2;

	// ������ת����±߽�
	int lowerBound = n.cur_y + newBlockHeight / 2;

	// ����Ƿ�Խ��
	if (leftBound < 0 || rightBound >= col || lowerBound >= row) {
		return false;
	}

	// �����ת��ķ��������������Ƿ��ص�
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
�������ƣ�down
��    �ܣ�����һ��
�� �� ֵ��
˵    ����
***************************************************************************/
void down(block& n, int game[max_height][max_width], int row, int col) {
	if (moveable(n, game, row, col, 0))
	{
		n.cur_y++;
		updatemap(row, col, game, n);
	}
}
/***************************************************************************
�������ƣ�rotate
��    �ܣ���ʱ����ת
�� �� ֵ��
˵    ����
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
�������ƣ�move
��    �ܣ�����ƽ�ơ���ת
�� �� ֵ��
˵    ����
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
�������ƣ�isin_block
��    �ܣ�
�� �� ֵ��
˵    ����
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
�������ƣ�isover
��    �ܣ��ж���Ϸ�Ƿ����
�� �� ֵ��
˵    ����
***************************************************************************/
bool isover(int game[max_height][max_width], int row, int col)
{
	// �����Ϸ����Ķ����Ƿ�ռ��
	for (int i = 0; i < col; i++) {
		if (game[0][i] != -1) {
			return true; 
		}
	}
	int cent = col / 2;
	// ����Ƿ��޷������µķ���
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