// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#pragma once

#include "xsapi-c/system_c.h"

struct XSAPI_XBOX_LIVE_USER_IMPL
{
public:
    XSAPI_XBOX_LIVE_USER_IMPL(_In_ Windows::System::User^ creationContext, _In_ XBL_XBOX_LIVE_USER* pUser);
    XSAPI_XBOX_LIVE_USER_IMPL(_In_ std::shared_ptr<xbox::services::system::xbox_live_user> cppUser, _In_ XBL_XBOX_LIVE_USER *cUser);
    void Refresh();
    std::shared_ptr<xbox::services::system::xbox_live_user> cppUser() const;

private:
    xsapi_internal_string m_xboxUserId;
    xsapi_internal_string m_gamertag;
    xsapi_internal_string m_ageGroup;
    xsapi_internal_string m_privileges;
    xsapi_internal_string m_webAccountId;

    XBL_XBOX_LIVE_USER* m_pUser;
    std::shared_ptr<xbox::services::system::xbox_live_user> m_cppUser;
};