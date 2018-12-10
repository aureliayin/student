#ifndef TEACHER_H
#define TEACHER_H

struct Teacher{//工号、密码、姓名、性别、年龄、工龄
	int id;
	char pw[20];
	char name[20];
	char sex[10];
	char age;
	int year;
	int work;//入职年份
	char ls;//工龄
	char flag;
	char back;
};
typedef struct Teacher Teacher;
extern Teacher tea[100];

#include <stdio.h>
#include <string.h>
#include <getch.h>
#include <stdlib.h>
extern int count_tea;
int show_tea(void);
int find_id_tea(int id);
int find_id_stu(int id);
char* find_name_stu(char* str1,char* str2);
void login_teacher(void);
void show_tea1(void);
int all_rank(int id,float num,char flag);
void tea_add_stu(void);
void tea_del_stu(void);
void tea_ch_stu(void);
void tea_def_stu(void);
void tea_unlock_stu(void);
void tea_sou_mess(void);
void show_all_stu(void);
void show_back_stu(void);
void back_1_3_2(void);
//
void show_grade(void);
void back_4_3_2(void);
void get_key_5(void);
void change_pp(void);
void back_3_3_2(void);
void back_2_3_2(void);
void show_tea2(void);
void get_key_4(void);
void import_grade(void);
void change_grade(void);
void search_grade(void);
void rank_grade(char index);
void search_grade(void);

int get_key_1(void);

void get_key_3(void);
#endif

