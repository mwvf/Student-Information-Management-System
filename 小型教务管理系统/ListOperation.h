#define  _CRT_SECURE_NO_WARNINGS	//����scanf()�����ȵľ���
#ifndef _List_
#define _List_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char id[20];			//ѧ��
	char name[20];			//����
	char sex[5];			//�Ա�
	int age;				//����
	int Math;				//��ѧ�ɼ�
	int English;			//Ӣ��ɼ�
	int C_Language;			//C���Գɼ�
	int TotalScore;			//�ܷ�
};

typedef struct Node
{
	struct student data;
	struct Node* next;
}Node, * LinkNode;

struct Node* createList();	//������

LinkNode createNode(struct student data);	//�������

void InsertNode(LinkNode head, struct student data);	//������(β�巨)

void DeleteNode_id(LinkNode head, char* id);	//ɾ��ѧ��id�Ľ��

void DeleteNode_name(LinkNode head, char* name);	//ɾ������name�Ľ��

int Search_id(LinkNode head, struct student data);	//��ѯ�Ƿ������ͬid�Ľ��

LinkNode SearchNode_id(LinkNode head, char* id);	//����ѧ��id�Ľ��

LinkNode SearchNode_name(LinkNode head, char* name);	//��������name�Ľ��

double CalculateAverage(LinkNode head, int num);	//����ƽ����
//˵����num = 1ʱ����ѯ�ܷ֣�num = 2ʱ����ѯ������num = 3ʱ����ѯӢ�num = 4ʱ����ѯC���ԣ�

double CalculatePassRate(LinkNode head, int num);	//���㼰����
//˵����num=1ʱ����ѯ�ܷ֣�num=2ʱ����ѯ������num=3ʱ����ѯӢ�num=4ʱ����ѯC���ԣ�

void  BubbleSort(LinkNode head, int num);	//ð������-��������
//˵����num=1ʱ����ѯ�ܷ֣�num=2ʱ����ѯ������num=3ʱ����ѯӢ�num=4ʱ����ѯC���ԣ�

void SelectSort(LinkNode head, int num);	//ѡ������-��������
//˵����num=1ʱ����ѯ�ܷ֣�num=2ʱ����ѯ������num=3ʱ����ѯӢ�num=4ʱ����ѯC���ԣ�

void ResultInquiry(LinkNode head, int a, int b, int num);	//������[a,b]�ɼ���ѯ
//˵����num=1ʱ����ѯ������num=2ʱ����ѯӢ�num=3ʱ����ѯC���ԣ�

void ReadFile(LinkNode head, char* fileName);	//�ļ�������

void WriteFile(LinkNode head, char* fileName);	//�ļ�д����

void printitle();	//��ӡ��ͷ

void printNode(LinkNode p);	//��ӡ���

void printList(LinkNode head);	//��ӡ����

#endif