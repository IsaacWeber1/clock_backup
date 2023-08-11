#ifndef DISPLAY_H_
#define DISPLAY_H_

void display_time(int hours, int minutes, int seconds, uint16_t pixels[8][8]);
void display_colons(uint16_t pixels[8][8], uint16_t color);
void display_hours(int hours, uint16_t pixels[8][8], uint16_t color);
void display_minutes(int minutes, uint16_t pixels[8][8], uint16_t color);
void display_seconds(int seconds, uint16_t pixels[8][8], uint16_t color);

#endif
