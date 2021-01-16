#include "map.h"
#include <string.h>

const uint8_t tilemap_a[] = {
#include "../build/overworld_a_gb_map.c"
};

const uint8_t tilemap_b[] = {
#include "../build/overworld_b_gb_map.c"
};

#include "../build/lvl_0_0_tmap.c"
#include "../build/lvl_0_1_tmap.c"

#define METAMAP_HIGHT (uint8_t)(2)
#define METAMAP_WIDTH (uint8_t)(1)
const Level level[METAMAP_HIGHT][METAMAP_WIDTH] = {{{lvl_0_0_tmap_background}},
                                                   {{lvl_0_1_tmap_background}}};

// maximum length we can iterate with 8bit
uint8_t tmp_map[4][256];
uint8_t tmp_tilemap[256];// twice 32

// meta map coordinates
uint8_t map_x;
uint8_t map_y;
// top left of the visible map
uint8_t view_x;
uint8_t view_y;
// offset for background layer
uint8_t bg_x;
uint8_t bg_y;

// mx,my is the coordinate of the map in the meta map
// tlx,tly marks the top left of the rendered part of the map
void init_map(const uint8_t mx, const uint8_t my, const uint8_t tlx,
              const uint8_t tly) {
    map_x = mx;
    map_y = my;
    bg_y = tlx;
    bg_x = tly;
    memcpy(tmp_map[0], level[my][mx].background, 256);
    memcpy(tmp_map[1], level[my+1][mx].background, 256);
    memcpy(tmp_map[2], level[my+1][mx].background, 256);
    memcpy(tmp_map[3], level[my][mx].background, 256);
    memcpy(tmp_tilemap, tilemap_a, 128);
    memcpy(&(tmp_tilemap[128]), tilemap_b, 128);
    // shift the second map by 128
    for(uint8_t i = 128; i > 0; ++i)
        tmp_tilemap[i] ^= 0x40;
    render_map();
}

// tlx,tly marks the top left of the rendered part of the map
void render_map() {
    uint8_t tile;
    // loaded spritesheet
    uint8_t tiles[4];
    for (uint8_t y = VIEW_HIGHT; y > 0; --y) {
        for (uint8_t x = VIEW_WIDTH; x > 0; --x) {
            uint8_t index = 0;
            uint8_t final_y = (uint8_t)(y + bg_y - 1);
            if (final_y >= MAP_HIGHT) {
                final_y -= MAP_HIGHT;
                ++index; // 2 or 4
            }
            uint8_t final_x = (uint8_t)(x + bg_x - 1);
            if (final_x >= MAP_WIDTH) {
                final_x -= MAP_WIDTH;
                index += 2; // 3 or 4
            }
            uint8_t tile_index = (uint8_t)(final_y * MAP_WIDTH) + final_x;
            // 4 tiles are a meta tile
            tile = tmp_map[index][tile_index] * 4;
            // they are in special 8x16 format
            tiles[0] = tmp_tilemap[tile++];
            tiles[2] = tmp_tilemap[tile++];
            tiles[1] = tmp_tilemap[tile++];
            tiles[3] = tmp_tilemap[tile];
            // draw meta tile in one go
            set_bkg_tiles((final_x)*2, (final_y)*2, 2, 2, tiles);
        }
    }
    move_bkg(bg_x * 16, bg_y * 16);
}

void map_top() {
    --bg_y;
    render_map();
}

void map_down() {
    ++bg_y;
    render_map();
}

void map_left() {
    --bg_x;
    render_map();
}

void map_right() {
    ++bg_x;
    render_map();
}