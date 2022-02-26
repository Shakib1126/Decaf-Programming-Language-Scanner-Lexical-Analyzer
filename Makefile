## 
## Simple makefile for DECAF Lexical Analyzer
##

.PHONY: clean strip


COMPILER = dcc
PRODUCTS = $(COMPILER) $(PREPROCESSOR)
default: $(PRODUCTS)

# List of our object files like errors.cc utility.cc etc
SRCS = errors.cc utility.cc main.cc


OBJS = lex.yy.o $(patsubst %.cc, %.o, $(filter %.cc,$(SRCS))) $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

JUNK = *.log *~ *.o lex.yy.c dpp.yy.c y.tab.c y.tab.h *.core core

# The tools and libraries that we are going to use for our project
CC = g++
LD = g++
LEX = flex
YACC = bison


CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare


LEXFLAGS = -d


YACCFLAGS = -dvty


# LIBS = -lc -lm -ll

# Rules made for the target

.yy.o: $*.yy.c
	$(CC) $(CFLAGS) -c -o $@ $*.cc

lex.yy.c: scanner.l 
	$(LEX) $(LEXFLAGS) scanner.l

.cc.o: $*.cc
	$(CC) $(CFLAGS) -c -o $@ $*.cc

# The rules in order to build a compiler (SCANNER in our case)

$(COMPILER) : $(PREPROCESSOR) $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS)



strip : $(PRODUCTS)
	strip $(PRODUCTS)
	rm -rf $(JUNK)


depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

clean:
	@rm -rf $(JUNK) y.output $(PRODUCTS) $(TEST)

