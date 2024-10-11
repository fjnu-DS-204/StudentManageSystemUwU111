#include "main.h"
using namespace std;

void printDividerStar(){ cout<<"*****************************************************"; }
void printShortStar(){ cout<<"***************"; }
void printLongStar(){ cout<<"*******************"; }
void printItemDot(){ cout<<"\t^ "; }
void printCommandSign(){ cout<<"\t$ ";}

int tryPasswordCount = 0;// 登录失败计数

void printGreetMenu(){
    string password;

    printLongStar(); cout<<"欢迎进入学生管理系统"; printLongStar(); cout<<endl;
    printItemDot(); cout<<"Made with ❤❤❤ by noone & xjs114 & 001Pro-Max & "<<endl;
    printItemDot(); cout<<"当前系统时间是:\t"; cout << getTime();
    printItemDot(); cout<<"进入该系统设有密码,只有"<<TryPasswordTimes<<"次机会"<<endl;
    printItemDot(); cout<<"温馨向您提示,登录密码为: "<<TruePassword<<endl;
    printItemDot(); cout<<"请您输入密码:"; cin>>password; checkLoginPassword(password);
}

void printMainMenu(){
    char chooseItemId;

    printDividerStar(); cout<<endl;
    printLongStar(); cout<<"欢迎来到学生管理系统"; printLongStar(); cout<<endl; printDividerStar(); cout<<endl;
    printShortStar(); cout<<"\t\t1 创建学生信息\t\t"; printShortStar(); cout<<endl;
    printShortStar(); cout<<"\t\t2 显示学生信息\t\t"; printShortStar(); cout<<endl;
    printShortStar(); cout<<"\t\t3 排序学生信息\t\t"; printShortStar(); cout<<endl;
    printShortStar(); cout<<"\t\t4 查询学生信息\t\t"; printShortStar(); cout<<endl;
    printShortStar(); cout<<"\t\t5 删除学生信息\t\t"; printShortStar(); cout<<endl;
    printShortStar(); cout<<"\t\t6 修改学生信息\t\t"; printShortStar(); cout<<endl;
    printShortStar(); cout<<"\t\t0 成功退出系统\t\t"; printShortStar(); cout<<endl;
    printDividerStar(); cout<<endl; printDividerStar(); cout<<endl;

    printItemDot(); cout<<"请输入您想要完成的操作:";
    cin>>chooseItemId;
    switchFunction(chooseItemId);
}