#include "main.h"
#define  _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;

void clear_screen(){
    system("cls");
    // cout << "\033c";
}

void error_1(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"输错了喵，再试一次："<<" ";
}

void error_2(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"你先别急，输慢点喵"<<endl;
    print_itemdot(); cout<<"再来一次："<<" ";
}

void error_3(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"嘶，不是哥们，我怀疑你是故意的"<<endl;
    print_itemdot(); cout<<"你这次最好是对的："<<" ";
}

void error_4(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"等下，我们最好都冷静一下"<<endl; Sleep(1000);
    print_itemdot(); cout<<"你只需要在0~6的范围内挑一个数字就好了好吗"<<endl; Sleep(1000);
    print_itemdot(); cout<<"我相信你已经明白了，现在让我们谨慎的再试一次："<<" ";
}

void error_5(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); cout<<"..."<<endl; Sleep(2000);
    print_itemdot(); cout<<"..."<<endl; Sleep(1000);
    print_itemdot(); cout<<"我很确定这只是一个简单实现学生管理系统的程序，而不是一个对某个能调戏旁白的游戏的拙略模仿"<<endl; Sleep(2000);
    print_itemdot(); cout<<"你唯一需要做的，就是去调试这个程序的正常功能，"<<endl; Sleep(500);
    print_itemdot(); cout<<"而非来看看我到底写了多少种特判来处理不合法输入的情况"<<endl; Sleep(1000);
    print_itemdot(); cout<<"我很确信没有别的特判了，别玩了，再试一次吧："<<" ";
}

void error_6(){
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    print_itemdot(); Sleep(2000); cout<<"..."; Sleep(2000); cout<<endl;
    print_itemdot(); cout<<"哦！ 我明白了"<<endl;  Sleep(1000);
    print_itemdot(); cout<<"你一定是忘了功能对应的键位了"<<endl;  Sleep(1000);
    print_itemdot(); cout<<"没关系，我再向你展示一遍："<<endl;  Sleep(1000);
    print_MAIN_menu();
}

void error_7(){
    /*
    WCHAR UserName[255];
    unsigned long size = 255;
    GetUserName(UserName, &size);
    */ //这玩意有bug
    char currentUser[256]={0};  //以下在模块化呀调用windows.h中读用户名函数
	DWORD dwSize_currentUser=256;
	GetUserName(
		currentUser,			// 接收当前登录用户的用户名
		&dwSize_currentUser		// 缓冲区大小
		);
    cout<<endl; print_dividerstar(); cout<<endl; cout<<endl;
    clear_screen(); Sleep(1000);
	print_itemdot(); cout<<"这样并不好玩，管理员"<<endl; Sleep(700);
    print_itemdot(); cout<<"也许。。我更应该称呼你为。。"<<currentUser<<"?"<<endl; Sleep(1500);
    
}