cmake_minimum_required(VERSION 3.29)
project(multi_broker_trading_system)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(multi_broker_trading_system src/main.cpp)

#[[target_link_libraries(multi_broker_trading_system PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(multi_broker_trading_system PRIVATE spdlog::spdlog)
target_link_libraries(multi_broker_trading_system PRIVATE imgui::imgui)]]

target_link_libraries(${PROJECT_NAME} PRIVATE
        spdlog::spdlog
        nlohmann_json::nlohmann_json
        imgui::imgui
)

#[[
src/core/Logger.cpp
src/core/Logger.h
src/core/RiskManager.cpp
src/core/RiskManager.h
src/core/OrderManager.cpp
src/core/OrderManager.h
src/core/MarketDataManager.cpp
src/core/MarketDataManager.h
src/core/TradingEngine.cpp
src/core/TradingEngine.h
src/brokers/ExnessBroker.cpp
src/brokers/ExnessBroker.h
src/brokers/BinanceBroker.cpp
src/brokers/BinanceBroker.h
src/core/DataSource.cpp
src/core/DataSource.h
src/strategies/EMA.cpp
src/strategies/EMA.h
src/strategies/BollingerBands.cpp
src/strategies/BollingerBands.h
src/strategies/RSI.cpp
src/strategies/RSI.h
src/strategies/Hedging.cpp
src/strategies/Hedging.h]]
