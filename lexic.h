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

		if (strcmp(tempState, "������") != 0)
		{
			countLexems++;
			strcpy(lex[countLexems].key, tempState);
		}
		int temp = strlen(lex[countLexems].word);
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
			if ((words[i].letter >= 97 && words[i].letter <= 102) || (words[i].letter >= 65 && words[i].letter <= 70))
				strcpy(tempState, "�����. �����");
			else
				strcpy(tempState, "������");
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
int InKeyWords(char* word)
{
	char keyWords[2][6] = { "while", "do" };
	for (int i = 0; i < 2; i++)
		if (strcmp(word, keyWords[i]) == 0)
			return i + 1;
	return 0;
}

int InOpWords(char* word)
{
	char opWords[2][4] = { "div", "mod" };
	for (int i = 0; i < 2; i++)
		if (strcmp(word, opWords[i]) == 0)
			return 1;
	return 0;
}

int InCompare(char* word)
{
	char CompareSigns[5][3] = { "<", ">", "<>", ">=", "<=" };
	for (int i = 0; i < 5; i++)
		if (strcmp(word, CompareSigns[i]) == 0)
			return 1;
	return 0;
}

void editClasses()
{
	char keyWords[2][6] = { "while", "do" };
	for (int i = 0; i < countLexems; i++)
	{
		if (InKeyWords(lex[i].word))
		{
			char temp[50] = { "�������_" };
			strcat(temp, keyWords[InKeyWords(lex[i].word) - 1]);
			strcpy(lex[i].key, temp);
		}
		else if (InOpWords(lex[i].word)) strcpy(lex[i].key, "����");
		else if (InCompare(lex[i].word)) strcat(lex[i].key, " ��");
	}
}