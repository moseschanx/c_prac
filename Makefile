
ifeq ($(OS),Windows_NT)

else

ifeq ($(shell uname),Darwin)

	CC := clang
	LD := clang
endif

ifeq ($(shell uname),Linux)

	CC := gcc 
	LD := gcc 
endif

endif


CCFLAGS = -x c -c -g -std=c99 -pg -O0  -Wextra -pedantic
LDFLAGS = -std=c99 -lm -pg

CCFLAGS += -D DEBUG

all : main.o
	$(LD) $(LDFLAGS) -o main.out $^	

main.o : main.c
	$(CC) $(CCFLAGS) -c -o $@ $^


.PHONY : all 


.PHONY : clean
clean : 
	rm -rf *.o *.out prep core 


run : all
	@./main.out

prep : main.c 
	rm -rf prep
	$(CC) -E -D DEBUG -o $@ $^	


