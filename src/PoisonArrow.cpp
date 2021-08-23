#include "PoisonArrow.hpp"


PoisonArrow::PoisonArrow(int damage, int poisonDamage, int rounds)
    :  m_arrowDamage(damage), m_poisonDamage(poisonDamage), m_rounds(rounds)
{}

std::vector<std::pair<phazeType, Involve>> PoisonArrow::operator()(std::weak_ptr<Character> self,
                                                                   std::weak_ptr<Character> enemy) {

    noused(self);
    std::pair<phazeType, Involve> instantDamage = {phazeType::Instantly, [this, enemy]() mutable {
        auto enemyPtr = enemy.lock();
        enemyPtr->getDamage(m_arrowDamage);
        std::cout<< "damaged by arrow" << std::endl;
        return 0;
    }};
    int time = m_rounds;
    std::pair<phazeType, Involve> startDamage = {phazeType::Start, [this, enemy, time]() mutable {
        auto enemyPtr = enemy.lock();
        enemyPtr->getDamage(m_poisonDamage);
        std::cout<< "damaged by poison" << std::endl;
        return --time;
    }};
    return {instantDamage, startDamage};
}


