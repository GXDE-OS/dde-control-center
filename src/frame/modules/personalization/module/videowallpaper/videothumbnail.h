#ifndef VIDEOTHUMBNAIL_H
#define VIDEOTHUMBNAIL_H

#include <QObject>

class VideoThumbnail : public QObject
{
    Q_OBJECT
public:
    VideoThumbnail();

    static QImage getVideoThumbnailQt5(const QString& filePath, qint64 positionMs = 1000);
};

#endif // VIDEOTHUMBNAIL_H
