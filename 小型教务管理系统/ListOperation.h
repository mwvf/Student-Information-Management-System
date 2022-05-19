#define  _CRT_SECURE_NO_WARNINGS	//屏蔽scanf()函数等的警告
#ifndef _List_
#define _List_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char id[20];			//学号
	char name[20];			//姓名
	char sex[5];			//性别
	int age;				//年龄
	int Math;				//数学成绩
	int English;			//英语成绩
	int C_Language;			//C语言成绩
	int TotalScore;			//总分
};

typedef struct Node
{
	struct student data;
	struct Node* next;
}Node, * LinkNode;

struct Node* createList();	//创建表

LinkNode createNode(struct student data);	//创建结点

void InsertNode(LinkNode head, struct student data);	//插入结点(尾插法)

void DeleteNode_id(LinkNode head, char* id);	//删除学号id的结点

void DeleteNode_name(LinkNode head, char* name);	//删除姓名name的结点

int Search_id(LinkNode head, struct student data);	//查询是否存在相同id的结点

LinkNode SearchNode_id(LinkNode head, char* id);	//查找学号id的结点

LinkNode SearchNode_name(LinkNode head, char* name);	//查找姓名name的结点

double CalculateAverage(LinkNode head, int num);	//计算平均分
//说明：num = 1时，查询总分；num = 2时，查询高数；num = 3时，查询英语；num = 4时，查询C语言；

double CalculatePassRate(LinkNode head, int num);	//计算及格率
//说明：num=1时，查询总分；num=2时，查询高数；num=3时，查询英语；num=4时，查询C语言；

void  BubbleSort(LinkNode head, int num);	//冒泡排序法-降序排列
//说明：num=1时，查询总分；num=2时，查询高数；num=3时，查询英语；num=4时，查询C语言；

void SelectSort(LinkNode head, int num);	//选择排序法-升序排列
//说明：num=1时，查询总分；num=2时，查询高数；num=3时，查询英语；num=4时，查询C语言；

void ResultInquiry(LinkNode head, int a, int b, int num);	//分数段[a,b]成绩查询
//说明：num=1时，查询高数；num=2时，查询英语；num=3时，查询C语言；

void ReadFile(LinkNode head, char* fileName);	//文件读操作

void WriteFile(LinkNode head, char* fileName);	//文件写操作

void printitle();	//打印表头

void printNode(LinkNode p);	//打印结点

void printList(LinkNode head);	//打印链表

#endif