CC=lcc
test_emulator=sameboy
debug_emulator=java -jar dev/emulicious/Emulicious.jar
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
	$(CC)$(CFLAGS) -o $@ $^

test: $(ROM).gb
	$(test_emulator) ./$(ROM).gb

# not really needed, emulicious can reload rom on change
debug: $(ROM).gb
	$(debug_emulator) ./$(ROM).gb

$(BUILDIR)main.asm: src/main.c $(BUILDIR)overworld_gb_data.c $(BUILDIR)overworld_gb_map.c $(BUILDIR)demo_tmap.c | $(BUILDIR)
	$(CC) -S -o $@ $<

$(BUILDIR)%.asm: src/%.c | $(BUILDIR)
	$(CC) -S -o $@ $<

%.o: %.asm
	$(CC) -c -o $@ $<

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

