#include "fileSort.h"
//main 函数不使用的函数可以不在声明里面
//去空格的补一个空格的简单思路：
//原地复制，一个快，一个慢，不是空格的话，直接复制过去
//空格不复制过去，	每次复制完了之后快的指针指向比单词刚好的单词后卖弄的那个位置，如果fast指针指向的位置
//如果是空格的话， 直接在慢的指针的位置加一个空格。，指向慢的指针的那个位置
//是否
//
void trim_space(char* src)
{
	int to, from;
	for (to = -1, from = 0;src[from] != 0;++from)

	{
		if (!isspace(src[from]))
		{
			src[++to] = src[from];
		}
		else
		{
			if (to != -1 && !isspace(src[to]))
			{
				src[++to] = ' ';
			}
		}
	}
	src[++to] = 0;
}
int stu_sum(int* array, int len)
{
	int sum = 0;
	int ix;
	for (ix = 0; ix < len; ++ix)
	{
		sum = sum + array[ix];
	}
	return sum;
}
void linkSaveFile(pSTU phead, char* dest);
/*
以下的程序是从文件中读出来并且, 把它串在链表当中。


*/
void linkInitFromFile(char* fileName, pSTU* phead)
{
	pSTU pnew, pcur, ppre;
	FILE* fp = fopen(fileName, "r");
	char line[1024];
	if (fp == NULL)
	{
		printf("fail exit(0)");
		return;
	}
	while (memset(line, 0, sizeof(line)) && fgets(line, 1024, fp) != NULL)//把文件读进line ：自己定义的数组
	{
		trim_space(line);
		if (line[0] == 0)
		{
			continue;  //如果读到的是空行的话，直接返回。
		}

		 pnew = (pSTU)calloc(1, sizeof(STU));//申请完了之后就立即把程序读进去；
		 if (pnew == NULL)
		 {
			 printf("fail to calloc");
			 return;
		 }
		 sscanf(line, "%d %s %c %d %d %d %d %d", &pnew->m_id, pnew->m_name, &pnew->m_gender, &pnew->m_scores[0], &pnew->m_scores[1], &pnew->m_scores[2],&pnew->m_scores[3], &pnew->m_scores[4]);
		pcur = *phead;
		ppre = NULL;
		while (pcur && stu_sum(pcur->m_scores, 5) < stu_sum(pnew->m_scores,5))
		{
			ppre = pcur;
			pcur = pcur->m_next;
		}
		if (ppre == NULL)//前面的节点是NULL的话，只需要做这样的操作
		{
			pnew->m_next = *phead;
			*phead = pnew;
		}
		else
		{
			pnew->m_next = pcur;
			ppre->m_next = pnew;
		}

	}
	fclose(fp);


}

//void linkInitFromFile(char* fileName, pSTU* phead)
//{
//	pSTU pnew, pcur, ppre;
//	FILE* fp = fopen(fileName, "r");
//	char line[1024];
//	if (fp == NULL)
//	{
//		printf("fail ");
//		return;
//	}
//	while (memset(line, 0, sizeof(line)), fgets(line, 1024, fp) != NULL)//实际是读到\n 的 就结束，如果一行读完还没有结束的话，那么他返回的就会是NULL
//	{
//		trim_space(line);
//		pnew = (pSTU)calloc(1, sizeof(STU));
//		sscanf(line, "%d %s %c %d %d %d %d %d", &pnew->m_id, pnew->m_name, &pnew->m_gender, &pnew->m_scores[0], &pnew->m_scores[1], &pnew->m_scores[2], &pnew->m_scores[3], &pnew->m_scores[4]);
//		pcur = *phead;
//		ppre = NULL;
//		while (pcur && stu_sum(pcur->m_scores, 5) < stu_sum(pnew->m_scores, 5))
//		{
//			ppre = pcur;
//			pcur = pcur->m_next;
//			 
//		}
//	}
//
//}
void linkSaveFile(pSTU phead, char* dest)
{
	//将链表中的字符存进到文件当中去
	pSTU pcur = phead,ptmp;
	char line[1024];
	FILE* wf = fopen(dest, "w");
	if (wf == NULL)
	{
		printf("read error");
		return;
	}
	memset(line, 0, sizeof(line));
	//pcur = phead;
	while(pcur)
	{
		sprintf(line, "%-4d%-10s %c %d %d %d %d %d\n", pcur->m_id, pcur->m_name, pcur->m_gender, pcur->m_scores[0], pcur->m_scores[1], pcur->m_scores[2], pcur->m_scores[3], pcur->m_scores[4]);
		fputs(line, wf);
		ptmp = pcur;
		pcur = pcur->m_next;
		free(ptmp);
	}

	fclose(wf);
}