#ifndef LINE_PARSAR_
#define	LINE_PARSAR_

char* scanner(char* line);
char* specifyTokenType(char* token);
char* stringConc(char* first, char* second);
int comapreString(char* str1 , char* str2);
int isResevedWord(char* token);
int isSpecialSymbol(char* token);
int isNumber(char* token);
int isIdentifier(char* token);
int isDataType(char* token);
int isBinaryOperator(char* token);
int isUnaryOperator(char* token);
int isEqual(char* token);

#endif
