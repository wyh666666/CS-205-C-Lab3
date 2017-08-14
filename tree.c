/*
* @Author: Caesar
* @Date:   2017-08-11 10:32:06
* @Last Modified by:   Caesar
* @Last Modified time: 2017-08-14 14:07:18
*/
#include "tree.h"

/**
 * Add node into a tree
 * @param  root The root of the tree
 * @param  node 
 * @return      0: for success; 1: for failure;
 */
int add(FILE_NODE *root, FILE_NODE *node){
	if(root == NULL){
		root = node;
		return 0;
	}else{
		int result = file_compare(root, node);
		if(0 == result){
			// Whether have same content
			FILE *fp1;
			FILE *fp2;
			if((fp1 = fopen(root -> address, "rb")) == NULL || (fp2 = fopen(node -> address, "rb")) == NULL){
				if(fp1 == NULL && fp2 == NULL){
					fclose(fp1);
					fclose(fp2);
					return 1;
				}else if(fp1 == NULL){
					strncpy(root -> address, node -> address, ADD_SIZE);
					FILE_NODE *same = root -> same;
					root -> same = NULL;
					fclose(fp1);
					fclose(fp2);
					if(same != NULL){
						add(node, same);
					}
				}else{
					fclose(fp1);
					fclose(fp2);
					return 1;
				}
			}else{
				while(feof(fp1) == 1 || feof(fp2) == 1){
					char c1 = fgetc(fp1);
					char c2 = fgetc(fp2);
					if(GLOBAL.debug == 1){
						fprintf(stderr, "%c\t%c\n", c1, c2);
					}
					
					if(c1 != c2){
						fclose(fp1);
						fclose(fp2);
						if(root -> sibling != NULL){
							add(root -> sibling, node);
						}else{
							root -> sibling = node;
						}
						return 0;
					}
				}
				fclose(fp1);
				fclose(fp2);
				if(root -> same != NULL){
					add_same(root, node);
				}else{
					root -> same = node;
				}
				char *add_root = root -> address;
				char *add_node = node -> address;
				if(GLOBAL.debug == 1){
					fprintf(stderr, "%s\t%s\n", add_root, add_node);
				}	
			}
		}else if(1 == result){
			// root is bigger than node
			if(root -> left != NULL){
				add(root -> left, node);
			}else{
				root -> left = node;
			}
		}else{
			// root is smaller than node
			if(root -> right != NULL){
				add(root -> right, node);
			}else{
				root -> right = node;
			}

		}
	}
	return 0;
}

/**
 * Add the node to the root which have same file
 * @param  root 
 * @param  node 
 * @return      0 for success
 */
int add_same(FILE_NODE *root, FILE_NODE *node){
	if(root -> same == NULL){
		root -> same = node;
	}else{
		add_same(root -> same, node);
	}
	return 0;
}



/**
 * Compare the size of two file
 * @param  fp1 
 * @param  fp2 
 * @return     0: fp1 = fp2; 1: fp1 > fp2; -1: fp1 < fp2
 */
int file_compare(FILE_NODE *fp1, FILE_NODE *fp2){
	long size1 = fp1 -> size;
	long size2 = fp2 -> size;
	if(size1 == size2){
		return 0;
	}else if(size1 > size2){
		return 1;
	}else{
		return -1;
	}
}

/**
 * Construct a new FILE_NODE
 * @param  address 
 * @return         pointer of the node
 */
FILE_NODE *new_FILE_NODE(char *address){
	FILE_NODE *file_new = NULL;
	file_new = (FILE_NODE *)malloc(sizeof(FILE_NODE));
	strncpy(file_new -> address, address, ADD_SIZE);
	FILE *fp;
	if((fp = fopen(file_new -> address, "rb")) != NULL){
		fseek(fp, 0L, SEEK_END);
		file_new -> size = (long)ftell(fp);
		fclose(fp);
		if(GLOBAL.debug == 1){
			fprintf(stderr, "The size of %s is %ld\n",file_new -> address, file_new -> size);
		}
		file_new -> left = NULL;
		file_new -> right = NULL;
		file_new -> same = NULL;
		file_new -> sibling = NULL;
		return file_new;
	}
	return NULL;
}


/**
 * Free the FILE_NODE
 * @param  node 
 * @return      0 for success; 1 for failure;
 */
int free_FILE_NODE(FILE_NODE *node){
	if(node != NULL){
		free(node);
		node = NULL;
	}else{
		return 1;
	}
	return 0;
}

/**
 * Print all the file have same size
 * @param  root 
 * @return      0 for success; 1 for failure;
 */
int print_same(FILE_NODE *root){
	if(root != NULL){
		if(root -> same != NULL){
			printf("%s\t%s\n", (root -> address) + GLOBAL.add_ignore, (root -> same -> address) + GLOBAL.add_ignore);
			print_same(root -> same);
		}
		if(root -> left != NULL){
			print_same(root -> left);
		}
		if(root -> right != NULL){
			print_same(root -> right);
		}
		return 0;
	}
	return 1;
}





