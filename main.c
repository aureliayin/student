#include "student.h"
#include "teacher.h"
#include "s_admini.h"
#include "admini.h"
int main()
{
	int id=0,i=-1;
	char pw[10];
	while(1)
	{
		while(i == -1)
		{
			show_menu();
			scanf("%d",&id);
			printf("请输入密码：");
			scanf("%s",pw);
			getchar();
			i=find_i(id,pw);
		}
		if(3 == strlen(pw))
		{
			change_pw(i,id/10000000);
			i=-1;
		}
		else
		{
			switch(id/10000000)
			{
				case 1:i=show_stu(i);break;
				case 2:i=-1;show_tea();break;	
				case 3:i=-1;show_admini();break;
				case 4:i=-1;show_s_admini();break;
			}
		}
	}
}
