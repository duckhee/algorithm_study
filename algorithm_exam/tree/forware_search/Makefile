CC = gcc

SRCS = stack.c forware_tree.c

TARGET = test

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

C_INCLUDES = node.h

CEXTEND = -I$(C_INCLUDES)

CFLAGS = 

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



#  $@ 현재 타켓의 이름
# $^ 현재 타켓의 종속 항목 리스트 