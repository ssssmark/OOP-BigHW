/* 2153538 ������ ������ */
#pragma once
const int bigHW_no = 1;
void input(int& n, char& src, char& tmp, char& dst, int menu);//����
void hanoi(int n, char src, char tmp, char dst, int menu);//��Ҫ�ݹ麯��
void print_y(int Y);//��ӡ��������
void sleep_s(int t);//��ʱ����
void print_x();//��ӡ��������
void reset();//���ò�����
void pause(int x, int y);//�ȴ����س�����
void func_by_menu(int menu, int n, char src, char tmp, char dst);//���ݲ˵�ѡ��ݹ麯����ִ�еĲ���
void printplate(char src, int n);//��ӡԲ��
void printpillar();//��ӡ����
/* ------------------------------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

