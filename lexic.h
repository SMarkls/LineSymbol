#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transliterator.h"

 
enum States
{
	space,
	ident,
	num,
	hex,
	equal,
	sign
};

enum States state = space;

void splitWordsClasses(int i) // принимает элемент из массивва Dict words[i];
{
	char tempState[15];
	if (state == space)
	{
		//strcat(tempState, words[i].key == "цифра" ? "целое" : words[i].key == "буква" ? "идент" : words[i].key == "доллар" ? "шестн. конст" : words[i].key);// words[i].key == "цифра" ? "целое" : words[i].key == "буква" ? "идент" : words[i].key;
		if (strcmp(words[i].key, "цифра") == 0)
		{
			state = num;
			strcpy(tempState, "целое");
		}
		else if (strcmp(words[i].key, "буква") == 0)
		{
			state = ident;
			strcpy(tempState, "идент");
		}
		else if (strcmp(words[i].key, "доллар") == 0)
		{
			state = hex;
			strcpy(tempState, "шестн. конст");
		}
		else if (strcmp(words[i].key, "пробел") == 0)
		{
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "скобка") == 0)
		{
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "тчкзпт") == 0)
		{
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "знак") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "дв.-точие") == 0)
		{
			state = equal;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "ошибка");
		}

		if(strcmp(tempState, "пробел") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == ident)
	{
		if (strcmp(words[i].key, "цифра") == 0)
		{
			strcpy(tempState, "идент");
		}
		else if (strcmp(words[i].key, "буква") == 0)
		{
			strcpy(tempState, "идент");
		}
		else if (strcmp(words[i].key, "доллар") == 0)
		{
			state = hex;
			strcpy(tempState, "шестн. конст");
		}
		else if (strcmp(words[i].key, "пробел") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "скобка") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "тчкзпт") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "знак") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "дв.-точие") == 0)
		{
			state = equal;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "ошибка");
		}
		if (strcmp(tempState, "идент") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == num)
	{
		if (strcmp(words[i].key, "цифра") == 0)
		{
			strcpy(tempState, "целое");
		}
		else if (strcmp(words[i].key, "доллар") == 0)
		{
			state = hex;
			strcpy(tempState, "шестн. конст");
		}
		else if (strcmp(words[i].key, "пробел") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "скобка") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "знак") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "дв.-точие") == 0)
		{
			state = equal;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "ошибка");
		}
		if (strcmp(tempState, "целое") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == hex)
	{
		if (strcmp(words[i].key, "цифра") == 0)
		{
			strcpy(tempState, "шестн. конст");
		}
		else if (strcmp(words[i].key, "буква") == 0)
		{
			strcpy(tempState, "шестн. конст");
		}
		else if (strcmp(words[i].key, "пробел") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "знак") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "ошибка");
		}
		if (strcmp(tempState, "шестн. конст") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == equal)
	{
		if (strcmp(words[i].key, "равно") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "ошибка");
		}
		if (strcmp(tempState, "равно") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == sign)
	{
		if (strcmp(words[i].key, "цифра") == 0)
		{
			state = num;
			strcpy(tempState, "целое");
		}
		else if (strcmp(words[i].key, "буква") == 0)
		{
			state = ident;
			strcpy(tempState, "идент");
		}
		else if (strcmp(words[i].key, "доллар") == 0)
		{
			state = hex;
			strcpy(tempState, "шестн. конст");
		}
		else if (strcmp(words[i].key, "пробел") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "знак") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "равно") == 0)
		{
			state = space;
			strcpy(tempState, "знак");
		}
		else
		{
			strcpy(tempState, "ошибка");
		}
		if (strcmp(tempState, "знак") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
}

