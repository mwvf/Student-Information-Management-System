#ifndef _VIEW_
#define _VIEW_
#include <stdio.h>
#include "ListOperation.h"
extern LinkNode linklist;

int JudgmentCommand();	//��ȡ����ж�ѡ��

struct View
{
	void title();				//�˵�������ʾ
	void showmenu();			//���˵�
	void addstudent();			//ѧ���ɼ���Ϣ¼��
	void deletestudent();		//ѧ���ɼ���Ϣɾ��
	void editstudent();			//ѧ���ɼ���Ϣ�޸�
	void editlist(LinkNode p);	//�޸�ѧ���ĸ�����Ϣ
	void inquirestudent();		//ѧ����Ϣ�ɼ���ѯ
	void visitstudent();		//����༶�������
	void showstatistics();		//�༶�������ͳ��
	void scoresort();			//�༶��������
	void showtotalscore();		//�ܷ�����
	void showmath();			//��ѧ�ɼ�����
	void showehglish();			//Ӣ��ɼ�����
	void showc_language();		//C���Գɼ�����
	void showrange();			//��Χ�ɼ�
	void showage();				//����ƽ����
	void showpass();			//���㼰����
	void FilaSaveAs(LinkNode head);		//���Ϊ�ɼ��ļ�
};
#endif