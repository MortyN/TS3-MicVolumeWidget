/**
 * TeamSpeak 3 Client Dock Widget Plugin
 *
 * Copyright (c) Sven Paulsen. All rights reserved.
 */

#ifndef SHARED_H
#define SHARED_H

#include <QApplication>
#include <QMainWindow>
#include <QStackedWidget>
#include <QDockWidget>
#include <QTabWidget>
#include <QSettings>
#include <QSplitter>
#include <QDialog>
#include <QTimer>
#include <QThread>

#include "teamspeak/public_rare_definitions.h"
#include "ts3_functions.h"

#define PLUGIN_NAME "Mic Volume Widget"
#define PLUGIN_VER  "1.0"
#define PLUGIN_API  26
#define BUFFSIZE_L  512
#define BUFFSIZE_M  256
#define BUFFSIZE_D  128
#define BUFFSIZE_S  64

extern struct TS3Functions pluginSDK;
extern char*               pluginID;

#endif // SHARED_H
