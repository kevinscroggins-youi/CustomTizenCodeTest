// © You i Labs Inc. All rights reserved.

#ifndef _CUSTOM_TIZEN_CODE_TEST_H_
#define _CUSTOM_TIZEN_CODE_TEST_H_

#include <framework/YiApp.h>

class CustomTizenCodeTestApp : public CYIApp
{
public:
    CustomTizenCodeTestApp();
    virtual ~CustomTizenCodeTestApp();

    virtual bool UserInit() override;
    virtual bool UserStart() override;
    virtual void UserUpdate() override;
};

#endif // _CUSTOM_TIZEN_CODE_TEST_H_
