extern struct Dict
{
	char letter;
	char key[11];
};
int countSyms = 0;
struct Dict words[100];

extern struct Lexems
{
	char word[50];
	char key[20];
};
int countLexems = 0;
struct Lexems lex[30];