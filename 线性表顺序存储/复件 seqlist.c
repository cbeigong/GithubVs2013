#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "seqlist.h"

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	unsigned int *node ;
}TSeqList;

//typdef的意思 把void 重新命名成SeqList

/*
void * SeqList_Create(int capacity)
{
	TSeqList *ret = NULL;
	ret = (TSeqList *)malloc(sizeof(TSeqList));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->capacity = capacity;
	ret->node = (unsigned int *)malloc(sizeof(unsigned int *) * capacity);
	if (ret->node == NULL)
	{
		return NULL;
	}
	ret->length = 0;
	return ret;
}
*/

void * SeqList_Create(int capacity)
{
	TSeqList *ret = NULL;

	if (capacity <= 0)
	{
		return NULL;
	}
	ret = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(unsigned int *) * capacity );
	if (ret == NULL)
	{
		return NULL;
	}
	ret->capacity = capacity;
	ret->node = (unsigned int *)(ret + 1);
	
	ret->length = 0;
	return ret;
}

void SeqList_Destroy(SeqList* list)
{
	if (list == NULL)
	{
		return ;
	}
	free(list);
	return ;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList *tlist = list;
	if (list == NULL)
	{
		return ;
	}
	tlist->length = 0;
	return ;
}

int SeqList_Length(SeqList* list)
{
	TSeqList *tlist = list;
	if (list == NULL)
	{
		return -1;
	}
	return tlist->length;
}

int SeqList_Capacity(SeqList* list)
{
	TSeqList *tlist = list;
	if (list == NULL)
	{
		return -1;
	}
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	return NULL;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	return NULL;
}
