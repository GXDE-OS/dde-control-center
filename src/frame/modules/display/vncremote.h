#ifndef VNCREMOTE_H
#define VNCREMOTE_H

#include "widgets/contentwidget.h"
#include "widgets/translucentframe.h"
#include "widgets/nextpagewidget.h"
#include "widgets/titledslideritem.h"
#include "widgets/switchwidget.h"

#include <QObject>
#include <QVBoxLayout>
#include <QDebug>
#include <QPushButton>
#include <QDBusMessage>
#include "widgets/passwdeditwidget.h"

namespace dcc
{
class ContentWidget;
namespace display
{
class DisplayModel;
class VNCRemote : public ContentWidget
{
    Q_OBJECT
public:
    explicit VNCRemote(QWidget *parent = nullptr);

public Q_SLOTS:
    void setModel(DisplayModel *const model);


private:
    QVBoxLayout        *m_mainlayout;
    widgets::TranslucentFrame   *m_widget;
    dcc::widgets::SwitchWidget *m_enableSwitch;
    dcc::widgets::PasswdEditWidget *passwordFirst;
    dcc::widgets::PasswdEditWidget  *passwordAgain;
    dcc::widgets::TipsLabel *passwordTips;
    dcc::widgets::TipsLabel *passwordSettingStatus;
    QPushButton *setPasswordButton;



    void EnableOptionChange();
    void LoadSetting();
    void SetVNCPassword();
    void SetVNCEnabled();
    void RestartX11VNC();


};
}
}

#endif // VNCREMOTE_H
