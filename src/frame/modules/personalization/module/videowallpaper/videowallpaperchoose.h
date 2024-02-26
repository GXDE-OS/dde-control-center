#ifndef VIDEOWALLPAPERCHOOSE_H
#define VIDEOWALLPAPERCHOOSE_H

#include "widgets/translucentframe.h"
#include "widgets/settingsgroup.h"

#include <QObject>
#include <QSlider>

namespace dcc
{
namespace widgets
{
class TranslucentFrame;
class SettingsGroup;
class TitledSliderItem;
}
namespace personalization
{
class VideoWallpaperChoose : public widgets::TranslucentFrame
{
    Q_OBJECT
public:
    explicit VideoWallpaperChoose(QWidget *parent = nullptr);

Q_SIGNALS:

private:
    QVBoxLayout   *m_mainlayout;
    widgets::SettingsGroup *m_mainWidget;
    widgets::TitledSliderItem *m_sizeWidget;
    //QSlider          *m_fontSlider;
};
}
}

#endif // VIDEOWALLPAPERCHOOSE_H
