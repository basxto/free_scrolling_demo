// original gameboy
#include <gb/gb.h>
// gameboy color
#include <gb/cgb.h>
// uint8_t etc
#include <stdint.h>

#include "map.h"

#include "../build/demo_tmap.c"

const uint8_t overworld_gb_data[] = {
#include "../build/overworld_a_gb_data.c"
};

void main() {
    NR52_REG = 0x00; // enable sound
    NR50_REG = 0x00; // full volume
    NR51_REG = 0x00; // all channels
    SPRITES_8x8;

    // cgb_compatibility();
    set_bkg_data(0, sizeof(overworld_gb_data) / 16, overworld_gb_data);
    load_map(demo_tmap_background);

    SHOW_BKG;
    SHOW_SPRITES;
}
