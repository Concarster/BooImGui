#pragma once
#include "Engine/InputMgr.h"

namespace boo
{
    class WInputMgr : public InputMgr
    {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;

        virtual std::pair<float, float> GetMousePositionImpl() override;

        virtual float GetMouseXImpl() override;

        virtual float GetMouseYImpl() override;
    };
}
