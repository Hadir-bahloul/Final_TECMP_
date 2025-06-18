#pragma once

#include <memory>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "TE-DriverBase/DriverBaseTypes.hpp"
#include "TE-DriverBase/DriverBaseMain.hpp"
#include "TE-DriverBase/DriverBaseInterface.hpp"
#include "TE-BTS-Driver/InitData.hpp"
#include "TE-BTS-Driver/Interfaces.hpp"
#include "TE-BTS-Driver/Types.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <utility>
#include <imgui.h>

class Logging:public TE::Driver::ILogger {
public:
    static void init(const std::string& loggerName, const std::string& filePath = "");

    template<typename... Args>
    static void info(const std::string& fmt, Args&&... args) {
        logMessage(spdlog::level::info, fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void debug(const std::string& fmt, Args&&... args) {
        logMessage(spdlog::level::debug, fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void warn(const std::string& fmt, Args&&... args) {
        logMessage(spdlog::level::warn, fmt, std::forward<Args>(args)...);
    }

    template<typename... Args>
    static void error(const std::string& fmt, Args&&... args) {
        logMessage(spdlog::level::err, fmt, std::forward<Args>(args)...);
    }

    static const std::vector<std::pair<std::string, ImVec4>>& getLogs();
    static void renderLogArea();
    static void clean();

private:
    static std::shared_ptr<spdlog::logger> logger;
    static std::vector<std::pair<std::string, ImVec4>> logs;

    static std::string getCurrentTimestamp();
    static ImVec4 getColorForLevel(spdlog::level::level_enum level);

    template<typename... Args>
    static void logMessage(spdlog::level::level_enum level, const std::string& fmtStr, Args&&... args) {
        if (logger) {
            std::string timestamp = getCurrentTimestamp();
            std::string message = fmt::format(fmtStr, std::forward<Args>(args)...);
            
            logs.push_back({ timestamp + " " + message, getColorForLevel(level) });
            
            // Limit log history to prevent memory issues
            if (logs.size() > 1000) {
                logs.erase(logs.begin());
            }
            
            logger->log(level, fmtStr, std::forward<Args>(args)...);
        }
    }
};