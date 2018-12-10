#include "s_admini.h"
#include "admini.h"


int s_id=43994399;
char s_pw[10]="9876543210";
int count_adm = 1;
int adm_id_start = 30123456;
int count=1;

Admini adm[10]={{30123456,"123",0,1}};

int find_id_adm(int id)
{
	for(int i=0; i<10; i++)
	{
		if(adm[i].id == id)
		{
			return i;
		}
	}
	return -1;
}
void show_s_admini(void)
{
	system("clear");
	printf("**********超级管理员界面**********\n");
	printf("1、添加管理员\n");
	printf("2、删除管理员\n");
	printf("3、重置管理员密码\n");
	printf("4、解锁管理员账号\n");
	printf("5、显示所有管理员\n");
	printf("6、退出登录\n");
	get_key_888();
}

void get_key_888(void)
{
	switch(getch())
	{
		case 49:add_admini();break;
		case 50:del_admini();break;
		case 51:reset_admini();break;
		case 52:unlock_admini();break;
		case 53:show_admini();break;
		case 54:return;
	}
}

void back_1(void)
{
	printf("**********按任意键返回**********\n");
	getch();
	show_s_admini();
}

void add_admini(void)
{
	system("clear");
	printf("**********添加管理员**********\n");
	for(int i=0; i<10; i++)
	{
		if(0 == adm[i].back)
		{
			adm[i].id=adm_id_start+i;
			strcpy(adm[i].pw,"abc");
			adm[i].back=1;
			printf("新添加的管理员账号为：%d\n",adm[i].id);
			printf("密码：abc\n");
			count++;
			break;
		}
	}
	if(count == 10)
	{
		printf("管理员人数已满！\n");
	}
	back_1();
}

void del_admini(void)
{
	system("clear");
	printf("**********删除管理员**********\n");
	int id=0,i=-1;
	printf("请输入要删除的管理员账号：");
	scanf("%d",&id);
	getchar();
	i=find_id_adm(id);
	if(i == -1)
	{
		printf("该管理员账号不存在！\n");
	}
	else
	{
		adm[i].back=0;
		printf("删除成功！\n");
		count--;
	}
	back_1();
}

void reset_admini(void)
{
	system("clear");
	printf("**********重置管理员密码**********\n");
	int id=0,i=-1;
	printf("请输入要重置的管理员账号：");
	scanf("%d",&id);
	getchar();
	i=find_id_adm(id);
	if(i == -1)
	{
		printf("该管理员账号不存在！\n");
	}
	else
	{
		strcpy(adm[i].pw,"abc");
		printf("重置成功！\n");
	}
	back_1();
}

void unlock_admini(void)
{
	int id=0,i=-1;
	system("clear");
	printf("**********解锁管理员**********\n");
	printf("请输入要解锁的管理员账号：");
	scanf("%d",&id);
	getchar();
	i=find_id_adm(id);
	if(i == -1)
	{
		printf("该管理员账号不存在！\n");
	}
	else if(adm[i].flag >= 3)
	{
		adm[i].flag=0;
		printf("解锁成功！\n");
	}
	else
	{
		printf("该管理员账号不需要解锁！\n");
		//usleep(2000000);
	}
	back_1();
}

void show_alladmini(void)
{
	system("clear");
	printf("**********显示所有管理员**********\n");
	int i=0,num=1;
	for(int n=0; n<10; n++)
	{
		if(1 == adm[n].back)
		{
			printf("管理员%d:%d\n",num++,adm[n].id);
		}
	}
	back_1();
}

