/*2153538 ������ ������*/
#pragma once
# define bigHW_no 3
#define numheight 5//��������߶�
#define numwidth 3//����������
#define numsquare 6 //һ��ı߳�
#define max_height 26
#define max_width 21

//������������Ŀ�Ľṹ��
struct block {
	int num;//������������
	int map[numheight][numheight] = {};//5*5�����飬����������תλ��
	int direction = 0;//�����λ�÷���0-����1-����90�ȣ�2-����3-����90��
	int cur_x=0, cur_y=0;//Ŀǰ��������ڵ�ͼ�����������
	int block_height = 5, block_width = 3;
};
const int X = 2, Y = 2;//��������ĵ��������������


void inputrow_col(int& M, int& N);
void console_main_fun(int mode);//ͼ�ν�����Ҫ����
void fillmap(int num, int map[numheight][numheight]);//�����ֶ�Ӧ����״��������
void draw_square(int cen_x, int cen_y, int num);//����һ����������
void drawnum(int centx, int centy,block n);//����ͼ�ΰ�����
void move(block& n, int game[max_height][max_width], int row, int col);//���ݼ���ָ���ƶ�
void down(block& n, int game[max_height][max_width], int row, int col);//�����ڵ�ͼ����������
void drawmap(int row, int col, int game[max_height][max_width]);//������Ϸ����
void draw_scoreboard(block n, int score, int linenum);//���ƼƷְ�
void updatemap(int row, int col, int game[max_height][max_width],block n);//���µ�ͼ
int get_next_num(const bool new_seed, const unsigned int seed);//��ȡ��һ������
void end();//����˵�������ͣ��
bool isin_block(int i, int j, block n);//�жϵ�ͼ�ϵĵ��Ƿ������ֿ���
void updateblock(int row, int col, int game[max_height][max_width], block n);//��������������״̬
void mergeinto_gamemap(int game[max_height][max_width], block& n, int M, int N);//����������ɺ������ͼ
bool moveable(block n, int game[max_height][max_width], int row, int col, int direction);//�ж��Ƿ����ƶ�
bool rotatable(block n, int game[max_height][max_width], int row, int col);//�ж��Ƿ�����ת
void clearline(int game[max_height][max_width], int row, int col, int& score, int& linenum);//����һ�в��ӷ�
bool isover(int game[max_height][max_width], int row, int col);//�ж���Ϸ�Ƿ����