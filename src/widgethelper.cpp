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
QCheckBox* cBox;

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

    cBox = new QCheckBox();
    cBox->setText("lock volume:");
    cBox->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

    parentToolbar->addWidget(slider);
    parentToolbar->addWidget(qlcd);
    parentToolbar->addWidget(cBox);

    m_hooked = true;
    restore();
    return 0;
}

unsigned int WidgetHelper::hook() {
    QTimer::singleShot(10, this, &WidgetHelper::betterhook);
    return 0;
}

/**
 * Unhooks from the client UI.
 */
unsigned int WidgetHelper::unhook()
{
    if(!m_hooked) return 1;

    backup();

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

    QSettings conf(QString(path) + "plugin_micvolchanger.ini", QSettings::IniFormat);

    pluginSDK.logMessage(QString("Writing plugin settings: %0").arg(conf.fileName()).toUtf8().data(), LogLevel_INFO, PLUGIN_NAME, 0);

    conf.setValue("lockVolSetting", cBox->isChecked());

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

    QSettings conf(QString(path) + "plugin_micvolchanger.ini", QSettings::IniFormat);

    if(conf.childKeys().size())
    {
        pluginSDK.logMessage(QString("Reading plugin settings: %0").arg(conf.fileName()).toUtf8().data(), LogLevel_INFO, PLUGIN_NAME, 0);

        cBox->setChecked(conf.value("lockVolSetting", cBox->isChecked()).toBool());

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

