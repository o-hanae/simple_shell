#ifndef P_SHELL_H
#define P_SHELL_H

/** preprocessors **/
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

/** MACRO **/
#define MAX_ARGS 20
#define FILE_END -2
#define EXIT -3

/** global **/
extern char **environ;/** environment extern var **/

/**
 * struct link_s - linked list struct
 *
 * Description:
 * @dir: directory
 * @nex: new pointer to struct link_s.
 *
 */

typedef struct link_s
{
	char *dir;
	struct link_s *nex;
} link_t;

/**
 * struct inbuilt_s - struct for builtin commands
 *
 * Description:
 * @name: builtin command name
 * @f: function pointer
 *
 */

typedef struct inbuilt_s
{
	char *name;
	int (*f)(char **argv, char **ahead);
} inbuilt_t;

/**
 * struct alias_s - struct for defining alias
 *
 * Description:
 * @name: aliaas anem
 * @value: alias value
 * @nex: pointer to new alais
 *
 */

typedef struct alias_s
{
	char *value;
	char *name;
	struct alias_s *nex;
} alias_t;

/** global linked list alias **/
alias_t *aliaz;

/** MAIN **/
char *p_atoi(int numb);
ssize_t p_getline(char **lneptr, size_t *w, FILE *strm);
link_t *path_dir(char *path);
void *p_realloc(void *ptr, unsigned int prev_size, unsigned int pres_size);
char *acq_location(char *prompt);
char **p_strtok(char *strg, char *delimeter);
void list_free(link_t *top);
int execute(char **args, char **ahead);

/** p_shell.c functions **/
int execute(char **args, char **ahead);
void sigHandler(int sign);

/** for input **/
char **alias_replace(char **args);
void handleLine(char **line, ssize_t read);
void args_free(char **args, char **ahead);
void rep_variable(char **args, int *exec);
int args_call(char **args, char **ahead, int *exec);
char *args_acq(char *line, int *exec);
int args_run(char **args, char **ahead, int *exec);
int args_check(char **args);
int args_handle(int *exec);
