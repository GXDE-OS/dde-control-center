/*
 * Copyright (C) 2016 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "device.h"

namespace dcc {
namespace bluetooth {

Device::Device(QObject *parent) :
    QObject(parent),
    m_id(""),
    m_name(""),
    m_paired(false),
    m_trusted(false),
    m_connecting(false),
    m_state(StateUnavailable)
{

}

void Device::setId(const QString &id)
{
    m_id = id;
}

void Device::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        Q_EMIT nameChanged(name);
    }
}

void Device::setPaired(bool paired)
{
    if (paired != m_paired) {
        m_paired = paired;
        Q_EMIT pairedChanged(paired);
    }
}

void Device::setState(const State &state)
{
    if (state != m_state) {
        m_state = state;
        Q_EMIT stateChanged(state);
    }
}

void Device::setTrusted(bool trusted)
{
    if (trusted != m_trusted) {
        m_trusted = trusted;
        Q_EMIT trustedChanged(trusted);
    }
}

void Device::setConnecting(bool connecting)
{
    if (connecting != m_connecting) {
        m_connecting = connecting;
        Q_EMIT connectingChanged(connecting);
    }
}

QDebug &operator<<(QDebug &stream, const Device *device)
{
    stream << "Device name:" << device->name() << " paired:" << device->paired() << " state:" << device->state();

    return stream;
}

} // namespace bluetooth
} // namespace dcc
