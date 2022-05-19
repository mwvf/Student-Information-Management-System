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
			printf("\n输入错误，请重新输入：");
			memset(choose, 0, sizeof(choose));
		}
	} while (1);
}

void View::title()	//菜单表头
{
	printf("\n\t\t\t\t教务管理系统\n");
	printf("\n==============================================================================\n");
}

void View::showmenu()	//显示菜单内容
{
	printf("   1.学生成绩信息录入\n");
	printf("   2.学生成绩信息删除\n");
	printf("   3.学生成绩信息修改\n");
	printf("   4.学生信息成绩查询\n");
	printf("   5.浏览班级分数情况\n");
	printf("   6.班级分数情况统计\n");
	printf("   7.班级分数排序\n");
	printf("   8.另存为成绩文件\n");
	printf("   0.退出本程序\n");
	printf("\n==============================================================================\n");
}

void View::addstudent()	//学生成绩信息录入，即插入学生信息至链表
{
	struct student data;
	int flag = 0;
	do {
		system("cls");
		title();
		printf("请输入学生的学号：");
		scanf("%s", data.id);
		printf("请输入学生的姓名：");
		scanf("%s", data.name);
		printf("请输入学生的性别：");
		scanf("%s", data.sex);
		printf("请输入学生的年龄：");
		scanf("%d", &data.age);
		printf("请输入学生的高数成绩：");
		scanf("%d", &data.Math);
		printf("请输入学生的英语成绩：");
		scanf("%d", &data.English);
		printf("请输入学生的C语言成绩：");
		scanf("%d", &data.C_Language);
		printf("\n==============================================================================\n");
		data.TotalScore = data.Math + data.English + data.C_Language;	//计算总分
		if (Search_id(linklist, data))
		{
			printf("检测到存在相同学号的同学信息，是否还要录入该同学信息？y/n：");
			if (sure())
			{
				InsertNode(linklist, data);
				printitle();
				printf("%2d\t", 1);
				printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n\n", data.id, data.name, data.sex, data.age, data.Math, data.English, data.C_Language, data.TotalScore);
				printf("添加完毕，是否需要继续添加？y/n：");
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
			printf("添加完毕，是否需要继续添加？y/n：");
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

void View::deletestudent()	//学生成绩信息删除
{
	system("cls");
	LinkNode p = NULL;
	title();
	printf("1.按学号查询需要删除的人\n");
	printf("2.按姓名查询需要删除的人\n");
	printf("0.返回主菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			char id[20];
			printf("请输入学号：");
			scanf("%s", id);
			p = SearchNode_id(linklist, id);
			if (p == NULL)
				printf("未查到该学生\n");
			else
			{
				printf("查询结果如下：\n");
				printitle();
				printf("%2d\t", 1);
				printNode(p);
				printf("是否需要删除该同学？y/n：");
				if (sure())
				{
					DeleteNode_id(linklist, id);
					printf("删除成功！\n");
				}
			}
			choice = 0;
			system("pause");
			system("cls");
			deletestudent();
			break;
		case 2:
			char name[20];
			printf("请输入姓名：");
			scanf("%s", name);
			p = SearchNode_name(linklist, name);
			if (p == NULL)
				printf("未查到该学生\n");
			else
			{
				printf("查询结果如下：\n");
				printitle();
				printf("%2d\t", 1);
				printNode(p);
				printf("是否需要删除该同学？y/n：");
				if (sure())
				{
					DeleteNode_name(linklist, name);
					printf("删除成功！\n");
				}
			}
			choice = 0;
			system("pause");
			system("cls");
			deletestudent();
			break;
		default:
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
	}
	system("cls");
	title();
	showmenu();
}

//修改学生的各项信息
void View::editlist(LinkNode p)
{
	system("cls");
	title();
	printf("1.修改学号\n");
	printf("2.修改姓名\n");
	printf("3.修改性别\n");
	printf("4.修改年龄\n");
	printf("5.修改高数成绩\n");
	printf("6.修改英语成绩\n");
	printf("7.修改C语言成绩\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			printf("请输入需要修改的学号：");
			char id[20];
			scanf("%s", id);
			strcpy(p->data.id, id);
			printf("修改成功！\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 2:
		{
			printf("请输入需要修改的姓名：");
			char name[20];
			scanf("%s", name);
			strcpy(p->data.id, name);
			printf("修改成功！\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 3:
		{
			printf("请输入需要修改的性别：");
			char sex[5];
			scanf("%s", sex);
			strcpy(p->data.sex, sex);
			printf("修改成功！\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 4:
		{
			printf("请输入需要修改的年龄：");
			int age = 0;
			scanf("%d", &age);
			p->data.age = age;
			printf("修改成功！\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 5:
		{
			printf("请输入需要修改的高数成绩：");
			int Math = 0;
			scanf("%d", &Math);
			p->data.Math = Math;
			printf("修改成功！\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;

		}
		case 6:
		{
			printf("请输入需要修改的英语成绩：");
			int English = 0;
			scanf("%d", &English);
			p->data.English = English;
			printf("修改成功！\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		case 7:
		{
			printf("请输入需要修改的C语言成绩：");
			int C_Language = 0;
			scanf("%d", &C_Language);
			p->data.C_Language = C_Language;
			printf("修改成功！\n");
			choice = 0;
			system("pause");
			system("cls");
			editlist(p);
			break;
		}
		default:
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
	}
}

//学生成绩信息修改
void View::editstudent()	//学生成绩信息修改
{
	system("cls");
	LinkNode p = NULL;
	title();
	printf("1.按学号查询需要修改的人\n");
	printf("2.按姓名查询需要修改的人\n");
	printf("0.返回主菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			char id[20];
			printf("请输入学号：");
			scanf("%s", id);
			p = SearchNode_id(linklist, id);
			if (p == NULL)
				printf("未查到该学生\n");
			else
			{
				printf("查询结果如下：\n");
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
			printf("请输入学号：");
			scanf("%s", name);
			p = SearchNode_name(linklist, name);
			if (p == NULL)
				printf("未查到该学生\n");
			else
			{
				printf("查询结果如下：\n");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
	}
	system("cls");
	title();
	showmenu();
}

void View::showrange()	//求范围成绩
{
	system("cls");
	LinkNode p = NULL;
	title();
	printf("1.查询高数成绩\n");
	printf("2.查询英语成绩\n");
	printf("3.查询C语言成绩\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
	int choice = JudgmentCommand();
	int a = 0, b = 0;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			printf("请输入分数段（如60 80）：");
			scanf("%d%d", &a, &b);
			ResultInquiry(linklist, a, b, 1);	//num=1，分数段[a,b]高数查询
			system("pause");
			choice = 0;
			system("cls");
			showrange();
			break;
		}
		case 2:
		{
			printf("请输入分数段（如60 80）：");
			scanf("%d%d", &a, &b);
			ResultInquiry(linklist, a, b, 2);	//num=1，分数段[a,b]高数查询
			system("pause");
			choice = 0;
			system("cls");
			showrange();
			break;
		}
		case 3:
		{
			printf("请输入分数段（如60 80）：");
			scanf("%d%d", &a, &b);
			ResultInquiry(linklist, a, b, 3);	//num=1，分数段[a,b]C语言查询
			system("pause");
			choice = 0;
			system("cls");
			showrange();
			break;
		}
		default:
		{
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
}

//学生信息成绩查询
void View::inquirestudent()
{
	LinkNode p = NULL;
	system("cls");
	title();
	printf("1.按学号查询\n");
	printf("2.按姓名查询\n");
	printf("0.返回主菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			char id[20];
			printf("请输入学号：");
			scanf("%s", id);
			p = SearchNode_id(linklist, id);
			if (p == NULL)
				printf("未查到该学生\n");
			else
			{
				printf("查询结果如下：\n");
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
			printf("请输入姓名：");
			scanf("%s", name);
			p = SearchNode_name(linklist, name);
			if (p == NULL)
				printf("未查到该学生\n");
			else
			{
				printf("查询结果如下：\n");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
	system("cls");
	title();
	showmenu();
}

void View::visitstudent()	//浏览班级分数情况
{
	system("cls");
	title();
	printList(linklist);
	system("pause");
	system("cls");
	title();
	showmenu();
}

void View::showage()	//班级分数情况统计-计算平均分
{
	system("cls");
	title();
	printf("1.总分平均分\n");
	printf("2.高数平均分\n");
	printf("3.英语平均分\n");
	printf("4.C语言平均分\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			double sum = CalculateAverage(linklist, 1);
			printf("总分平均分：%0.2lf\n", sum);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		case 2:
		{
			double Math = CalculateAverage(linklist, 2);
			printf("高数平均分：%0.2lf\n", Math);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		case 3:
		{
			double English = CalculateAverage(linklist, 3);
			printf("英语平均分：%0.2lf\n", English);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		case 4:
		{
			double C_Language = CalculateAverage(linklist, 4);
			printf("C语言平均分：%0.2lf\n", C_Language);
			choice = 0;
			system("pause");
			system("cls");
			showage();
			break;
		}
		default:
		{
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
}

//计算及格率
void View::showpass()
{
	system("cls");
	title();
	printf("1.高数及格率\n");
	printf("2.英语及格率\n");
	printf("3.C语言及格率\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
	int choice = JudgmentCommand();
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			double Math = CalculatePassRate(linklist, 1);
			printf("高数及格率：%0.2lf%%\n", Math);
			choice = 0;
			system("pause");
			system("cls");
			showpass();
			break;
		}
		case 2:
		{
			double English = CalculatePassRate(linklist, 2);
			printf("英语及格率：%0.2lf%%\n", English);
			choice = 0;
			system("pause");
			system("cls");
			showpass();
			break;
		}
		case 3:
		{
			double C_Language = CalculatePassRate(linklist, 3);
			printf("C语言及格率：%0.2lf%%\n", C_Language);
			choice = 0;
			system("pause");
			system("cls");
			showpass();
			break;
		}
		default:
		{
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
}

void View::showstatistics()	//班级分数情况统计
{
	system("cls");
	title();
	printf("1.查询平均分\n");
	printf("2.查询及格率\n");
	printf("3.按分数段-课程名查询\n");
	printf("0.返回主菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
	system("cls");
	title();
	showmenu();
}

//总分排序
void View::showtotalscore()
{
	system("cls");
	title();
	printf("1.升序排列\n");
	printf("2.降序排列\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
}

void View::showmath()
{
	system("cls");
	title();
	printf("1.升序排列\n");
	printf("2.降序排列\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
}

//英语成绩排序
void View::showehglish()
{
	system("cls");
	title();
	printf("1.升序排列\n");
	printf("2.降序排列\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
}

//C语言成绩排序
void View::showc_language()
{
	system("cls");
	title();
	printf("1.升序排列\n");
	printf("2.降序排列\n");
	printf("0.返回上一级菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
}

//班级分数排序
void View::scoresort()
{
	system("cls");
	title();
	printf("1.总成绩排序\n");
	printf("2.高数成绩排序\n");
	printf("3.英语成绩排序\n");
	printf("4.C语言成绩排序\n");
	printf("0.返回主菜单\n");
	printf("\n==============================================================================\n");
	printf("请输入指令的序号：");
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
			printf("输入错误，请重新输入：");
			choice = JudgmentCommand();
		}
		}
	}
	system("cls");
	title();
	showmenu();
}

//另存为成绩文件
void View::FilaSaveAs(LinkNode head)
{
	system("cls");
	char path_SaveAs[100];
	printf("请输入保存路径(例如：D:\\1.txt)：\n");
	scanf("%s", path_SaveAs);
	WriteFile(head, path_SaveAs);
	system("pause");
	system("cls");
	title();
	showmenu();
}

//获取命令，判断选项
int JudgmentCommand()
{
	/*
		虽然C库函数int atoi(const char *str)可以把字符串转换为整数
		但是存在漏洞
		"1"->1		"1mm"->1
		虽然上述两个字符串都可以转换成整数1，显然"1mm"并不是合理的命令输入结果
		故考虑编写一个菜单命令函数int JudgmentCommand();进行判断
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