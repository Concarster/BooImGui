#pragma once
#include "Define.h"
#include <memory>
#include <spdlog\spdlog.h>
#include <spdlog\fmt\ostr.h>

namespace boo
{
    class BOO_API Log
    {
    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    };
}

/*Engine System Logger*/
#define BOO_ENGINE_TRACE(...)       ::boo::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define BOO_ENGINE_INFO(...)        ::boo::Log::GetEngineLogger()->info(__VA_ARGS__)
#define BOO_ENGINE_WARN(...)        ::boo::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define BOO_ENGINE_ERROR(...)       ::boo::Log::GetEngineLogger()->error(__VA_ARGS__)
#define BOO_ENGINE_CRITICAL(...)    ::boo::Log::GetEngineLogger()->critical(__VA_ARGS__)

/*Client System Logger*/
#define BOO_CLIENT_TRACE(...)       ::boo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BOO_CLIENT_INFO(...)        ::boo::Log::GetClientLogger()->info(__VA_ARGS__)
#define BOO_CLIENT_WARN(...)        ::boo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BOO_CLIENT_ERROR(...)       ::boo::Log::GetClientLogger()->error(__VA_ARGS__)
#define BOO_CLIENT_CRITICAL(...)    ::boo::Log::GetClientLogger()->critical(__VA_ARGS__)