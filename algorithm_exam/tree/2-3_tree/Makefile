CC = gcc

SRCS = queue.c two_three_Tree.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

TARGET = test

CINCLUDE = node.h

CFLAG = -I$(CINCLUDE)

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $(CFLAG) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)