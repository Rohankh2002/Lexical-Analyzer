#include "main.h"

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        if(read_and_validate(argv) == FAILURE)
        {
            return 0;
        }
        printf("INFO : Read and validation of %s file is done\n",argv[1]);

        if(check_type(argv) == FAILURE)
        {
            printf("INFO : Execution of %s file is terminated\n",argv[1]);
            return 0;
        }
        printf("INFO : Execution of %s file is done\n",argv[1]);
    }
    else
    {
        printf("ERROR : Insufficient arguments\n");
        printf("INFO : For execution provide argument like\n");
        printf("INFO : 'gcc main.c read_validate.c check_keyword_or_operator.c'\n");
        printf("INFO : './a.out [output_filename]'\n");
    }
    return 0;
}
