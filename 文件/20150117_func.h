#ifndef __FUNC__
#define __FUNC__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tag
{
	int m_val;
	struct tag* m_next;
}NODE, *pNODE;
void link_init_tail(pNODE* pphead);
void link_init_head(pNODE* pphead);
void link_init_sort(pNODE* pphead);
void link_destroy(pNODE* pphead);
void link_revese(pNODE* pphead);
void link_delete(pNODE* pphead, int val);
void link_show(pNODE phead);
//void stu_init(pSTU* pstu);
#endif