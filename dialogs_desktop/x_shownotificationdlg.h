// Copyright 2019 The MWC Developers
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SHOWNOTIFICATIONDLG_H
#define SHOWNOTIFICATIONDLG_H

#include <QDialog>
#include "../core/Notification.h"
#include "../control_desktop/mwcdialog.h"

namespace Ui {
class ShowNotificationDlg;
}

namespace dlg {

class ShowNotificationDlg : public control::MwcDialog {
Q_OBJECT

public:
    explicit ShowNotificationDlg(const QString & time, const QString & level,
            const QString & message, QWidget *parent);

    ~ShowNotificationDlg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowNotificationDlg *ui;
};

}

#endif // SHOWNOTIFICATIONDLG_H
