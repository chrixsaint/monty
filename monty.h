#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/**
 * struct montyNode_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct montyNode_s
{
	int n;
	struct montyNode_s *prev;
	struct montyNode_s *next;
} MontyNode_t;

/**
 * struct struct_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * carries values through the program
 */
typedef struct struct_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  struct_t;
extern struct_t bus;
/**
 * struct comand_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project.
 */
typedef struct comand_s
{
	char *opcode;
	void (*f)(MontyNode_t **stack, unsigned int line_number);
} comand_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void  opcodePush(MontyNode_t **head, unsigned int number);
void   prntAll(MontyNode_t **head, unsigned int number);
void   topPrinter(MontyNode_t **head, unsigned int number);
int funcnCaller(char *content, MontyNode_t **head,
unsigned int counter, FILE *file);
void  clearStack(MontyNode_t *head);
void  remove_top(MontyNode_t **head, unsigned int counter);
void exchange(MontyNode_t **head, unsigned int counter);
void sum(MontyNode_t **head, unsigned int counter);
void   redundant(MontyNode_t **head, unsigned int counter);
void subtrakt(MontyNode_t **head, unsigned int counter);
void    divider(MontyNode_t **head, unsigned int counter);
void  multply(MontyNode_t **head, unsigned int counter);
void  computeMod(MontyNode_t **head, unsigned int counter);
void prnt_char(MontyNode_t **head, unsigned int counter);
void right_rotatn(MontyNode_t **head, __attribute__((unused)) unsigned int counter);
void insertNode(MontyNode_t **head, int n);
void left_rotatn(MontyNode_t **head, unsigned int counter);
void addqueue(MontyNode_t **head, int n);
void switch_stack(MontyNode_t **head, unsigned int counter);
void enqueue(MontyNode_t **head, unsigned int counter);
void prnt_strng(MontyNode_t **head, unsigned int counter);

#endif
