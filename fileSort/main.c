#include "fileSort.h"

int main(int argc, char* argv[])
{
	pSTU head = NULL;
	linkInitFromFile(argv[1], &head);
	linkSaveFile(head, argv[2]);
	head = NULL;
	system("pause");
	return 0;
}