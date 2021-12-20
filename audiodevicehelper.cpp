#include <Windows.h>
#include <stdio.h>
#include "audiodevicehelper.h"
#include <Mmdeviceapi.h>
#include <Endpointvolume.h>

#pragma comment(lib, "WinMM.lib")

using namespace AudioDeviceHelper;

//IAudioEndpointVolume getEndpoint(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 micorspeaker) {
//
//
//
//    return
//}

int ADH::setDefaultMicrophoneVolume(float nVolume)
{
    HRESULT hr = NULL;
    IMMDeviceEnumerator* deviceEnumerator = NULL;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
        __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
    if (FAILED(hr))
        return FALSE;

    IMMDevice* defaultDevice = NULL;
    hr = deviceEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    if (FAILED(hr))
        return FALSE;

    IAudioEndpointVolume* endpointVolume = NULL;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
        CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
    defaultDevice->Release();
    if (FAILED(hr))
        return FALSE;

    hr = endpointVolume->SetMasterVolumeLevelScalar(nVolume, NULL);
    endpointVolume->Release();

    return SUCCEEDED(hr);


	return 0;
}

int ADH::getCurrentDefaultMicVolume()
{
    float masterVol;
    int resVol;
    HRESULT hr = NULL;
    IMMDeviceEnumerator* deviceEnumerator = NULL;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
        __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
    if (FAILED(hr))
        return FALSE;

    IMMDevice* defaultDevice = NULL;
    hr = deviceEnumerator->GetDefaultAudioEndpoint(eCapture, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    if (FAILED(hr))
        return FALSE;

    IAudioEndpointVolume* endpointVolume = NULL;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
        CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
    defaultDevice->Release();
    if (FAILED(hr))
        return FALSE;

    hr = endpointVolume->GetMasterVolumeLevelScalar(&masterVol);
    endpointVolume->Release();
    resVol = masterVol * 100;

    return resVol;

}

