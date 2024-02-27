#include "videowallpaperchoose.h"
#include "videowallpaper.h"
#include "videowallpapermodel.h"
#include "widgets/nextpagewidget.h"
#include "widgets/buttontuple.h"
#include "widgets/labels/tipslabel.h"
#include "../../personalizationmodel.h"

using namespace dcc;
using namespace dcc::widgets;
using namespace dcc::personalization;

dcc::personalization::VideoWallpaper::VideoWallpaper(QWidget *parent)
    : ContentWidget{parent}
{
    m_mainlayout         = new QVBoxLayout;
    m_widget             = new TranslucentFrame;

    m_videoWallpaperChooseWidget = new FileChooseWidget();
    m_playButton = new QPushButton(tr("Play"));
    m_pauseButton = new QPushButton(tr("Pause"));
    m_moreSettingButton = new NextPageWidget();

    m_videoWallpaperChooseWidget->setTitle(tr("Choose wallpaper path:"));
    m_moreSettingButton->setTitle(tr("More Settings"));

    connect(m_playButton, &QPushButton::clicked, this, [](){VideoWallpaperModel().Play();});
    connect(m_pauseButton, &QPushButton::clicked, this, [](){VideoWallpaperModel().Pause();});
    connect(m_moreSettingButton, &NextPageWidget::clicked, this, [](){VideoWallpaperModel().ActiveWindow();});

    // 并列显示按钮
    mediaControl = new QHBoxLayout;
    mediaControl->addWidget(m_playButton);
    mediaControl->addWidget(m_pauseButton);

    m_mainlayout->addWidget(m_videoWallpaperChooseWidget);
    m_mainlayout->addLayout(mediaControl);
    m_mainlayout->addWidget(m_moreSettingButton);
    m_mainlayout->addWidget(new TipsLabel("Power by fantascene-dynamic-wallpaper"));

    m_mainlayout->addSpacing(10);
    m_mainlayout->setMargin(0);
    m_mainlayout->setSpacing(10);

    m_widget->setLayout(m_mainlayout);
    setTitle(tr("Video Wallpaper"));
    setContent(m_widget);


}

void VideoWallpaper::setModel(PersonalizationModel *const model)
{
    //m_fontSizeWidget->setModel(model->getFontSizeModel());
    //m_fontSettingsWidget->setModel(model);
}

void VideoWallpaper::OpenMoreSettingsWindow(){
    system("setsid fantascene-dynamic-wallpaper > /dev/null 2>&1 &");
}
