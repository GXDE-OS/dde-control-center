#include "videowallpaper.h"
#include "widgets/nextpagewidget.h"
#include "../../personalizationmodel.h"

dcc::personalization::VideoWallpaper::VideoWallpaper(QWidget *parent)
    : ContentWidget{parent}
{
    setTitle(tr("Video Wallpaper"));
}
