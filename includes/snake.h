#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH 60
#define HEIGHT 20
#define MAX_TAIL 100

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
};

void init_snake(void);
void update_snake(void);
void spawn_fruit(void);
int check_collision(void);

extern int head_x, head_y;
extern int fruit_x, fruit_y;
extern int tail_x[MAX_TAIL], tail_y[MAX_TAIL];
extern int tail_length;
extern int score;
extern enum Direction dir;

#endif

