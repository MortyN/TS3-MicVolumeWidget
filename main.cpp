#include "volumeslider.h"

#include <QApplication>
#include <Windows.h>
#include <objbase.h>
#include <strsafe.h>
#include <assert.h>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VolumeSlider w;
    w.getMicrophones();
    w.show();
    return a.exec();
}
