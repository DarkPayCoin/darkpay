
Debian
====================
This directory contains files used to package darkpaycoind/darkpaycoin-qt
for Debian-based Linux systems. If you compile darkpaycoind/darkpaycoin-qt yourself, there are some useful files here.

## darkpaycoin: URI support ##


darkpaycoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install darkpaycoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your darkpaycoinqt binary to `/usr/bin`
and the `../../share/pixmaps/darkpaycoin128.png` to `/usr/share/pixmaps`

darkpaycoin-qt.protocol (KDE)

