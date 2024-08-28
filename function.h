#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "shelldata.h"

extern char **environ;

void begin(shelldata_t *mytype);
int number(int num);
char *stringify(int numbe);
int isNumeric(unsigned int number);
int hasLetter(char *string);
char **tokenize_words(char *string, const char *del);
char *mergeWords(char *w1, char *w2, char *w3, const char *del);
char *parse_prompt(void);
void initiatePrompt(shelldata_t *mytype);
void signatureHandler(int num);
int writeCharacter(char character);
int display(char *message);
int displayError(char *message);
void getInput(shelldata_t *mytype);
int writeCharacterToFD(char cha, int fil_d);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int outputToFD(char *message, int fil_d);
int isExecutable(char *name);
int isFile(char *filename);
char *exchange(shelldata_t *mytype, int *id, char *word);
int writeCharacterToFD(char cha, int fil_d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *subEnv(shelldata_t *mytype, char *envi_var);
void patternAnalysis(shelldata_t *mytype, char **args);
char *handle_pattern(shelldata_t *mytype, char *words);
char *subtituteValue(shelldata_t *info, int *id, char *str);
void releaseMemory(void *pointer);
void releaseMemoryPointer(void **pointer);
void binaryExit(shelldata_t *mytype, char **args);
int manageNumbers(shelldata_t *mytype, char *argument);
void run(char *cmd, char **argu, shelldata_t *mytype, char *buffer);
int getCurrentDir(char *command, char **argu, char *buff, shelldata_t *mytype);
void issue(shelldata_t *mytype);
char *selectMessage(shelldata_t mytype);
void additionalError(shelldata_t *mytype, char *more);
char *getEnv(const char *variable);
char *choose(char *dirname, shelldata_t *mytype);
void isCurrPath(char *pat, shelldata_t *mytype);
void fetchFullEnv(void);
void binaryEnv(shelldata_t *mytype, char **args);
int systemFunction(shelldata_t *mytype, char **args);
int verifyBuiltin(shelldata_t *mytype, char **args);
void evaluate(char **args, shelldata_t *mytype, char *buffer);
int _atoi(char *s);
#endif
