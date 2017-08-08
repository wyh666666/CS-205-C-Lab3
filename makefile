objects = main.o

find_same : $(objects)
	gcc -Wall $(objects) -o find_same

main.o : xxx.h

clean :
	rm find_same $(objects)