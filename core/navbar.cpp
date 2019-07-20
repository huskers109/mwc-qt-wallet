#include <state/state.h>
#include "navbar.h"
#include "ui_navbar.h"
#include "../state/statemachine.h"
#include "navmenuconfig.h"
#include "navmenuaccount.h"

namespace core {

NavBar::NavBar(QWidget *parent, state::StateContext * _context ) :
        QWidget(parent),
        ui(new Ui::NavBar),
        prntWnd(parent),
        context(_context)
{
    ui->setupUi(this);
}

NavBar::~NavBar() {
    delete ui;
}

void NavBar::checkButton(BTN b) {
    ui->accountButton->setChecked(b==BTN::ACCOUNTS);
    ui->notificationButton->setChecked(b==BTN::NOTIFICATION);
    ui->settingsButton->setChecked(b==BTN::SETTINGS);
}

void NavBar::on_notificationButton_clicked()
{
    checkButton(BTN::NOTIFICATION);
    context->stateMachine->setActionWindow( state::STATE::EVENTS );
}

void NavBar::on_settingsButton_clicked()
{
    checkButton(BTN::SETTINGS);

    showNavMenu( new NavMenuConfig( prntWnd, context ) );
}

void NavBar::on_accountButton_clicked()
{
    checkButton(BTN::ACCOUNTS);

    showNavMenu( new NavMenuAccount( prntWnd, context ) );
}

void NavBar::onMenuDestroy() {
    checkButton(BTN::NONE);
}


void NavBar::showNavMenu( NavMenu * menu ) {
    menu->move( navMenuPos );
    QObject::connect( menu, SIGNAL(closed()), this, SLOT(onMenuDestroy()));
    menu->show();
}


}
