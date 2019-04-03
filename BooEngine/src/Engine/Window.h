#pragma once
#include "booPCH.h"
#include "Define.h"

#include "Engine\Events\Event.h"

namespace boo
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "BooEngine", unsigned int width = 1440, unsigned int height = 900)
            :Title(title),
            Width(width),
            Height(height)
        {

        }
    };

    /*Interface Desktop System based Window than will be implementin by Platform*/
    class BOO_API Window
    {
    public:
        using EventCallBackFn = std::function<void(Event&)>;

        //Window();
        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;

        virtual unsigned int GetHeight() const = 0;

        /*Window Settings*/
        virtual void SetEventCallBack(const EventCallBackFn& callBack) = 0;

        virtual void SetVSync(bool enable) = 0;

        virtual bool IsVSync() const = 0;

        virtual void* GetNativeWindow() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());

    };

}

