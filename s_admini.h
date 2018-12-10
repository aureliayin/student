#ifndef S_ADMINI_H
#define S_ADMINI_H
#include <stdio.h>
#include <string.h>
#include <getch.h>
#include <stdlib.h>
struct Admini
{
	int id;
	char pw[10];
	char flag;
	char back;
};
typedef struct Admini Admini;
extern Admini adm[10];
extern int s_id;
extern char s_pw[10];
extern int count_adm;
int find_id_adm(int id);
void show_s_admini(void);
void get_key_888(void);
void back_1(void);
void add_admini(void);
void del_admini(void);
void reset_admini(void);
void unlock_admini(void);
void show_alladmini(void);

#endif//S_ADMINI_H
