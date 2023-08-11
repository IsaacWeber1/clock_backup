#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/time.h>
#include "display.h"

#define WHITE 1
#define BLACK 0
#define RED 2
#define GREEN 3
#define BLUE 4

void display_time(int hours, int minutes, int seconds, uint16_t pixels[8][8])
{
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);

    display_colons(pixels, WHITE);
    display_hours(hours, pixels, BLUE);
    display_minutes(minutes, pixels, GREEN);
    display_seconds(seconds, pixels, RED);
}

void display_colons(uint16_t pixels[8][8], uint16_t color)
{
   for (int i = 1; i < 6; i++) {
       for (int j = 2; j < 7; j++) {
           if ((i != 3) && (j != 4)) {
               pixels[i][j] = color;
           }
       }
   }
}

void display_hours(int hours, uint16_t pixels[8][8], uint16_t color)
{
    for (int i = 0; i < 5; i++) {
        if ((hours % 2) == 1) {
            pixels[6][7-i] = color;
        }
        hours = hours / 2;
    }
}   

void display_minutes(int minutes, uint16_t pixels[8][8], uint16_t color)
{
    for (int i = 0; i < 6; i++) {
        if ((minutes % 2) == 1) {
            pixels[3][7-i] = color;
        }
        minutes = minutes / 2;
    }
}

void display_seconds(int seconds, uint16_t pixels[8][8], uint16_t color)
{
    for (int i = 0; i < 6; i++) {
        if ((seconds % 2) == 1) {
            pixels[0][7-i] = color;
        }
        seconds = seconds / 2;
    }
}
