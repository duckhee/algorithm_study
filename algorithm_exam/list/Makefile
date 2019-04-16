CC = gcc

SRCS = ex1_dataInsert.c ex2_linkedList.c ex2_linkedList.c ex3_linkedListDelete.c \
ex4_doublelinkedList.c ex5_linkedListStack.c ex6_linkedListQueue.c

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))


all: clean createdirs $(COBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)

