#include "fileSort.h"
//main ������ʹ�õĺ������Բ�����������
//ȥ�ո�Ĳ�һ���ո�ļ�˼·��
//ԭ�ظ��ƣ�һ���죬һ���������ǿո�Ļ���ֱ�Ӹ��ƹ�ȥ
//�ո񲻸��ƹ�ȥ��	ÿ�θ�������֮����ָ��ָ��ȵ��ʸպõĵ��ʺ���Ū���Ǹ�λ�ã����fastָ��ָ���λ��
//����ǿո�Ļ��� ֱ��������ָ���λ�ü�һ���ո񡣣�ָ������ָ����Ǹ�λ��
//�Ƿ�
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
���µĳ����Ǵ��ļ��ж���������, �������������С�


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
	while (memset(line, 0, sizeof(line)) && fgets(line, 1024, fp) != NULL)//���ļ�����line ���Լ����������
	{
		trim_space(line);
		if (line[0] == 0)
		{
			continue;  //����������ǿ��еĻ���ֱ�ӷ��ء�
		}

		 pnew = (pSTU)calloc(1, sizeof(STU));//��������֮��������ѳ������ȥ��
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
		if (ppre == NULL)//ǰ��Ľڵ���NULL�Ļ���ֻ��Ҫ�������Ĳ���
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
//	while (memset(line, 0, sizeof(line)), fgets(line, 1024, fp) != NULL)//ʵ���Ƕ���\n �� �ͽ��������һ�ж��껹û�н����Ļ�����ô�����صľͻ���NULL
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
	//�������е��ַ�������ļ�����ȥ
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