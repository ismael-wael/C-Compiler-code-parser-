#include "lineChecker.h"

char* specifyLineMeaning(char* line)
{
    static char* msg;

    if(isIf(line))
    {
        msg = "if condition";
    }
    else if(isFunction(line))
    {
       msg = "function";
    }
    else if(isFor(line))
    {
        msg = "for loop";
    }
    else if(isWhile(line))
    {
        msg = "while loop";
    }
    else if(isDoWhile(line))
    {
        msg = "do while loop";
    }
    else if(isSwitch(line))
    {
        msg = "switch case";
    }
    else if(isStatement(line))
    {
        msg = "statement";
    }
    else if(isIgnore(line))
    {
        msg = line;
    }
    else{
        msg = "syntax error";
    }
    return msg;
}

int isWhile(char* line)
{
    char* whileLoopTemplates[3] = {" while ( Identifier Binary_Operator INT_CONSTANT )",
                                   " while ( Identifier )",
                                   " while ( INT_CONSTANT )"};
    for(int i = 0 ; i < 3 ; i++)
    {
        if(comapreString(line ,whileLoopTemplates[i]))
            return 1;
    }

    return 0;
}

int isFor(char* line)
{
    char* forLoopTemplates[13] = {" for ( dataType Identifier = INT_CONSTANT ; Identifier Binary_Operator INT_CONSTANT ; Identifier = Identifier Binary_Operator INT_CONSTANT )",
                                 " for ( dataType Identifier = INT_CONSTANT ; Identifier Binary_Operator INT_CONSTANT ; Identifier unary_Operator )",
                                 " for ( dataType Identifier = INT_CONSTANT ; Identifier Binary_Operator INT_CONSTANT ; unary_Operator Identifier )",
                                 " for ( Identifier = INT_CONSTANT ; Identifier Binary_Operator INT_CONSTANT ; Identifier = Identifier Binary_Operator INT_CONSTANT )",
                                 " for ( Identifier = INT_CONSTANT ; Identifier Binary_Operator INT_CONSTANT ; Identifier unary_Operator )",
                                 " for ( Identifier = INT_CONSTANT ; Identifier Binary_Operator INT_CONSTANT ; unary_Operator Identifier )",
                                 " for ( Identifier = INT_CONSTANT ; ; )",
                                 " for ( dataType Identifier = INT_CONSTANT ; ; )",
                                 " for ( ; Identifier Binary_Operator INT_CONSTANT ; Identifier = Identifier Binary_Operator INT_CONSTANT )",
                                 " for ( ; Identifier Binary_Operator INT_CONSTANT ; Identifier unary_Operator )",
                                 " for ( ; Identifier Binary_Operator INT_CONSTANT ; unary_Operator Identifier )",
                                 " for ( ; Identifier Binary_Operator INT_CONSTANT ; )",
                                 " for ( ; ; )"};
    for(int i = 0 ; i < 13 ; i++)
    {
        if(comapreString(line ,forLoopTemplates[i]))
            return 1;
    }

    return 0;
}

/*function = " dataType Identifier ( dataType Identifier , dataType Identifier , dataType Identifier )"};
    argumnets can be infinite*/
int isFunction(char* line)
{
    char* argument = " dataType Identifier ";

    int start = 0;
    int end = strlen(argument);
    int i ;

    for(i = start ; i < end ; i++)
    {
        if(line[i] != argument[i])
            return 0;
    }

    if(line[i++] != '(')
        return 0;


    start = i;
    end += start;

    while(line[start+1] != ')')
    {
        for(i = start ; i < end ; i++)
        {
            if(line[i] != argument[i-start])
                    return 0;
        }

        if(line[i] == ')')
            return 1;
        else if (line[i++] != ',')
            return 0;

        start = i;
        end = start+strlen(argument);
    }

    return 1;
}

int isIf(char* line)
{
    char* ifTemplates[3] = {" if ( Identifier Binary_Operator Identifier )",
                            " if ( Identifier Binary_Operator INT_CONSTANT )",
                            " if ( Identifier )"};
    for(int i = 0 ; i < 3 ; i++)
    {
        if(comapreString(line ,ifTemplates[i]))
            return 1;
    }

    return 0;
}

int isSwitch(char* line)
{
    char* SwitchTemplates[3] = {" switch ( Identifier )",
                                " switch ( Identifier Binary_Operator INT_CONSTANT )",
                                " switch ( Identifier Binary_Operator Identifier )"};

    for(int i = 0 ; i < 3 ; i++)
    {
        if(comapreString(line ,SwitchTemplates[i]))
            return 1;
    }

    return 0;
}

int isDoWhile(char* line)
{
    char* doWhileTemplates[3] = {" } while ( Identifier ) ;",
                                 " } while ( Identifier Binary_Operator INT_CONSTANT ) ;",
                                 " } while ( Identifier Binary_Operator Identifier ) ;"};

    for(int i = 0 ; i < 3 ; i++)
    {
        if(comapreString(line ,doWhileTemplates[i]))
            return 1;
    }

    return 0;
}

int isStatement(char* line)
{
    char* statementsTemplates[14]={" dataType Identifier = INT_CONSTANT ;",
                                   " Identifier = INT_CONSTANT ;",
                                   " Identifier = INT_CONSTANT ;",
                                   " Identifier unary_Operator ;",
                                   " unary_Operator Identifier ;",
                                   " dataType Identifier ;",
                                   " return ;",
                                   " return Identifier ;",
                                   " return INT_CONSTANT ;",
                                   " case INT_CONSTANT :",
                                   " case INT_CONSTANT : Identifier = INT_CONSTANT ;",
                                   " default : Identifier = INT_CONSTANT ;",
                                   " default :",
                                   " break ;"};

    for(int i = 0 ; i < 14 ; i++)
    {
        if(comapreString(line ,statementsTemplates[i]))
            return 1;
    }

    return 0;
}
int isIgnore(char*line)
{
    char* ignoreTemplates[4] = {" {",
                                " }",
                                " else",
                                " return"};
    for(int i = 0 ; i < 4 ; i++)
    {
        if(comapreString(line ,ignoreTemplates[i]))
            return 1;
    }

    return 0;
}



