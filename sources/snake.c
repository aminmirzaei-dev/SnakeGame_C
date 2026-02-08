#include <stdlib.h>
#include "snake.h"

int head_x, head_y;
int fruit_x, fruit_y;
int tail_x[MAX_TAIL], tail_y[MAX_TAIL];
int tail_length;
int score;
enum Direction dir;

void init_snake(void) {
    head_x = WIDTH / 2;
    head_y = HEIGHT / 2;
    tail_length = 0;
    score = 0;
    dir = STOP;
    spawn_fruit();
}

// Moves snake and handles food logic
void update_snake(void) {

    for (int i = tail_length - 1; i > 0; i--) {
        tail_x[i] = tail_x[i - 1];
        tail_y[i] = tail_y[i - 1];
    }

    tail_x[0] = head_x;
    tail_y[0] = head_y;

    switch (dir) {
        case UP:    head_y--; break;
        case DOWN:  head_y++; break;
        case LEFT:  head_x--; break;
        case RIGHT: head_x++; break;
        default: break;
    }

    // Wall wrapping
    if (head_x < 0) head_x = WIDTH - 1;
    if (head_x >= WIDTH) head_x = 0;
    if (head_y < 0) head_y = HEIGHT - 1;
    if (head_y >= HEIGHT) head_y = 0;

    // Eat fruit
    if (head_x == fruit_x && head_y == fruit_y) {
        score += 10;
        tail_length++;
        spawn_fruit();
    }
}

// Checks collision with tail
int check_collision(void) {
    for (int i = 0; i < tail_length; i++) {
        if (tail_x[i] == head_x && tail_y[i] == head_y) {
            return 1;
        }
    }
    return 0;
}

// Spawns fruit at random location
void spawn_fruit(void) {
    fruit_x = rand() % WIDTH;
    fruit_y = rand() % HEIGHT;
}

