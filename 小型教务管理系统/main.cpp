/*
    程序编写使用VS2019
*/

#include "ListOperation.h"
#include "Student.h"
#include <windows.h>

char path[] = "dataset.txt";      //定义打开文本默认为当前目录下"dataset.txt"
struct Node* linklist = createList();

//隐藏光标
void HideConsoleCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//设置窗口界面
void SetWindow()
{
    system("title 教务管理系统");    //设置窗口标题
    system("mode con cols=80 lines=32");    //设置窗口大小
    system("color F9");     //设置窗口颜色
    HideConsoleCursor();    //隐藏光标
}

void program()
{
    View menu;
    menu.title();
    menu.showmenu();
    printf("请输入指令的序号：");
    int choice = JudgmentCommand();
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            menu.addstudent();      //学生成绩信息录入
            break;

        case 2:
            menu.deletestudent();      //学生成绩信息删除
            break;
        case 3:
            menu.editstudent();     //学生成绩信息修改
            break;
        case 4:
            menu.inquirestudent();         //学生信息成绩查询
            break;
        case 5:
            menu.visitstudent();        //浏览班级分数情况
            break;
        case 6:
            menu.showstatistics();       //班级分数情况统计
            break;
        case 7:
            menu.scoresort();            //班级分数排序
            break;
        case 8:
            menu.FilaSaveAs(linklist);  //另存为成绩文件
            break;
        default:
            system("cls");
            menu.title();
            menu.showmenu();
            printf("指令输入错误，请重新输入！\n\n");
        }
        printf("请输入指令的序号：");
        choice = JudgmentCommand();
    }
}

int main()
{
    SetWindow();

    //文件内容读取
    ReadFile(linklist, path);

    program();

    //文件保存
    WriteFile(linklist, path);
    return 0;
}
