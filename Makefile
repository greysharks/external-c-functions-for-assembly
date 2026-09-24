TARGET = executable
CFLAGS = -no-pie -m32
ASMFLAGS = -f elf

SRCS = $(wildcard *.asm)
LIB = $(wildcard *.c)
OBJS = $(SRCS:.asm=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIB) -o $(TARGET)

$(OBJS): $(SRCS)
	nasm $(ASMFLAGS) -o $(OBJS) $(SRCS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
