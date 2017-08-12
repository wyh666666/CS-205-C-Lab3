#ifndef __STACK_H__
#define __STACK_H__
#include "Lab3.h"

DIR_NODE *new_DIR_NODE(char *address);
int free_DIR_NODE(DIR_NODE *node);
int push(DIR_STACK *stack, DIR_NODE *node);
DIR_NODE *pull(DIR_STACK *stack);
int print_all(DIR_STACK *stack);
int is_empty(DIR_STACK *stack);

#endif