#include"20150117_func.h"
void link_revese(pNODE* pphead)
{
}
void link_init_tail(pNODE* pphead)
{
	int val;
	pNODE  ptail = NULL, pnew, pcur = NULL;
	while (scanf("%d", &val) == 1)
	{
		pnew = (pNODE)calloc(1, sizeof(NODE));
		pnew->m_val = val;
		if (*pphead == NULL)
		{
			*pphead = pnew;
			ptail = pnew;
		}
		else
		{
			ptail->m_next = pnew;
			ptail = pnew;
		}

	}
	val = 3;
}
void link_init_head(pNODE* pphead)
{
	int val;
	pNODE pnew;
	while (scanf("%d", &val) == 1)
	{
		pnew = (pNODE)calloc(1, sizeof(NODE));
		pnew->m_val = val;

		pnew->m_next = *pphead;
		*pphead = pnew;
	}
}
void link_init_sort(pNODE* pphead)
{
	int val;
	pNODE pnew, pcur, ppre;

	while (scanf("%d", &val) == 1)
	{
		pnew = (pNODE)calloc(1, sizeof(NODE));
		pnew->m_val = val;

		pcur = *pphead;
		ppre = NULL;
		while (pcur && pcur->m_val < pnew->m_val)
		{
			ppre = pcur;
			pcur = pcur->m_next;
		}
		if (ppre == NULL)
		{
			pnew->m_next = *pphead;
			*pphead = pnew;
		}
		else
		{
			pnew->m_next = pcur;
			ppre->m_next = pnew;
		}

	}
}
void link_destroy(pNODE* pphead)
{
	pNODE  pcur, ptmp;
	pcur = *pphead;
	while (pcur)
	{
		ptmp = pcur;
		pcur = pcur->m_next;
		free(ptmp);
	}
	*pphead = NULL;
}

void link_delete(pNODE* pphead, int val)
{
	pNODE pcur, ppre;
	pcur = *pphead;
	ppre = NULL;
	while (pcur && pcur->m_val != val)
	{
		ppre = pcur;
		pcur = pcur->m_next;
	}
	if (pcur == NULL)
	{
		printf("not exist ! \n");

	}
	else
	{
		if (ppre == NULL)
		{
			*pphead = pcur->m_next;
			free(pcur);
		}
		else
		{
			ppre->m_next = pcur->m_next;
			free(pcur);
		}
	}
}
void link_show(pNODE phead)
{
	pNODE pcur;
	pcur = phead;
	while (pcur != NULL)
	{
		printf("%d ", pcur->m_val);
		pcur = pcur->m_next;
	}
}

