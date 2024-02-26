#ifndef VIDEOWALLPAPER_H
#define VIDEOWALLPAPER_H

#include "widgets/contentwidget.h"
#include "widgets/translucentframe.h"
#include "widgets/switchwidget.h"

#include <QObject>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>

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
    QPushButton *m_moreSettingButton;
    QHBoxLayout *mediaControl;

    void OpenMoreSettingsWindow();

};
}
}

#endif // VIDEOWALLPAPER_H
