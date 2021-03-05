#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lineChecker.c"
#include "lineparsar.c"
#include "support.c"


int main()
{
    FILE* ptrF;
    char arr[100][100];
    ptrF = fopen("test10.c","r");

    if(ptrF != NULL)
    {
        int rowNum = 0;
        while (fgets(*(arr+rowNum), 100, ptrF) != NULL)
            printf("%s", *(arr+rowNum++));

        fclose(ptrF);
    }

    int rows = numberOfLines("test10.c");
    processFile (rows-1, 100 , arr);

    return 0;
}












