/*2153538 大数据 刘博洋*/
#pragma once
# define bigHW_no 3
#define numheight 5//数字区域高度
#define numwidth 3//数字区域宽度
#define numsquare 6 //一格的边长
#define max_height 26
#define max_width 21

//代表正在下落的块的结构体
struct block {
	int num;//方块代表的数字
	int map[numheight][numheight] = {};//5*5的数组，包含所有旋转位置
	int direction = 0;//方块的位置方向，0-正向，1-左旋90度，2-逆向，3-右旋90度
	int cur_x=0, cur_y=0;//目前块的中心在地图数组里的坐标
	int block_height = 5, block_width = 3;
};
const int X = 2, Y = 2;//方块的中心点在数组里的坐标


void inputrow_col(int& M, int& N);
void console_main_fun(int mode);//图形界面主要函数
void fillmap(int num, int map[numheight][numheight]);//将数字对应的形状存入数组
void draw_square(int cen_x, int cen_y, int num);//画出一个单独方块
void drawnum(int centx, int centy,block n);//画出图形版数字
void move(block& n, int game[max_height][max_width], int row, int col);//根据键盘指令移动
void down(block& n, int game[max_height][max_width], int row, int col);//数字在地图中整体下移
void drawmap(int row, int col, int game[max_height][max_width]);//绘制游戏区域
void draw_scoreboard(block n, int score, int linenum);//绘制计分板
void updatemap(int row, int col, int game[max_height][max_width],block n);//更新地图
int get_next_num(const bool new_seed, const unsigned int seed);//获取下一个数字
void end();//处理菜单结束的停顿
bool isin_block(int i, int j, block n);//判断地图上的点是否在数字块上
void updateblock(int row, int col, int game[max_height][max_width], block n);//更新正在下落块的状态
void mergeinto_gamemap(int game[max_height][max_width], block& n, int M, int N);//数字下落完成后融入地图
bool moveable(block n, int game[max_height][max_width], int row, int col, int direction);//判断是否能移动
bool rotatable(block n, int game[max_height][max_width], int row, int col);//判断是否能旋转
void clearline(int game[max_height][max_width], int row, int col, int& score, int& linenum);//消除一行并加分
bool isover(int game[max_height][max_width], int row, int col);//判断游戏是否结束