cmake_minimum_required(VERSION 3.15)
project(grawing_way_oop_3.0)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME, "mortalCombat.exe")
set(HEADERS
        inc/Character.hpp
        inc/Skill.hpp
        inc/Controller.hpp
        inc/FireFist.hpp
        inc/PoisonArrow.hpp
        inc/Paralysis.hpp
        inc/VampiricClaw.hpp
        inc/MagicShield.hpp
        inc/Heal.hpp
        )
set(SOURCES
        src/Character.cpp
        src/Skill.cpp
        src/Controller.cpp
        src/FireFist.cpp
        src/PoisonArrow.cpp
        src/Paralysis.cpp
        src/VampiricClaw.cpp
        src/MagicShield.cpp
        src/Heal.cpp
        main.cpp)

add_executable(${PROJECT_NAME}
        ${HEADERS}
        ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PUBLIC "inc")

#find_package(sfml REQUIRED)
#if(sfml_FOUND)
#set(TARGET_NAME )


