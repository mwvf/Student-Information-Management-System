#define  _CRT_SECURE_NO_WARNINGS
#include "Student.h"

bool sure()
{
	char choose[10] = "0";
	char y[2] = "y", Y[2] = "Y", n[2] = "n", N[2] = "N";
	do {
		scanf("%s", &choose);
		if (strcmp(choose, y) == 0 || strcmp(choose, Y) == 0) return 1;
		else if (strcmp(choose, n) == 0 || strcmp(choose, N) == 0) return 0;
		else
		{
			printf("\n����������������룺");
			memset(choose, 0, sizeof(choose));
		}
	} while (1);
}

void View::title()	//�˵���ͷ
{
	printf("\n\t\t\t\t�������ϵͳ\n");
	printf("\n==============================================================================\n");
}

void View::showmenu()	//��ʾ�˵�����
{
	printf("   1.ѧ���ɼ���Ϣ¼��\n");
	printf("   2.ѧ���ɼ���Ϣɾ��\n");
	printf("   3.ѧ���ɼ���Ϣ�޸�\n");
	printf("   4.ѧ����Ϣ�ɼ���ѯ\n");
	printf("   5.����༶�������\n");
	printf("   6.�༶�������ͳ��\n");
	printf("   7.�༶��������\n");
	printf("   8.���Ϊ�ɼ��ļ�\n");
	printf("   0.�˳�������\n");
	printf("\n==============================================================================\n");
}

void View::addstudent()	//ѧ���ɼ���Ϣ¼�룬������ѧ����Ϣ������
{
	struct student data;
	int flag = 0;
	do {
		system("cls");
		title();
		printf("������ѧ����ѧ�ţ�");
		scanf("%s", data.id);
		printf("������ѧ����������");
		scanf("%s", data.name);
		printf("������ѧ�����Ա�");
		scanf("%s", data.sex);
		printf("������ѧ�������䣺");
		scanf("%d", &data.age);
		printf("������ѧ���ĸ����ɼ���");
		scanf("%d", &data.Math);
		printf("������ѧ����Ӣ��ɼ���");
		scanf("%d", &data.English);
		printf("������ѧ����C���Գɼ���");
		scanf("%d", &data.C_Language);
		printf("\n==============================================================================\n");
		data.TotalScore = data.Math + data.English + data.C_Language;	//�����ܷ�
		if (Search_id(linklist, data))
		{
			printf("��⵽������ͬѧ�ŵ�ͬѧ��Ϣ���Ƿ�Ҫ¼���ͬѧ��Ϣ��y/n��");
			if (sure())
			{
				InsertNode(linklist, data);
				printitle();
				printf("%2d\t", 1);
				printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n\n", data.id, data.name, data.sex, data.age, data.Math, data.English, data.C_Language, data.TotalScore);
				printf("�����ϣ��Ƿ���Ҫ������ӣ�y/n��");
				if (sure())
					flag = 1;
				else
					flag = 0;
			}
			else
				flag = 0;
		}
		else
		{
			InsertNode(linklist, data);
			printitle();
			printf("%2d\t", 1);
			printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n\n", data.id, data.name, data.sex, data.age, data.Math, data.English, data.C_Language, data.TotalScore);
			printf("�����ϣ��Ƿ���Ҫ������ӣ�y/n��");
			if (sure())
				flag = 1;
			else
				flag = 0;
		}
	} while (flag);
	system("cls");
	title();
	showmenu();
}

void View::deletestudent()	//ѧ���ɼ���Ϣɾ��
{
	system("cls");
	LinkNode p = NULL;
	title();
	printf("1.��ѧ�Ų�ѯ��Ҫɾ������\n");
	printf("2.��������ѯ��Ҫɾ������\n");
	printf("0.�������˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			char id[20];
			printf("������ѧ�ţ�");
			scanf("%s", id);
			p = SearchNode_id(linklist, id);
			if (p == NULL)
				printf("δ�鵽��ѧ��\n");
			else
			{
				printf("��ѯ������£�\n");
				printitle();
				printf("%2d\t", 1);
				printNode(p);
				printf("�Ƿ���Ҫɾ����ͬѧ��y/n��");
				if (sure())
				{
					DeleteNode_id(linklist, id);
					printf("ɾ���ɹ���\n");
				}
			}
			choice = 0;
			system("pause");
			system("cls");
			deletestudent();
			break;
		case 2:
			char name[20];
			printf("������������");
			scanf("%s", name);
			p = SearchNode_name(linklist, name);
			if (p == NULL)
				printf("δ�鵽��ѧ��\n");
			else
			{
				printf("��ѯ������£�\n");
				printitle();
				printf("%2d\t", 1);
				printNode(p);
				printf("�Ƿ���Ҫɾ����ͬѧ��y/n��");
				if (sure())
				{
					DeleteNode_name(linklist, name);
					printf("ɾ���ɹ���\n");
				}
			}
			choice = 0;
			system("pause");
			system("cls");
			deletestudent();
			break;
		default:
			printf("����������������룺");
			choice = JudgmentCommand();
		}
	}
	system("cls");
	title();
	showmenu();
}

//�޸�ѧ���ĸ�����Ϣ
void View::editlist(LinkNode p)
{
	system("cls");
	title();
	printf("1.�޸�ѧ��\n");
	printf("2.�޸�����\n");
	printf("3.�޸��Ա�\n");
	printf("4.�޸�����\n");
	printf("5.�޸ĸ����ɼ�\n");
	printf("6.�޸�Ӣ��ɼ�\n");
	printf("7.�޸�C���Գɼ�\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			printf("��������Ҫ�޸ĵ�ѧ�ţ�");
			char id[20];
			scanf("%s", id);
			strcpy(p->data.id, id);
			printf("�޸ĳɹ���\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 2:
		{
			printf("��������Ҫ�޸ĵ�������");
			char name[20];
			scanf("%s", name);
			strcpy(p->data.id, name);
			printf("�޸ĳɹ���\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 3:
		{
			printf("��������Ҫ�޸ĵ��Ա�");
			char sex[5];
			scanf("%s", sex);
			strcpy(p->data.sex, sex);
			printf("�޸ĳɹ���\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 4:
		{
			printf("��������Ҫ�޸ĵ����䣺");
			int age = 0;
			scanf("%d", &age);
			p->data.age = age;
			printf("�޸ĳɹ���\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 5:
		{
			printf("��������Ҫ�޸ĵĸ����ɼ���");
			int Math = 0;
			scanf("%d", &Math);
			p->data.Math = Math;
			printf("�޸ĳɹ���\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;

		}
		case 6:
		{
			printf("��������Ҫ�޸ĵ�Ӣ��ɼ���");
			int English = 0;
			scanf("%d", &English);
			p->data.English = English;
			printf("�޸ĳɹ���\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 7:
		{
			printf("��������Ҫ�޸ĵ�C���Գɼ���");
			int C_Language = 0;
			scanf("%d", &C_Language);
			p->data.C_Language = C_Language;
			printf("�޸ĳɹ���\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		default:
			printf("����������������룺");
			choice = JudgmentCommand();
		}
	}
}

//ѧ���ɼ���Ϣ�޸�
void View::editstudent()	//ѧ���ɼ���Ϣ�޸�
{
	system("cls");
	LinkNode p = NULL;
	title();
	printf("1.��ѧ�Ų�ѯ��Ҫ�޸ĵ���\n");
	printf("2.��������ѯ��Ҫ�޸ĵ���\n");
	printf("0.�������˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			char id[20];
			printf("������ѧ�ţ�");
			scanf("%s", id);
			p = SearchNode_id(linklist, id);
			if (p == NULL)
				printf("δ�鵽��ѧ��\n");
			else
			{
				printf("��ѯ������£�\n");
				printitle();
				printf("%2d\t ", 1);
				printNode(p);
				system("pause");
				editlist(p);
			}
			choice = 0;
			system("cls");
			editstudent();
			break;
		case 2:
			char name[20];
			printf("������ѧ�ţ�");
			scanf("%s", name);
			p = SearchNode_name(linklist, name);
			if (p == NULL)
				printf("δ�鵽��ѧ��\n");
			else
			{
				printf("��ѯ������£�\n");
				printitle();
				printf("%2d\t ", 1);
				printNode(p);
				system("pause");
				editlist(p);
			}
			choice = 0;
			system("cls");
			editstudent();
			break;
		default:
			printf("����������������룺");
			choice = JudgmentCommand();
		}
	}
	system("cls");
	title();
	showmenu();
}

void View::showrange()	//��Χ�ɼ�
{
	system("cls");
	LinkNode p = NULL;
	title();
	printf("1.��ѯ�����ɼ�\n");
	printf("2.��ѯӢ��ɼ�\n");
	printf("3.��ѯC���Գɼ�\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	int a = 0, b = 0;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			printf("����������Σ���60 80����");
			scanf("%d%d", &a, &b);
			ResultInquiry(linklist, a, b, 1);	//num=1��������[a,b]������ѯ
			system("pause");
			choice = 0;
			system("cls");
			showrange();
			break;
		}
		case 2:
		{
			printf("����������Σ���60 80����");
			scanf("%d%d", &a, &b);
			ResultInquiry(linklist, a, b, 2);	//num=1��������[a,b]������ѯ
			system("pause");
			choice = 0;
			system("cls");
			showrange();
			break;
		}
		case 3:
		{
			printf("����������Σ���60 80����");
			scanf("%d%d", &a, &b);
			ResultInquiry(linklist, a, b, 3);	//num=1��������[a,b]C���Բ�ѯ
			system("pause");
			choice = 0;
			system("cls");
			showrange();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
}

//ѧ����Ϣ�ɼ���ѯ
void View::inquirestudent()
{
	LinkNode p = NULL;
	system("cls");
	title();
	printf("1.��ѧ�Ų�ѯ\n");
	printf("2.��������ѯ\n");
	printf("0.�������˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			char id[20];
			printf("������ѧ�ţ�");
			scanf("%s", id);
			p = SearchNode_id(linklist, id);
			if (p == NULL)
				printf("δ�鵽��ѧ��\n");
			else
			{
				printf("��ѯ������£�\n");
				printitle();
				printf("%2d\t ", 1);
				printNode(p);
			}
			choice = 0;
			system("pause");
			system("cls");
			inquirestudent();
			break;
		}
		case 2:
		{
			char name[20];
			printf("������������");
			scanf("%s", name);
			p = SearchNode_name(linklist, name);
			if (p == NULL)
				printf("δ�鵽��ѧ��\n");
			else
			{
				printf("��ѯ������£�\n");
				printitle();
				printf("%2d\t ", 1);
				printNode(p);
			}
			choice = 0;
			system("pause");
			system("cls");
			inquirestudent();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
	system("cls");
	title();
	showmenu();
}

void View::visitstudent()	//����༶�������
{
	system("cls");
	title();
	printList(linklist);
	system("pause");
	system("cls");
	title();
	showmenu();
}

void View::showage()	//�༶�������ͳ��-����ƽ����
{
	system("cls");
	title();
	printf("1.�ܷ�ƽ����\n");
	printf("2.����ƽ����\n");
	printf("3.Ӣ��ƽ����\n");
	printf("4.C����ƽ����\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			double sum = CalculateAverage(linklist, 1);
			printf("�ܷ�ƽ���֣�%0.2lf\n", sum);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		case 2:
		{
			double Math = CalculateAverage(linklist, 2);
			printf("����ƽ���֣�%0.2lf\n", Math);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		case 3:
		{
			double English = CalculateAverage(linklist, 3);
			printf("Ӣ��ƽ���֣�%0.2lf\n", English);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		case 4:
		{
			double C_Language = CalculateAverage(linklist, 4);
			printf("C����ƽ���֣�%0.2lf\n", C_Language);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
}

//���㼰����
void View::showpass()
{
	system("cls");
	title();
	printf("1.����������\n");
	printf("2.Ӣ�Ｐ����\n");
	printf("3.C���Լ�����\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			double Math = CalculatePassRate(linklist, 1);
			printf("���������ʣ�%0.2lf%%\n", Math);
			choice = 0;
			system("pause");
			system("cls");
			showpass();
			break;
		}
		case 2:
		{
			double English = CalculatePassRate(linklist, 2);
			printf("Ӣ�Ｐ���ʣ�%0.2lf%%\n", English);
			choice = 0;
			system("pause");
			system("cls");
			showpass();
			break;
		}
		case 3:
		{
			double C_Language = CalculatePassRate(linklist, 3);
			printf("C���Լ����ʣ�%0.2lf%%\n", C_Language);
			choice = 0;
			system("pause");
			system("cls");
			showpass();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
}

void View::showstatistics()	//�༶�������ͳ��
{
	system("cls");
	title();
	printf("1.��ѯƽ����\n");
	printf("2.��ѯ������\n");
	printf("3.��������-�γ�����ѯ\n");
	printf("0.�������˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			showage();
			choice = 0;
			system("cls");
			showstatistics();
			break;
		}
		case 2:
		{
			showpass();
			choice = 0;
			system("cls");
			showstatistics();
			break;
		}
		case 3:
		{
			showrange();
			choice = 0;
			system("cls");
			showstatistics();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
	system("cls");
	title();
	showmenu();
}

//�ܷ�����
void View::showtotalscore()
{
	system("cls");
	title();
	printf("1.��������\n");
	printf("2.��������\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			SelectSort(linklist, 1);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showtotalscore();
			break;
		}
		case 2:
		{
			BubbleSort(linklist, 1);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showtotalscore();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
}

void View::showmath()
{
	system("cls");
	title();
	printf("1.��������\n");
	printf("2.��������\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			SelectSort(linklist, 2);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showmath();
			break;
		}
		case 2:
		{
			BubbleSort(linklist, 2);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showmath();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
}

//Ӣ��ɼ�����
void View::showehglish()
{
	system("cls");
	title();
	printf("1.��������\n");
	printf("2.��������\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			SelectSort(linklist, 3);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showehglish();
			break;
		}
		case 2:
		{
			BubbleSort(linklist, 3);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showehglish();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
}

//C���Գɼ�����
void View::showc_language()
{
	system("cls");
	title();
	printf("1.��������\n");
	printf("2.��������\n");
	printf("0.������һ���˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			SelectSort(linklist, 4);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showc_language();
			break;
		}
		case 2:
		{
			BubbleSort(linklist, 4);
			printList(linklist);
			choice = 0;
			system("pause");
			system("cls");
			showc_language();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
}

//�༶��������
void View::scoresort()
{
	system("cls");
	title();
	printf("1.�ܳɼ�����\n");
	printf("2.�����ɼ�����\n");
	printf("3.Ӣ��ɼ�����\n");
	printf("4.C���Գɼ�����\n");
	printf("0.�������˵�\n");
	printf("\n==============================================================================\n");
	printf("������ָ�����ţ�");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			showtotalscore();
			choice = 0;
			system("cls");
			scoresort();
			break;
		}
		case 2:
		{
			showmath();
			choice = 0;
			system("cls");
			scoresort();
			break;
		}
		case 3:
		{
			showehglish();
			choice = 0;
			system("cls");
			scoresort();
			break;
		}
		case 4:
		{
			showc_language();
			choice = 0;
			system("cls");
			scoresort();
			break;
		}
		default:
		{
			printf("����������������룺");
			choice = JudgmentCommand();
		}
		}
	}
	system("cls");
	title();
	showmenu();
}

//���Ϊ�ɼ��ļ�
void View::FilaSaveAs(LinkNode head)
{
	system("cls");
	char path_SaveAs[100];
	printf("�����뱣��·��(���磺D:\\1.txt)��\n");
	scanf("%s", path_SaveAs);
	WriteFile(head, path_SaveAs);
	system("pause");
	system("cls");
	title();
	showmenu();
}

//��ȡ����ж�ѡ��
int JudgmentCommand()
{
	/*
		��ȻC�⺯��int atoi(const char *str)���԰��ַ���ת��Ϊ����
		���Ǵ���©��
		"1"->1		"1mm"->1
		��Ȼ���������ַ���������ת��������1����Ȼ"1mm"�����Ǻ��������������
		�ʿ��Ǳ�дһ���˵������int JudgmentCommand();�����ж�
	*/
	int num = -1;
	char a[] = "0", b[] = "1", c[] = "2", d[] = "3", e[] = "4";
	char f[] = "5", g[] = "6", h[] = "7", i[] = "8";
	char choose[100] = "\0";
	scanf("%s", choose);
	if (strcmp(a, choose) == 0) num = 0;
	else if (strcmp(b, choose) == 0) num = 1;
	else if (strcmp(c, choose) == 0) num = 2;
	else if (strcmp(d, choose) == 0) num = 3;
	else if (strcmp(e, choose) == 0) num = 4;
	else if (strcmp(f, choose) == 0) num = 5;
	else if (strcmp(g, choose) == 0) num = 6;
	else if (strcmp(h, choose) == 0) num = 7;
	else if (strcmp(i, choose) == 0) num = 8;
	else num = -1;
	return num;
}