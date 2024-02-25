#ifndef VIDEOWALLPAPER_H
#define VIDEOWALLPAPER_H

#include "widgets/contentwidget.h"
#include "widgets/translucentframe.h"

#include <QObject>
#include <QVBoxLayout>
#include <QDebug>

namespace dcc
{
class ContentWidget;
namespace personalization
{
class VideoWallpaperChooser;
class VideoWallpaperControl;
class VideoWallpaper : public ContentWidget
{
    Q_OBJECT
public:
    explicit VideoWallpaper(QWidget *parent = nullptr);

Q_SIGNALS:

private:
    QVBoxLayout        *m_mainlayout;
    widgets::TranslucentFrame   *m_widget;

};
}
}

#endif // VIDEOWALLPAPER_H
