CC:=gcc
CFLAGS:=-g -Wall -std=c17

SRC:=./src
OBJ:=./obj
APP:=t6502
SRCS:=$(wildcard $(SRC)/*.c)
OBJS:=$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
HDRS:=$(wildcard $(SRC)/*.h)

all: $(APP)

$(OBJ)/%.o: $(SRC)/%.c $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(APP): $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)/*.o $(APP)

test: $(APP)
	./$(APP)