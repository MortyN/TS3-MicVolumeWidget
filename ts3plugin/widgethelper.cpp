/**
 * TeamSpeak 3 Client Notification Plugin
 *
 * Copyright (c) Sven Paulsen. All rights reserved.
 */

#include "widgethelper.h"
#include <QtWidgets>
#include "audiodevicehelper.h"

QSlider* slider;
QLCDNumber* qlcd;

/**
 * The WidgetHelper object constructor.
 */
WidgetHelper::WidgetHelper() : Singleton<WidgetHelper>()
{
    QWidgetList widgets = qApp->allWidgets();

    for(QWidgetList::iterator i = widgets.begin(); i != widgets.end(); ++i)
    {
        if((*i)->inherits("QMainWindow")) m_mainWindow = (QMainWindow*) (*i);
    }
}

/**
 * The WidgetHelper object destructor.
 */
WidgetHelper::~WidgetHelper()
{}

///**
// * Starts manipulating the client UI by adding dock widget areas and making the chat and info frame areas dockable.
// */
unsigned int WidgetHelper::betterhook() {
    if (!m_mainWindow) return 1;
    
    int curMasterVol;
    AudioDeviceHelper::ADH adh;
   

    QToolBar* parentToolbar = m_mainWindow->addToolBar(tr("toolbar"));
    
    slider = new QSlider(Qt::Horizontal, 0);
    slider->setMaximumWidth(200);
    
    qlcd = new QLCDNumber();

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setMicVolume(int)));
    connect(slider, SIGNAL(valueChanged(int)), qlcd, SLOT(display(int)));

    curMasterVol = adh.getCurrentDefaultMicVolume();
    slider->setValue(curMasterVol);

    parentToolbar->addWidget(slider);
    parentToolbar->addWidget(qlcd);

    m_hooked = true;
    return 0;
}

unsigned int WidgetHelper::hook() {
    QTimer::singleShot(200, this, &WidgetHelper::betterhook);
    return 0;
}

/**
 * Unhooks from the client UI.
 */
unsigned int WidgetHelper::unhook()
{
    if(!m_hooked) return 1;

    //backup();

    m_hooked = false;
    printf("%s", "deleting");

    delete slider;
    delete qlcd;
    delete m_stacked;
    delete m_dockInfo;
    delete m_dockChat;

    return 0;
}

/**
 * Writes plugin settings back to the config file.
 */
unsigned int WidgetHelper::backup()
{
    if(!m_loaded) return 0;

    char path[BUFFSIZE_S];

    pluginSDK.getConfigPath(path, BUFFSIZE_S);

    QSettings conf(QString(path) + "plugin_dockwidget.ini", QSettings::IniFormat);

    pluginSDK.logMessage(QString("Writing plugin settings: %0").arg(conf.fileName()).toUtf8().data(), LogLevel_INFO, PLUGIN_NAME, 0);

    conf.setValue("mainGeometry", m_mainWindow->saveGeometry());
    conf.setValue("mainWinState", m_mainWindow->saveState());
    conf.setValue("chatFloating", m_dockChat->isFloating());
    conf.setValue("chatGeometry", m_dockChat->saveGeometry());
    conf.setValue("infoFloating", m_dockInfo->isFloating());
    conf.setValue("infoGeometry", m_dockInfo->saveGeometry());

    m_loaded = false;

    return conf.status();
}

/**
 * Reads plugin settings from the config file.
 */
unsigned int WidgetHelper::restore()
{
    if(m_loaded) return 0;

    char path[BUFFSIZE_S];

    pluginSDK.getConfigPath(path, BUFFSIZE_S);

    QSettings conf(QString(path) + "plugin_dockwidget.ini", QSettings::IniFormat);

    if(conf.childKeys().size())
    {
        pluginSDK.logMessage(QString("Reading plugin settings: %0").arg(conf.fileName()).toUtf8().data(), LogLevel_INFO, PLUGIN_NAME, 0);

        m_mainWindow->restoreGeometry(conf.value("mainGeometry", m_mainWindow->saveGeometry()).toByteArray());
        m_mainWindow->restoreState(conf.value("mainWinState", m_mainWindow->saveState()).toByteArray());
        m_dockChat->setFloating(conf.value("chatFloating", m_dockChat->isFloating()).toBool());
        m_dockChat->restoreGeometry(conf.value("chatGeometry", m_dockChat->saveGeometry()).toByteArray());
        m_dockInfo->setFloating(conf.value("infoFloating", m_dockInfo->isFloating()).toBool());
        m_dockInfo->restoreGeometry(conf.value("infoGeometry", m_dockInfo->saveGeometry()).toByteArray());

        m_dockChat->show();
        m_dockInfo->show();
    }

    m_loaded = true;

    return conf.status();
}

void WidgetHelper::setMicVolume(int vol)
{
    AudioDeviceHelper::ADH audiodevicehelper;
    float volF = (float)vol / 100;
    int volume = audiodevicehelper.setDefaultMicrophoneVolume(volF);
}

/**
 * Called when the plugin fails to hook for a maximum of 25 retries.
 */
void WidgetHelper::onPluginHookFailed()
{
    hook();
}

