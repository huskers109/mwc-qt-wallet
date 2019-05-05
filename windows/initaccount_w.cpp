#include "initaccount_w.h"
#include "ui_initaccount.h"
#include "../util/passwordanalyser.h"
#include <QMessageBox>
#include "../state/initaccount.h"

namespace wnd {

InitAccount::InitAccount(QWidget *parent, state::InitAccount * _state) :
    QWidget(parent),
    ui(new Ui::InitAccount),
    state(_state)
{
    ui->setupUi(this);

    util::PasswordAnalyser pa( ui->password1Edit->text() );
    ui->strengthLabel->setText(pa.getPasswordQualityStr());

    ui->submitButton->setEnabled( pa.isPasswordOK() );
}

InitAccount::~InitAccount()
{
    delete ui;
}

}

void wnd::InitAccount::on_password1Edit_textChanged(const QString &text)
{
    util::PasswordAnalyser pa(text);
    ui->strengthLabel->setText(pa.getPasswordQualityStr());
    ui->submitButton->setEnabled( pa.isPasswordOK() );
}

void wnd::InitAccount::on_submitButton_clicked()
{
    QString pswd1 = ui->password1Edit->text();
    QString pswd2 = ui->password2Edit->text();

    if (pswd1!=pswd2) {
        QMessageBox::critical(this, "Password", "Password doesn't match confirm string. Please retype the password correctly");
        return;
    }

    util::PasswordAnalyser pa(pswd1);
    if (! pa.isPasswordOK() ) {
        QMessageBox::critical(this, "Password", "Your password is not strong enough. Please input stronger password");
        return;
    }

    state->setPassword(pswd1);
}
