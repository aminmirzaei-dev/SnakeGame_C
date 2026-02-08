#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "snake.h"
#include "ui.h"
#include "input.h"

void start_game(void) {
    srand(time(NULL));
    init_terminal();
    init_snake();
    print_banner();

    while (1) {
        draw_game();
        handle_input();
        update_snake();

        if (check_collision()) {
            clear_screen();
            printf("GAME OVER!\nFinal Score: %d\n", score);
            break;
        }

        usleep(200000 - (score * 1000));
    }

    reset_terminal();
}

