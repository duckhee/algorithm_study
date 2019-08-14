CC = gcc

SRCS = main.c

BUILDDIR = buildExe

TARGET = fibonacciNumber

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir $(BUILDDIR))

clean:
	rm -rf $(BUILDDIR)

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) -o $@ -c $<