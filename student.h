#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getch.h>
#include <time.h>
struct Student
{
	int id;
	char pw[10];
	char name[20];
	char sex[10];
	char age;
	int year;
	float chinese;
	float math;
	float english;
	float ave;
	float sum;
	int c_rank;
	int m_rank;
	int e_rank;
	int rank;
	char flag;
	char back;
};
typedef struct Student Student;
int show_stu1(int i);
int show_stu(int i);
void show_menu(void);
void change_pw(int i,int kind);
int find_i(int id,char* pw);

extern Student stu[100];
#endif//STUDENT_H
