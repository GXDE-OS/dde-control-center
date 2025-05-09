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

#ifndef PERSONALIZATIONWIDGET_H
#define PERSONALIZATIONWIDGET_H

#include <QPushButton>
#include <QVBoxLayout>
#include "modules/modulewidget.h"
#include "personalizationmodel.h"
#include "widgets/switchwidget.h"

namespace dcc {
namespace widgets {
class SettingsGroup;
class TitledSliderItem;
}
namespace personalization {
class PersonalizationWidget : public dcc::ModuleWidget {
    Q_OBJECT

public:
    explicit PersonalizationWidget();

public Q_SLOTS:
    void setModel(PersonalizationModel* const model);

Q_SIGNALS:
    void showThemeWidget();
    void showFontsWidget();
    void showVideoWallpaperWidget();
    void requestSwitchWM();
    void requestSetOpacity(int value);
    void requestSetTopPanel(int value);
    void requestSetTopPanelGlobalMenu(int value);
    void requestSetBottomPanel(int value);
    void requestSet20Launcher(int value);
    void requestSetHideDDEDock(int value);
    void requestSetSizeMode(int value);
    void requestSetDockUseMacMode(int value);

private:
    void onOpacityChanged(std::pair<int, double> value);
    void onBlurWindowChanged();
    void requestSetRadius(int value);
    void initRadiusSlider();

private:
    PersonalizationModel *m_model;
    dcc::widgets::SettingsGroup* m_userGroup;
    dcc::widgets::SwitchWidget*  m_wmSwitch;
    dcc::widgets::SwitchWidget*  m_showTopPanel;
    dcc::widgets::SwitchWidget*  m_showTopPanelGlobalMenu;
    dcc::widgets::SwitchWidget*  m_showBottomPanel;
    dcc::widgets::SwitchWidget*  m_use20Launcher;
    dcc::widgets::SwitchWidget*  m_hideDDEDock;
    dcc::widgets::SwitchWidget*  m_dockUseMacMode;
    dcc::widgets::SwitchWidget*  m_sizeMode;
    widgets::TitledSliderItem*   m_transparentSlider;
    widgets::TitledSliderItem*   m_radiusSlider;
    dcc::widgets::SettingsGroup *m_trGrp;
};
}
}

#endif  // PERSONALIZATIONWIDGET_H
