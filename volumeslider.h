#ifndef VOLUMESLIDER_H
#define VOLUMESLIDER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class VolumeSlider; }
QT_END_NAMESPACE

class VolumeSlider : public QWidget
{
    Q_OBJECT

public:
    VolumeSlider(QWidget *parent = nullptr);
    void getMicrophones();
    ~VolumeSlider();

private:
    Ui::VolumeSlider *ui;
};
#endif // VOLUMESLIDER_H