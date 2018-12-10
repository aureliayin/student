#include "student.h"
#include "teacher.h"
#include "s_admini.h"
#include "admini.h"

/*struct Admini{//帐号，密码，姓名，
    int  id;
	char pw[20];
	char back;
	char flag;
};
typedef struct Admini Admini;
struct Teacher{
	int id;
	char pw[10];
	char name[20];
	char sex[10];
	char age;
	char ls;
	char flag;
	char back;
};
typedef struct Teacher Teacher;*/
//int count=1;
//int count_tea=1;
//int count_admini=10;
//Admini adm[100]={{34567890,"abc",1,-1}};
//Teacher tea[100]={{20304050,"123","张三","男",55,20,-1,1}};
Teacher tea[100]={{20304050,"123456","李四","男",55,1963,1988,20,-1,1}};
int start_tea_id=20304050;

void show_admini(void)
{
	system("clear");
	puts("**********管理员操作界面**********");
	puts("1:添加教师，单个加或者批量添加");
	puts("2:删除教师，删除后的老师记作离职");
	puts("3:修改教师基本信息");
	puts("4:重置教师密码");
	puts("5:解锁教师帐号");
	puts("6:根据姓名查询教师基本信息");
	puts("7:显示所有离职教师");
	puts("8:显示所有在职教师");
	puts("9:修改登陆密码");
	puts("0:退出这个界面");
	puts("--------------------------------");
	puts("请输入你的指令");
	key();
}
 /*int find_id_adm(int id)
 { 
	 for(int i=0;i<100;i++)
	 {
		 if(adm[i].id==id )
		 {
			
			 return i;
		 }
	}		  
	 return -1;

 }*/
 int find_id_tea1(int id)
 {
	 for(int i=0;i<100;i++)
	 {
		 if(tea[i].id==id && tea[i].back)
		 {
			 return i;
		 }
	}
 return -1;
 }
void clear(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
}

 int find_name_tea1(char*str)
 {
	 for(int i=0;i<100;i++)
	 {
		 if(strcmp(tea[i].name,str)==0)
		 {
			 return i;
		 }
	 }
	 return -1;
 }
void key(void)
	{	
	        	switch (getch())
			{
				case 49:add_tea();break;
				case 50:del_tea();break;
				case 51:change_tea();break;
				case 52:reset_tea();break;
				case 53:jie_tea();break;
				case 54:find_tea();break;
				case 55:allno_tea();break;
				case 56:allyes_tea();break;
                case 57:change_password();break;
                case 48:return ;
			}
	} 
/*void login_admini(void)
{
   system("clear");
   int id=0,count=0;
   char pw_in[20]={};

   system("clear");
   printf("*****伟大的管理员欢迎你********\n");
 
   printf("请输入用户名:");
   scanf("%d",&id);
   getchar();
   if(find_id_adm(id)==-1)
   {
	   printf("没有此用户,重新输入\n");
	   back2();
          
    }
	else 
	{
		while(1)
		{
			printf("请输入密码:");
			gets(pw_in);
		if(0==strcmp(adm[find_id_adm(id)].pw,pw_in))
		     {
				 show_admini();
				 break;
			 }
	     else
		 {
			 count++;
		 }
		 if(count<3)
		 {
			 continue;
		 }
		 else
		 {
			 printf("密码错误多次且限制登陆");break;
			 
		 }
		}
		back2();
    }


}*/


void add_tea(void)
{  
	system("clear");
	int num=0;
	printf("＊＊＊添加教师＊＊＊\n");
	printf("请选择单个添加或文件导入(1/0):");
	scanf("%d",&num);
	stdin->_IO_read_ptr=stdin->_IO_read_end;

	if(1 == num)
	{	
		tea[count_tea].id=++start_tea_id;
		strcpy(tea[count_tea].pw,"123");
		printf("请输入教师的姓名:");
		scanf("%s",tea[count_tea].name);
		clear();
		printf("请输入老师的性别:");
		scanf("%s",tea[count_tea].sex);
		clear();
		printf("请输入老师的出生年份:");
		scanf("%d",&tea[count_tea].year);
		clear();
		tea[count_tea].age=(char)(time(NULL)/(365*24*60*60)+1970-tea[count_tea].year);
		printf("请输入老师的入职年份:");
		scanf("%d",&tea[count_tea].work);
		clear();
		tea[count_tea].ls=(char)(time(NULL)/(365*24*60*60)+1970-tea[count_tea].work);
		tea[count_tea].flag = 0;
		tea[count_tea].back=1;
		count_tea++; 
		printf("添加教师完成\n");
	}
	else if(0 == num)
	{
		system("clear");
		printf("＊＊＊添加教师＊＊＊\n");
		FILE *frp = fopen("教师信息.txt","r");
		for(int i=count_tea;i<6+count_tea;i++)
		{
			fscanf(frp,"%d%s%s%d%d",&tea[i].id,tea[i].name,tea[i].sex,&tea[i].year,&tea[i].work);
			strcpy(tea[i].pw,"123");
			tea[i].age = (char)(time(NULL)/(365*24*60*60)+1970-tea[i].year);
			tea[i].ls = (char)(time(NULL)/(365*24*60*60)+1970-tea[i].work);
			tea[i].back = 1;
			tea[i].flag = 0;
		}
		count_tea += 6;
		start_tea_id +=6; 
		printf("添加教师完成！\n");
	}
    back1();
}
void back1(void)
{
	printf("***按任意键返回上一级菜单***\n");
	getch();
	show_admini();
}
void back2(void)
{
	getch();
	
}
void del_tea(void)
{
	system("clear");
	int num=0;
	
    printf("请输入你要删除的老师工号:");
    clear();
	scanf("%d",&num);
	getchar();
	if(find_id_tea1(num)==-1)
	{
		printf("此人不存在\n");		
    }
	else if(tea[find_id_tea1(num)].back==0)
	{
		printf("删除该教师记载为离职\n");
	}
	else
	{
		printf("删除成功");
		tea[find_id_tea1(num)].back=0;
    }

	
	back1();
}
void change_tea(void)
{
	system("clear");
  int num=0;
  printf("请输入老师工号");
  scanf("%d",&num);
  getchar();
  if(find_id_tea1(num)==-1|| tea[find_id_tea1(num)].back==0)
  {
	  printf("此人不存在或者已经离职\n");
	 
	  
  }
  else
  {
	  int n;
	  printf("需要修改姓名吗？(1/0)");
	  
	  scanf("%d",&n);
      clear();
	  if(n==1)
	  {
		 printf("请输入你要修改的姓名:");
          gets(tea[find_id_tea1(num)].name);
		 printf("修改姓名成功\n");
	  }
	  printf("请输入你是否修改性别(1/0)");
	  scanf("%d",&n);
	  clear();
	  if(n==1)
	  {
		  printf("你要修改的教师的性别:");
		  gets(tea[find_id_tea1(num)].sex);
		  printf("修改性别成功\n");
	  }
      

  }
  back1();
}



void reset_tea(void)
{
	system("clear");
	printf("*****重改密码****\n");
	int id=0;
	printf("请输入重改密码的教师工号：");
	scanf("%d",&id);
	clear();
  
	if(find_id_tea1(id)==-1)
	{
		printf("没有此人或者此人已经离职\n");
	}
	else

	{  
		printf("请输入新的密码\n");
		scanf("%s",tea[find_id_tea1(id)].pw);
	    clear();
		
		
		
		printf("重改密码成功!\n");
	}
      back1();
}
void jie_tea(void)
{ 
 
  system("clear");
  printf("***解锁教师帐号****");
  int id=0;
 printf("请输入要解锁的老师工号");
  scanf("%d",&id);
  stdin->_IO_read_ptr=stdin->_IO_read_end;
	 if(find_id_tea1(id)==-1)
	 {
		 printf("没有此人\n");
	 }
	 else if(tea[find_id_tea1(id)].flag<3)
	 {
		 printf("此人不需要解锁\n");
	 }
	 else
	 {
		 tea[find_id_tea1(id)].flag=0;
		 printf("解锁成功\n");
	 }
back1();
  ///////back?

} 
void find_tea(void)
{
  
  system("clear");
  char na[20]={};
  printf("请输入要查询的老师的名字");
  gets(na);
  if(find_name_tea1(na)==-1)
  {
	  printf("没有此人!\n");
  }

  else 
  {  
	  for(int i=0;i<count_tea;i++)
	  {
		  if(strcmp(na,tea[i].name) == 0)
		  {
	  		printf("帐号" ,"密码","姓名" ,"性别","年龄","工龄\n");
	  		printf("%d %s %s %s %hhd %hhd\n",tea[i].id,tea[i].pw,tea [i].name,tea[i].sex,tea[i].age,tea[i].ls);
	  	  }
	  }
  back1();
  }
}
void allno_tea(void)
{
  system("clear");
  printf("***显示离职教师***\n");
  for(int i=0;i<count_tea;i++)
	  {
		  if(tea[i].back==0)
		  {
			  		
		  printf("离职教师\n姓名：%s 性别：%s  工号：%d 密码：%s\n",tea[i].name,tea[i].sex,tea[i].id,tea[i].pw);
  }

}
back1();
  
}
	  
/*void  anykey_continue(void)
{
	puts("按任意一个键返回");
	getch();
}*/
void allyes_tea(void)
{
  system("clear");
  printf("工号\t\t姓名\t性别\t年龄\t工龄\n");
  for(int j=0;j<100;j++)
  {
	  if(tea[j].back == 1)
	  {
		  printf("%d\t%s\t%s\t%hhd\t%hhd\n",tea[j].id,tea[j].name,tea[j].sex,tea[j].age,tea[j].ls);
      }

  }
  back1();
}
char get_cmd(char start,char end)
{
	while(1)
	{
		char cmd=getch();
		if(cmd>=start && cmd<=end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}
void change_password(void)
{
	system("clear");
	printf("＊＊＊修改密码＊＊＊\n");
	int id=0;
	char pw1[20];
	printf("请管理员输入用户名：");
	scanf("%d",&id);
	getchar();
	int count1=0;
	if(find_id_adm(id) != -1)
	{
		int index=find_id_adm(id);
		while(1)
		{
			printf("请输入原密码:");
			gets(pw1);
			if(strcmp(pw1,adm[index].pw) == 0)
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
						strcpy(adm[index].pw,pw1);
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
	back1();	
}
