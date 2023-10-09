CC = gcc
CFLAGS = -I./mt -I./simulation -I./test
LDFLAGS = -lm

SRCDIR = .
MT_DIR = mt
SIMULATION_DIR = simulation
TEST_DIR = test

SRCS = $(wildcard $(SRCDIR)/*.c)
MT_SRCS = $(wildcard $(MT_DIR)/*.c)
SIMULATION_SRCS = $(wildcard $(SIMULATION_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

OBJS = $(SRCS:.c=.o)
MT_OBJS = $(MT_SRCS:.c=.o)
SIMULATION_OBJS = $(SIMULATION_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

EXEC = main

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS) $(MT_OBJS) $(SIMULATION_OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS) $(MT_OBJS) $(SIMULATION_OBJS) $(TEST_OBJS)
