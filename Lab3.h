#ifndef __LAB_3_H__
#define __LAB_3_H__
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define ADD_SIZE 1000
#define NAME_SIZE 250

typedef struct dir_node{
	char address[ADD_SIZE];
	struct dir_node *next;
}DIR_NODE;

typedef struct file_node{
	char address[ADD_SIZE];
	long size;
	struct file_node *left; // Left node of the subtree
	struct file_node *right; // Right node of the subtree
	struct file_node *sibling; // Have same size 
	struct file_node *same; // Same file
}FILE_NODE;

typedef struct dir_stack{
	DIR_NODE *head;
}DIR_STACK;

struct globalArgs_t{
	int detail;
	int debug;
	char *add_ori;
	int add_ignore;
	FILE_NODE *root;
	DIR_STACK *dir_stack;
}GLOBAL;

static const char *optString = "vd";
FILE_NODE *root;
int add_ignore;

int process(int argc, char **argv);

#endif
