/*������ ������ 2153538*/
#pragma once

/*���ڲ������ģʽ*/
#define WITH_COLOR 1
#define RESULT 2
#define RESULT_COLOR 3
/*��ͼ�ν����ģʽ*/
#define WITHOUT_LINE 1
#define WITH_LINE 2
const int bigHW_no = 2;
/*ƫ�Ʒ���ֵ*/
const struct direction {
	int dx;
	int dy;
};
const direction mov[4] = { {0,1},{0,-1},{1,0},{-1,0} };//��������λ��ƫ����
/*��¼��ǰ�ڵ��ǰ���ڵ�*/
struct Node {
	int x;//��ǰ����x
	int y;  //��ǰ����y 
	int px;  //ǰ�����x
	int py;  //ǰ�����y
};

void input_rowcol(int& row, int& col);//��������
void rand_array(int menu);//�ڲ������������ɺ���
bool is_full(int map[9][9], int row, int col);//�ж��Ƿ��ͼ����
void printmap(int row, int col, int map[9][9], int func, int result[9][9]);//��ӡ�ڲ������ͼ
void func(int mode);//ͼ�ν������ɺ���
void randball_color(int row, int col, int map[9][9], int color[], int menu);//������������ɫ
bool bfs(int x, int y, int map[9][9], Node path[100], int mark[9][9], int row, int col, const int dstx, const int dsty, int& step);//�����������Ѱ��·��
int score_cal(int map[9][9], int row, int col, int clearnum[]);//�������
void end();//������ʾ