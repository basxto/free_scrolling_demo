CC=lcc
emulator=sameboy
debug_emulator=emulicious
tmxconvert=./dev/tmx2c.py
pngconvert=rgbgfx
pngconvert+= -h -u
xxd=xxd
xxd+= -i
montage=magick montage
montage+= -geometry +0+0 -tile x1
loadgpl=./dev/loadgpl/loadgpl.py
CFLAGS =
ifdef DEBUG
CFLAGS+= -Wf--debug -Wf--nolospre -Wl-j -Wl-m -Wl-w -Wl-y
endif
ROM=fsr
BUILDIR=build

build: $(ROM).gb

$(BUILDIR)/:
	mkdir -p $@

$(ROM).gb: $(BUILDIR)/main.o $(BUILDIR)/map.o
	$(CC) $(CFLAGS) -Wm-yc -Wm-yn="FREESCROLLDEMO" -o $@ $^

run: $(ROM).gb
	$(emulator) ./$(ROM).gb

# not really needed, emulicious can reload rom on change
debug:
	make DEBUG=1 $(ROM).gb
	$(debug_emulator) ./$(ROM).gb

$(BUILDIR)/main.asm: src/main.c $(BUILDIR)/overworld_a_gb_data.c $(BUILDIR)/overworld_b_gb_data.c | $(BUILDIR)/
	$(CC) $(CFLAGS) --fverbose-asm -S -o $@ $<

$(BUILDIR)/map.asm: src/map.c src/map.h $(BUILDIR)/overworld_a_gb_map.c $(BUILDIR)/overworld_a_gbc_pal.c $(BUILDIR)/overworld_b_gb_map.c $(BUILDIR)/overworld_b_gbc_pal.c $(BUILDIR)/lvl_0_0_tmap.c $(BUILDIR)/lvl_0_1_tmap.c | $(BUILDIR)/
	$(CC) $(CFLAGS) --fverbose-asm -S -o $@ $<

$(BUILDIR)/%.asm: src/%.c | $(BUILDIR)/
	$(CC) $(CFLAGS) --fverbose-asm -S -o $@ $<

%.o: %.asm
	$(CC) $(CFLAGS) -c -o $@ $<

%.2bpp %.tilemap: %.png
	$(pngconvert) $< -o $*.2bpp -t $*.tilemap

$(BUILDIR)/%.2bpp $(BUILDIR)/%.tilemap: pix/%.png | $(BUILDIR)/
	$(pngconvert) $< -o $(BUILDIR)/$*.2bpp -t $(BUILDIR)/$*.tilemap

$(BUILDIR)/%.pal: pix/%.png | $(BUILDIR)/
	dev/SuperFamiconv/bin/superfamiconv -RF -M gbc -i $< -p $@

%_pal.c: %.pal
	$(xxd) -c8 < $< > $@

%_data.c: %.2bpp
	$(xxd) < $< > $@

%_map.c: %.tilemap
	$(xxd) < $< > $@

# for quick tileset testing
#$(BUILDIR)/overworld_a_gb.png: $(BUILDIR)/overworld_a_house_ext_gb.png
#	cp $< $@

# switch to dmg palette and combine metatile rows
$(BUILDIR)/overworld_%_gb.png: pix/overworld_%_gbc.png | $(BUILDIR)/
	$(loadgpl) $^ pix/gb4.gpl $@
	# image magick would fuck up the tilemap order of png8
	$(montage) \( $@ -crop x16 \) png24:$@

$(BUILDIR)/%_tmap.c: lvl/%.tmx | $(BUILDIR)/
	$(tmxconvert) $^ -o $@

clean:
	rm -rf ./*.ihx ./*.map ./*.noi build/


.PHONY: spaceleft
spaceleft: build
	@hexdump -v -e '/1 "%02X\n"' $(ROM).gb | awk '/FF/ {n += 1} !/FF/ {n = 0} END {print n}'
