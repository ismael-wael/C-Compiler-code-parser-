#ifndef LINE_CHECKER_
#define	LINE_CHECKER_

char* specifyLineMeaning(char* line);
int isWhile(char* line);
int isFunction(char* line);
int isFor(char* line);
int isDoWhile(char* line);
int isSwitch(char* line);
int isIf(char* line);
int isStatement(char* line);
int isIgnore(char*line);

#endif
