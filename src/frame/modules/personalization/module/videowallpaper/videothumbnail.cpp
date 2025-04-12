#include "videothumbnail.h"
#include <QImage>
#include <QMediaPlayer>
#include <QVideoProbe>
#include <QEventLoop>
#include <QTimer>
#include <QImage>
#include <QFileInfo>
#include <QMediaMetaData>

VideoThumbnail::VideoThumbnail()
{

}

// 显示缩略图
QImage VideoThumbnail::getVideoThumbnailQt5(const QString& filePath, qint64 positionMs) {
    QImage thumbnail;

    // 检查文件存在性
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists()) {
        qWarning() << "File not found:" << filePath;
        return thumbnail;
    }

    QMediaPlayer player;
    QVideoProbe probe;
    if (!probe.setSource(&player)) {
        qWarning() << "Failed to initialize video probe";
        return thumbnail;
    }

    QEventLoop loop;
    QTimer timeoutTimer;
    timeoutTimer.setSingleShot(true);

    // 超时处理
    QObject::connect(&timeoutTimer, &QTimer::timeout, [&]() {
        qWarning() << "Operation timed out";
        loop.quit();
    });

    // 错误处理
    QObject::connect(&player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),
        [&](QMediaPlayer::Error error) {
            qWarning() << "Media error:" << player.errorString();
            loop.quit();
        });

    bool frameCaptured = false;

    // 视频帧捕获
    QObject::connect(&probe, &QVideoProbe::videoFrameProbed, [&](const QVideoFrame &frame) {
        if (frame.isValid() && !frameCaptured) {
            QVideoFrame cloneFrame(frame);
            if (cloneFrame.map(QAbstractVideoBuffer::ReadOnly)) {
                thumbnail = cloneFrame.image();
                cloneFrame.unmap();
                frameCaptured = true;
                loop.quit();
            }
        }
    });

    // 媒体状态处理
    QObject::connect(&player, &QMediaPlayer::mediaStatusChanged, [&](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadedMedia) {
            player.setPosition(positionMs);
            timeoutTimer.start(3000); // 3秒内捕获帧
        } else if (status == QMediaPlayer::InvalidMedia) {
            qWarning() << "Invalid media file";
            loop.quit();
        }
    });

    player.setMedia(QUrl::fromLocalFile(filePath));
    timeoutTimer.start(5000); // 总超时5秒
    loop.exec();

    return thumbnail;
}
