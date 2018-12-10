#include "student.h"
#include "teacher.h"
#include "s_admini.h"


//Student stu[100]={{15041805,"abcd","尹佳怡","女",21,90,88,95,91,273,2,3,1,1,2,1}};

void change_pw(int i,int kind)
{
	char new[10];
	system("clear");
	printf("**********修改密码**********\n");
	printf("请输入修改后的新密码：");
	scanf("%s",new);
	while(6 > strlen(new) || strlen(new)>10)
	{
		printf("密码长度不符合要求！（应在6-10位）\n");
		printf("请重新输入修改后的密码：");
		scanf("%s",new);
	}
	switch(kind)
	{
		case 1:strcpy(stu[i].pw,new);break;
		case 2:strcpy(tea[i].pw,new);break;
		case 3:strcpy(adm[i].pw,new);break;
	}
}

void show_menu(void)
{
	system("clear");
	printf("**********学生成绩管理系统**********\n");
	printf("请输入用户名：");
}
int find_i(int id,char* pw)
{
	if(1 == id/10000000)
	{
		for(int i=0; i<100; i++)
		{
				if(stu[i].id == id && 0 == strcmp(pw,stu[i].pw) && stu[i].flag<3)
				{
					stu[i].flag=0;
					return i;
				}
				if(stu[i].id == id && 0 != strcmp(pw,stu[i].pw) && stu[i].flag<3)
				{
					stu[i].flag++;
					printf("密码错误！\n");
					usleep(2000000);
					return -1;
				}
				if(stu[i].id == id && stu[i].flag >= 3)
				{
					printf("账号已被锁定！无法登录！\n");
					usleep(2000000);
					return -1;
				}
				else
				{
					printf("用户名错误！\n");
					usleep(2000000);
					return -1;
				}
		}
	}
	if(2 == id/10000000)
	{
		for(int i=0; i<100; i++)
		{
				if(tea[i].id == id && 0 == strcmp(pw,tea[i].pw) && tea[i].flag<3)
				{
					tea[i].flag=0;
					return i;
				}
				if(tea[i].id == id && 0 != strcmp(pw,tea[i].pw) && tea[i].flag<3)
				{
					tea[i].flag++;
					printf("密码错误！\n");
					usleep(2000000);
					return -1;
				}
				if(tea[i].id == id && tea[i].flag >= 3)
				{
					printf("账号已被锁定！无法登录！\n");
					usleep(2000000);
					return -1;
				}
				else
				{
					printf("用户名错误！\n");
					usleep(2000000);
					return -1;
				}
		}
	}
	if(3 == id/10000000)
	{
		for(int i=0; i<10; i++)
		{
				if(adm[i].id == id && 0 == strcmp(pw,adm[i].pw) && adm[i].flag<3)
				{
					adm[i].flag=0;
					return i;
				}
				if(adm[i].id == id && 0 != strcmp(pw,adm[i].pw) && adm[i].flag<3)
				{
					adm[i].flag++;
					printf("密码错误！\n");
					usleep(2000000);
					return -1;
				}
				if(adm[i].id == id && adm[i].flag >= 3)
				{
					printf("账号已被锁定！无法登录！\n");
					usleep(2000000);
					return -1;
				}
				else
				{
					printf("用户名错误！\n");
					usleep(2000000);
					return -1;
				}
		}
	}
	if(4 == id/10000000)
	{
		if(id == s_id && 0 == strcmp(pw,s_pw))
		{
			return 1;
		}
		else
		{
			printf("用户名或密码错误！\n");
			usleep(2000000);
			return -1;
		}
	}
	else
	{
		printf("用户名或密码错误！\n");
		usleep(2000000);
		return -1;
	}

}

int show_stu(int i)
{	while(1)
	{
		system("clear");
		int n=0;
		printf("欢迎你，%s同学！\n",stu[i].name);
		printf("姓名：%s\n",stu[i].name);
		printf("成绩：\n");
		printf("语文：%.2f\n",stu[i].chinese);
		printf("数学：%.2f\n",stu[i].math);
		printf("英语：%.2f\n",stu[i].english);
		printf("总分：%.2f\n",stu[i].sum);
		printf("若要查询排名请输入数字1\n");
		printf("修改密码请输入数字2\n");
		printf("退出请输入数字3\n");
		switch(getch())
		{
			case 49:i=show_stu1(i);break;
			case 50:change_pw(i,1);return -1;
			case 51:return -1;
		}
	}
}

int show_stu1(int i)
{
	int n=0;
	system("clear");
	printf("请选择要查询的科目：\n");
	printf("1、语文\n");
	printf("2、数学\n");
	printf("3、英语\n");
	printf("4、总分\n");
	printf("===按数字0返回学生主界面===\n");
	while(1)
	{
		switch(getch())
		{
			case 49:printf("语文排名：%d\n",stu[i].c_rank);break;
			case 50:printf("数字排名：%d\n",stu[i].m_rank);break;
			case 51:printf("英语排名：%d\n",stu[i].e_rank);break;
			case 52:printf("总分排名：%d\n",stu[i].rank);break;
			case 48:return i;break;
		}
	}
}



