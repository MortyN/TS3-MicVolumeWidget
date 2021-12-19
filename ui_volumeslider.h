/********************************************************************************
** Form generated from reading UI file 'volumeslider.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMESLIDER_H
#define UI_VOLUMESLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeSlider
{
public:
    QSlider *horizontalSlider;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *VolumeSlider)
    {
        if (VolumeSlider->objectName().isEmpty())
            VolumeSlider->setObjectName(QString::fromUtf8("VolumeSlider"));
        VolumeSlider->resize(635, 600);
        horizontalSlider = new QSlider(VolumeSlider);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 10, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        lcdNumber = new QLCDNumber(VolumeSlider);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(200, 10, 64, 23));

        retranslateUi(VolumeSlider);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(VolumeSlider);
    } // setupUi

    void retranslateUi(QWidget *VolumeSlider)
    {
        VolumeSlider->setWindowTitle(QApplication::translate("VolumeSlider", "VolumeSlider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolumeSlider: public Ui_VolumeSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMESLIDER_H
