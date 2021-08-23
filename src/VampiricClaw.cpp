#include "VampiricClaw.hpp"


VampiricClaw::VampiricClaw(int vampiricDamage, int vampiricHp, int rounds)
    : m_vampiricDamage(vampiricDamage), m_vampiricHp(vampiricHp), m_rounds(rounds)
{}

std::vector<std::pair<phazeType, Involve>> VampiricClaw::operator()(std::weak_ptr<Character> self,
                                                                    std::weak_ptr<Character> enemy) {

    std::pair<phazeType, Involve> instantDamage = {phazeType::Instantly, [vampiricDamage = m_vampiricDamage, enemy]() {
        auto enemyPtr = enemy.lock();
        enemyPtr->getDamage(vampiricDamage);
        std::cout << "damaged by vampiric claw" << std::endl;
        return 0;
    }};

    int time = m_rounds;
    std::pair<phazeType, Involve> vampiric = {phazeType::End, [this, self, time]() mutable {
        auto selfPtr = self.lock();
        selfPtr->addHp(m_vampiricHp); // внутри выглядит как this->m_vampiricHp
        std::cout << "drinked hp" << std::endl;
        return --time;
    }};
    return {instantDamage, vampiric};
}