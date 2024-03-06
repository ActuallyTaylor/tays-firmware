#include "dolphin_deed.h"
#include <furi.h>

static const DolphinDeedWeight dolphin_deed_weights[] = {
    {DolphinAppSubGhz, DolphinDeedDifficultyEasy}, // DolphinDeedSubGhzReceiverInfo
    {DolphinAppSubGhz, DolphinDeedDifficultyHard}, // DolphinDeedSubGhzSave
    {DolphinAppSubGhz, DolphinDeedDifficultyEasy}, // DolphinDeedSubGhzRawRec
    {DolphinAppSubGhz, DolphinDeedDifficultyMedium}, // DolphinDeedSubGhzAddManually
    {DolphinAppSubGhz, DolphinDeedDifficultyMedium}, // DolphinDeedSubGhzSend
    {DolphinAppSubGhz, DolphinDeedDifficultyEasy}, // DolphinDeedSubGhzFrequencyAnalyzer

    {DolphinAppRfid, DolphinDeedDifficultyEasy}, // DolphinDeedRfidRead
    {DolphinAppRfid, DolphinDeedDifficultyHard}, // DolphinDeedRfidReadSuccess
    {DolphinAppRfid, DolphinDeedDifficultyHard}, // DolphinDeedRfidSave
    {DolphinAppRfid, DolphinDeedDifficultyMedium}, // DolphinDeedRfidEmulate
    {DolphinAppRfid, DolphinDeedDifficultyMedium}, // DolphinDeedRfidAdd

    {DolphinAppNfc, DolphinDeedDifficultyEasy}, // DolphinDeedNfcRead
    {DolphinAppNfc, DolphinDeedDifficultyHard}, // DolphinDeedNfcReadSuccess
    {DolphinAppNfc, DolphinDeedDifficultyHard}, // DolphinDeedNfcSave
    {DolphinAppNfc, DolphinDeedDifficultyEasy}, // DolphinDeedNfcDetectReader
    {DolphinAppNfc, DolphinDeedDifficultyMedium}, // DolphinDeedNfcEmulate
    {DolphinAppNfc, DolphinDeedDifficultyMedium}, // DolphinDeedNfcMfcAdd
    {DolphinAppNfc, DolphinDeedDifficultyEasy}, // DolphinDeedNfcAddSave
    {DolphinAppNfc, DolphinDeedDifficultyEasy}, // DolphinDeedNfcAddEmulate

    {DolphinAppIr, DolphinDeedDifficultyEasy}, // DolphinDeedIrSend
    {DolphinAppIr, DolphinDeedDifficultyHard}, // DolphinDeedIrLearnSuccess
    {DolphinAppIr, DolphinDeedDifficultyHard}, // DolphinDeedIrSave

    {DolphinAppIbutton, DolphinDeedDifficultyEasy}, // DolphinDeedIbuttonRead
    {DolphinAppIbutton, DolphinDeedDifficultyHard}, // DolphinDeedIbuttonReadSuccess
    {DolphinAppIbutton, DolphinDeedDifficultyHard}, // DolphinDeedIbuttonSave
    {DolphinAppIbutton, DolphinDeedDifficultyMedium}, // DolphinDeedIbuttonEmulate
    {DolphinAppIbutton, DolphinDeedDifficultyMedium}, // DolphinDeedIbuttonAdd

    {DolphinAppBadusb, DolphinDeedDifficultyHard}, // DolphinDeedBadUsbPlayScript
    {DolphinAppPlugin, DolphinDeedDifficultyHard}, // DolphinDeedU2fAuthorized

    {DolphinAppPlugin, DolphinDeedDifficultyEasy}, // DolphinDeedGpioUartBridge

    {DolphinAppPlugin, DolphinDeedDifficultyMedium}, // DolphinDeedPluginStart
    {DolphinAppPlugin, DolphinDeedDifficultyEasy}, // DolphinDeedPluginGameStart
    {DolphinAppPlugin, DolphinDeedDifficultyDeadly}, // DolphinDeedPluginGameWin
};

static uint16_t dolphin_deed_difficulty_value[20][4] = {
    {25, 50, 76, 100}, // Level 1
    {50, 100, 150, 200}, // Level 2
    {75, 150, 225, 400}, // Level 3
    {125, 250, 475, 500}, // Level 4
    {250, 500, 750, 1100}, // Level 5
    {300, 600, 900, 1400}, // Level 6
    {350, 750, 1100, 1700}, // Level 7
    {450, 900, 1400, 2100}, // Level 8
    {550, 1100, 1600, 2400}, // Level 9
    {600, 1200, 1900, 2800}, // Level 10
    {800, 1600, 2400, 3600}, // Level 11
    {1000, 2000, 3000, 4500}, // Level 12
    {1100, 2200, 3400, 5100}, // Level 13
    {1250, 2500, 3800, 5700}, // Level 14
    {1400, 2800, 4300, 6400}, // Level 15
    {1600, 3200, 4800, 7200}, // Level 16
    {2000, 3900, 5900, 8800}, // Level 17
    {2100, 4200, 6300, 9500}, // Level 18
    {2400, 4900, 7300, 10900}, // Level 19
    {2800, 5700, 8500, 12700}, // Level 20
};

_Static_assert(COUNT_OF(dolphin_deed_weights) == DolphinDeedMAX, "dolphin_deed_weights size error");

uint8_t dolphin_deed_get_weight(DolphinDeed deed, uint8_t level) {
    furi_check(deed < DolphinDeedMAX);
    uint8_t difficulty = dolphin_deed_weights[deed].difficulty;
    return dolphin_deed_difficulty_value[level][difficulty];
}

DolphinApp dolphin_deed_get_app(DolphinDeed deed) {
    furi_check(deed < DolphinDeedMAX);
    return dolphin_deed_weights[deed].app;
}

uint8_t dolphin_deed_get_app_limit(DolphinApp app, uint8_t level) {
    furi_check(app < DolphinAppMAX);
    // Get deadly difficulty. Max of one deadly action per day.
    return dolphin_deed_difficulty_value[level][3];
}