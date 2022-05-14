
ifeq ($(OS),Windows_NT)

else

ifeq ($(shell uname),Darwin)

	CC = clang
	LD = clang
endif

ifeq ($(shell uname),Linux)

	CC = gcc 
	LD = gcc 
endif

endif


CCFLAGS = -x c -std=c99 -g -O0  -Wextra -pedantic
LDFLAGS = -std=c99 -lm


all : main.o
	$(LD) $(LDFLAGS) -o main.out $^	

main.o : main.c
	$(CC) $(CCFLAGS) -c -o $@ $^


.PHONY : all 


.PHONY : clean
clean : 
	rm -rf *.o *.out


run : all
	@./main.out

