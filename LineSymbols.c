#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include "syntax.h"
#include <locale.h>

void main(void)
{
	setlocale(LC_ALL, "RUS");
	char line[256];
	FILE* f;
	f = fopen("INPUT.txt", "r");
	fgets(line, 256, f);
	fclose(f);
	//char* line = "while A<>B do C:=Arr[$1F0 - 2];";
	for (int i = 0; i < strlen(line); i++)
	{
		splitSymsClasses(line[i]);
	}

	f = fopen("OUTPUT.txt", "w");

	for (int i = 0; i < countSyms; i++)
	{
		if (strcmp(words[i].key, "др.символ") == 0)
		{
			fputs("REJECT", f);
			return;
		}
		splitWordsClasses(i);
	}

	editClasses();

	/*for (int i = 0; i <= countLexems; i++)
	{
		printf("['%s', '%s'] ", lex[i].word, lex[i].key);
	}*/
	fputs(Result(), f);
}
