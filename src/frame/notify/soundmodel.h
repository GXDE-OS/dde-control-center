#ifndef SOUNDMODEL_H
#define SOUNDMODEL_H

#include <QObject>
#include <QDBusInterface>

class SoundModel
{
public:
    SoundModel();
    double sound() const;
    void setSound(double sound);
};

#endif // SOUNDMODEL_H
