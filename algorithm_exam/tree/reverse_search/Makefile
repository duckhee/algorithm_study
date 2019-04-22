CC = gcc

SRCS = stack.c reverse_tree.c

BUILDDIR = build

TARGET = test

CINC = node.h

C_EXTEND = -I$(CINC)

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $(C_EXTEND) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TARGET)