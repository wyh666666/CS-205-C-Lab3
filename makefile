objects = scan_dir.o stack.o tree.o process_input.o

scan_dir : $(objects)
	gcc -Wall $(objects) -o scan_dir

process_input.o : Lab3.h
scan_dir.o : Lab3.h stack.h
stack.o : Lab3.h stack.h
tree.o : Lab3.h tree.h

clean :
	rm scan_dir $(objects)