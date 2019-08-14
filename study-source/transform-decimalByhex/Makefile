CC = gcc

SRCS = main.c

TARGET = DecimalByHex

RM = rm

REMOVE = rm -rf

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) -o $@ -c $<

clean:
	$(REMOVE) $(BUILDDIR)
	$(REMOVE) $(TARGET)
