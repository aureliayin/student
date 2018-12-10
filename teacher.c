#include "teacher.h"
#include "student.h"
int count_tea = 1;
int count_stu = 1;
//int tea_id_start = 25102030;
int stu_id_start = 12345678;


Student stu[100]={{12345678,"123","张三","男",30,1992,50,50,50,50,150,1,1,1,1,-1,1}};
int show_tea(void)
{
	char arr[3];
	int n=0;
	while(n == 0)
	{
		system("clear");
		printf("****教师欢迎你****\n");
		printf("1.学生信息管理\n");
		printf("2.学生成绩管理\n");
		printf("3.修改登录密码\n");
		printf("4.退出登录\n");
		n=get_key_1();
	}
	return -1;
}
void back_4_3_2(void)
{
	printf("＊＊＊按任意键返回上一级菜单＊＊＊\n");
	getch();
	show_grade();
}
void back_3_3_2(void)
{
	printf("＊＊＊按任意键返回上一级菜单＊＊＊\n");
	getch();
	show_tea();
}
void back_1_3_2(void)
{
	printf("＊＊＊按任意键返回上一级菜单＊＊＊\n");
	getch();
	show_tea1();
}

void back_2_3_2(void)
{
	printf("＊＊＊按任意键返回上一级菜单＊＊＊\n");
	getch();
	show_tea2();
}
int get_key_1(void)
{
	switch(getch())
	{
		case 49:show_tea1();break;
		case 50:show_tea2();break;
		case 51:change_pp();break;
		case 52:return -1;
	}
}
void change_pp(void)
{
	system("clear");
	printf("＊＊＊修改密码＊＊＊\n");
	int id=0;
	char pw1[20];
	printf("请老师输入用户名：");
	scanf("%d",&id);
	getchar();
	int count1=0;
	if(find_id_tea(id) != -1)
	{
		int index=find_id_tea(id);
		while(1)
		{
			printf("请输入原密码:");
			gets(pw1);
			if(strcmp(pw1,tea[index].pw) == 0)
			{
				while(1)
				{
					printf("请输入新密码：");
					gets(pw1);
					if(strlen(pw1)<6 || strlen(pw1)>10)
					{
						printf("密码不符合要求！\n");
					}
					else
					{
						strcpy(tea[index].pw,pw1);
						printf("密码修改成功！\n");
						break;
					}
				}
				break;
			}
			else
			{
				count1++;
				printf("原密码输入错误%d次！\n",count1);
			}
			if(count1>=3)
			{
				printf("错误次数过多,退出！\n");
				break;
			}
		}
	}
	else
	{
		printf("此用户不存在！\n");
	}
	back_3_3_2();
}
void get_key_3(void)
{
	switch(getch())
	{
		case 49:tea_add_stu();break;
		case 50:tea_del_stu();break;
		case 51:tea_ch_stu();break;
		case 52:tea_def_stu();break;
		case 53:tea_unlock_stu();break;
		case 54:tea_sou_mess();break;
		case 55:show_all_stu();break;
		case 56:show_back_stu();break;
		case 57:show_tea();break;
		default:show_tea();break;
	}
}

int find_id_tea(int id)
{
	for(int i=0;i<100;i++)
	{
		if(tea[i].id == id && tea[i].back != 0)
		{
			return i;
		}
	}
	return -1;
}
int find_id_stu(int id)
{
	for(int i=0;i<100;i++)
	{
		if(stu[i].id == id && stu[i].back != 0)
		{
			return i;
		}
	}
	return -1;
}
char* find_name_stu(char* str1,char* str2)
{
	int start = 0;
	for(int i=0;i<100;i++)
	{
		if(strcmp(stu[i].name,str1)==0)
		{
			str2[start++]=i+'0';
		}
	}
	str2[start]='\0';
	return str2;
}
void show_tea1(void)
{
	system("clear");
	printf("＊＊＊学生信息管理＊＊＊\n");
	printf("1.添加学生\n");
	printf("2.删除学生\n");
	printf("3.修改学生基本信息\n");
	printf("4.重置学生密码\n");
	printf("5.解锁学生账号\n");
	printf("6.查询学生基本信息\n");
	printf("7.显示在读学生\n");
	printf("8.显示退学学生\n");
	printf("9.返回上一级菜单\n");
	get_key_3();
}
void show_tea2(void)
{
	
	system("clear");
	printf("＊＊＊学生成绩管理＊＊＊\n");
	printf("1.录入学生成绩\n");
	printf("2.修改学生成绩\n");
	printf("3.查询学生成绩\n");
	printf("4.显示成绩排名\n");
	printf("5.返回上一级菜单\n");
	get_key_4();
}
void show_grade(void)
{
	system("clear");
	printf("＊＊＊成绩排名＊＊＊\n");
	printf("1.总分排名\n");
	printf("2.语文排名\n");
	printf("3.数学排名\n");
	printf("4.英文排名\n");
	printf("5.平均排名\n");
	printf("6.返回上一级菜单\n");
	get_key_5();
}
void get_key_5(void)
{
	switch(getch())
	{
		case 49:rank_grade(0);break;
		case 50:rank_grade(1);break;
		case 51:rank_grade(2);break;
		case 52:rank_grade(3);break;
		case 53:rank_grade(4);break;
		case 54:show_tea2();break;
		default:show_tea2();break;
	}
}
void get_key_4(void)
{
	switch(getch())
	{
		case 49:import_grade();break;
		case 50:change_grade();break;
		case 51:search_grade();break;
		case 52:show_grade();break;
		case 53:show_tea();break;
		default:show_tea();break;
	}
}
//导入成绩
void import_grade(void)
{
	system("clear");
	printf("＊＊＊成绩录入＊＊＊\n");
	int num = 0;
	printf("请选择单个录入或导入文件(1/0)：");
	scanf("%d",&num);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(0 == num)
	{
		FILE *frp=fopen("学生信息.txt","r");
		for(int i=0;i<6;i++)
		{
			char name2[20]={};
			int id2 = 0;
			char laji[10];
			int la=0;
			
			fscanf(frp,"%d%s%s%d",&id2,name2,laji,&la);
			int index=find_id_stu(id2);	
			fscanf(frp,"%f%f%f",&stu[index].chinese,&stu[index].math,&stu[index].english);
			stu[index].sum=(stu[index].chinese+stu[index].math+stu[index].english);
			stu[index].ave=stu[index].sum/3;
		}
		printf("添加成绩完成！\n");
	}
	else
	{
		int id2=0;
		printf("请输入学号：");
		scanf("%d",&id2);
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		int index=find_id_stu(id2);
		if(find_id_stu(id2) != -1)
		{
			printf("请输入语文数学英语三科成绩：");
			scanf("%f%f%f",&stu[index].chinese,&stu[index].math,&stu[index].english);
			getchar();
			stu[index].sum=(stu[index].chinese+stu[index].math+stu[index].english);
			stu[index].ave=stu[index].sum/3;
			printf("添加成绩完成！\n");
		}
		else
		{
			printf("此人不存在！\n");
		}
	}	
	back_2_3_2();
}
//修改成绩
void change_grade(void)
{
	system("clear");
	printf("＊＊＊修改成绩＊＊＊\n");
	int id2;
	printf("请输入学生学号：");
	scanf("%d",&id2);
	getchar();
	int index=find_id_stu(id2);
	if(find_id_stu(id2) == -1)
	{
		printf("此人不存在!\n");
	}
	else if(stu[index].back == 0)
	{
		printf("此人已被退学！\n");
	}
	else
	{
		int num = 0;
		printf("是否要修改语文成绩？(1/0)\n");
		scanf("%d",&num);
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		if(1 == num)
		{
			printf("请输入语文成绩：");
			scanf("%f",&stu[index].chinese);
			getchar();
			printf("修改语文成绩成功！\n");
		}
		printf("是否要修改数学成绩？(1/0)\n");
		scanf("%d",&num);
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		if(1 == num)
		{
			printf("请输入数学成绩：");
			scanf("%f",&stu[index].math);
			printf("修改数学成绩成功！\n");
		}
		printf("是否要修改英语成绩？(1/0)\n");
		scanf("%d",&num);
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		if(1 == num)
		{
			printf("请输入英语成绩：");
			scanf("%f",&stu[index].english);
			getchar();
			printf("修改英语成绩成功！\n");
		}
		stu[index].sum=stu[index].chinese+stu[index].math+stu[index].english;
		stu[index].ave=stu[index].sum/3;
		stu[index].rank=all_rank(stu[index].id,stu[index].sum,0);
		
	}
	back_2_3_2();
}
//根据学号或姓名查询学生成绩
void search_grade(void)
{
	system("clear");
	printf("＊＊＊成绩查询＊＊＊\n");
	char name2[20]={};
	char arr[count_stu+1];
	int num = 0;
	int id2 = 0;
	printf("请选择学号或姓名查询(1/0):");
	scanf("%d",&num);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(1 == num)
	{
		printf("请输入学号：");
		scanf("%d",&id2);
		int index=find_id_stu(id2);
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		if(index == -1 || stu[index].back == 0)
		{
			printf("此人不存在或已被退学！\n");
		}
		else
		{
			system("clear");
			printf("排名\t学号\t\t姓名\t语文\t数学\t英语\t平均分\t总分\n");
			printf("%d\t%d\t%s\t%g\t%g\t%g\t%g\t%g\n",all_rank(stu[index].id,stu[index].sum,0),stu[index].id,stu[index].name,stu[index].chinese,stu[index].math,stu[index].english,stu[index].ave,stu[index].sum);
		}
	}
	else if(0 == num)
	{
		printf("请输入姓名：");
		gets(name2);
		char* index = find_name_stu(name2,arr);
		if(strlen(find_name_stu(name2,arr)) == 0)
		{
			printf("不存在此人！\n");
		}
		else
		{
			system("clear");
			printf("排名\t学号\t\t姓名\t语文\t数学\t英语\t平均分\t总分\n");
			for(int i=0;arr[i];i++)
			{
				printf("%d\t%d\t%s\t%g\t%g\t%g\t%g\t%g\n",all_rank(stu[*(index+i)-'0'].id,stu[*(index+i)-'0'].sum,0),stu[*(index+i)-'0'].id,stu[*(index+i)-'0'].name,stu[*(index+i)-'0'].chinese,stu[*(index+i)-'0'].math,stu[*(index+i)-'0'].english,stu[*(index+i)-'0'].ave,stu[*(index+i)-'0'].sum);
			}
		}
	}
	back_2_3_2();
}
//总分排名
void rank_grade(char index)
{
	system("clear");
	int erank = 1;
	switch(index)
	{
		case 0:printf("＊＊＊总分成绩排名＊＊＊\n");break;
		case 1:printf("＊＊＊语文成绩排名＊＊＊\n");break;
		case 2:printf("＊＊＊数学成绩排名＊＊＊\n");break;
		case 3:printf("＊＊＊英语成绩排名＊＊＊\n");break;
		case 4:printf("＊＊＊平均成绩排名＊＊＊\n");break;
	}
	printf("排名\t学号\t\t姓名\t总分\n");
	for(int i =0;i<count_stu;i++)
	{
		if(0 == index)
		{
			
			if(all_rank(stu[i].id,stu[i].sum,index) == erank)
			{
				printf("%d\t%d\t%s\t%g\n",erank,stu[i].id,stu[i].name,stu[i].sum);
				i = -1;
				erank++;
			}
		}
		if(1 == index)
		{
			if(all_rank(stu[i].id,stu[i].chinese,index) == erank)
			{
				printf("%d\t%d\t%s\t%g\n",erank,stu[i].id,stu[i].name,stu[i].chinese);
				i = -1;
				erank++;
			}
		}
		if(2 == index)
		{
			if(all_rank(stu[i].id,stu[i].math,index) == erank)
			{
				printf("%d\t%d\t%s\t%g\n",erank,stu[i].id,stu[i].name,stu[i].math);
				i = -1;
				erank++;
			}
		}
		if(3 == index)
		{
			if(all_rank(stu[i].id,stu[i].english,index) == erank)
			{
				printf("%d\t%d\t%s\t%g\n",erank,stu[i].id,stu[i].name,stu[i].english);
				i = -1;
				erank++;
			}
		}
		if(4 == index)
		{
			if(all_rank(stu[i].id,stu[i].ave,index) == erank)
			{
				printf("%d\t%d\t%s\t%g\n",erank,stu[i].id,stu[i].name,stu[i].ave);
				i = -1;
				erank++;
			}
		}
	}
	back_4_3_2();
}
int all_rank(int id,float score,char flag)
{
	int rank = count_stu;
	char arr[20];
	for(int i=0;i<count_stu;i++)
	{
		if(0 == flag)//总分
		{
			if(score>stu[i].sum)
			{
				rank--;
			}
			else if(score == stu[i].sum)
			{
				if(stu[find_id_stu(id)].id>stu[i].id)
				{
					rank--;
				}
			}	
		}
		if(1 == flag)//语文
		{
			if(score>stu[i].chinese)
			{
				rank--;
			}
			else if(score == stu[i].chinese)
			{
				if(stu[find_id_stu(id)].id>stu[i].id)
				{
					rank--;
				}
			}	
		}
		if(2 == flag)//数学
		{
			if(score>stu[i].math)
			{
				rank--;
			}
			else if(score == stu[i].math)
			{
				if(stu[find_id_stu(id)].id>stu[i].id)
				{
					rank--;
				}
			}	
		}
		if(3 == flag)//英语
		{
			if(score>stu[i].english)
			{
				rank--;
			}
			else if(score == stu[i].english)
			{
				if(stu[find_id_stu(id)].id>stu[i].id)
				{
					rank--;
				}
			}	
		}
		if(4 == flag)//平均
		{
			if(score>stu[i].ave)
			{
				rank--;
			}
			else if(score == stu[i].ave)
			{
				if(stu[find_id_stu(id)].id>stu[i].id)
				{
					rank--;
				}
			}	
		}
	}
	return rank;
}
void tea_add_stu(void)
{
	system("clear");
	printf("＊＊＊添加学生＊＊＊\n");
	int num = 0;
	printf("请选择单个录入或者文件导入(1/0):");
	scanf("%d",&num);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	
	if(0 == num)//int fseek(FILE *stream, long offset, int whence);long ftell(FILE *stream);
	{
		FILE *frp = fopen("学生信息.txt","r");
		for(int i=count_stu;i<count_stu+6;i++)
		{
			fscanf(frp,"%d%s%s%d\n",&stu[i].id,stu[i].name,stu[i].sex,&stu[i].year);
			fseek(frp,9,SEEK_CUR);
			stu[i].id=++stu_id_start;
			stu[i].age = (char)(time(NULL)/(365*24*60*60)+1970-stu[i].year);
			strcpy(stu[i].pw,"123");
			stu[i].flag=-1;
			stu[i].back=1;
		}
		count_stu += 6;
		printf("添加完成！\n");
	}
	else
	{
		stu[count_stu].id=++stu_id_start;
		strcpy(stu[count_stu].pw,"123");
		stu[count_stu].flag = -1;
		printf("请输入姓名：");
		gets(stu[count_stu].name);
		printf("请输入性别：");
		gets(stu[count_stu].sex);
		printf("请输入出生年份：");
		scanf("%d",&stu[count_stu].year);
		getchar();
		stu[count_stu].age = (char)(time(NULL)/(365*24*60*60)+1970-stu[count_stu].year);
		stu[count_stu].back = 1;
		count_stu += 1;
		printf("添加完成！\n");
	}
	back_1_3_2();
}
void tea_del_stu(void)
{
	system("clear");
	printf("＊＊＊删除学生＊＊＊\n");
	int num = 0;
	printf("请输入你要删除学生的学号：");
	scanf("%d",&num);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(find_id_stu(num) == -1)
	{
		printf("此人不存在\n");
	}
	else if(0 == stu[find_id_stu(num)].back)
	{
		printf("此人已被退学！\n");
	}
	else
	{
		stu[find_id_stu(num)].back = 0;
		printf("删除成功！\n");
	}
	back_1_3_2();
}
void tea_ch_stu(void)
{
	system("clear");
	printf("＊＊＊修改信息＊＊＊\n");
	int num = 0;
	printf("请输入学号：");
	scanf("%d",&num);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	
	if(find_id_stu(num) == -1 || stu[find_id_stu(num)].back == 0)
	{
		printf("此人不存在或以被退学！\n");
	}
	else
	{
		int n = 10;
		printf("需要修改姓名吗？(1/0)：");
		scanf("%d",&n);
		getchar();
		if(1 == n)
		{
			printf("请输入要修改的姓名：");
			gets(stu[find_id_stu(num)].name);
			printf("修改姓名成功！\n");
		}
		printf("需要修改性别吗？(1/0)：");
		scanf("%d",&n);
		getchar();
		if(1 == n)
		{
			printf("请输入性别：");
			gets(stu[find_id_stu(num)].sex);
			printf("修改性别成功！\n");
		}
		printf("需要修改出生年份吗？(1/0):");
		scanf("%d",&n);
		getchar();
		if(1 == n)
		{
			printf("请输入出生年份：");
			scanf("%d",&stu[find_id_stu(num)].year);
			getchar();
			stu[find_id_stu(num)].age = (char)(time(NULL)/(365*24*60*60)+1970-stu[find_id_stu(num)].year);
			printf("修改出生年份成功！\n");
		}
	}
	back_1_3_2();
}
void tea_def_stu(void)
{
	system("clear");
	printf("＊＊＊重置密码＊＊＊\n");
	int id = 0;
	printf("请输入要重置密码的学生学号：");
	scanf("%d",&id);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(find_id_stu(id) == -1)
	{
		printf("没有此人！\n");
	}
	else if(stu[find_id_stu(id)].back == 0)
	{
		printf("此人以被退学！\n");
	}
	else
	{
		strcpy(stu[find_id_stu(id)].pw,"123");
		printf("重置密码成功！\n");
	}
	back_1_3_2();
}
void tea_unlock_stu(void)
{
	system("clear");
	printf("＊＊＊解锁学生＊＊＊\n");
	int id = 0;
	printf("请输入要解锁学生的学号：");
	scanf("%d",&id);
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	if(find_id_stu(id) == -1)
	{
		printf("没有此人！\n");
	}
	else if(stu[find_id_stu(id)].back == 0)
	{
		printf("此人已被退学！\n");
	}
	else if(stu[find_id_stu(id)].flag < 3)
	{
		printf("此人不需要解锁！\n");
	}
	else
	{
		stu[find_id_stu(id)].flag = 0;
		printf("解锁成功！\n");
	}
	back_1_3_2();
}
void tea_sou_mess(void)
{
	system("clear");
	printf("＊＊＊查询学生＊＊＊\n");
	char na[20] = {};
	char arr[count_stu+1];
    printf("请输入要查询学生的姓名：");
	gets(na);
	if(strlen(find_name_stu(na,arr)) == 0) 
	{   
	    printf("没有此人！\n");
	}   
	else if(stu[*find_name_stu(na,arr)-'0'].back == 0)		
	{   
		printf("此人已被退学！\n");
	}
	else
	{
		system("clear");
		printf("编号\t学号\t\t姓名\t性别\t年龄\n");
		for(int i=0;arr[i];i++)
		{
			printf("%d\t%d\t%s\t%s\t%d\n",*(find_name_stu(na,arr))-'0'+1+i,stu[*find_name_stu(na,arr)-'0'+i].id,stu[*find_name_stu(na,arr)-'0'+i].name,stu[*find_name_stu(na,arr)-'0'+i].sex,(int)(time(NULL)/(365*24*60*60)+1970-stu[*find_name_stu(na,arr)-'0'+i].year));
		}
	}
	back_1_3_2();
}
void show_all_stu(void)
{
	system("clear");
	printf("＊＊＊显示在学学生＊＊＊\n");
	printf("编号\t学号\t\t姓名\t性别\t年龄\n");
	for(int i=0;i<count_stu;i++)
	{
		if(stu[i].back)
		{
			printf("%d\t%d\t%s\t%s\t%d\n",i+1,stu[i].id,stu[i].name,stu[i].sex,(int)(time(NULL)/(365*24*60*60)+1970-stu[i].year));
		}
	}
	back_1_3_2();
	}
void show_back_stu(void)
{
	system("clear");
	printf("＊＊＊显示退学学生＊＊＊\n");
	printf("编号\t学号\t\t姓名\t性别\t年龄\n");
	for(int i=0;i<count_stu;i++)
	{
		if(0 == stu[i].back)
		{
			printf("%d\t%d\t%s\t%s\t%d\n",i+1,stu[i].id,stu[i].name,stu[i].sex,(int)(time(NULL)/(365*24*60*60)+1970-stu[i].year));
		}
	}
	back_1_3_2();
}
