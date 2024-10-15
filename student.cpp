#include "main.h"

/******************************************************
 * 学生类函数
 */

int student::check_score(int tempScore){
    if(tempScore<0||tempScore>100){
        printItemDot();
        cout<<"error!: 学生成绩输入有误,成绩范围0~100,请再次尝试:";
        cin>>tempScore;
        return check_score(tempScore);
    }
    return tempScore;
}

void student::add(){
    printItemDot();
    cout<<"请输入学生姓名:";
    cin>>name;
    string tempId="";
    int tempScore=0;
    //学号处理
    printItemDot();
    cout<<"请输入学生学号(十位):";
    cin>>tempId;
    while(tempId.length()!=10){
        printItemDot();
        cout<<"error!: 学生学号输入有误,学号为十位整数,请再次尝试:";
        cin>>tempId;
    }
    id=tempId;

    //成绩处理
    printItemDot();
    cout<<"请输入DS课程的期末成绩:";
    cin>>tempScore;
    DSScore=check_score(tempScore);

    printItemDot();
    cout<<"请数学课程的期末成绩:";
    cin>>tempScore;
    mathScore=check_score(tempScore);

    printItemDot();
    cout<<"请英语课程的期末成绩:";
    cin>>tempScore;
    enScore=check_score(tempScore);
    next=NULL;
}

/**********************************************************
 * 学生类接口定义
 */
// void student::readFile(istream & in)//有bug的读入文件
// {
//     in>>name>>id>>DSScore>>mathScore>>enScore;
// }

void student::display(){
    cout<<id<<"\t"<<name<<"  \t"<<DSScore<<"   \t"<<mathScore<<"   \t"<<enScore;
    cout<<endl;
}

void student::swap(student *toExchange){//与传入的对象交换信息 用于简单排序法时交换
    string tempName,tempId;
    int tempDSScore,tempMathScore,tempEnScore;
    tempName=name;name=toExchange->name;toExchange->name=tempName;
    tempId=id;id=toExchange->id;toExchange->id=tempId;
    tempDSScore=DSScore;DSScore=toExchange->DSScore;toExchange->DSScore=tempDSScore;
    tempMathScore=mathScore;mathScore=toExchange->mathScore;toExchange->mathScore=tempMathScore;
    tempEnScore=enScore;enScore=toExchange->enScore;toExchange->enScore=tempEnScore;
}

/*******************************************************
 * 学生列表类构造函数
 */
studentList::studentList(){
    // in.open("stuDate.txt");//有bug的读入文件
    // if(!in){
        // cout<<"\t*欢迎新用户,请先输入用户信息再使用.";
        // printShortStar();
        // cout<<endl;
        first =NULL;
        last =NULL;
        num=0;
    // }else{
    //     first=new student;
    //     last=first;
    //     num=0;
    //     while(!in.eof()){
    //         last->readFile(in);
    //         //数据结束 但会余留一个空节点
    //         if(last->id[0]!=NULL){
    //             last->next=new student;
    //             last=last->next;
    //         }
    //     }
    //     //删除空节点
    //     stuL.removeLast();

    //     in.close();
    //     cout<<"\t*欢迎再次使用,读取学生信息成功.";
    //     printShortStar();
    //     cout<<endl;
    // }
}

/**
 *通过Id添加学生信息
 */
void studentList::add(){
    student * t =new student;
    t->add();
    student * p=first;
    while(p){
        if(p->id==t->id)
        {
            printItemDot();
            cout<<"error!: 学号输入错误或该学生已经存在 如需添加，请先删除原纪录再重新录入!"<<endl;
            return;
        }
        p=p->next;
    }
    num++;
    if(first==NULL){
        first=last=t;
        cout<<"\t*学生信息创建成功:) "<<endl; Sleep(1000);
        printStudentTableTitle();
        last->display();
        printStudentTableFoot();
    }
    else{
        last->next=t;
        last=last->next;
        cout<<"\t*学生信息创建成功:) "<<endl; Sleep(1000);
        printStudentTableTitle();
        last->display();
        printStudentTableFoot();
    }
}

/**
 *通过Id修改学生信息
 */
void studentList::edit(){
    string tempId;
    char isCheck;
    student *t=first;

    printItemDot(); cout<<"请输入要修改的学生学号:";
    cin>>tempId;
    while(tempId.length()!=10){//学号验证
        printItemDot();
        cout<<"error!: 学生学号输入有误,学号为十位整数,请再次尝试:";
        cin>>tempId;
    }
    while(t){
        if(t->id==tempId) break;
        t=t->next;
    }

    if(!t){//t到最后为空
        printItemDot();
        cout<<"error!:\n    未找到您所要修改的学生\n     请确认学号后重试"<<endl;
        return;
    }else{
        cout<<"\t*已为您查询到该学生 ";
        printShortStar();
        cout<<endl;
        printStudentTableTitle();
        t->display();
        printStudentTableFoot();
    }
    cout<<endl;
    printItemDot(); cout<<"确认修改此学生吗(y/n) (默认为y) :";
    // cin>>isCheck;
    getchar(); scanf("%c",&isCheck); //getchar先读掉前面的回车，用scanf来读入回车的情况
    switch(isCheck){
        case 'Y':
        case 'y':
        case '\n': {
            printItemDot();
            cout<<"修改学生姓名:";
            cin>>t->name;
            int tempScore=0;

            printItemDot();//成绩处理
            cout<<"修改DS课程的期末成绩:";
            cin>>tempScore;
            while(tempScore<0 || tempScore>100){
                printItemDot();
                cout<<"error!: 学生成绩输入有误,成绩范围0~100,请再次尝试:";
                cin>>tempScore;
            }
            t->DSScore=tempScore;

            printItemDot();
            cout<<"修改数学课程的期末成绩:";
            cin>>tempScore;
            while(tempScore<0 || tempScore>100){
                printItemDot();
                cout<<"error!: 学生成绩输入有误,成绩范围0~100,请再次尝试:";
                cin>>tempScore;
            }
            t->mathScore=tempScore;

            printItemDot();
            cout<<"修改英语课程的期末成绩:";
            cin>>tempScore;
            while(tempScore<0 || tempScore>100){
                printItemDot();
                cout<<"error!: 学生成绩输入有误,成绩范围0~100,请再次尝试:";
                cin>>tempScore;
            }
            t->enScore=tempScore;

            cout<<"\t>./学生信息已成功修改."<<endl;
            printStudentTableTitle();
            t->display();
            printStudentTableFoot();
            Sleep(500);
        }
            break;
        case 'N':
        case 'n':
        default :
            cout<<"\t>./学生信息修改已取消."<<endl;
            Sleep(500);
            break;
    }
}

/**
 * 删除最后一个节点
 */
void studentList::removeLast(){
    //删除空节点 p为倒数第二个
    student *p=first;
    while(p->next->next!=NULL){ p=p->next; }
    free(p->next);
    p->next=NULL;
    last=p;
}

/**
 *通过Id删除学生信息
 */
void studentList::remove(){
    string tempId;
    cout<<"\t>./准备删除学生信息 "; printSlowDot();
    cout<<"请输入要删除的学生的学号: ";
    cin>>tempId;
    student *t=first;
    student *p=NULL;
    while(t){
        if(t->id==tempId) break;
        p=t; t=t->next;
    }
    if(!t){//t到最后为空
        printItemDot();
        cout<<"error!: 未找到要删除的学生，请确认学号后重试"<<endl;
        return;
    }
    if(!p){//特判第一个就相同
        first=first->next;
        printItemDot();
        cout<<"Congratulations!: 您已成功删除学生"<<tempId<<endl;
        delete t;
    }
    else{
        p->next=t->next;//把t的下一个地址赋给p的next
        printItemDot();
        cout<<"Congratulations!: 您已成功删除学生"<<tempId<<endl;
        delete t;
    }
    --num;
    Sleep(1000);
}

/**
 *通过Id搜索学生
 */
void studentList::searchById(){
    string tempId;
    student *t=first;

    printItemDot(); cout<<"请输入要查找的学生学号:";
    cin>>tempId;
    while(tempId.length()!=10){//学号验证
        printItemDot();
        cout<<"error!: 学生学号输入有误，学号为十位整数，请再次尝试：";
        cin>>tempId;
    }
    while(t){
        if(t->id==tempId) break;
        t=t->next;
    }

    if(!t){//t已跑到最后为空
        printItemDot();
        cout<<"error!:\n    未找到您所要查找的学生\n     请确认学号后重试"<<endl;
        return;
    }else{
        cout<<"\t*已为您查询到以下学生 "<<endl;
        printStudentTableTitle();
        t->display();
        printStudentTableFoot();
    }
}

/**
 *通过Name搜索学生
 */
void studentList::searchByName(){
    string tempName;
    student *t=first;
    student *p[] ={NULL};
    int foundCount=0;//从0开始的计数器

    printItemDot(); cout<<"请输入要查找的学生姓名:";
    cin>>tempName;
    while(t){
        if(t->name==tempName) p[foundCount++]=t;
        t=t->next;
    }

    if(!p[0]){//p[0]为空，即t已跑到最后为空
        printItemDot();
        cout<<"error!: 未找到您所要查找的学生，请确认姓名后重试"<<endl;
        return;
    }else{
        cout<<"\t*已为您查询到以下学生 "<<endl;
        printStudentTableTitle();
        for(int i=0;i<foundCount;++i) p[i]->display();
        printStudentTableFoot();
    }
}

/**
 *通过Id排序学生
 */
void studentList::sortById(){
    student *t=first;
    student *p=NULL;

    if(t==NULL){//无数据
        printItemDot();
        cout<<"error!: 当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    for(;t->next!=NULL;t=t->next)//冒泡 //需要更新为堆排序
        for(p=t->next;p!=NULL;p=p->next) if(p->id<t->id) p->swap(t);

    cout<<"\t*已按学生学号排序成功 "<<endl;
    stuL.show();
}

/**
 *通过DS排序学生
 */
void studentList::sortByDS(){
    student *t=first;
    student *p=NULL;

    if(t==NULL){//无数据后的退出
        printItemDot();
        cout<<"error!:\n    当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    //链表 简单选择排序法
    for(;t->next!=NULL;t=t->next){
        for(p=t->next;p!=NULL;p=p->next){
            if(p->DSScore>t->DSScore){
                p->swap(t);
            }
        }
    }

    cout<<"\t*已按DS成绩排序成功 ";
    printShortStar();
    cout<<endl;
    stuL.show();

}

/**
 *通过Math排序学生
 */
void studentList::sortByMath(){
    student *t=first;
    student *p=NULL;

    if(t==NULL){//无数据后的退出
        printItemDot();
        cout<<"error!:\n    当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    //链表 简单选择排序法
    for(;t->next!=NULL;t=t->next){
        for(p=t->next;p!=NULL;p=p->next){
            if(p->mathScore>t->mathScore){
                p->swap(t);
            }
        }
    }

    cout<<"\t*已按数学成绩排序成功 ";
    printShortStar();
    cout<<endl;
    stuL.show();
}

/**
 *通过En排序学生
 */
void studentList::sortByEn(){
    student *t=first;
    student *p=NULL;

    if(t==NULL){//无数据后的退出
        printItemDot();
        cout<<"error!:\n    当前无学生数据,请先添加后排序"<<endl;
        return;
    }

    //链表 简单选择排序法
    for(;t->next!=NULL;t=t->next){
        for(p=t->next;p!=NULL;p=p->next){
            if(p->enScore>t->enScore){
                p->swap(t);
            }
        }
    }

    cout<<"\t*已按英语成绩排序成功 ";
    printShortStar();
    cout<<endl;
    stuL.show();
}

/**
 *显示所有学生信息
 */
void studentList::show(){
    printStudentTableTitle();
    student *t=first;
    if(t) while(t){ t->display(); t=t->next; }
    else{
        printItemDot();
        cout<<"error!:当前无学生信息"<<endl;
    }
    printStudentTableFoot();
}


//有bug的文件保存

// void studentList::save()
// {
//     student *t=first;
//     out.open("stuDate.txt");
//     for(;t!=NULL;t=t->next)
//         out<<t->name<<"\t"<<t->id<<"\t"<<t->DSScore<<"\t"
//            <<t->mathScore<<"\t"<<t->enScore<<'\n';
//     out.close();
// }

studentList::~studentList()
{
    // save(); //有bug的文件保存
}

void createStudent(){
    cout<<"\t>./正在创建学生信息 ";
    printSlowDot();
    stuL.add();
}

void deleteStudent(){ stuL.remove(); }

void showAllStudents(){
    cout<<"\t>./显示所有学生信息 ";
    printSlowDot();
    stuL.show();
}

void editStudent(){
    cout<<"\t>./进入修改学生信息 ";
    printSlowDot();
    stuL.edit();
}

/**
 * 查询学生信息逻辑
 */
void searchStudents(){
    char chooseWayId;
    cout<<"\t.>/如何查询学生信息 ";
    printSlowDot();
    cout<<endl;
    printItemDot(); printLongStar();cout<<endl;
    printItemDot(); cout<<"1.按学生的姓名查找(支持重名)"<<endl;
    printItemDot(); cout<<"2.按学生的学号查找(学号唯一)"<<endl;
    printItemDot(); cout<<"3.显示所有学生信息"<<endl;
    printItemDot(); printLongStar();cout<<endl;
    cout<<endl;
    printItemDot(); cout<<"请选择查找方式:";
    cin>>chooseWayId;
    switchSearchFun(chooseWayId);
}

/**
 * 切换查询方式函数
 * @param chooseWayId
 */
void switchSearchFun(char chooseWayId){
    switch(chooseWayId){
        case '1'://按姓名
            stuL.searchByName();
            break;
        case '2'://按学号
            stuL.searchById();
            break;
        case '3'://全部
            showAllStudents();
            break;
        default:
            printItemDot(); cout<<"error!: 无您所输入的选项,请确认后重试:";
            cin>>chooseWayId;
            switchSearchFun(chooseWayId);
    }
}

/**
 * 排序学生信息逻辑
 */
void sortStudents(){
    char chooseWayId;
    cout<<"\t*如何排序学生信息 ";
    cout<<endl;
    printItemDot(); printLongStar(); cout<<endl;
    printItemDot(); cout<<"1.按学生的DS成绩"<<endl;
    printItemDot(); cout<<"2.按学生的数学成绩"<<endl;
    printItemDot(); cout<<"3.按学生的英语成绩"<<endl;
    printItemDot(); cout<<"4.按学生的学号"<<endl;
    printItemDot(); printLongStar(); cout<<endl;
    cout<<endl;
    printItemDot(); cout<<"请选择排序方式:";
    cin>>chooseWayId;
    switchSortFun(chooseWayId);
}

/**
 * 切换排序方式函数
 * @param chooseWayId
 */
void switchSortFun(char chooseWayId){
    switch(chooseWayId){
        case '1':
            stuL.sortByDS(); break;
        case '2':
            stuL.sortByMath(); break;
        case '3':
            stuL.sortByEn(); break;
        case '4':
            stuL.sortById(); break;
        default:
            printItemDot(); cout<<"error!: 无您所输入的选项,请确认后重试:";
            cin>>chooseWayId;
            switchSortFun(chooseWayId);
    }
}

void printStudentTableTitle(){
    cout<<endl;
    cout<<"------------------学生列表------------------"<<endl;
    cout<<"\t"<<"学号"<<"  \t"<<"姓名"<<"  \t"<<"DS"<<"  \t"<<"数学"<<"  \t"<<"英语"<<endl;
}

void printStudentTableFoot(){
    cout<<"------------------列表结束------------------"<<endl;
    cout<<endl;
    Sleep(1500);
}
