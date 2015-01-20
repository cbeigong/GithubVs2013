#ifndef __SIMS__
#define __SIMS__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define USR_PWD_LEN 10
#define USR_NAME_LEN 20
typedef  int USR_ROLE;
typedef struct usr_account_tag
{
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	USR_ROLE usr_role;
	struct usr_account_tag *pNext_Usr_Account;

}USR_ACCOUNT,*pUSR_ACCOUNT;

typedef struct stu_INFO_TAG
{
	int m_id;
	char m_name[USR_NAME_LEN]

};


#endif