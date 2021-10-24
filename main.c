#include<stdio.h>
void main(int argc , char **argv)
{
    if (argc != 3)
        printf("You need to enter two arguments");
    else
    {
        FILE *first_file, *second_file;
        char c;

        first_file = fopen(argv[1],"r");
        second_file = fopen(argv[2],"w");

        
        while((c = fgetc(first_file)) !=EOF)
            fputc(c, second_file);
        
        fclose(first_file);
        fclose(second_file);
    }

}