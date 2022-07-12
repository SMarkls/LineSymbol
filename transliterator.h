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
		strcpy(words[countSyms].key, "буква");
	}
	else if (isDigit(word))
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "цифра");
	}
	else if (word == ' ')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "пробел");
	}
	else if (word == '<' || word == '>')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "знак");
	}
	else if (word == ':')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "дв.-точие");
	}
	else if (word == '=')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "равно");
	}
	else if (word == '$')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "доллар");
	}
	else if (word == ';')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "тчкзпт");
	}
	else if (word == '[' || word == ']')
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "скобка");
	}
	else if (In(word, "+-*/"))
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "знак");
	}
	else
	{
		words[countSyms].letter = word;
		strcpy(words[countSyms].key, "др.символ");
	}
	countSyms++;
}
