#ifndef VIDEOTHUMBNAILVIEW_H
#define VIDEOTHUMBNAILVIEW_H

#include <QObject>
#include <QLabel>
#include <QGridLayout>

class VideoThumbnailView : public QWidget {
    Q_OBJECT
public:
    explicit VideoThumbnailView(QWidget* parent = nullptr);

    void addVideo(const QString& path);
    void setVideoDirList(QStringList videoDirPath);

Q_SIGNALS:
    void newQLabel(QPixmap);

private:
    void resizeEvent(QResizeEvent* event) override;

    void addThumbnail(const QImage& image);

    void handleNewQLabel(QPixmap pixmap);

    QList <QLabel*> m_thumbnailList;
    QList <QPixmap> m_thumbnailPixmapList;
    QStringList m_thumbnailVideoPathList;
    QGridLayout m_imageLayout;
};

#endif // VIDEOTHUMBNAILVIEW_H
