#include "MagicShield.hpp"
#include "Character.hpp"


MagicShield::MagicShield(int rounds)
    : m_rounds(rounds)
{}

std::vector<std::pair<phazeType, Involve>> MagicShield::operator()(std::shared_ptr<Character> self,
                                                                   std::shared_ptr<Character> enemy) {
    int time = m_rounds;
    std::pair<phazeType, Involve> startBlock = {phazeType::Start, [this, self, time]() mutable {
        std::cout << "Under the shield (start)" << std::endl;
        /*self->setShield(m_turns);*/
        return --time;
    }};
    std::pair<phazeType, Involve> endBlock = {phazeType::End, [this, self, time]() mutable {
        std::cout << "Under the shield (end)" << std::endl;
        /*self->setShield(m_turns);*/
        return -- time;
    }};

    //self->getDamage(m_blockedDamage); TODO
    noused(enemy);
    return {startBlock, endBlock};
}

