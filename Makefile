CC = gcc
AR = ar
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: isort libsorting.a txtfind libstrings.a
libsorting.a: sorting.o
	$(AR) -rcs libsorting.a $^
libstrings.a: strings.o
	$(AR) -rcs libstrings.a $^ 	
isort: main1.o libsorting.a
	$(CC) $(FLAGS) -o isort $^ -I.
txtfind: main2.o libstrings.a
	$(CC) $(FLAGS) -o txtfind $^ -I.	
main1.o: main1.c sorting.h
	$(CC) $(FLAGS) -c -o $@ $< -I.
main2.o: main2.c strings.h
	$(CC) $(FLAGS) -c -o $@ $< -I.		
sorting.o: sorting.c
	$(CC) $(FLAGS) -fPIC -c -o $@ $< -I.
strings.o: strings.c
	$(CC) $(FLAGS) -fPIC -c -o $@ $< -I.		
	
.PHONY: clean all
	
clean:
	rm -f *.o *.out *.a isort txtfind
