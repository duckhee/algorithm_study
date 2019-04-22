CC = gcc

SRCS = queue.c step_tree.c

BUILDDIR = build

CFLAGS = 

TARGET = test

C_INC = node.h

C_EXTEND = -I$(C_INC)

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