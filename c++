#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio> 
#include "windows.h"
#include <ctime>

using namespace std;

string PlayerName[2] = {"",""}; //������Ϸ���������
int Maps[100]; //������Ϸ��ͼ����
int PlayerZB[2] = {0,0}; //���������������
bool PlayerZT[2] = {false,false};  
int XinYunPnums[] = {9,18,32,37,61,68}; //�����������̹ؿ�������
int DiLeinums[] = {22,31,36,38,47,58,71}; //������׹ؿ�������
int ShiKongnums[] = {8,27,54,66,77,88};//����ʱ�������ؿ�������
int ZanTingnums[] = {10,16,15,33,44,55};//������ͣ�ؿ�������


void ShowGameHead() //����Ϸͷ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//�ú�ɫ
	cout << "���ЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩ�\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//����ɫ
	cout << "�����������������������\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//����ɫ
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//������ɫ
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//�ú���
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
	cout << "��";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);//�û�ɫ
    cout << "<<<<<<<<<С�߷����� V1.0 .Cpp>>>>>>>>>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
	cout << "��\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
	cout << "��";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY);//�û�ɫ
	cout << "<<<<<<<<<Xiaoqi.Me OpenSource>>>>>>>>>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
	cout << "��\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//�ú���
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//������ɫ
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);//����ɫ
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//����ɫ
	cout << "�����������������������\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);//�ú�ɫ
	cout << "���ةةةةةةةةةةةةةةةةةةة�\n";
}

int RandoM()           //���������
{
return rand() % 6 + 1; //���������,����rand ȡ��6 ��� 1
}


void SetGamePlayerName () //�����������
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
    cout << "���������A��������"; //��ʾ����A�������
	cin >> PlayerName[0];          //�������A������C++������û�н��յ��κ��ַ���һֱ�ȴ����գ����Բ���Ҫ��ʾ��
setb:cout << "���������B��������";
    cin >> PlayerName[1];
	if(PlayerName[1] == PlayerName[0]) //�ж�A������B�����Ƿ����
	{
	cout << "����������ͬ,����������:"; //��ʾ������ͬ
	goto setb;                          //����setb���
	}
	else                               //AB������
	cout << "�������������ϣ�\n";
    cout << "����������Դ..\n";
	cout << "���ڳ�ʼ����ͼ..\n";
	cout << "�����������..\n";
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
cout << "ǰ�� ";
cout << number;
cout << "��\n";
getchar;
	break;
	case 1:
	cout << "��� ";
	cout << PlayerName[gamei];
	cout << "�����������̣���ѡ��ʽ:\n";
set:cout << "A�������Է������룺A��   B������λ�ã�����:B��\n";
    cin >> strr;
    if (strr != "A" && strr != "B")
	{
        goto set;
	}
	if (strr == "A")
	{
		int a = gamei == 0 ? 1 : 0;
		PlayerZB[a] -= 6;
		cout << "������ɣ��Է���6��\n";
		getchar();
	}
	else
	
		temp = PlayerZB[0];
		PlayerZB[0] = PlayerZB[1];
		PlayerZB[0] = temp;
		cout << "�������\n";
		getchar();
		break;
	
	
	case 2:
		PlayerZB[gamei] -= 6;
		cout << "�ȵ�����6��\n";
		getchar();
		break;
	case 3:
		PlayerZB[gamei] += 6;
		cout << "������ ��6��\n";
		getchar();
		break;
	case 4:
		PlayerZT[gamei] = true;
		cout<< "�ȵ���ͣ����ͣһ�غ�";
		getchar();
		break;
	}
}





void MapInstart() //��ͼ��ʶ��ʼ��
{
    for (int i =0; i<6;i++)      
	{
       Maps[XinYunPnums[i]] = 1;  //����ͼ���鸳���������̹ؿ���1��ʶ
	}
	for (int j =0; j<7;j++)
	{
		Maps[DiLeinums[j]] = 2;  //����ͼ���鸳����׹ؿ���2��ʶ
	}
	for (int k =0; k<6;k++)
	{
		Maps[ShiKongnums[k]] = 3; //����ͼ���鸳��ʱ�������ؿ���3��ʶ
	}
	for (int l =0; l<6;l++)
	{
		Maps[ZanTingnums[l]] = 4;  //����ͼ���鸳����ͣ�ؿ���4��ʶ
	}
}



void PDMap_s(int gameZB)  //�ж��������Բ������ؿ�ͼ��
{
	if(PlayerZB[0] == gameZB && PlayerZB[1] == gameZB) //������A�����B�����궼�뵱ǰ�������
	{
		cout <<"�d"; //�����ַ���ʾ��������һ��
	}
	else if(PlayerZB[0]==gameZB)  //�����ǰ����������A������A
	{
		cout << "A";  
	}
	else if (PlayerZB[1] == gameZB) //�����ǰ����������B������B
	{
		cout << "B";
	}
	
	else
		switch(Maps[gameZB]) //��switch�ж�
	{
	   case 0:
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//������ɫ
		   cout << "��";  //����ͨ��
		   break;
	   case 1:
		   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//�ú���
		   cout << "��";  //����������
		   break;
	   case 2: 
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
		   cout << "��";  //�����׹�
		   break;
	   case 3:
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//�ú���
		   cout << "��";   //��ʱ������
		   break;
	   case 4:
		   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//����ɫ
		   cout << "��";   //����ͣ�ؿ�
		   break;
	}
	
}




void DrewMap_one ()
{
  //�����ʾ��Ϣ
  cout << "��ң� ";
  cout << PlayerName[0];
  cout << "  �� A ��ʾ  ��ң� ";
  cout <<PlayerName[1];
  cout << "  �� B ��ʾ\n";
  //��Ϸͼ��
  cout << "ͼ����";
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);//������ɫ
  cout << "��  ��ͨ ";  //����ͨ��
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//�ú���
  cout << "��  ��������";  //����������
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);//�û�ɫ
  cout << "��  ����";  //�����׹�
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);//�ú���
  cout << "��  ʱ������  ";   //��ʱ������
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);//����ɫ
  cout << "��  ��ͣ\n"; 


  //����ͼԪ��
	for (int i = 0; i < 30; i++)  //����һ�е�ͼ�������0 - 29
	{
		PDMap_s(i);                //���������ж�
	}
	cout << "\n";                  //���껻��

	for (int j = 30;j<35;j++)      //�����ҵ����У������ 30 - 34 
	{
		for (int j1 = 0;j1<29;j1++) // ��Ϊ������ǰ����29*2���ո��ڲ�����ѭ��
		{
			cout << "  ";            //��������ո�
		}

		PDMap_s(j);                //�����ж����귽��
		cout << "\n";              //���껻��
	}
	
	for (int k = 64;k >= 35; k--)   //���������У������35 - 64 ��Ϊ�෴�������Եݼ�ѭ��
	{
		PDMap_s(k);                 //�����ж����귽��
	} 
	cout << "\n";                   //���껻��
    
	for (int l = 65;l<70;l++)       //��������  ����� 65 - 69
	{
		PDMap_s(l);                 //���÷������Ȼ���һ��
		for (int l1 =0;l1<30;l1++)
		{
			cout << "  ";               //��������ո�
		}
		cout << "\n";                   //���껻��
	}
	
	for (int m = 70;m<100;m++)         //�����һ��  �����70 - 99
	{
		PDMap_s(m);                   //���÷����ж�����
	}
	cout << "\n";                      //���껻��
}


void PlayGame()
{
	int setNumber;
	while(true)
	{
		cout << "��ң�";
		cout << PlayerName[0];
		cout << "��ʼ��ɫ��:\n";
		system("pause");
		setNumber = RandoM();
		cout << "ɫ������";
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
			cout << "��� ";
			cout << PlayerName[0];
			cout << " Ӯ�����";
			cout << PlayerName[1];
			getchar();
			return;
			}
		}
		else
			PlayerZT[0] = false;
		
		cout << "��ң�";
		cout << PlayerName[1];
		cout << "��ʼ��ɫ��:\n";
		system("pause");
		setNumber = RandoM();
		cout << "ɫ������";
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
			cout << "��� ";
			cout << PlayerName[1];
			cout << " Ӯ�����";
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
  srand(time(0));      //�����������
  ShowGameHead();      //����Ϸͷ
  SetGamePlayerName(); //������Ϸ��
  system("cls");       //�������
  MapInstart();        //��ͼ��ʼ��
  DrewMap_one();       //����ͼԪ��
  PlayGame();          //��Ϸ��
  getchar();
  
  return 0;
}


