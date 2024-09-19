//
// Created by null on 9/18/2024.
//

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void init(std::string_view loggerName, std::string_view logFile="logs/trading.log") {
        try {
            // Create color multi-threaded stdout logger
            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            console_sink->set_level(spdlog::level::info);

            // Create rotating file sink
            auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                std::string(logFile), 1024 * 1024 * 5, 3);
            file_sink->set_level(spdlog::level::trace);

            // Create logger with multiple sinks
            logger = std::make_shared<spdlog::logger>(std::string(loggerName),
                spdlog::sinks_init_list({console_sink, file_sink}));

            // Set global log level to debug
            logger->set_level(spdlog::level::debug);

            // Set global logger
            spdlog::set_default_logger(logger);

            spdlog::info("Logger initialized successfully");
        }
        catch (const spdlog::spdlog_ex& ex) {
            std::cerr << "Log initialization failed: " << ex.what() << std::endl;
        }
    }

    template<typename... Args>
    void trace(std::string_view fmt, const Args&... args) {
        logger->trace(fmt, args...);
    }

    template<typename... Args>
    void debug(std::string_view fmt, const Args&... args) {
        logger->debug(fmt, args...);
    }

    template<typename... Args>
    void info(std::string_view fmt, const Args&... args) {
        logger->info(fmt, args...);
    }

    template<typename... Args>
    void warn(std::string_view fmt, const Args&... args) {
        logger->warn(fmt, args...);
    }

    template<typename... Args>
    void error(std::string_view fmt, const Args&... args) {
        logger->error(fmt, args...);
    }

    template<typename... Args>
    void critical(std::string_view fmt, const Args&... args) {
        logger->critical(fmt, args...);
    }

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    std::shared_ptr<spdlog::logger> logger;
};

// Convenience macro for easy access to the logger
#define LOG Logger::getInstance()

// Usage example:
// LOG.info("This is an info message");
// LOG.error("This is an error message with args: {}, {}", arg1, arg2);