// original gameboy
#include <gb/gb.h>
// gameboy color
#include <gb/cgb.h>
// uint8_t etc
#include <stdint.h>

const uint8_t overworld_gb_data[] = {
#include "../build/overworld_gb_data.c"
};
const uint8_t overworld_gb_map[] = {
#include "../build/overworld_gb_map.c"
};
#include "../build/demo_tmap.c"

// all maps are 10 tiles (16x16) wide and 9 tiles high
#define HIGHT (9)
#define WIDTH (10)


void load_map(const unsigned int background[]) {
	uint8_t tile;
	// loaded spritesheet
	uint8_t tiles[4];
	for(uint8_t y = 0; y < HIGHT; ++y){
		for(uint8_t x = 0; x < WIDTH; ++x){
			// 4 tiles are a meta tile
			tile = (background[(y * WIDTH) + x]-1) * 4;
			// they are in special 8x16 format
			tiles[0] = overworld_gb_map[tile];
			tiles[2] = overworld_gb_map[tile + 1];
			tiles[1] = overworld_gb_map[tile + 2];
			tiles[3] = overworld_gb_map[tile + 3];
			set_bkg_tiles(x * 2, y * 2, 2, 2, tiles);
		}
	}
}

void main() {
	NR52_REG = 0x80; // enable sound
	NR50_REG = 0x77; // full volume
	NR51_REG = 0xFF; // all channels
	SPRITES_8x16;

	//cgb_compatibility();
	set_bkg_data(0, sizeof(overworld_gb_data)/16, overworld_gb_data);
	load_map(demo_tmap_background);
	
	SHOW_BKG;
}
