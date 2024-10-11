#ifndef STUMANAGE_MAIN_H
#define STUMANAGE_MAIN_H
#define  _WINSOCK_DEPRECATED_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
// #include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <string>
#include <windows.h>
#include <stdlib.h>
#define TruePassword "1"
#define TryPasswordTimes 3
using namespace std;

/* 菜单布局 */
void printDividerStar();
void printShortStar();
void printLongStar();
void printItemDot();
void printCommandSign();

void printGreetMenu();
void printMainMenu();

/* 功能函数 */
extern int tryPasswordCount;
void checkLoginPassword(string password);
char* getTime();
void switchFunction(char chooseItemId);

/* icey交互类 */
void clear_screen();
void error_1();
void error_2();
void error_3();
void error_4();
void error_5();
void error_6();
void error_7();

/* 个人呢学生类 */
class student{
    friend class studentList;
private:
    string name;
    string id;
    int DSScore,mathScore,enScore;
    student * next; //指向下一个学生
public:
    void add();
    // void readFile(istream & in); //有bug的读入文件
    void display(); //打印学生信息
    void swap(student *toExchange); //与传入的对象交换信息
};

/* 学生链表类 */
class studentList{
private:
    student * first;
    student * last;
    int num;
    ifstream in;
    ofstream out;

public:
    studentList();          //学生链表类构造函数
    ~studentList();         //析构函数
    void add();             //增
    void edit();            //改
    void removeLast();      //删除表中最后一个节点
    void remove();          //删除表中学生成绩记录
    void searchById();      //学号查询学生成绩记录
    void searchByName();    //姓名查询学生成绩记录
    void sortById();        //按学号排序学生成绩记录
    void sortByDS();        //按DS排序学生成绩记录
    void sortByMath();      //按Math排序学生成绩记录
    void sortByEn();        //按En排序学生成绩记录
    void show();            //显示学生信息
    // void save();            //有bug的文件保存

};
extern studentList stuL;
void createStudent();
void editStudent();
void deleteStudent();
void searchStudents();
void sortStudents();
void switchSearchFun(char chooseWayId);
void switchSortFun(char chooseWayId);
void showAllStudents();
void printStudentTableTitle();
void printStudentTableFoot();

#endif //STUMANAGE_MAIN_H