#!/bin/bash

DESKTOP_TEMP_FILE=gxde-control-center.desktop.tmp
DESKTOP_SOURCE_FILE=gxde-control-center.desktop

DESKTOP_TS_DIR=translations/desktop/

/usr/bin/deepin-desktop-ts-convert ts2desktop $DESKTOP_SOURCE_FILE $DESKTOP_TS_DIR $DESKTOP_TEMP_FILE
mv $DESKTOP_TEMP_FILE $DESKTOP_SOURCE_FILE
