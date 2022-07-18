#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lexic.h"

enum SyntaxStates
{
	start,
	stateWhile,
	ident1,
	compare,
	ident2,
	stateDo,
	ident3,
	equalSyntax,
	ident4,
	bracket1,
	hexSyntax,
	op,
	numSyntax,
	bracket2,
	semicolon
} stateSyntax;

stateSyntax = start;

int check(int i)
{
	if (stateSyntax == start)
		if (strcmp(lex[i].key, "клслово_while") != 0) return 0;
		else
		{
			stateSyntax = stateWhile;
			return 1;
		}
	if (stateSyntax == stateWhile)
		if (strcmp(lex[i].key, "идент") != 0) return 0;
		else 
		{
			stateSyntax = ident1;
			return 1;
		}
	if (stateSyntax == ident1) 
		if (strcmp(lex[i].key, "знак ср") != 0) return 0;
		else 
		{
			stateSyntax = compare;
			return 1;
		}
	if (stateSyntax == compare)
		if (strcmp(lex[i].key, "идент") != 0) return 0;
		else
		{
			stateSyntax = ident2;
			return 1;
		}
	if (stateSyntax == ident2) 
		if(strcmp(lex[i].key, "клслово_do") != 0) return 0;
		else
		{
			stateSyntax = stateDo;
			return 1;
		}
	if (stateSyntax == stateDo) 
		if(strcmp(lex[i].key, "идент") != 0) return 0;
		else
		{
			stateSyntax = ident3;
			return 1;
		}
	if (stateSyntax == ident3) 
		if(strcmp(lex[i].key, "равно") != 0) return 0;
		else
		{
			stateSyntax = equalSyntax;
			return 1;
		}
	if (stateSyntax == equalSyntax) 
		if (strcmp(lex[i].key, "идент") != 0) return 0;
		else
		{
			stateSyntax = ident4;
			return 1;
		}
	if (stateSyntax == ident4)
		if (strcmp(lex[i].key, "скобка") != 0 || strcmp(lex[i].word, "[") != 0) return 0;
		else
		{
			stateSyntax = bracket1;
			return 1;
		}
	if (stateSyntax == bracket1)
		if (strcmp(lex[i].key, "шестн. конст") != 0) return 0;
		else
		{
			stateSyntax = hexSyntax;
			return 1;
		}
	if (stateSyntax == hexSyntax)
		if (strcmp(lex[i].key, "знак") != 0) return 0;
		else 
		{
			stateSyntax = op;
			return 1;
		}
	if (stateSyntax == op)
		if (strcmp(lex[i].key, "целое") != 0) return 0;
		else
		{
			stateSyntax = numSyntax;
			return 1;
		}
	if (stateSyntax == numSyntax)
		if (strcmp(lex[i].key, "скобка") != 0 || strcmp(lex[i].word, "]") != 0) return 0;
		else
		{
			stateSyntax = bracket2;
			return 1;
		}
	if (stateSyntax == bracket2)
		if (strcmp(lex[i].key, "тчкзпт") != 0) return 0;
		else
		{
			stateSyntax = semicolon;
			return 1;
		}
	return 0;
}

char* Result()
{
	stateSyntax = start;
	char* result = (char*)malloc(12);
	for (int i = 0; i <= countLexems; i++)
	{
		if (strcmp(lex[i].word, " ") != 0 && strcmp(lex[i].word, "") != 0 && check(i) == 0)
		{
			strcpy(result, "REJECTED");
			return result;
		}
	}
	if (stateSyntax != semicolon)
		strcpy(result, "REJECTED");
	else strcpy(result, "ACCEPTED");
	return result;
}