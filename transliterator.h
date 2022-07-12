#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Structures.h"


int In(char word, const char* dict)
{
	for (int i = 0; i < strlen(dict); i++)
		if (word == dict[i]) return 1;
	return 0;
}

int isDigit(char word)
{
	const char* abc = "1234567890";
	return In(word, abc);
}

int isLetter(char word)
{
	const char* abc = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	return In(word, abc);
}


void splitSymsClasses(char word)
{
	if (isLetter(word))
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "�����");
	}
	else if (isDigit(word))
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "�����");
	}
	else if (word == ' ')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "������");
	}
	else if (word == '<' || word == '>')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "����");
	}
	else if (word == ':')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "��.-�����");
	}
	else if (word == '=')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "�����");
	}
	else if (word == '$')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "������");
	}
	else if (word == ';')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "������");
	}
	else if (word == '[' || word == ']')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "������");
	}
	else if (In(word, "+-*/"))
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "����");
	}
	else
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "��.������");
	}
	countSyms++;
}
