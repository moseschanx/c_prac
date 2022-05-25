
ifeq ($(OS),Windows_NT)

else

ifeq ($(shell uname),Darwin)

	CC := clang
	LD := clang
endif

ifeq ($(shell uname),Linux)

	CC := gcc 
	LD := gcc 

	ULIMIT = ulimit -c unlimited
endif

endif

TARGET = main.out

CCFLAGS = -x c -c -g -std=c99 -pg -O0  -Wextra -pedantic
LDFLAGS = -std=c99 -lm -pg -ldl 

# TO use separate static library (.a ) linking , you need recompile
# the final target using GCC instead of LD or liker optioons 
# And you must put sourcefiles at the beginning of your compilation command



 
CCFLAGS += -D DEBUG

all : $(TARGET) 
#main_s.out

#CCFLAGS_S = $(filter-out -c ,$(CCFLAGS))
#main_s.out : main.c 
#	$(CC) $^  $(CCFLAGS_S) -L. -lstring_functions -o $@ 



$(TARGET) : main.o  libstring_functions.so
	$(LD)  -o $@ $<	 $(LDFLAGS)

main.o : main.c
	$(CC) $(CCFLAGS) -c -o $@ $<

string_functions.o : string_functions.c
	$(CC) $(CCFLAGS) -c -o $@ $<
	
libstring_functions.a : string_functions.o
		ar rcs libstring_functions.a $^ ;		

libstring_functions.so : string_functions.c
	$(CC) -fPIC -shared $^ -o $@


.PHONY : all 


.PHONY : clean
clean : 
	rm -rf *.o *.out prep core *.a *.so

run : all
	@./main.out

prep : main.c 
	rm -rf prep
	$(CC) -E -D DEBUG -o $@ $^	

set-core : 
	$(ULIMIT)



