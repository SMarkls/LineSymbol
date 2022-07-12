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

void splitWordsClasses(int i) // ��������� ������� �� �������� Dict words[i];
{
	char tempState[15];
	if (state == space)
	{
		//strcat(tempState, words[i].key == "�����" ? "�����" : words[i].key == "�����" ? "�����" : words[i].key == "������" ? "�����. �����" : words[i].key);// words[i].key == "�����" ? "�����" : words[i].key == "�����" ? "�����" : words[i].key;
		if (strcmp(words[i].key, "�����") == 0)
		{
			state = num;
			strcpy(tempState, "�����");
		}
		else if (strcmp(words[i].key, "�����") == 0)
		{
			state = ident;
			strcpy(tempState, "�����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = hex;
			strcpy(tempState, "�����. �����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "����") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "��.-�����") == 0)
		{
			state = equal;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "������");
		}

		if(strcmp(tempState, "������") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == ident)
	{
		if (strcmp(words[i].key, "�����") == 0)
		{
			strcpy(tempState, "�����");
		}
		else if (strcmp(words[i].key, "�����") == 0)
		{
			strcpy(tempState, "�����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = hex;
			strcpy(tempState, "�����. �����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "����") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "��.-�����") == 0)
		{
			state = equal;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "������");
		}
		if (strcmp(tempState, "�����") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == num)
	{
		if (strcmp(words[i].key, "�����") == 0)
		{
			strcpy(tempState, "�����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = hex;
			strcpy(tempState, "�����. �����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "����") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "��.-�����") == 0)
		{
			state = equal;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "������");
		}
		if (strcmp(tempState, "�����") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == hex)
	{
		if (strcmp(words[i].key, "�����") == 0)
		{
			strcpy(tempState, "�����. �����");
		}
		else if (strcmp(words[i].key, "�����") == 0)
		{
			strcpy(tempState, "�����. �����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "����") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "������");
		}
		if (strcmp(tempState, "�����. �����") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == equal)
	{
		if (strcmp(words[i].key, "�����") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else
		{
			strcpy(tempState, "������");
		}
		if (strcmp(tempState, "�����") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
	if (state == sign)
	{
		if (strcmp(words[i].key, "�����") == 0)
		{
			state = num;
			strcpy(tempState, "�����");
		}
		else if (strcmp(words[i].key, "�����") == 0)
		{
			state = ident;
			strcpy(tempState, "�����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = hex;
			strcpy(tempState, "�����. �����");
		}
		else if (strcmp(words[i].key, "������") == 0)
		{
			state = space;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "����") == 0)
		{
			state = sign;
			strcpy(tempState, words[i].key);
		}
		else if (strcmp(words[i].key, "�����") == 0)
		{
			state = space;
			strcpy(tempState, "����");
		}
		else
		{
			strcpy(tempState, "������");
		}
		if (strcmp(tempState, "����") != 0)
			countLexems++;
		int temp = strlen(lex[countLexems].word);
		strcpy(lex[countLexems].key, tempState);
		lex[countLexems].word[temp] = words[i].letter;
		lex[countLexems].word[temp + 1] = '\0';
		return;
	}
}
