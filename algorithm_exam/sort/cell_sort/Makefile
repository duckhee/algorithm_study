CC = gcc

SRCS = cell_sort.c

BUILDDIR = build

TARGET = cell_sort

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))


all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o:%.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)


.SUFFIXIXES : .c .o