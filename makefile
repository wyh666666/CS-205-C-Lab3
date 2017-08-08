objects = a.o b.o

a : $(objects)
	gcc -Wall $(objects) -o a

a.o : test.h b.h
b.o : b.h

clean :
	rm a $(objects)