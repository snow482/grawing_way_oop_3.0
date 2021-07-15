#pragma once
#include "Skill.hpp"


class Paralysis : public Skill {
public:
    explicit Paralysis(int turns);
    void Use(std::shared_ptr<Character> self,
             std::shared_ptr<Character> enemy) override;
private:
    int m_turns;
};


/*
контроллер должен спросить не парализована ли цель, если да, то ход следующего
если нет и паралич скастован, то парализовать, ход следующего и состояние
паралича  true после хода соперника паралич false
 */
