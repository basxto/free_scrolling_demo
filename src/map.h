#ifndef MAP_H
#define MAP_H

#include <gb/gb.h>
#include <stdint.h>

// all maps are 10 tiles (16x16) wide and 9 tiles high
#define MAP_HIGHT  (uint8_t)(16)
#define MAP_WIDTH  (uint8_t)(16)
#define VIEW_HIGHT (uint8_t)( 9)
#define VIEW_WIDTH (uint8_t)(10)

typedef struct {
    const uint8_t *background;
} Level;

void init_map(const uint8_t mx, const uint8_t my, const uint8_t x, const uint8_t y);
void render_map();

// move map
void map_top();
void map_down();
void map_left();
void map_right();
#endif