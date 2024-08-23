#include "soundmodel.h"

SoundModel::SoundModel()
{

}

double SoundModel::sound() const
{
    // 使用 dbus 获取当前音量
    QDBusInterface dbus("com.deepin.daemon.Audio",
                        "/com/deepin/daemon/Audio/Sink0",
                        "com.deepin.daemon.Audio.Sink");
    return dbus.property("Volume").toDouble();
}

void SoundModel::setSound(double sound)
{
    // 使用 dbus 调整音量
    QDBusInterface dbus("com.deepin.daemon.Audio",
                        "/com/deepin/daemon/Audio/Sink0",
                        "com.deepin.daemon.Audio.Sink");
    QList<QVariant> arg;
    arg << sound << true;
    dbus.callWithArgumentList(QDBus::CallMode::NoBlock, "SetVolume", arg);

}
