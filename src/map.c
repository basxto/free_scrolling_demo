#include "map.h"
#include <string.h>

const uint8_t overworld_gb_map[] = {
#include "../build/overworld_a_gb_map.c"
};

#include "../build/lvl_0_0_tmap.c"
#include "../build/lvl_0_1_tmap.c"

#define METAMAP_HIGHT (uint8_t)(2)
#define METAMAP_WIDTH (uint8_t)(1)
const Level level[METAMAP_HIGHT][METAMAP_WIDTH] = {{{lvl_0_0_tmap_background}},
                                                   {{lvl_0_1_tmap_background}}};

// maximum length we can iterate with 8bit
uint8_t tmp_map[256];
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
    view_x = tlx;
    view_y = tly;
    bg_y = 0;
    bg_x = 0;
    memcpy(tmp_map, level[my][mx].background, 256);
    render_map();
}

// tlx,tly marks the top left of the rendered part of the map
void render_map() {
    uint8_t tile;
    // loaded spritesheet
    uint8_t tiles[4];
    for (uint8_t y = bg_y; y < (bg_y + VIEW_HIGHT); ++y) {
        for (uint8_t x = bg_x; x < (bg_x + VIEW_WIDTH); ++x) {
            // 4 tiles are a meta tile
            tile = (tmp_map[((view_y + y) * MAP_WIDTH) + view_x + x]) * 4;
            // they are in special 8x16 format
            tiles[0] = overworld_gb_map[tile];
            tiles[2] = overworld_gb_map[tile + 1];
            tiles[1] = overworld_gb_map[tile + 2];
            tiles[3] = overworld_gb_map[tile + 3];
            // draw meta tile in one go
            set_bkg_tiles(x * 2, y * 2, 2, 2, tiles);
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