#include "main.h"

int is_keyword(char *str)
{
    char key_word[32][20] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};


    for(int i=0;i<32;i++)
    {
        if(strcmp(str,key_word[i]) == 0)
        return SUCCESS;
    }

    return FAILURE;
}

int is_operator(char *str)
{
    char operator[100][20] = {"[","]","+","-","*","/","%","==","!=",">","<",">=","<=","&&","||","!","&","|","^","~","<<",">>","=","+=","-=","*=","/=","%=","++","--","?",":","*","&",".","->",","};

    for(int i=0;i<47;i++)
    {
        if(strcmp(str,operator[i]) == 0)
        return SUCCESS;
    }
    return FAILURE;
}

int my_is_punct(char ch)
{
    char punct[18][1] = {"[","]","+","-","*","%","=","!",">","<","&","|","^","~","?",":",".","-"};

    for(int i=0;i<18;i++)
    {
        if(ch == punct[i][0])
        return 1;
    }
    return 0;
}
