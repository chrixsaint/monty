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
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_struct
{
	int n;
	struct stack_struct *prev;
	struct stack_struct *next;
} tmp_stack;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(tmp_stack **stack, unsigned int line_number);
} instruction_t;
/**
* struct col_s - Struct for holding context data.
* @arg:  Argument string passed to Monty program
* @line: Current line being processed from Monty file
* @file: File pointer to Monty file being interpreted
*/
typedef struct col_s
{
	char *arg;
	char *line;
	FILE *file;
} col_t;

extern col_t col;

int funcnCaller(char *line, unsigned int line_number, tmp_stack **stack);
/*void parse_line(char *line, char *opcode, char *arg); */
void opcodePush(tmp_stack **stack, unsigned int line_number);
void stakPusher(tmp_stack **stack, int value);
void clearStack(tmp_stack **stack);
void prntAll(tmp_stack **head, unsigned int line_number);
void topPrinter(tmp_stack **top, unsigned int line_number);
void remove_top(tmp_stack **top, unsigned int line_number);
void exchange(tmp_stack **top, unsigned int line_number);
void sum(tmp_stack **top, unsigned int line_number);
void redundant(tmp_stack **top, unsigned int line_number);
void subtrakt(tmp_stack **top, unsigned int line_number);
void multply(tmp_stack **top, unsigned int line_number);
int intChecker(int num);
void divider(tmp_stack **top, unsigned int line_number);
void computeMod(tmp_stack **top, unsigned int line_number);
#endif
