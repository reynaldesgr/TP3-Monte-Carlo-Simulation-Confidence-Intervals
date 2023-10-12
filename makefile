CC = gcc
CFLAGS = -I./mt -I./simulation -I./test -I./imath -I./math_utility  
LDFLAGS = -lm

SRCDIR = .
MT_DIR = mt
SIMULATION_DIR = simulation
TEST_DIR = test
MATH_UTILITY_DIR = imath

SRCS = $(wildcard $(SRCDIR)/*.c)
MT_SRCS = $(wildcard $(MT_DIR)/*.c)
SIMULATION_SRCS = $(wildcard $(SIMULATION_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
MATH_UTILITY_SRCS = $(wildcard $(MATH_UTILITY_DIR)/*.c)  

OBJS = $(SRCS:.c=.o)
MT_OBJS = $(MT_SRCS:.c=.o)
SIMULATION_OBJS = $(SIMULATION_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)
MATH_UTILITY_OBJS = $(MATH_UTILITY_SRCS:.c=.o)  

EXEC = main

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS) $(MT_OBJS) $(SIMULATION_OBJS) $(TEST_OBJS) $(MATH_UTILITY_OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS) $(MT_OBJS) $(SIMULATION_OBJS) $(TEST_OBJS) $(MATH_UTILITY_OBJS)
