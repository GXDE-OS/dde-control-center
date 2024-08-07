/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
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

#include "personalizationmodel.h"
#include "model/thememodel.h"
#include "model/fontmodel.h"
#include "model/fontsizemodel.h"

#include <QFile>
#include <QDir>
#include <QProcessEnvironment>

using namespace dcc;
using namespace dcc::personalization;

PersonalizationModel::PersonalizationModel(QObject *parent)
    : QObject(parent)
    , m_opacity(std::pair<int, double>(2, 0.4f))
{
    m_windowModel    = new ThemeModel(this);
    m_iconModel      = new ThemeModel(this);
    m_mouseModel     = new ThemeModel(this);
    m_standFontModel = new FontModel(this);
    m_monoFontModel  = new FontModel(this);
    m_fontSizeModel  = new FontSizeModel(this);
    m_is3DWm = true;
}

PersonalizationModel::~PersonalizationModel()
{

}

void PersonalizationModel::setIs3DWm(const bool is3d)
{
    if (is3d != m_is3DWm) {
        m_is3DWm = is3d;
        Q_EMIT wmChanged(is3d);
    }
}

void PersonalizationModel::setTopPanelGlobalMenu(const bool value)
{
    if(!QFile::exists("/usr/share/applications/dde-globalmenu-service.desktop") /*|| !QFile::exists("/usr/share/applications/gxde-globalmenu-service.desktop")*/){
        // Setting error
        qDebug() << "Can't find gxde top panel config file: /usr/share/applications/dde-globalmenu-service.desktop or /usr/share/applications/dde-globalmenu-service.desktop";
        return;
    }
    if(value){
        QFile::copy("/usr/share/applications/dde-globalmenu-service.desktop",
                    QDir::homePath() + "/.config/autostart/dde-globalmenu-service.desktop"); // 设置自动启动
        system("setsid dde-globalmenu-service > /dev/null 2>&1 &");
        return;
    }
    QFile::remove(QDir::homePath() + "/.config/autostart/dde-globalmenu-service.desktop"); // 移除自动启动
    system("killall dde-globalmenu-service -9");
}

void PersonalizationModel::setTopPanel(const bool isTopPanel)
{
    if(!QFile::exists("/usr/share/applications/gxde-top-panel.desktop") /*|| !QFile::exists("/usr/share/applications/gxde-globalmenu-service.desktop")*/){
        // Setting error
        qDebug() << "Can't find gxde top panel config file: /usr/share/applications/gxde-top-panel.desktop or /usr/share/applications/gxde-globalmenu-service.desktop";
        return;
    }
    if(isTopPanel){
        QFile::copy("/usr/share/applications/gxde-top-panel.desktop",
                    QDir::homePath() + "/.config/autostart/gxde-top-panel.desktop"); // 设置自动启动
        system("setsid gxde-top-panel > /dev/null 2>&1 &");
        return;
    }
    QFile::remove(QDir::homePath() + "/.config/autostart/gxde-top-panel.desktop"); // 移除自动启动
    system("killall gxde-top-panel -9");
}

void PersonalizationModel::setBottomPanel(const bool value)
{
    if(!QFile::exists("/usr/share/applications/plank.desktop")){
        // Setting error
        qDebug() << "Can't find gxde top panel config file: /usr/share/applications/plank.desktop";
        return;
    }
    if(value){
        QFile::copy("/usr/share/applications/plank.desktop",
                    QDir::homePath() + "/.config/autostart/plank.desktop"); // 设置自动启动
        system("setsid plank > /dev/null 2>&1 &");
        return;
    }
    QFile::remove(QDir::homePath() + "/.config/autostart/plank.desktop"); // 移除自动启动
    system("killall plank -9");
}

void PersonalizationModel::set20Launcher(const bool value)
{
    QDir dir(QDir::homePath() + "/.config/gxde/gxde-launcher/");
    if (!dir.exists()) {
        dir.mkpath(QDir::homePath() + "/.config/gxde/gxde-launcher/");
    }
    if(value){
       QFile file(QDir::homePath() + "/.config/gxde/gxde-launcher/use_20_launcher");
       file.open(QFile::WriteOnly);
       file.write("1");
       file.close();
    }
    else {
        QFile::remove(QDir::homePath() + "/.config/gxde/gxde-launcher/use_20_launcher");
    }
    system("killall dde-launcher-x11 -9");
    system("killall dde-launcher-wayland -9");
}

void PersonalizationModel::setHideDDEDock(const bool value)
{
    QDir dir(QDir::homePath() + "/.config/gxde/gxde-launcher/");
    if (!dir.exists()) {
        dir.mkpath(QDir::homePath() + "/.config/gxde/gxde-launcher/");
    }
    if(value){
       QFile file(QDir::homePath() + "/.config/gxde/gxde-dock/dock-hide");
       file.open(QFile::WriteOnly);
       file.write("1");
       file.close();
    }
    else {
        QFile::remove(QDir::homePath() + "/.config/gxde/gxde-dock/dock-hide");
    }
    system("killall dde-dock -9");
}

bool PersonalizationModel::is3DWm() const
{
    return m_is3DWm;
}

bool PersonalizationModel::isOpenTopPanelGlobalMenu() const
{
    return QFile::exists(QDir::homePath() + "/.config/autostart/dde-globalmenu-service.desktop");
}

bool PersonalizationModel::isOpenTopPanel() const
{
    return QFile::exists(QDir::homePath() + "/.config/autostart/gxde-top-panel.desktop");
}

bool PersonalizationModel::isOpenBottomPanel() const
{
    return QFile::exists(QDir::homePath() + "/.config/autostart/plank.desktop");
}

bool PersonalizationModel::isInstallTopPanel() const
{
    return QFile::exists("/usr/bin/gxde-top-panel");
}

bool PersonalizationModel::isInstallVideoWallpaper() const
{
    return QFile::exists("/usr/bin/fantascene-dynamic-wallpaper");
}

bool PersonalizationModel::isInstallBottomPanel() const
{
    return QFile::exists("/usr/bin/plank");
}

bool PersonalizationModel::isInstall20Launcher() const
{
    return QFile::exists("/usr/bin/dde-launcher-wayland");
}

bool PersonalizationModel::isUse20Launcher() const
{
    return QFile::exists(QDir::homePath() + "/.config/gxde/gxde-launcher/use_20_launcher");
}

bool PersonalizationModel::isHideDDEDock() const
{
    return QFile::exists(QDir::homePath() + "/.config/gxde/gxde-dock/dock-hide");
}

bool PersonalizationModel::isWayland() const
{
    QString XDG_SESSION_TYPE = QProcessEnvironment::systemEnvironment().value("XDG_SESSION_TYPE");
    QString WAYLAND_DISPLAY = QProcessEnvironment::systemEnvironment().value("WAYLAND_DISPLAY");
    return XDG_SESSION_TYPE == "wayland" || WAYLAND_DISPLAY != "";
}

void PersonalizationModel::setOpacity(std::pair<int, double> opacity)
{
    if (m_opacity == opacity) return;

    m_opacity = opacity;

    Q_EMIT onOpacityChanged(opacity);
}
