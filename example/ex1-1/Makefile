CC = gcc

TARGET = ex1_1

SRC = main.c

BUILDDIR = build

SRCS = main.c

COBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.c=.o))

all: clean createdirs $(COBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@
	#$(CC) $< -o $@ 


clean:
	rm -rf $(BUILDDIR)
