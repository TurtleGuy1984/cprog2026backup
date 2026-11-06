CC = gcc
CFLAGS = -Wall -Wextra -g -I.
# CFLAGS += -DDEBUG

SRC = main.c board/board.c display/display.c game/game.c input/input.c player/player.c walls/walls.c
OBJ = $(SRC:.c=.o)
TARGET = quoridor

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# compile rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) a *.o */*.o

re: clean all