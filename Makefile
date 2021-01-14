CC=lcc
test_emulator=sameboy
debug_emulator=emulicious
tmxconvert=./dev/tmx2c.py
pngconvert=rgbgfx
pngconvert+= -h -u
xxd=xxd
xxd+= -i
CFLAGS =
ifdef DEBUG
CFLAGS += -Wf--debug -Wf--nolospre -Wl-j -Wl-m -Wl-w -Wl-y
endif
ROM=fsr
BUILDIR=build/

build: $(ROM).gb

$(BUILDIR):
	mkdir -p $@

$(ROM).gb: $(BUILDIR)main.o
	$(CC) $(CFLAGS) -o $@ $^

test: $(ROM).gb
	$(test_emulator) ./$(ROM).gb

# not really needed, emulicious can reload rom on change
debug: $(ROM).gb
	$(debug_emulator) ./$(ROM).gb

$(BUILDIR)main.asm: src/main.c $(BUILDIR)overworld_gb_data.c $(BUILDIR)overworld_gb_map.c $(BUILDIR)demo_tmap.c | $(BUILDIR)
	$(CC) $(CFLAGS) -S -o $@ $<

$(BUILDIR)%.asm: src/%.c | $(BUILDIR)
	$(CC) $(CFLAGS) -S -o $@ $<

%.o: %.asm
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILDIR)%.2bpp $(BUILDIR)%.tilemap: pix/%.png | $(BUILDIR)
	$(pngconvert) $< -o $(BUILDIR)$*.2bpp -t $(BUILDIR)$*.tilemap

%_data.c: %.2bpp
	$(xxd) < $< > $@

%_map.c: %.tilemap
	$(xxd) < $< > $@


$(BUILDIR)%_tmap.c: lvl/%.tmx | $(BUILDIR)
	$(tmxconvert) $^ -o $@

clean:
	rm -r build/


.PHONY: spaceleft
spaceleft: build
	@hexdump -v -e '/1 "%02X\n"' $(ROM).gb | awk '/FF/ {n += 1} !/FF/ {n = 0} END {print n}'
