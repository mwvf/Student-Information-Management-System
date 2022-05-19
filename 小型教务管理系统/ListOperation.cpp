#include "ListOperation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//������
struct Node* createList()
{
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	return head;
}

//�������
LinkNode createNode(struct student data)
{
	LinkNode p = (struct Node*)malloc(sizeof(struct Node));
	p->data = data;
	p->next = NULL;
	return p;
}

//������(β�巨)
void InsertNode(LinkNode head, struct student data)
{
	LinkNode p = createNode(data);
	LinkNode r = head;
	while (r->next != NULL)
		r = r->next;
	r->next = p;
	p->next = NULL;
}

//ɾ��ѧ��id�Ľ��
void DeleteNode_id(LinkNode head, char* id)
{
	LinkNode p = head->next;
	LinkNode pre = head;
	if (p == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ����\n");
		return;
	}
	while (strcmp(p->data.id, id))
	{
		pre = p;
		p = pre->next;
		if (p == NULL)
		{
			printf("δ�ҵ�ָ��λ�ã��޷�ɾ����\n");
			return;
		}
	}
	pre->next = p->next;
	free(p);
}

//ɾ������name�Ľ��
void DeleteNode_name(LinkNode head, char* name)
{
	LinkNode p = head->next;
	LinkNode pre = head;
	if (p == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ����\n");
		return;
	}
	while (strcmp(p->data.name, name))
	{
		pre = p;
		p = pre->next;
		if (p == NULL)
		{
			printf("δ�ҵ�ָ��λ�ã��޷�ɾ����\n");
			return;
		}
	}
	pre->next = p->next;
	free(p);
}

//��ѯ�Ƿ������ͬ���
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

//����ѧ��id�Ľ��
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

//��������name�Ľ��
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

//����ƽ����
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

//���㼰����
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

//ð������-��������
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
			case 1:		//�ܷ�����
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
			case 2:		//��������
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
			case 3:		//Ӣ������
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
			case 4:		//C��������
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

//ѡ������-��������
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
					min = p2; //minָ������Ԫ����С�Ľ�� 
				}
				break;
			}
			case 2:
			{
				if (p2->data.Math < min->data.Math)
				{
					min = p2; //minָ������Ԫ����С�Ľ�� 
				}
				break;
			}
			case 3:
			{
				if (p2->data.English < min->data.English)
				{
					min = p2; //minָ������Ԫ����С�Ľ�� 
				}
				break;
			}
			case 4:
			{
				if (p2->data.C_Language < min->data.C_Language)
				{
					min = p2; //minָ������Ԫ����С�Ľ�� 
				}
				break;
			}
			}
			p2 = p2->next;
		}
		for (p2 = p1; p2->next != min; p2 = p2->next); //qָ��ָ��minָ���ǰһ�� 
		p2->next = min->next;
		min->next = p1->next; //minָ��Ľ����뵽pָ�����
		p1->next = min;
		p1 = p1->next; //pָ�����һλ 
	}
}

//������[a,b]�ɼ���ѯ
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
	if (flag)	printf("\nδ��ѯ���÷������ڵ�ѧ����Ϣ��\n\n");
}

//�ļ�������
void ReadFile(LinkNode head, char* fileName)
{
	FILE* fp;
	struct student data;
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("\n�޷����ļ���\n");
		printf("�������´������ļ�......\n\n");
		system("pause");
		system("cls");

		fp = fopen(fileName, "w+");		//�ļ��������򴴽����ļ�
		if (fp == NULL)
		{
			printf("�޷��������ļ��ļ���\n");
			exit(0);
		}
	}
	while (fscanf(fp, ("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n"), data.id, data.name, data.sex, &data.age, &data.Math, &data.English, &data.C_Language, &data.TotalScore) != EOF)
	{
		InsertNode(head, data);
	}
	fclose(fp);
}

//�ļ�д����

void WriteFile(LinkNode head, char* fileName)
{
	FILE* fp;
	fp = fopen(fileName, "w");	//����ļ���ԭ�е����ݣ����±���
	if (fp == NULL)
	{
		printf("�ļ�����ʧ�ܣ�\n");
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

//��ӡ��ͷ
void printitle()
{
	printf("���      ѧ ��          ����   �Ա�   ����    ����    Ӣ��    C����   �ܷ�\n");
}

//��ӡ���
void printNode(LinkNode p)
{
	if (p == NULL)
	{
		printf("δ��ѯ����Ա��\n");
		return;
	}
	printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", p->data.id, p->data.name, p->data.sex, p->data.age, p->data.Math, p->data.English, p->data.C_Language, p->data.TotalScore);

}

//��ӡ����
void printList(LinkNode head)
{
	LinkNode p = head->next;
	if (p == NULL)
	{
		printf("ʧ��");
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