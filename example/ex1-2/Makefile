CC = gcc

TARGET = ex1_2

SRCS = main.c

OUT_DIR = build


COBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))

all: clean createdirs $(COBJS)

createdirs:
	@echo make file $@
	$(shell mkdir ${OUT_DIR})

# $< 씨 파일을 의미한다. < 리다이랙션을 의미
$(COBJS): $(OUT_DIR)/%.o : %.c
	$(CC) $< -o $(OUT_DIR)/$(TARGET)


clean:
	rm -rf $(OUT_DIR)
