/*
* @Author: nixizi
* @Date:   2017-08-11 15:38:43
* @Last Modified by:   nixizi
* @Last Modified time: 2017-08-12 00:53:44
*/
#include "Lab3.h"

/**
 * Process the input type in command
 * @param  argc 
 * @param  argv 
 * @return      0 for success
 */
int process(int argc, char **argv){
	int opt = 0;
	GLOBAL.detail = 0;
	GLOBAL.debug = 0;
	char defauleAddress[] = "/home/caesar/Documents";
	GLOBAL.add_ori = defauleAddress;
	GLOBAL.add_ignore = 23;
	GLOBAL.root = NULL;
	GLOBAL.dir_stack = (DIR_STACK *)malloc(sizeof(DIR_STACK));
	opt = getopt(argc, argv, optString);
	while(-1 != opt){
		switch(opt){
			case 'v':
				GLOBAL.detail = 1;
				break;
			case 'd':
				GLOBAL.debug = 1;
				break;
			default:
				fprintf(stderr, "Input Error!\n Please enter argument like -v visual, -d debug, searching address");
				break;
		}
		opt = getopt(argc, argv, optString);
	}
	if(optind + 1 == argc){
		GLOBAL.add_ori = argv[optind];
		fprintf(stderr, "%s\n", GLOBAL.add_ori);
		int len = strlen(GLOBAL.add_ori);
		if(GLOBAL.add_ori[len - 2] == '/'){
			GLOBAL.add_ori[len - 2] = '\0';
			len = len - 1;
		}
		GLOBAL.add_ignore = len + 1;
	}
	return 0;
}