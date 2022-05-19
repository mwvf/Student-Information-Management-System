#ifndef _VIEW_
#define _VIEW_
#include <stdio.h>
#include "ListOperation.h"
extern LinkNode linklist;

int JudgmentCommand();	//获取命令，判断选项

struct View
{
	void title();				//菜单标题显示
	void showmenu();			//主菜单
	void addstudent();			//学生成绩信息录入
	void deletestudent();		//学生成绩信息删除
	void editstudent();			//学生成绩信息修改
	void editlist(LinkNode p);	//修改学生的各项信息
	void inquirestudent();		//学生信息成绩查询
	void visitstudent();		//浏览班级分数情况
	void showstatistics();		//班级分数情况统计
	void scoresort();			//班级分数排序
	void showtotalscore();		//总分排序
	void showmath();			//数学成绩排序
	void showehglish();			//英语成绩排序
	void showc_language();		//C语言成绩排序
	void showrange();			//求范围成绩
	void showage();				//计算平均分
	void showpass();			//计算及格率
	void FilaSaveAs(LinkNode head);		//另存为成绩文件
};
#endif