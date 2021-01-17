License
-------

The code is licensed under [MIT](LICENSE.md).

For graphics see the [attribution](pix/ATTRIBUTION.md) file there.

How to build
------------

Production:

```term
$ make
```

Debug:

```term
$ make DEBUG=1
```

Requirements
------------

* [gbdk-2020 4.0.1](https://github.com/Zal0/gbdk-2020/releases/tag/4.0.1)
* [sdcc 4.0.3](http://sdcc.sourceforge.net/snap.php)
* [rgbgfx 0.4.2](https://github.com/gbdev/rgbds/releases/tag/v0.4.2)
* [Python 3](https://www.python.org/) (for self written tools)
* [GNU Make](https://www.gnu.org/software/make/) (for makefile)
* [Image Magick](https://imagemagick.org/)
* [superfamiconv](https://github.com/Optiroc/SuperFamiconv) (Makefile rules should be merged with rgbgfx)
* loadgpl (included as a submodule, just needs python3 and pypng)

Development tools
-----------------

* [vscode](https://visualstudio.microsoft.com/downloads/)
* [emulicious debugger plugin for vscode](https://marketplace.visualstudio.com/items?itemName=emulicious.emulicious-debugger)
* [emulicious](https://emulicious.net/downloads/) (for debugging)
* [sameboy](https://sameboy.github.io/) (for testing; is free software; supports sgb and gba)
* Maybe some wrong but better than nothing [assembly highlighting](https://marketplace.visualstudio.com/items?itemName=donaldhays.rgbds-z80) (rgbds syntax is different from asxxxx)
