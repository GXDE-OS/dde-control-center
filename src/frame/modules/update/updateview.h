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

#ifndef UPDATEVIEW_H
#define UPDATEVIEW_H

#include "modules/modulewidget.h"
#include "widgets/nextpagewidget.h"
#include "widgets/settingsgroup.h"
#include "dpushbutton.h"
#include <QPushButton>

namespace dcc{
namespace update{
class UpdateView : public ModuleWidget
{
    Q_OBJECT

public:
    explicit UpdateView();

Q_SIGNALS:
    void pushUpdate();
    void pushMirrors();

private:
    dcc::widgets::SettingsGroup* m_updateGroup;
    dcc::widgets::SettingsGroup* m_settingsGroup;
    dcc::widgets::NextPageWidget* m_updateItem;
    dcc::widgets::NextPageWidget* m_settingsItem;
    DPushButton* m_addTestingSource;
    DPushButton* m_neoUpgrader;

    void ShowTesingDialog();
    void ExecUpgrader();
};

}
}
#endif // UPDATEVIEW_H
