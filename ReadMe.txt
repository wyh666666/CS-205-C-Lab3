This excercise is for CS 205  C/C++ course in SUStech
Written by 11510602 Ni Xizi/ 11612027 Zhang Jinpeng

Lab 3 require to search all the file in a folder, print the name of same file in stdout.

The user need to enter the address that he/she wants to search.
If the address is missed, the default folder is current woring path.
If -p is missed, the default search model is fast search.

Fast search: the running time will be fast, but the accuracy is low, only check parks of the data in file.

Precise search: the running time  will be slow, compare byte by byte. But the accuracy is 100%.

Also have some option.
	-v for visualize details default false
	-d for debug model default false
	-p for precise search model
The correct input format should be like following
	./scan_dir -v -d -p /home/caesar/root


process_input.c
	This file define a function to process the input from the user.
	Also for initialize the global variable

tree.c
	This file contain some functions to operate tree
	Only avilable for FILE_NODE strcture

stack.c
	This file contain some functions to operate stack
	Only avilable for DIR_NODE strcture

scan_dir.c
	This file contain the main function
	Search every thing in the folder and put it into a stack.
	Search every folder in the stack
	Put every file into a tree
	In the tree, search for the same file. And store it.
	At the end of the program, print all the name of the same file.

Lab3.h
	Contain all the structs and global variables

tree.h
	Contain the head of functions for operating tree

stack.h
	Contain the head of functions for operating stack

