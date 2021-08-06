// © You i Labs Inc. 2000-2020. All rights reserved.

#include "CustomTizenCodeTestApp.h"

#include "bridges/example/ExampleBridgeLocator.h"

#include <framework/YiFramework.h>
#include <logging/YiLogger.h>

#define LOG_TAG "CustomTizenCodeTestApp"

CustomTizenCodeTestApp::CustomTizenCodeTestApp() = default;

CustomTizenCodeTestApp::~CustomTizenCodeTestApp() = default;

bool CustomTizenCodeTestApp::UserInit()
{
    auto pExampleBridge = ExampleBridgeLocator::GetExampleBridge();

    if(pExampleBridge)
    {
        pExampleBridge->SequentialNumber.Connect([](int32_t sequentialNumber){
            YI_LOGI(LOG_TAG, "Sequential Number Event #%d!", sequentialNumber);
        });

        CYIString nickname(pExampleBridge->GetNickname());

        YI_LOGI(LOG_TAG, "Default Nickname: '%s'.", nickname.GetData());

        pExampleBridge->SetNickname("Awesome Bridge");

        CYIString newNickname(pExampleBridge->GetNickname());

        YI_LOGI(LOG_TAG, "New Nickname: '%s'.", newNickname.GetData());

        CYIString ipAddress(pExampleBridge->GetIPAddress());

        YI_LOGI(LOG_TAG, "IP Address: '%s'.", ipAddress.GetData());

        std::vector<CYIString> loadedScripts = pExampleBridge->GetLoadedScripts();

        YI_LOGI(LOG_TAG, "%d Scripts Loaded:", loadedScripts.size());

        for(size_t i = 0; i < loadedScripts.size(); i++)
        {
            YI_LOGI(LOG_TAG, "%d. %s", i + 1, loadedScripts[i].GetData());
        }
    }
    else
    {
        YI_LOGW(LOG_TAG, "Example bridge not available for current platform!");
    }

    return true;
}

bool CustomTizenCodeTestApp::UserStart()
{
    return true;
}

void CustomTizenCodeTestApp::UserUpdate()
{
}
