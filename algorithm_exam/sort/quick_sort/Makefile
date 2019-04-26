CC = gcc

SRCS = quick_sort.c

BUILDDIR = build

TARGET = test

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

CFLAGS = 

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)


$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)