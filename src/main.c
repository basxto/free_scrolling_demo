// original gameboy
#include <gb/gb.h>
// gameboy color
#include <gb/cgb.h>
// uint8_t etc
#include <stdint.h>

#include "map.h"

//#include "../build/demo_tmap.c"

const uint8_t overworld_a_data[] = {
#include "../build/overworld_a_gb_data.c"
};

const uint8_t overworld_a_pal[] = {
#include "../build/overworld_a_gbc_pal.c"
};

const uint8_t overworld_b_data[] = {
#include "../build/overworld_b_gb_data.c"
};

const uint8_t overworld_b_pal[] = {
#include "../build/overworld_b_gbc_pal.c"
};

void main() {
    NR52_REG = 0x00; // enable sound
    NR50_REG = 0x00; // full volume
    NR51_REG = 0x00; // all channels
    SPRITES_8x8;

    cgb_compatibility();
    // load tiles
    set_bkg_data(0, 64, overworld_a_data);
    set_bkg_data(64, 64, overworld_b_data);
    // load palettes
    set_bkg_palette(0, 4, overworld_a_pal);
    set_bkg_palette(4, 4, overworld_b_pal);
    // load_map(demo_tmap_background);
    init_map(0, 0, 3, 3);

    SHOW_BKG;
    SHOW_SPRITES;
    while (1) {
        switch (joypad()) {
        case J_UP: // If joypad() is equal to UP
            map_top();
            delay(200);
            break;
        case J_DOWN:
            map_down();
            delay(200);
            break;
        case J_LEFT:
            map_left();
            delay(200);
            break;
        case J_RIGHT:
            map_right();
            delay(200);
            break;
        default:
            break;
        }
        wait_vbl_done();
    }
}
