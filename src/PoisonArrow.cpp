#include "PoisonArrow.hpp"


PoisonArrow::PoisonArrow(int damage, int poisonDamage, int rounds)
    :  m_arrowDamage(damage), m_poisonDamage(poisonDamage), m_rounds(rounds)
{}

std::vector<std::pair<phazeType, Involve>> PoisonArrow::operator()(std::shared_ptr<Character> self,
                                                                   std::shared_ptr<Character> enemy) {

    noused(self);
    std::pair<phazeType, Involve> instantDamage = {phazeType::Instantly, [this, enemy]() mutable {
        enemy->getDamage(m_arrowDamage);
        std::cout<< "damaged by arrow" << std::endl;
        return 0;
    }};
    int time = m_rounds;
    std::pair<phazeType, Involve> endDamage = {phazeType::End, [this, enemy, time]() mutable {
        enemy->getDamage(m_poisonDamage);
        std::cout<< "damaged by poison" << std::endl;
        return --time;
    }};
    return {instantDamage, endDamage};
}


