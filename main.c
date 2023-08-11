#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/time.h>
#include "display.h"
#include <time.h>
#include <string.h>
#include <ctype.h>

#define WHITE 1
#define BLACK 0
#define RED 2
#define GREEN 3
#define BLUE 4

void fill_background(uint16_t pixels[8][8], uint16_t color);
void draw_clock(uint16_t pixels[8][8]);
const char*  getDate(time_t curTime);

int main(void)
{
    uint16_t pixel[8][8];
    initscr();
    start_color();

    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    char *broken;
    char *s;
    int hour;
    int min;
    int sec;
    char *clock = (char*) malloc(9);
    char *date = (char*) malloc(25);
    int iterator;
    int runningSum;

    fscanf(stdin, "%s", clock);
    while (clock[0] != '\0') {
        iterator = 0;
        runningSum =0;
        fscanf(stdin, "%s", clock);
        for (s=&clock[0]; *s != '\0'; s++) {
            if (iterator >= 11) {
                runningSum += isdigit(*s);
            }
            iterator++;
        }
        if (runningSum != 12288) {
            printf("Time not valid\n");
            break;
        }
        broken = strtok(clock, ":");
        hour = broken[0];
        broken = strtok(NULL, ":");
        min = atoi(broken);
        broken = strtok(NULL, ":");
        sec = atoi(broken);
        broken[0] = '\0';
        fill_background(pixel, BLACK);
        display_time(hour, min, sec, pixel);
        draw_clock(pixel);
    }
    endwin();
    return 0;
}

void fill_background(uint16_t pixels[8][8], uint16_t color)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pixels[i][j] = color;
        }
    }
    
    display_colons(pixels, WHITE);
}

void draw_clock(uint16_t pixels[8][8])
{
    for (int i = 0; i < 8; i++) {
        move (i,0);
        for (int j = 0; j < 8; j++) {
            if (pixels[7-j][i]) {
                attron(COLOR_PAIR(pixels[7-j][i]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7-j][i]));
            } else {
                addch(' ');
            }
        }
    }
    refresh();
}
