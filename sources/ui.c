#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "snake.h"

void print_banner(void) {
    FILE *file = fopen("assets/banner.txt", "r");
    if (!file) return;

    char ch;
    while ((ch = fgetc(file)) != EOF)
        putchar(ch);

    fclose(file);
}

// Draws game field
void draw_game(void) {
    clear_screen();

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        printf("#");
        for (int x = 0; x < WIDTH; x++) {
            if (x == head_x && y == head_y)
                printf("O");
            else if (x == fruit_x && y == fruit_y)
                printf("F");
            else {
                int tail = 0;
                for (int k = 0; k < tail_length; k++) {
                    if (tail_x[k] == x && tail_y[k] == y) {
                        printf("o");
                        tail = 1;
                        break;
                    }
                }
                if (!tail) printf(" ");
            }
        }
        printf("#\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

