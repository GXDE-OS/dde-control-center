#ifndef VIDEOWALLPAPERMODEL_H
#define VIDEOWALLPAPERMODEL_H

#include <QObject>
#include <QDBusMessage>


class VideoWallpaperModel
{

public:
    VideoWallpaperModel();
    void Play(const QString path = NULL);
    void ActiveWindow();
    void Clear();
    void Pause();
    void SetFile(const QString path);
    void SetVolume(const int volume);
    void Stop();


private:
    const QString m_videoDBusDestination = "com.deepin.dde.fantascene";
    const QString m_videoDBusPath = "/com/deepin/dde/fantascene";
    const QString m_videoDBusinterface = "com.deepin.dde.fantascene";
    const QString m_videoDBusmethod;
};

#endif // VIDEOWALLPAPERMODEL_H
