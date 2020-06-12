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

#include "state/z_wallethome.h"
#include "../wallet/wallet.h"
#include "../core/appcontext.h"
#include "../state/statemachine.h"
#include "../util/Log.h"
#include "../core/global.h"
#include "../core/Config.h"
#include "../core/WndManager.h"
#include <QCoreApplication>
#include "../bridge/BridgeManager.h"
#include "../bridge/wnd/a_inputpassword_b.h"

namespace state {

WalletHome::WalletHome( StateContext * _context) :
    State(_context, STATE::WALLET_HOME)
{
}

WalletHome::~WalletHome() {
}

NextStateRespond WalletHome::execute() {
    if (context->appContext->getActiveWndState() != STATE::WALLET_HOME)
        return NextStateRespond(NextStateRespond::RESULT::DONE);

    core::getWndManager()->pageWalletHome();   // you need to add your page at WndManager
    return NextStateRespond( NextStateRespond::RESULT::WAIT_FOR_ACTION );
}

}
