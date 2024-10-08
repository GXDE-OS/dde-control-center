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

#include "updateview.h"
#include "dapplication.h"

#include <QStyle>
#include <QDebug>
#include <ddialog.h>
#include <QProcess>
#include <QFile>
#include <dpushbutton.h>
#include <unistd.h>


using namespace dcc::widgets;

namespace dcc{
namespace update{

UpdateView::UpdateView()
    : ModuleWidget()
{
    setObjectName("Update");
//    m_updateItem = new NextPageWidget;
//    m_updateItem->setTitle(tr("Update"));
//    m_updateGroup = new SettingsGroup;
//    m_updateGroup->appendItem(m_updateItem);

//    m_settingsItem = new NextPageWidget;
//    m_settingsItem->setTitle(tr("Update Settings"));
//    m_settingsGroup = new SettingsGroup;
//    m_settingsGroup->appendItem(m_settingsItem);

//    m_centralLayout->addWidget(m_updateGroup);
//    m_centralLayout->addWidget(m_settingsGroup);
    m_neoUpgrader = new DPushButton;
    m_neoUpgrader->setText(tr("Check and perform system Upgrade"));
    if (QFile::exists("/usr/bin/gxde-app-upgrader")) {
        // 需要保证脚本存在才会显示按钮
        m_centralLayout->addWidget(m_neoUpgrader);
    }

    m_addTestingSource = new DPushButton;
    m_addTestingSource->setText(tr("Internal Testing Group Settings"));
    if (QFile::exists("/usr/share/dde-control-center/join-testing-group.sh")) {
        // 需要保证脚本存在才会显示按钮
        m_centralLayout->addWidget(m_addTestingSource);
    }




    connect(m_addTestingSource, &DPushButton::clicked, this, &UpdateView::ShowTesingDialog);
    connect(m_neoUpgrader,&DPushButton::clicked,this,&UpdateView::ExecUpgrader);


    setTitle(tr("Update"));

    //connect(m_updateItem, &NextPageWidget::clicked, this, &UpdateView::pushUpdate);
    //connect(m_settingsItem, &NextPageWidget::clicked, this, &UpdateView::pushMirrors);
}
void UpdateView::ExecUpgrader()
{
    QProcess process;
    system("/usr/bin/gxde-app-upgrader &");
}
void UpdateView::ShowTesingDialog()
{

            QProcess process;
            process.start("bash", QStringList() << "/usr/share/dde-control-center/join-testing-group.sh");
            process.waitForStarted();
            process.waitForFinished(-1);


}



}
}
