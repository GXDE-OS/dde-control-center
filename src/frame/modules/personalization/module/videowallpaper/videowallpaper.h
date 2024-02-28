#ifndef VIDEOWALLPAPER_H
#define VIDEOWALLPAPER_H

#include "widgets/contentwidget.h"
#include "widgets/translucentframe.h"
#include "widgets/filechoosewidget.h"
#include "widgets/nextpagewidget.h"
#include "widgets/titledslideritem.h"

#include <QObject>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>
#include <QDBusMessage>

namespace dcc
{
class ContentWidget;
namespace personalization
{
class VideoWallpaperChooser;
class VideoWallpaperControl;
class PersonalizationModel;
class VideoWallpaper : public ContentWidget
{
    Q_OBJECT
public:
    explicit VideoWallpaper(QWidget *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
    void setModel(PersonalizationModel *const model);

private:
    QVBoxLayout        *m_mainlayout;
    widgets::TranslucentFrame   *m_widget;
    QPushButton *m_playButton;
    QPushButton *m_pauseButton;
    dcc::widgets::NextPageWidget *m_moreSettingButton;
    dcc::widgets::FileChooseWidget *m_videoWallpaperChooseWidget;
    dcc::widgets::TitledSliderItem *m_volumeSetting;
    QHBoxLayout *mediaControl;


    void OpenMoreSettingsWindow();
    void SetVolumeTip(int volume);
    void SetVolume(int volume);
    void Play();

};
}
}

#endif // VIDEOWALLPAPER_H
