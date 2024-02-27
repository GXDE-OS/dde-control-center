#include "videowallpapermodel.h"

#include <QDBusConnection>
#include <QDebug>

VideoWallpaperModel::VideoWallpaperModel()
{

}

void VideoWallpaperModel::Play()
{
    QDBusMessage dbus = QDBusMessage::createMethodCall(m_videoDBusDestination,
                                                       m_videoDBusPath,
                                                       m_videoDBusinterface,
                                                       "play");
    QDBusMessage res = QDBusConnection::sessionBus().call(dbus);
}

void VideoWallpaperModel::ActiveWindow()
{
    QDBusMessage dbus = QDBusMessage::createMethodCall(m_videoDBusDestination,
                                                       m_videoDBusPath,
                                                       m_videoDBusinterface,
                                                       "activeWindow");
    QDBusMessage res = QDBusConnection::sessionBus().call(dbus);
}

void VideoWallpaperModel::Clear()
{
    QDBusMessage dbus = QDBusMessage::createMethodCall(m_videoDBusDestination,
                                                       m_videoDBusPath,
                                                       m_videoDBusinterface,
                                                       "clear");
    QDBusMessage res = QDBusConnection::sessionBus().call(dbus);
}

void VideoWallpaperModel::Pause()
{
    QDBusMessage dbus = QDBusMessage::createMethodCall(m_videoDBusDestination,
                                                       m_videoDBusPath,
                                                       m_videoDBusinterface,
                                                       "pause");
    QDBusMessage res = QDBusConnection::sessionBus().call(dbus);
}

void VideoWallpaperModel::SetFile(QString path)
{

}

void VideoWallpaperModel::SetVolume(int volume)
{

}

void VideoWallpaperModel::Stop()
{
    QDBusMessage dbus = QDBusMessage::createMethodCall(m_videoDBusDestination,
                                                       m_videoDBusPath,
                                                       m_videoDBusinterface,
                                                       "stop");
    QDBusMessage res = QDBusConnection::sessionBus().call(dbus);
}
