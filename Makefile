NAME=hashtest

BIND=bin
INCD=include
SRCD=src

CC=gcc
STD=-std=c89
CFLAGS=$(STD) -O2 -g
INC=-I $(INCD)
#LIBS=

SRCS=$(shell find $(SRCD) -name '*.c')
OBJS=$(SRCS:.c=.o)

BINF=$(BIND)/$(NAME)

.PHONY: all clean
.DEFAULT_GOAL: all

all: $(BINF)

$(BINF): $(BIND) $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

$(BIND):
	mkdir $(BIND)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
clean:
	rm -rf $(BIND) $(OBJS)
