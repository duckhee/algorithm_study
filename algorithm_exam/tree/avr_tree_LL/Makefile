CC = gcc

SRCS = queue.c left_balanceTree.c

TARGET = test

BUILDDIR = build

CINC = node.h

C_EXINC = -I$(CINC)

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdris build

createdris:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $(C_EXINC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TARGET)