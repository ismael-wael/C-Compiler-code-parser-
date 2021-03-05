#include <stdio.h>
#include "support.h"

char* stringConc(char* first, char* second)
{
    int size = strlen(first) + strlen(second) + 2;
    char* z = (char*) malloc(size);
    int i = 0;
    while(*first)
        z[i++] = *first++;
    z[i++] = ' ';
    while(*second)
        z[i++] = *second++;
    z[i] = '\0';
    return z;
}

int comapreString(char* str1 , char* str2)
{
    int flag = 0;
    while(*str1 != '\0' && *str2 != '\0')
    {
        if(*str1 != *str2)
        {
            flag = 1;
            break;
        }
        *str1++;
        *str2++;
    }

    if(flag == 0 && *str1 == '\0' && *str2 == '\0')
        return 1;
    else
        return 0;
}

int numberOfLines(char* fileName)
{
    FILE *fp;
	int count = 0; // Line counter (result)
	char c; // To store a character read from file

	fp = fopen(fileName, "r");

	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n')
			count = count + 1;

	fclose(fp);

    return count;
}

int curlyBracketsChecker(char* line)
{
    static int curly = 0;
    if(comapreString(line , " {"))
        curly++;
    else if(comapreString(line , " }"))
        curly--;

    return curly ;
}

void processFile (int rows , int cols , char arr[][cols])
{
    int curly_counter = 0;

    for(int i = 0 ; i < rows ; i++)
    {
        char* x = scanner(arr[i]);
        //printf("%s\n",x);
        if(comapreString(x , "Misspelled word/s")){
            printf("SYNTAX ERROR at line %d",i+1);
            return;
        }
        else{
            char* y = specifyLineMeaning(x);
            if(comapreString(y , "syntax error"))
            {
                printf("SYNTAX at line %d",i+1);
                return;
            }
            else
            {
                printf("%s\n",y);
                curly_counter = curlyBracketsChecker(y);
                if(curly_counter < 0)
                {
                   printf("closing curly bracket without opening curly bracket");
                   return;
                }
            }
        }
    }

    if(curly_counter > 0)
        printf("missing curly bracket");
    else
        printf("no syntactical errors. good job");
}



