#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include "syntax.h"
#include <locale.h>

void main(void)
{
	setlocale(LC_ALL, "RUS");
	char* line = "while A<>B do C:=Arr[10-B];";
	for (int i = 0; i < strlen(line); i++)
	{
		splitSymsClasses(line[i]);
	}
	

	for (int i = 0; i < countSyms; i++)
	{
		if (strcmp(words[i].key, "др.символ") == 0)
		{
			printf("REJECTED");
			return;
		}
		splitWordsClasses(i);
	}

	editClasses();

	for (int i = 0; i <= countLexems; i++)
	{
		printf("['%s', '%s'] ", lex[i].word, lex[i].key);
	}
	printf("%s", Result());
}
