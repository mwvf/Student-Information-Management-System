#include "ListOperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//创建表
struct Node* createList()
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	return head;
}

//创建结点
LinkNode createNode(struct student data)
{
	LinkNode p = (struct Node*)malloc(sizeof(struct Node));
	p->data = data;
	p->next = NULL;
	return p;
}

//插入结点(尾插法)
void InsertNode(LinkNode head, struct student data)
{
	LinkNode p = createNode(data);
	LinkNode r = head;
	while (r->next != NULL)
		r = r->next;
	r->next = p;
	p->next = NULL;
}

//删除学号id的结点
void DeleteNode_id(LinkNode head, char* id)
{
	LinkNode p = head->next;
	LinkNode pre = head;
	if (p == NULL)
	{
		printf("数据为空，无法删除！\n");
		return;
	}
	while (strcmp(p->data.id, id))
	{
		pre = p;
		p = pre->next;
		if (p == NULL)
		{
			printf("未找到指定位置，无法删除！\n");
			return;
		}
	}
	pre->next = p->next;
	free(p);
}

//删除姓名name的结点
void DeleteNode_name(LinkNode head, char* name)
{
	LinkNode p = head->next;
	LinkNode pre = head;
	if (p == NULL)
	{
		printf("数据为空，无法删除！\n");
		return;
	}
	while (strcmp(p->data.name, name))
	{
		pre = p;
		p = pre->next;
		if (p == NULL)
		{
			printf("未找到指定位置，无法删除！\n");
			return;
		}
	}
	pre->next = p->next;
	free(p);
}

//查询是否存在相同结点
int Search_id(LinkNode head, struct student data)
{
	LinkNode p = head->next;
	while (p)
	{
		if (!strcmp(p->data.id, data.id))
			return 1;
		p = p->next;
	}
	return 0;
}

//查找学号id的结点
LinkNode SearchNode_id(LinkNode head, char* id)
{
	LinkNode p = head->next;
	if (p == NULL)
		return NULL;
	while (p)
	{
		if (strcmp(p->data.id, id) != 0)
			p = p->next;
		else
			break;
	}
	return p;
}

//查找姓名name的结点
LinkNode SearchNode_name(LinkNode head, char* name)
{
	LinkNode p = head->next;
	if (p == NULL)
		return NULL;
	while (p)
	{
		if (strcmp(p->data.name, name) != 0)
			p = p->next;
		else
			break;
	}
	return p;
}

//计算平均分
double CalculateAverage(LinkNode head, int num)
{
	LinkNode p = head->next;
	double average = 0;
	int len = 0;
	while (p)
	{
		switch (num)
		{
		case 1:
		{
			average += p->data.TotalScore;
			break;
		}
		case 2:
		{
			average += p->data.Math;
			break;
		}
		case 3:
		{
			average += p->data.English;
			break;
		}
		case 4:
		{
			average += p->data.C_Language;
			break;
		}
		}
		len++;
		p = p->next;
	}
	return average / len;
}

//计算及格率
double CalculatePassRate(LinkNode head, int num)
{
	LinkNode p = head->next;
	double pass = 0, len = 0;
	while (p)
	{
		switch (num)
		{
		case 1:
		{
			if (p->data.Math >= 60 && p->data.Math <= 100)
				pass++;
			break;
		}
		case 2:
		{
			if (p->data.English >= 60 && p->data.English <= 100)
				pass++;
			break;
		}
		case 3:
		{
			if (p->data.C_Language >= 60 && p->data.C_Language <= 100)
				pass++;
			break;
		}
		}
		len++;
		p = p->next;
	}
	return pass * 100 / len;
}

//冒泡排序法-降序排列
void  BubbleSort(LinkNode head, int num)
{
	LinkNode p = head, p1, p2 = NULL;
	LinkNode q;
	while ((p->next->next) != p2)
	{
		q = p;
		p1 = p->next;
		while (p1->next != p2)
		{
			switch (num)
			{
			case 1:		//总分排序
			{
				if (p1->data.TotalScore < p1->next->data.TotalScore)
				{
					q->next = p1->next;
					p1->next = p1->next->next;
					q->next->next = p1;
					p1 = q->next;
				}
				break;
			}
			case 2:		//高数排序
			{
				if (p1->data.Math < p1->next->data.Math)
				{
					q->next = p1->next;
					p1->next = p1->next->next;
					q->next->next = p1;
					p1 = q->next;
				}
				break;
			}
			case 3:		//英语排序
			{
				if (p1->data.English < p1->next->data.English)
				{
					q->next = p1->next;
					p1->next = p1->next->next;
					q->next->next = p1;
					p1 = q->next;
				}
				break;
			}
			case 4:		//C语言排序
			{
				if (p1->data.C_Language < p1->next->data.C_Language)
				{
					q->next = p1->next;
					p1->next = p1->next->next;
					q->next->next = p1;
					p1 = q->next;
				}
				break;
			}
			}
			p1 = p1->next;
			q = q->next;
		}
		p2 = p1;
	}
}

//选择排序法-升序排列
void SelectSort(LinkNode head, int num)
{
	LinkNode p1 = head, p2, min;
	while (p1->next)
	{
		p2 = p1->next;
		min = p2;
		while (p2)
		{
			switch (num)
			{
			case 1:
			{
				if (p2->data.TotalScore < min->data.TotalScore)
				{
					min = p2; //min指向数据元素最小的结点 
				}
				break;
			}
			case 2:
			{
				if (p2->data.Math < min->data.Math)
				{
					min = p2; //min指向数据元素最小的结点 
				}
				break;
			}
			case 3:
			{
				if (p2->data.English < min->data.English)
				{
					min = p2; //min指向数据元素最小的结点 
				}
				break;
			}
			case 4:
			{
				if (p2->data.C_Language < min->data.C_Language)
				{
					min = p2; //min指向数据元素最小的结点 
				}
				break;
			}
			}
			p2 = p2->next;
		}
		for (p2 = p1; p2->next != min; p2 = p2->next); //q指针指向min指针的前一个 
		p2->next = min->next;
		min->next = p1->next; //min指向的结点插入到p指针后面
		p1->next = min;
		p1 = p1->next; //p指针后移一位 
	}
}

//分数段[a,b]成绩查询
void ResultInquiry(LinkNode head, int a, int b, int num)
{
	LinkNode p = head->next;
	int flag = 1, i = 1;
	printitle();
	while (p)
	{
		switch (num)
		{
		case 1:
		{
			if (p->data.Math >= a && p->data.Math <= b)
			{
				flag = 0;
				printf("%2d\t", i++);
				printNode(p);
			}
			break;
		}
		case 2:
		{
			if (p->data.English >= a && p->data.English <= b)
			{
				flag = 0;
				printf("%2d\t", i++);
				printNode(p);
			}
			break;
		}
		case 3:
		{
			if (p->data.C_Language >= a && p->data.C_Language <= b)
			{
				flag = 0;
				printf("%2d\t", i++);
				printNode(p);
			}
			break;
		}
		}
		p = p->next;
	}
	if (flag)	printf("\n未查询到该分数段内的学生信息！\n\n");
}

//文件读操作
void ReadFile(LinkNode head, char* fileName)
{
	FILE* fp;
	struct student data;
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("\n无法打开文件！\n");
		printf("正在重新创建新文件......\n\n");
		system("pause");
		system("cls");

		fp = fopen(fileName, "w+");		//文件不存在则创建新文件
		if (fp == NULL)
		{
			printf("无法创建新文件文件！\n");
			exit(0);
		}
	}
	while (fscanf(fp, ("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n"), data.id, data.name, data.sex, &data.age, &data.Math, &data.English, &data.C_Language, &data.TotalScore) != EOF)
	{
		InsertNode(head, data);
	}
	fclose(fp);
}

//文件写操作

void WriteFile(LinkNode head, char* fileName)
{
	FILE* fp;
	fp = fopen(fileName, "w");	//清空文件内原有的内容，重新保存
	if (fp == NULL)
	{
		printf("文件保存失败！\n");
		return;
	}
	LinkNode p = head->next;
	while (p)
	{
		fprintf(fp, "%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p->data.id, p->data.name, p->data.sex, p->data.age, p->data.Math, p->data.English, p->data.C_Language, p->data.TotalScore);
		p = p->next;
	}
	fclose(fp);
}

//打印表头
void printitle()
{
	printf("序号      学 号          姓名   性别   年龄    高数    英语    C语言   总分\n");
}

//打印结点
void printNode(LinkNode p)
{
	if (p == NULL)
	{
		printf("未查询到成员！\n");
		return;
	}
	printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p->data.id, p->data.name, p->data.sex, p->data.age, p->data.Math, p->data.English, p->data.C_Language, p->data.TotalScore);

}

//打印链表
void printList(LinkNode head)
{
	LinkNode p = head->next;
	if (p == NULL)
	{
		printf("失败");
		return;
	}
	int i = 1;
	printf("\n");
	printitle();
	while (p != NULL)
	{
		printf("%2d\t", i);
		printNode(p);
		p = p->next;
		i++;
	}
	printf("\n");
}