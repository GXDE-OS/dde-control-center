#ifndef BRIGHTNESSMODEL_H
#define BRIGHTNESSMODEL_H

#include <QStringList>
#include <QDBusInterface>
#include <QDBusConnection>
#include <QDBusReply>

class BrightnessModel
{
public:
    BrightnessModel();

    const QString SERVICE = "com.deepin.daemon.Display";
    const QString PATH = "/com/deepin/daemon/Display";
    const QString INTERFACES = "com.deepin.daemon.Display";

    double GetFirstDisplayBrightness();
    QMap<QString, double> GetBrightness();
    QStringList ListOutputNames();
    void SetAllScreenBrightness(double brightness);
    void SetBrightness(QString display,
                       double brightness);

private:
    QVariantMap DBusDictMethodWithoutArg(QString service,
                               QString path,
                               QString interface,
                               QString method);
    QList<QVariant> DBusMethodWithoutArg(QString service,
                               QString path,
                               QString interface,
                               QString method);

    QList<QVariant> DBusMethodWithArg(QString service,
                               QString path,
                               QString interface,
                               QString method,
                               QList<QVariant> argument);
};

#endif // BRIGHTNESSMODEL_H
