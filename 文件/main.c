#include"20150117_func.h"
int main(int argc, char* argv[])
{
	/*
	STU astu = {1001, "zhangsan"} ;
	pSTU p = NULL;
	stu_init(&p);

	p ->m_val = 1002 ;
	strcpy(p ->m_buf, "lisi");
	*/
	//int val;
	pNODE phead, pcur;
	phead = NULL;
	link_init_head(&phead);
	//link_init_sort(&phead);
	link_show(phead);
	printf("\n");
	/*while (scanf("%d", &val) == 1)
	{
		link_delete(&phead, val);
		link_show(phead);
		printf("\n");
	}*/

	//astu = 
	system("pause");
	return 0;
}