CC = gcc

SRCS = 

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

C_INCLUDES = node.h

CFLAGS = -I $(C_INCLUDES)

all: clean createdirs $(COBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	rm -rf $(BUILDDIR)