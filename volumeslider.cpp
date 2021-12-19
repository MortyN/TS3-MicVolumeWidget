#include "volumeslider.h"
#include "ui_volumeslider.h"
#include <Windows.h>
#include <mmsystem.h>
#include <mmeapi.h>

#pragma comment(lib, "WinMM.lib")

VolumeSlider::VolumeSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeSlider)
{
    ui->setupUi(this);
}

void showMixerCaps(int deviceNumber) {
	MMRESULT r;

	MIXERCAPS mixerCaps;
	memset(&mixerCaps, 0, sizeof(mixerCaps));
	r = mixerGetDevCaps(deviceNumber, &mixerCaps, sizeof(mixerCaps));
	printf("device number　= %d:\n", deviceNumber);
	printf("wMid           = %d\n", mixerCaps.wMid);
	printf("wPid           = %d\n", mixerCaps.wPid);	
	printf("vDriverVersion = %04xh\n", mixerCaps.vDriverVersion);	
	printf("szPname        = [%s]\n", mixerCaps.szPname);	
	printf("fdwSupport     = %d\n", mixerCaps.fdwSupport);	
	printf("cDestinations  = %d\n", mixerCaps.cDestinations);	

	OutputDebugString(mixerCaps.szPname);

	printf("\n");
}

void VolumeSlider::getMicrophones()
{
    UINT numdevs = mixerGetNumDevs();

    for (UINT i = 0; i < numdevs; i++)
    {
		showMixerCaps(i);
    }
    

    printf("%d", numdevs);
}

VolumeSlider::~VolumeSlider()
{
    delete ui;
}

