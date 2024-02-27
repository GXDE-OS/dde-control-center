#ifndef VIDEOWALLPAPERMODEL_H
#define VIDEOWALLPAPERMODEL_H

#include <QObject>
#include <QDBusMessage>


class VideoWallpaperModel
{

public:
    VideoWallpaperModel();
    void Play();
    void ActiveWindow();
    void Clear();
    void Pause();
    void SetFile(QString path);
    void SetVolume(int volume);
    void Stop();


private:
    const QString m_videoDBusDestination = "com.deepin.dde.fantascene";
    const QString m_videoDBusPath = "/com/deepin/dde/fantascene";
    const QString m_videoDBusinterface = "com.deepin.dde.fantascene";
    const QString m_videoDBusmethod;
};

#endif // VIDEOWALLPAPERMODEL_H
