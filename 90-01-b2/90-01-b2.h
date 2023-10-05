/*大数据 刘博洋 2153538*/
#pragma once

/*画内部数组的模式*/
#define WITH_COLOR 1
#define RESULT 2
#define RESULT_COLOR 3
/*画图形界面的模式*/
#define WITHOUT_LINE 1
#define WITH_LINE 2
const int bigHW_no = 2;
/*偏移方向值*/
const struct direction {
	int dx;
	int dy;
};
const direction mov[4] = { {0,1},{0,-1},{1,0},{-1,0} };//上下左右位置偏移量
/*记录当前节点和前驱节点*/
struct Node {
	int x;//当前坐标x
	int y;  //当前坐标y 
	int px;  //前驱点的x
	int py;  //前驱点的y
};

void input_rowcol(int& row, int& col);//输入行列
void rand_array(int menu);//内部数组界面的主干函数
bool is_full(int map[9][9], int row, int col);//判断是否地图已满
void printmap(int row, int col, int map[9][9], int func, int result[9][9]);//打印内部数组地图
void func(int mode);//图形界面主干函数
void randball_color(int row, int col, int map[9][9], int color[], int menu);//随机生成球和颜色
bool bfs(int x, int y, int map[9][9], Node path[100], int mark[9][9], int row, int col, const int dstx, const int dsty, int& step);//广度优先搜索寻找路径
int score_cal(int map[9][9], int row, int col, int clearnum[]);//计算分数
void end();//结束提示