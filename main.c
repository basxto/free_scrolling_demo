// original gameboy
#include <gb/gb.h>
// gameboy color
#include <gb/cgb.h>
// uint8_t etc
#include <stdint.h>

const uint8_t overworld_gb_data[] = {
#include "./build/overworld_gb_data.c"
};
const uint8_t overworld_gb_map[] = {
#include "./build/overworld_gb_map.c"
};
#include "./pix/demo_tmap.c"

// all maps are 10 tiles (16x16) wide and 9 tiles high
#define HIGHT (9)
#define WIDTH (10)
// tile (8x8) width of our sprite
#define SPRITEWIDTH (34)


void load_map(const unsigned int background[]) {
	int y;
	int x;
	int index;
	// tmx
	unsigned int tile;
	// loaded spritesheet
	int sprite_y;
	int sprite_x;
	unsigned char tiles[4];
	for(y = 0; y < HIGHT; ++y){
		for(x = 0; x < WIDTH; ++x){
			tile = background[(y * WIDTH) + x] - 1;
			sprite_x = tile % (SPRITEWIDTH/2);
			sprite_y = tile / (SPRITEWIDTH/2);
			index = (sprite_y * 2 * SPRITEWIDTH) + (sprite_x * 2);
			tiles[0] = overworld_gb_map[index];
			tiles[1] = overworld_gb_map[index + 1];
			tiles[2] = overworld_gb_map[index + SPRITEWIDTH];
			tiles[3] = overworld_gb_map[index + 1 + SPRITEWIDTH];
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
