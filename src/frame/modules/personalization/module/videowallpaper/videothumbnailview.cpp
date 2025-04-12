#include "videothumbnailview.h"
#include "videothumbnail.h"
#include <QResizeEvent>
#include <QDir>
#include <QtConcurrent>

VideoThumbnailView::VideoThumbnailView(QWidget* parent)
    : QWidget(parent)
{
    setLayout(&m_imageLayout);
    connect(this, &VideoThumbnailView::newQLabel, this, &VideoThumbnailView::handleNewQLabel);
}

void VideoThumbnailView::handleNewQLabel(QPixmap pixmap)
{
    QLabel *label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_thumbnailPixmapList << pixmap;
    m_thumbnailList << label;
    label->setPixmap(pixmap);
    m_imageLayout.addWidget(label,
                            (m_thumbnailList.count() - 1) / 2,
                            (m_thumbnailList.count() - 1) % 2);
}

void VideoThumbnailView::addThumbnail(const QImage& image)
{
    //QLabel *label = new QLabel();

    QPixmap pixmap = QPixmap::fromImage(image);
    //label->setAlignment(Qt::AlignCenter);
    //label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    if (pixmap.isNull()) {
        pixmap = QPixmap("/home/gfdgd_xi/Pictures/icon1.png");
    }




    pixmap = pixmap.scaled(
            this->width() * 0.45,
            this->width() * 0.45 * 9 / 16,
            Qt::KeepAspectRatio,
            Qt::FastTransformation
        );

    Q_EMIT newQLabel(pixmap);


    //connect(label, &QLabel)
}

void VideoThumbnailView::resizeEvent(QResizeEvent* event)
{
    int width = this->width() * 0.45;
    int height = this->width() * 0.45 * 9 / 16;
    for (int i = 0; i < m_thumbnailList.count(); ++i) {
        QPixmap pixmap = m_thumbnailPixmapList[i];
        QLabel *label = m_thumbnailList[i];
        pixmap = pixmap.scaled(
            width,
            height,
            Qt::KeepAspectRatio,
            Qt::FastTransformation
        );
        label->setPixmap(pixmap);
    }
    QWidget::resizeEvent(event);
}


void VideoThumbnailView::addVideo(const QString& path)
{
    addThumbnail(VideoThumbnail::getVideoThumbnailQt5(path));
    m_thumbnailVideoPathList << path;
}

void VideoThumbnailView::setVideoDirList(QStringList videoDirPath)
{
    for (QString i: videoDirPath) {
        QDir dir(i);
        if (!dir.exists()) {
            continue;
        }
        dir.setFilter(QDir::Files);
        dir.setNameFilters(QStringList() << "*.mp4");
        QStringList list = dir.entryList();
        for (QString j: list) {
            QString videoPath = i + "/" + j;
            if (m_thumbnailVideoPathList.contains(videoPath)) {
                continue;
            }
            QtConcurrent::run([=]() {
                addVideo(videoPath);
            });
        }
    }
}
