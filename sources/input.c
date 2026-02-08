#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include "input.h"
#include "snake.h"

static struct termios old_props;

static int key_pressed(void) {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

void handle_input(void) {
    if (key_pressed()) {
        char ch = getchar();
        switch (ch) {
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'x': exit(0);
        }
    }
}

// Disable canonical mode and echo
void init_terminal(void) {
    tcgetattr(STDIN_FILENO, &old_props);
    struct termios new_props = old_props;
    new_props.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_props);
}

// Restore terminal settings
void reset_terminal(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_props);
}

