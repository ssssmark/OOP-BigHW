/*大数据 刘博洋 2153538*/
#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
//本cpp放一些主函数即菜单函数
int deal_input(int range)
{
	while (1)
	{
		char a = _getch();
		for (char i = '0';i <= '0' + range;i++)
		{
			if (a == i)
			{
				cout << a << endl;
				cout << endl;
				return a - 48;
			}
		}
		continue;
	}
	return -1;
}
int menu(int bigHW_no)
{
	if (bigHW_no == 1)
	{
		cout << "-------------------------------------" << endl;
		cout << "1.基本解" << endl;
		cout << "2.基本解(步数记录)" << endl;
		cout << "3.内部数组显示(横向)" << endl;
		cout << "4.内部数组显示(纵向 + 横向)" << endl;
		cout << "5.图形解 - 预备 - 画三个圆柱" << endl;
		cout << "6.图形解 - 预备 - 在起始柱上画n个盘子" << endl;
		cout << "7.图形解 - 预备 - 第一次移动" << endl;
		cout << "8.图形解 - 自动移动版本" << endl;
		cout << "9.图形解 - 游戏版" << endl;
		cout << "0.退出" << endl;
		cout << "-------------------------------------" << endl;
		cout << "[请选择:] ";
		return deal_input(9);
	}
	else if (bigHW_no == 2)
	{
		cout << "--------------------------------------------" << endl;
		cout << "1.内部数组，随机生成初始5个球" << endl;
		cout << "2.内部数组，随机生成60 % 的球，寻找移动路径" << endl;
		cout << "3.内部数组，完整版" << endl;
		cout << "4.画出n * n的框架（无分隔线），随机显示5个球" << endl;
		cout << "5.画出n * n的框架（有分隔线），随机显示5个球" << endl;
		cout << "6.n * n的框架，60 % 的球，支持鼠标，完成一次移动" << endl;
		cout << "7.cmd图形界面完整版" << endl;
		cout << "0.退出" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "[请选择:]";
		return deal_input(7);
	}
	else if(bigHW_no==3)
	{
		cout<<"--------------------------------------------" << endl;
		cout << "1.根据输入画出9个数字的形状" << endl;
		cout << "2.绘制游戏地图并在上方随机生成数字显示" << endl;
		cout << "3.无操作数字自动下落" << endl;
		cout << "4.下落过程中实现键盘控制数字的旋转、平移" << endl;
		cout << "5.随机5个数字依次下落，并能够通过下方向键控制下落速度" << endl;
		cout << "6.cmd图形界面完整版" << endl;
		cout << "0.退出" << endl;
		cout << "--------------------------------------------" << endl;
		return deal_input(7);
	}
	return 0;
}