#ifndef VIDEOWALLPAPERMODEL_H
#define VIDEOWALLPAPERMODEL_H

#include <QObject>
#include <QDBusMessage>


class VideoWallpaperModel
{

public:
    VideoWallpaperModel();
    void play(const QString path = NULL);
    void activeWindow();
    void clear();
    void pause();
    void setFile(const QString path);
    void setVolume(const int volume);
    void stop();
    void setVideoWallpaperEnabled(const bool value);
    bool isVideoWallpaperEnabled() const;


private:
    const QString m_videoDBusDestination = "com.deepin.dde.fantascene";
    const QString m_videoDBusPath = "/com/deepin/dde/fantascene";
    const QString m_videoDBusinterface = "com.deepin.dde.fantascene";
    const QString m_videoDBusmethod;
};

#endif // VIDEOWALLPAPERMODEL_H
