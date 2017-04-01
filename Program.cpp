#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio> 
#include "windows.h"
#include <ctime>

using namespace std;

string PlayerName[2] = {"",""}; //声明游戏玩家名数组
int Maps[100]; //声明游戏地图数组
int PlayerZB[2] = {0,0}; //定义玩家坐标数组
bool PlayerZT[2] = {false,false};  
int XinYunPnums[] = {9,18,32,37,61,68}; //定义幸运轮盘关卡的数组
int DiLeinums[] = {22,31,36,38,47,58,71}; //定义地雷关卡的数组
int ShiKongnums[] = {8,27,54,66,77,88};//定义时空隧道关卡的数组
int ZanTingnums[] = {10,16,15,33,44,55};//定义暂停关卡的数组


void ShowGameHead() //画游戏头
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//置红色
	cout << "┌┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┐\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//置蓝色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//置绿色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//置蓝绿色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//置红蓝
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
	cout << "├";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);//置灰色
    cout << "<<<<<<<<<小七飞行棋 V1.0 .Cpp>>>>>>>>>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
	cout << "┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
	cout << "├";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);//置灰色
	cout << "<<<<<<<<<Xiaoqi.Me OpenSource>>>>>>>>>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
	cout << "┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//置红蓝
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//置蓝绿色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//置绿色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//置蓝色
	cout << "├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//置红色
	cout << "└┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┘\n";
}

int RandoM()           //随机数方法
{
return rand() % 6 + 1; //产生随机数,利用rand 取余6 后加 1
}


void SetGamePlayerName () //设置玩家姓名
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
    cout << "请输入玩家A的姓名："; //提示输入A玩家姓名
	cin >> PlayerName[0];          //接收玩家A姓名，C++输入流没有接收到任何字符会一直等待接收，所以不需要提示空
setb:cout << "请输入玩家B的姓名：";
    cin >> PlayerName[1];
	if(PlayerName[1] == PlayerName[0]) //判断A姓名与B姓名是否相等
	{
	cout << "姓名不能相同,请重新输入:"; //提示不能相同
	goto setb;                          //返回setb标记
	}
	else                               //AB输出完成
	cout << "玩家姓名设置完毕！\n";
    cout << "正在载入资源..\n";
	cout << "正在初始化地图..\n";
	cout << "按任意键继续..\n";
	getchar(); 
	getchar();
		return;

}

void PdPlayGame(int number,int gamei)
{
	int s =PlayerZB[gamei]+=number;
	string strr;
	int temp;
	switch(Maps[s])
	{
	case 0:
cout << "前进 ";
cout << number;
cout << "格\n";
getchar;
	break;
	case 1:
	cout << "玩家 ";
	cout << PlayerName[gamei];
	cout << "进入幸运轮盘，请选择方式:\n";
set:cout << "A、攻击对方（输入：A）   B、交换位置（输入:B）\n";
    cin >> strr;
    if (strr != "A" && strr != "B")
	{
        goto set;
	}
	if (strr == "A")
	{
		int a = gamei == 0 ? 1 : 0;
		PlayerZB[a] -= 6;
		cout << "攻击完成，对方退6格\n";
		getchar();
	}
	else
	
		temp = PlayerZB[0];
		PlayerZB[0] = PlayerZB[1];
		PlayerZB[0] = temp;
		cout << "交换完成\n";
		getchar();
		break;
	
	
	case 2:
		PlayerZB[gamei] -= 6;
		cout << "踩地雷退6格\n";
		getchar();
		break;
	case 3:
		PlayerZB[gamei] += 6;
		cout << "进隧道 进6格\n";
		getchar();
		break;
	case 4:
		PlayerZT[gamei] = true;
		cout<< "踩到暂停，暂停一回合";
		getchar();
		break;
	}
}





void MapInstart() //地图标识初始化
{
    for (int i =0; i<6;i++)      
	{
       Maps[XinYunPnums[i]] = 1;  //将地图数组赋予幸运轮盘关卡的1标识
	}
	for (int j =0; j<7;j++)
	{
		Maps[DiLeinums[j]] = 2;  //将地图数组赋予地雷关卡的2标识
	}
	for (int k =0; k<6;k++)
	{
		Maps[ShiKongnums[k]] = 3; //将地图数组赋予时空隧道关卡的3标识
	}
	for (int l =0; l<6;l++)
	{
		Maps[ZanTingnums[l]] = 4;  //将地图数组赋予暂停关卡的4标识
	}
}



void PDMap_s(int gameZB)  //判断坐标属性并画出关卡图形
{
	if(PlayerZB[0] == gameZB && PlayerZB[1] == gameZB) //如果玩家A与玩家B的坐标都与当前坐标相等
	{
		cout <<"卍"; //画万字符表示两个货在一起
	}
	else if(PlayerZB[0]==gameZB)  //如果当前坐标等于玩家A坐标则画A
	{
		cout << "A";  
	}
	else if (PlayerZB[1] == gameZB) //如果当前坐标等于玩家B坐标则画B
	{
		cout << "B";
	}
	
	else
		switch(Maps[gameZB]) //做switch判断
	{
	   case 0:
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//置蓝绿色
		   cout << "□";  //画普通关
		   break;
	   case 1:
		   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//置红蓝
		   cout << "☆";  //画幸运轮盘
		   break;
	   case 2: 
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
		   cout << "¤";  //画地雷关
		   break;
	   case 3:
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//置红蓝
		   cout << "◎";   //画时空隧道
		   break;
	   case 4:
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//置蓝色
		   cout << "△";   //画暂停关卡
		   break;
	}
	
}




void DrewMap_one ()
{
  //玩家提示信息
  cout << "玩家： ";
  cout << PlayerName[0];
  cout << "  用 A 表示  玩家： ";
  cout <<PlayerName[1];
  cout << "  用 B 表示\n";
  //游戏图例
  cout << "图例：";
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//置蓝绿色
  cout << "□  普通 ";  //画普通关
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//置红蓝
  cout << "☆  幸运轮盘";  //画幸运轮盘
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//置黄色
  cout << "¤  地雷";  //画地雷关
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//置红蓝
  cout << "◎  时空隧道  ";   //画时空隧道
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//置蓝色
  cout << "△  暂停\n"; 


  //画地图元素
	for (int i = 0; i < 30; i++)  //画第一行地图，坐标从0 - 29
	{
		PDMap_s(i);                //调用坐标判断
	}
	cout << "\n";                  //画完换行

	for (int j = 30;j<35;j++)      //画靠右的竖列，坐标从 30 - 34 
	{
		for (int j1 = 0;j1<29;j1++) // 因为靠右列前面有29*2个空格，内部进行循环
		{
			cout << "  ";            //输出两个空格
		}

		PDMap_s(j);                //调用判断坐标方法
		cout << "\n";              //画完换行
	}
	
	for (int k = 64;k >= 35; k--)   //画反方向行，坐标从35 - 64 因为相反方向，所以递减循环
	{
		PDMap_s(k);                 //调用判断坐标方法
	} 
	cout << "\n";                   //画完换行
    
	for (int l = 65;l<70;l++)       //画靠左列  坐标从 65 - 69
	{
		PDMap_s(l);                 //调用方法，先画第一个
		for (int l1 =0;l1<30;l1++)
		{
			cout << "  ";               //其余输出空格
		}
		cout << "\n";                   //画完换行
	}
	
	for (int m = 70;m<100;m++)         //画最后一行  坐标从70 - 99
	{
		PDMap_s(m);                   //调用方法判断坐标
	}
	cout << "\n";                      //画完换行
}


void PlayGame()
{
	int setNumber;
	while(true)
	{
		cout << "玩家：";
		cout << PlayerName[0];
		cout << "开始置色子:\n";
		system("pause");
		setNumber = RandoM();
		cout << "色子数：";
		cout << setNumber;
		cout << "\n";
        if(PlayerZT[0] == true && PlayerZT[1] == true)
		{
			PlayerZT[0] = false;
		}



		
		if(PlayerZT[0] == false)
		{
			PdPlayGame(setNumber,0);
			getchar();
			system("cls");
			DrewMap_one();
			if(PlayerZB[0] > 99)
			{
			system("cls");
			cout << "玩家 ";
			cout << PlayerName[0];
			cout << " 赢了玩家";
			cout << PlayerName[1];
			getchar();
			return;
			}
		}
		else
			PlayerZT[0] = false;
		
		cout << "玩家：";
		cout << PlayerName[1];
		cout << "开始置色子:\n";
		system("pause");
		setNumber = RandoM();
		cout << "色子数：";
		cout << setNumber;
		cout << "\n";
		if(PlayerZT[1] == false)
		{
			PdPlayGame(setNumber,1);
			getchar();
			system("cls");
			DrewMap_one();
			if(PlayerZB[1] > 99)
			{
			system("cls");
			cout << "玩家 ";
			cout << PlayerName[1];
			cout << " 赢了玩家";
			cout << PlayerName[0];
			getchar();
			return;
			}
		}
		else
			PlayerZT[1] = false;
		
	}
}


int main ()
{
  srand(time(0));      //置随机数种子
  ShowGameHead();      //画游戏头
  SetGamePlayerName(); //设置游戏名
  system("cls");       //清除画面
  MapInstart();        //地图初始化
  DrewMap_one();       //画地图元素
  PlayGame();          //游戏中
  getchar();
  
  return 0;
}


