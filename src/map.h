#ifndef MAP_H
#define MAP_H

#include <gb/gb.h>
#include <stdint.h>

// all maps are 10 tiles (16x16) wide and 9 tiles high
#define HIGHT (uint8_t)(9)
#define WIDTH (uint8_t)(10)

void load_map(const uint8_t background[]);
#endif