#ifndef __TREE_H__
#define __TREE_H__
#include "Lab3.h"

int file_compare(FILE_NODE *fp1, FILE_NODE *fp2);
int add(FILE_NODE *root, FILE_NODE *node);
int add_same(FILE_NODE *root, FILE_NODE *node);
FILE_NODE *new_FILE_NODE(char *address);
int free_FILE_NODE(FILE_NODE *node);
int print_same(FILE_NODE *root);

#endif