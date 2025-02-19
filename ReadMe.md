### Welcome to Tay's Flipper Zero Firmware!
#### **This firmware is a fork from** [DarkFlippers/unleashed-firmware](https://github.com/DarkFlippers/unleashed-firmware)

##### This software is for experimental purposes only and is not meant for any illegal activity/purposes. <br> I do not condone illegal activity and strongly encourage keeping transmissions to legal/valid uses allowed by law. <br> Also, this software is made without any support from Flipper Devices and is in no way related to the official devs. 

# What's changed
## Tay's Version
- [D&D style](https://roll20.net/compendium/dnd5e/Character%20Advancement#content) leveling system. Deed's and app limits scale with your Flipper's level.

## Core Unleashed Firmware
- **Sub-GHz** *lib & hal*
	- Regional TX restrictions removed
	- Extra Sub-GHz frequencies
	- Frequency range can be extended in settings file (Warning: It can damage Flipper's hardware)
	- Many rolling code [protocols](https://github.com/DarkFlippers/unleashed-firmware#current-modified-and-new-sub-ghz-protocols-list) now have the ability to save & send captured signals
	- FAAC SLH (Spa) & BFT Mitto (keeloq secure with seed) manual creation
	- External CC1101 module support [(by quen0n)](https://github.com/DarkFlippers/unleashed-firmware/pull/307)
- **Sub-GHz** *Main App*
	- Save last used frequency [(by derskythe)](https://github.com/DarkFlippers/unleashed-firmware/pull/77)
	- New frequency analyzer [(by ClusterM)](https://github.com/DarkFlippers/unleashed-firmware/pull/43)
	- Press OK in frequency analyzer to use detected frequency in Read modes [(by derskythe)](https://github.com/DarkFlippers/unleashed-firmware/pull/77)
	- Long press OK button in Sub-GHz Frequency analyzer to switch to Read menu [(by derskythe)](https://github.com/DarkFlippers/unleashed-firmware/pull/79)
	- New option to use timestamps + protocol name when you saving file, instead of random name or timestamp only - Enable in `Radio Settings -> Protocol Names = ON`
	- Read mode UI improvements (shows time when signal was received) (by @wosk)
	- External CC1101 module support (Hardware SPI used)
	- **Hold right in received signal list to delete selected signal**
	- **Custom buttons for Keeloq / Alutech AT4N / Nice Flor S / Somfy Telis / Security+ 2.0 / CAME Atomo** - now you can use arrow buttons to send signal with different button code
	-   `Add manually` menu extended with new protocols
	- FAAC SLH, BFT Mitto / Somfy Telis / Nice Flor S / CAME Atomo, etc.. manual creation with programming new remote into receiver (use button 0xF for BFT Mitto, 0x8 (Prog) on Somfy Telis, (right arrow button for other protocols))
	- Debug mode counter increase settings (+1 -> +5, +10, default: +1)
	- Debug PIN output settings for protocol development
	
- **Sub-GHz apps** *by unleashed team*
	- Sub-GHz Bruteforce - static code brute-force plugin | 
		- Time delay (between signals) setting (hold Up in main screen(says Up to Save)) + configure repeats in protocols list by pressing right button on selected protocol
        - Load your own file and select bytes you want to bruteforce or use preconfigured options in protocols list
	- Sub-GHz Remote - remote control for 5 sub-ghz files | bind one file for each button
		- use the built-in constructor or make config file by following this [instruction](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemotePlugin.md)
- **Infrared**
	- Recompiled IR TV Universal Remote for ALL buttons
	- Universal remotes for Projectors, Fans, A/Cs and Audio(soundbars, etc.) -> Also always updated and verified by our team
	- Infrared -> `RCA` Protocol
	- Infrared -> Debug TX PIN output settings
- **NFC/RFID/iButton**
	* LFRFID/iButton Fuzzer plugins
	* Extra Mifare Classic keys
	* EMV Protocol + Public data parser (by @Leptopt1los and @wosk)
	* NFC/LFRFID - Stop emulation after 5 mins to avoid antenna damage (by @Leptopt1los)
	* NFC `Add manually` -> Mifare Classic with custom UID
	* NFC parsers: Umarsh, Zolotaya Korona, Kazan, Metromoney, Moscow Social Card, Troika (reworked) and [many others](https://github.com/DarkFlippers/unleashed-firmware/tree/dev/applications/main/nfc/plugins/supported_cards) (by @Leptopt1los and @assasinfil)
- **Quality of life & other features**
	- Customizable Flipper name **Update! Now can be changed in Settings->Desktop** (by @xMasterX and @Willy-JL)
	- Text Input UI element -> Cursor feature (by @Willy-JL)
	- Byte Input Mini editor -> **Press UP** multiple times until the nibble editor appears (by @gid9798)
	- Clock on Desktop -> `Settings -> Desktop -> Show Clock` (by @gid9798)
	- Battery percentage display with different styles `Settings -> Desktop -> Battery View`
	- More games in Dummy Mode -> click or hold any of arrow buttons
	- Lock device with pin(or regular lock if pin not set) by holding UP button on main screen [(by an4tur0r)](https://github.com/DarkFlippers/unleashed-firmware/pull/107)
	- **BadBT** plugin (BT version of BadKB) [(by Willy-JL, ClaraCrazy, XFW contributors)](https://github.com/ClaraCrazy/Flipper-Xtreme/tree/dev/applications/main/bad_kb) - (See in Applications->Tools) - (aka BadUSB via Bluetooth)
	- BadUSB -> Keyboard layouts [(by rien > dummy-decoy)](https://github.com/dummy-decoy/flipperzero-firmware/tree/dummy_decoy/bad_usb_keyboard_layout)
	- Custom community plugins and games added + all known working apps can be downloaded in extra pack in every release
	- Other small fixes and changes throughout
	- See other changes in readme below

Also check the [changelog in releases](https://github.com/DarkFlippers/unleashed-firmware/releases) for latest updates!

### Current modified and new Sub-GHz protocols list:
Thanks to Official team (to their SubGHz Developer, Skorp) for implementing decoders for these protocols in OFW.

Keeloq [Not ALL systems supported for decode or emulation!] - [Supported manufacturers list](https://pastes.io/raw/unuj9bhe4m)

Encoders or sending made by @xMasterX:
- Nero Radio 57bit (+ 56bit encoder improvements)
- CAME 12bit/24bit encoder fixes (Fixes now merged in OFW)
- Keeloq: Dea Mio, Genius Bravo, GSN, HCS101, AN-Motors, JCM Tech, MHouse, Nice Smilo, DTM Neo, FAAC RC,XT, Mutancode, Normstahl, Beninca + Allmatic, Stilmatic, CAME Space, Aprimatic (model TR and similar), Centurion Nova (thanks Carlos !)

Encoders or sending made by @Eng1n33r(first implementation in Q2 2022) & @xMasterX (current version):
- CAME Atomo -> Update! check out new [instructions](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)
- Nice Flor S -> How to create new remote - [instructions](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)
- FAAC SLH (Spa) -> Update!!! Check out new [instructions](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)
- Keeloq: BFT Mitto -> Update! Check out new [instructions](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)
- Star Line
- Security+ v1 & v2 (encoders was made in OFW)

Encoders made by @assasinfil & @xMasterX:
- Somfy Telis -> How to create new remote - [instructions](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)
- Somfy Keytis
- KingGates Stylo 4k
- Alutech AT-4N -> How to create new remote - [instructions](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)
- Nice ON2E (Nice One) -> How to create new remote - [instructions](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)

# Instructions
## First look at official docs [docs.flipper.net](https://docs.flipper.net/)
## [How to install](/documentation/HowToInstall.md) - [versions info](/CHANGELOG.md#recommended-update-option---web-updater): `n`,` `,`e`...
## Firmware & Development

### - **[How to build](/documentation/HowToBuild.md#how-to-build-by-yourself) | [Project-structure](#project-structure)**

### - **CLion IDE** - How to setup workspace for flipper firmware development [by Savely Krasovsky](https://krasovs.ky/2022/11/01/flipper-zero-clion.html)

### - **"Hello world!"** - plugin tutorial [English<sub> by DroomOne</sub> ](https://github.com/DroomOne/Flipper-Plugin-Tutorial) | [Russian<sub> by Pavel Yakovlev</sub>](https://yakovlev.me/hello-flipper-zero/)

### - [How to write your own app](https://flipper.atmanos.com/docs/overview/intro). Docs by atmanos **⚠️outdated API**

## Firmware & main Apps feature

### - System: [How to change Flipper name](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/CustomFlipperName.md)

### - BadUSB: [How to add new keyboard layouts](https://github.com/dummy-decoy/flipperzero_badusb_kl)

### - Infrared: [How to make captures to add them into Universal IR remotes](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/InfraredCaptures.md)

## **Sub-GHz**

### - [How to use Flipper as new remote (Nice FlorS, BFT Mitto, Somfy Telis, Aprimatic, AN-Motors, etc..)](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemoteProg.md)

### - External Radio: [How to connect CC1101 module](https://github.com/quen0n/flipperzero-ext-cc1101)

### - Transmission is blocked? [How to extend Sub-GHz frequency range](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/DangerousSettings.md)

### - [How to add extra Sub-GHz frequencies](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzSettings.md)

### - [~~Configure Sub-GHz Remote App~~](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SubGHzRemotePlugin.md) Not recommended, please use embedded configurator

## **Plugins**

### - TOTP (Authenticator): [config description](https://github.com/akopachov/flipper-zero_authenticator/blob/master/docs/conf-file_description.md)

### - Barcode Generator: [How to use](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/BarcodeGenerator.md)

### - Multi Converter: [How to use](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/MultiConverter.md)

### - WAV Player: [sample files & how to convert](https://github.com/UberGuidoZ/Flipper/tree/main/Wav_Player#readme)

### - Sub-GHz playlist: [generator script](https://github.com/darmiel/flipper-scripts/blob/main/playlist/playlist_creator_by_chunk.py)

## **Plugins that works with external hardware** [GPIO]

### - Unitemp - Temperature sensors reader: [How to use & supported sensors](https://github.com/quen0n/unitemp-flipperzero#readme)

### - [NMEA] GPS: [How to use](https://github.com/xMasterX/all-the-plugins/blob/dev/base_pack/gps_nmea_uart/README.md)

### - i2c Tools [How to use](https://github.com/xMasterX/all-the-plugins/blob/dev/base_pack/flipper_i2ctools/README.md)

### - [NRF24] plugins: [How to use](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/NRF24.md)


### - [WiFi] Scanner: [How to use](https://github.com/SequoiaSan/FlipperZero-WiFi-Scanner_Module#readme) | [Web Flasher](https://sequoiasan.github.io/FlipperZero-WiFi-Scanner_Module/)

### - [ESP8266] Deauther: [How to use](https://github.com/SequoiaSan/FlipperZero-Wifi-ESP8266-Deauther-Module#readme) | [Web Flasher](https://sequoiasan.github.io/FlipperZero-Wifi-ESP8266-Deauther-Module/)

### - [ESP32] WiFi Marauder: [How to use](https://github.com/UberGuidoZ/Flipper/tree/main/Wifi_DevBoard)<sub> docs by UberGuidoZ</sub> | [Marauder repo](https://github.com/justcallmekoko/ESP32Marauder)

### - [ESP32-CAM] Camera Suite: [How to use](https://github.com/CodyTolene/Flipper-Zero-Camera-Suite)

### - How to Upload `.bin` to ESP32/ESP8266: [Windows](https://github.com/SequoiaSan/Guide-How-To-Upload-bin-to-ESP8266-ESP32) | [FAP "ESP flasher"](https://github.com/0xchocolate/flipperzero-esp-flasher)

### - [GPIO] SentrySafe plugin: [How to use](https://github.com/DarkFlippers/unleashed-firmware/blob/dev/documentation/SentrySafe.md)

<br>
<br>

# Where I can find IR, Sub-GHz, ... files, DBs, and other stuff?
## [UberGuidoZ Playground - Large collection of files - Github](https://github.com/UberGuidoZ/Flipper)
## [Awesome Flipper Zero - Github](https://github.com/djsime1/awesome-flipperzero)

<br>
<br>

# Links

* Official Docs: [docs.flipper.net](https://docs.flipper.net/)
* Official Forum: [forum.flipperzero.one](https://forum.flipperzero.one/)

# Project structure

- `applications`    - Applications and services used in firmware
- `assets`          - Assets used by applications and services
- `furi`            - Furi Core: OS-level primitives and helpers
- `debug`           - Debug tool: GDB-plugins, SVD-file and etc
- `documentation`   - Documentation generation system configs and input files
- `firmware`        - Firmware source code
- `lib`             - Our and 3rd party libraries, drivers and etc...
- `site_scons`      - Build helpers
- `scripts`         - Supplementary scripts and python libraries home

Also, pay attention to the `ReadMe.md` files inside those directories.
