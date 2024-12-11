#include "main.h"

int read_and_validate(char *argv[])
{
    FILE *fptr = fopen(argv[1],"r");

    if(fptr == NULL)
    {
        printf("Unable to open %s file\n",argv[1]);
        return FAILURE;
    }
    
    fclose(fptr);

    return SUCCESS;
}

int check_type(char *argv[])
{
    char ch;
    char buffer[100];
    int count = 0,count1 =0, flag = 0,i=0;

    FILE *fptr = fopen(argv[1],"r");

    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch == '{' || ch == '}' || ch == ';')
        {
            printf("%c\t: SYMBOL\n",ch);
        }
        else if(ch == '(' || ch == ')')
        {
            printf("%c\t: OPERATOR\n",ch);
        }
        else if(ch == '#')
        {
            while((ch = fgetc(fptr)) != '\n');
            fseek(fptr,-1,SEEK_CUR);
        }
        else if(ch == '/')
        {
            if((ch = fgetc(fptr)) == '/')
            {
                while((ch = fgetc(fptr)) != '\n');
                fseek(fptr,-1,SEEK_CUR);
            }
            else if(ch == '*')
            {
                while((ch = fgetc(fptr)) != '/');
                fseek(fptr,-1,SEEK_CUR);
            }
            else if(ch == '=')
            {
                printf("/=\t: OPERATOR\n");
            }
        }
        else if(isdigit(ch))
        {
            buffer[count++] = ch;
            while(isdigit(ch = fgetc(fptr)) || ch == '.')
            buffer[count++] = ch;
            buffer[count] = '\0';
            fseek(fptr,-1,SEEK_CUR);
            count = 0;
            if(strstr(buffer,"."))
            {
                printf("%s\t: FLOAT CONSTANT\n",buffer);
            }
            else
            printf("%s\t: NUMERIC CONSTANT\n",buffer);
        }
        else if(ch == '\'')
        {
            ch = fgetc(fptr);
            printf("%c\t: CHARACTER CONSTANT\n",ch);
            ch = fgetc(fptr);
        }
        else if(ch == '"')
        {
            while((ch = fgetc(fptr)) != '"')
            {
                buffer[count] = ch;
                count++;
            }
            printf("%s\t: LITERAL\n",buffer);
            count = 0;

        }
        else if(isalpha(ch) || ch == '_')
        {
            buffer[count++] = ch;
            while(isalpha(ch = fgetc(fptr)) || isdigit(ch) || ch == '_')
            buffer[count++] = ch;
            buffer[count] = '\0';
            fseek(fptr,-1,SEEK_CUR);
            count = 0;

            if(is_keyword(buffer) == SUCCESS)
            {
                printf("%s\t: KEYWORD\n",buffer);
            }
            else
            {
                printf("%s\t: IDENTIFIER\n",buffer);
            }
        }
        else if(my_is_punct(ch))
        {
            buffer[count++] = ch;
            while(my_is_punct(ch = fgetc(fptr)))
            buffer[count++] = ch;
            buffer[count] = '\0';
            fseek(fptr,-1,SEEK_CUR);
            count = 0;

            if(is_operator(buffer) == SUCCESS)
            {
                printf("%s\t: OPERATOR\n",buffer);
            }
        } 
    }
    return SUCCESS;
}

