#ifndef LEX_ANA
#define LEX_ANA

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SUCCESS 1
#define FAILURE -1


int read_and_validate(char *argv[]);

int is_keyword(char *str);

int is_operator(char *str);

int check_type(char *argv[]);

int my_is_punct(char ch);

#endif
