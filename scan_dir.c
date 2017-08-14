/*
* @Author: caesar
* @Date:   2017-08-10 13:52:23
* @Last Modified by:   caesar
* @Last Modified time: 2017-08-14 13:58:12
*/

#include "Lab3.h"
#include "stack.h"
#include "tree.h"

int main(int argc, char *argv[]) {
	process(argc, argv);
	fprintf(stderr, "Scanning %s\n", GLOBAL.add_ori);
	if(GLOBAL.debug == 1){
		fprintf(stderr, "Ignore: %d\n", GLOBAL.add_ignore);
	}
	DIR_NODE *dir_first;
	char add_cur[ADD_SIZE];
	strncpy(add_cur, GLOBAL.add_ori, ADD_SIZE);
	dir_first = new_DIR_NODE(add_cur);
	if(push(GLOBAL.dir_stack, dir_first) == 0){
		if(GLOBAL.detail == 1){
			fprintf(stderr, "Initialize success!\n");
		}
	}
	while(is_empty(GLOBAL.dir_stack)){
		DIR_NODE *dir_pull = pull(GLOBAL.dir_stack);
		strncpy(add_cur, dir_pull -> address, ADD_SIZE);
		free_DIR_NODE(dir_pull);//Free the node in memory
		DIR *dir;
		struct dirent *dp;
		if(GLOBAL.detail == 1){
			fprintf(stderr,"Opening: %s\n", add_cur);
		}
		if((dir = opendir(add_cur)) == NULL){
			if(GLOBAL.detail == 1){
				fprintf(stderr, "It is file\n");
			}
			char add_file[ADD_SIZE];
			strncpy(add_file, add_cur, ADD_SIZE);
			FILE_NODE *file_ptr;
			file_ptr = new_FILE_NODE(add_file);
			if(GLOBAL.root == NULL){
				GLOBAL.root = file_ptr;
			}else{
				add(GLOBAL.root, file_ptr);
			}
		}else{
			if(GLOBAL.detail == 1){
				fprintf(stderr, "Can open\n");
			}
			
			while((dp = readdir(dir)) != NULL){
				if(GLOBAL.debug == 1){
					fprintf(stderr, "current: %s\n", add_cur);
				}
				if((strcmp(dp -> d_name, ".") == 0) || (strcmp(dp -> d_name, "..") == 0)){
					continue;
				}
				if(GLOBAL.detail == 1){
					fprintf(stderr, "Scaning: %s\n", dp -> d_name);
				}
				char a[1];
				a[0] = '/';
				char add_new[ADD_SIZE];
				strncpy(add_new, add_cur, ADD_SIZE);
				strncat(add_new, a, 1);
				strncat(add_new, dp -> d_name, ADD_SIZE);
				DIR_NODE *dir_new = new_DIR_NODE(add_new);
				push(GLOBAL.dir_stack, dir_new);

			}
		}
		closedir(dir);
	}
	fprintf(stderr, "\n\n");
	fprintf(stderr, "Print all the same file\n");
	fprintf(stderr, "If nothing print on the screen, the searching address may wrong, or there are not same file\n");
	print_same(GLOBAL.root);
    return 0;
}