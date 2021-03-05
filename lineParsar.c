#include "lineParsar.h"

char* scanner(char* line)
{
    char token[20];
    int j;
    char* x = (char*) calloc(100,sizeof(char));
    for (int i = 0 ; line[i] != '\n' ; )
    {
        while(line[i] != '\n' && isspace(line[i]))
            i++;
        j = 0;
        while(line[i] != '\n' && !(isspace(line[i])))
            token[j++] = line[i++];
        token[j] = '\0';
        char* tokenType = specifyTokenType(token);
        if(comapreString(tokenType , "inCorrect Token"))
        {
            x = "Misspelled word/s";
            return x;
        }
        else if(comapreString(tokenType , "Keyword") || comapreString(tokenType , "special_symbol")){
            x = stringConc(x,token);
        }
        else{
            x = stringConc(x,tokenType);
        }
    }
    return x;
}

char* specifyTokenType(char* token)
{
    static char* msg;
    if(isResevedWord(token))
    {
       msg = "Keyword";
    }
    else if(isBinaryOperator(token))
    {
        msg = "Binary_Operator";
    }
    else if(isUnaryOperator(token))
    {
        msg = "unary_Operator";
    }
    else if(isSpecialSymbol(token))
    {
        msg = "special_symbol";
    }
    else if(isNumber(token))
    {
        msg = "INT_CONSTANT";
    }
    else if(isDataType(token))
    {
        msg = "dataType";
    }
    else if(isIdentifier(token))
    {
        msg = "Identifier";
    }
    else if(isEqual(token))
    {
        msg = "=";
    }
    else
    {
        msg = "inCorrect Token";
    }
    return msg;
}

int isResevedWord(char* token)
{
    char* reservedKeywords[27] = {"auto", "break" , "case" ,"const",
                                  "continue","default","do","else",
                                  "enum","extern","for","goto","if",
                                  "long","register","return","short",
                                  "signed","sizeof","static","struct",
                                  "switch","typedef","union","unsigned",
                                  "volatile","while"};

    for(int i = 0 ; i < 27 ; i++)
    {
        if(comapreString(token , reservedKeywords[i]))
            return 1;
    }

    return 0;
}

int isDataType(char* token)
{
    char* dataTypes[5] = {"char","int","float","double","void"};

    for(int i = 0 ; i < 5 ; i++)
    {
        if(comapreString(token , dataTypes[i]))
            return 1;
    }

    return 0;
}

int isBinaryOperator(char* token)
{
    char* operators[15] = {"+" , "-" , "*" , "/" , "%" ,"~" ,
                           "^" , "&" , "|" , "<" ,">"  , ">=" ,
                           "<=","||", "&&"};

    for(int i = 0 ; i < 15 ; i++)
    {
        if(comapreString(token , operators[i]))
            return 1;
    }
    return 0;
}

int isUnaryOperator(char* token)
{
    char* operators[3] = { "++" , "--", "!"};

    for(int i = 0 ; i < 3 ; i++)
    {
        if(comapreString(token , operators[i]))
            return 1;
    }
    return 0;
}

int isSpecialSymbol(char* token)
{
    char* specialSymbols[16] = {"#" , "$", "(" , ")" , "_" ,
                                "\\" ,"{" , "}" ,"[" , "]" ,
                                ":" , "\"" , ";" ,"?" , "," , "."};

    for(int i = 0 ; i < 16 ; i++)
    {
        if(comapreString(token , specialSymbols[i]))
            return 1;
    }
    return 0;
}

int isNumber(char* token)
{
    for(int i = 0 ; token[i] ; i++)
    {
        if(!isdigit(token[i]))
            return 0;
    }
    return 1;
}

int isIdentifier(char* token)
{
       if(token[0] == '_' || isalpha(token[0]))
       {
            for(int i = 0 ; token[i] ; i++)
            {
                if(isalpha(token[i]) || isdigit(token[i]) || token[i] == '_')
                    ;
                else
                    return 0;
            }
            return 1;
       }
       return 0;
}

int isEqual(char* token)
{
    return comapreString(token , "=");
}





