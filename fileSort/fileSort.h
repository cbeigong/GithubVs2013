#ifndef __FUNC_H__
#define __FUNC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct tag_stu
{
	int m_id;
	char m_gender;
	char m_name[32];
	int m_scores[5];
	struct tag_stu* m_next;

}STU, *pSTU;
void linkSaveFile(pSTU phead, char* dest);
void linkInitFromFile(char* fileName, pSTU* phead);

#endif
