#include "volumeslider.h"
#include "ui_volumeslider.h"
#include "audiodevicehelper.h"


VolumeSlider::VolumeSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeSlider)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setMicVolume(int)));
}

void VolumeSlider::setMicVolume(int vol)
{
    printf("%d", vol);
    AudioDeviceHelper::ADH audiodevicehelper;
    float volF = (float)vol / 100;
    int volume = audiodevicehelper.setDefaultMicrophoneVolume(volF);
    
}

VolumeSlider::~VolumeSlider()
{
    delete ui;
}

