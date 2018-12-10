#ifndef ADMINI_H
#define ADMINI_H
#include<stdio.h>
#include<getch.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
void show_admini(void);
int find_id_tea1(int id);
void clear(void);
int find_name_tea1(char*str);
void key(void);
void add_tea(void);
void back1(void);
void back2(void);
void del_tea(void);
void change_tea(void);
void reset_tea(void);
void jie_tea(void);
void find_tea(void);
void allno_tea(void);
void allyes_tea(void);
char get_cmd(char start,char end);
void change_password(void);
#endif//ADMINI_H
