CC = gcc

BUILDDIR = build

SRCS = stack.c recursive_tree.c

CFLAGS = 

TARGET = test

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

C_INCLUDES = node.h

CEXTEND = -I$(C_INCLUDES)

all: clean createdirs $(TARGET)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(TARGET): $(COBJS)
	$(CC) -o $(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $(CEXTEND) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TARGET)
	