// original gameboy
#include <gb/gb.h>
// gameboy color
#include <gb/cgb.h>
#include <stdio.h>

#include "pix/overworld_gb_data.c"
#include "pix/overworld_gb_map.c"



void main() {
	NR52_REG = 0x80; // enable sound
	NR50_REG = 0x77; // full volume
	NR51_REG = 0xFF; // all channels
	SPRITES_8x16;

	//cgb_compatibility();
	set_bkg_data(0,144,overworld_gb_data);
	
	SHOW_BKG;
}
