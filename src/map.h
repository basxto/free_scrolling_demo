#ifndef MAP_H
#define MAP_H

#include <gb/gb.h>
#include <stdint.h>

// all maps are 10 tiles (16x16) wide and 9 tiles high
#define MAP_HIGHT  (uint8_t)(16)
#define MAP_WIDTH  (uint8_t)(16)
#define VIEW_HIGHT (uint8_t)( 9)
#define VIEW_WIDTH (uint8_t)(10)

void load_map(const uint8_t background[]);
#endif