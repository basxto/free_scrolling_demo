#include "map.h"

const uint8_t overworld_gb_map[] = {
#include "../build/overworld_a_gb_map.c"
};

void load_map(const uint8_t background[]) {
    uint8_t tile;
    // loaded spritesheet
    uint8_t tiles[4];
    for (uint8_t y = 0; y < VIEW_HIGHT; ++y) {
        for (uint8_t x = 0; x < VIEW_WIDTH; ++x) {
            // 4 tiles are a meta tile
            tile = (background[(y * MAP_WIDTH) + x]) * 4;
            // they are in special 8x16 format
            tiles[0] = overworld_gb_map[tile];
            tiles[2] = overworld_gb_map[tile + 1];
            tiles[1] = overworld_gb_map[tile + 2];
            tiles[3] = overworld_gb_map[tile + 3];
            // draw meta tile in one go
            set_bkg_tiles(x * 2, y * 2, 2, 2, tiles);
        }
    }
}