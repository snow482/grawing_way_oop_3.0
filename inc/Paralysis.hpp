#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>


class Paralysis {
public:
    Paralysis(int rounds);
    ~Paralysis() = default;

    std::vector<std::pair<phazeType, Involve>> operator()(std::weak_ptr<Character> self,
                                                          std::weak_ptr<Character> enemy);
private:
    int m_rounds;
};


/*
контроллер должен спросить не парализована ли цель, если да, то ход следующего
если нет и паралич скастован, то парализовать, ход следующего и состояние
паралича  true после хода соперника паралич false
 */
