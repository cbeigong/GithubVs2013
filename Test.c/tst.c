#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*







*/
int main(int argc, char* argv[])
{
	int cnt_word = 0;
	int cnt_line = 0;
	char word[32];
	char ch;
	int cnt = 0;
//	const char* ch = "E:\\nimei.txt";
	FILE* read_file;
	FILE* file_write;
	FILE* file_read_2;
	file_write = fopen(argv[2], "w");// 以w 打开的方式如果是没有打开的时候，
	read_file = fopen(argv[1], "r");
	if (read_file == NULL || file_write == NULL)
	{
		printf( "fail to open the nimei.txt. exit(0)");
	}
	else
	{
		printf("success open the file");
		//sprintf(stdout, "open the file success");
	}
	while ((ch = fgetc(read_file)) != EOF)
	{/*
		
		}*/
	/*	if (ch > 'a' && ch < 'z' || ch > 'A' && ch < 'Z')
		{
			++cnt_cha;
		}
		if (ispunct(ch))
		{
			++cnt_ispunct;
		}*/
		if (ch == '\n')
		{
			++cnt_line;
		}
	//	putchar(ch);
		if (!ispunct(ch))
		{
			if (ch >= 'A' && 'Z' >= ch)
			{
				fputc(ch + 32, file_write);
			}
			else
			{
				fputc(ch, file_write);
			}
		}
		++cnt;
	}
	printf("\nline:%d\n", cnt_line);
	fclose(read_file);
	file_read_2 = fopen(argv[2], "r");
	while (fscanf(file_read_2, "%s", word) != EOF)
	{
		++cnt_word;
	}
	printf("cnt_char:%d\ncnt_word:%d\n", cnt,cnt_word);
	system("pause");

	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//int* p = a[0];
	//printf("%d ", p[2]);
	



	int k;
	scanf("%d", &k);
	system("pause");
	return 0;
}