/*
* @Author: nixizi
* @Date:   2017-08-10 16:43:07
* @Last Modified by:   nixizi
* @Last Modified time: 2017-08-12 00:53:18
*/

#include "stack.h"
#include "Lab3.h"

/**
 * Push a dir_node into stack
 * @param  stack The operating stack
 * @param  node  
 * @return       0 means success
 */
int push(DIR_STACK *stack, DIR_NODE *node){
	DIR_NODE *head = stack -> head;
	if(head == NULL){
		stack -> head = node;
	}else{
		node -> next = stack -> head;
		stack -> head = node;
	}
	return 0;
}

/**
 * Construct a new DIR_NODE
 * @param  address The pointer of address
 * @return         The pointer of the new DIR_NODE
 */
DIR_NODE *new_DIR_NODE(char *address){
	DIR_NODE *dir_new = NULL;
	dir_new = (DIR_NODE *)malloc(sizeof(DIR_NODE));
	strncpy(dir_new -> address, address, ADD_SIZE);
	return dir_new;
}

/**
 * Free the node in memory
 * @param  node Pointer of the node
 * @return      0 for success
 */
int free_DIR_NODE(DIR_NODE *node){
	if(node != NULL){
		free(node);
		node = NULL;
	}else{
		return 1;
	}
	return 0;
}

/**
 * Pull the node at the top
 * @param  stack The operating stack
 * @return       The pointer of the node
 */
DIR_NODE *pull(DIR_STACK *stack){
	DIR_NODE *head = stack -> head;
	if(head == NULL){
		
		return NULL;
	}
	DIR_NODE *node = head;
	DIR_NODE *next = head -> next;
	stack -> head = next;
	return node;
}

int print_to_end(DIR_NODE *node){
	if(node != NULL){
		printf("%s\n", node -> address);
		print_to_end(node -> next);
	}
}

/**
 * Print all the information in the stack
 * @param  stack 
 * @return       0 for success
 */
int print_all(DIR_STACK *stack){
	DIR_NODE *head = stack -> head;
	if(head != NULL){
		print_to_end(head);
	}
}

/**
 * Check whether the stack is empty
 * @param  stack 
 * @return       0 for is empty. 1 for is not empty
 */
int is_empty(DIR_STACK *stack){
	if(stack -> head == NULL){
		return 0;
	}else{
		return 1;
	}
}

