#pragma once
#include <functional>
#include <Character.hpp>


class Paralysis {
public:
    Paralysis(std::string& skillName);
    ~Paralysis() = default;

    int operator()(std::shared_ptr<Character> self,
             std::shared_ptr<Character> enemy);
private:
    std::string m_skillName;
};


/*
контроллер должен спросить не парализована ли цель, если да, то ход следующего
если нет и паралич скастован, то парализовать, ход следующего и состояние
паралича  true после хода соперника паралич false
 */
