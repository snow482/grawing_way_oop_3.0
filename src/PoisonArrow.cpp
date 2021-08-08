#include "PoisonArrow.hpp"


PoisonArrow::PoisonArrow(int damage, int poisonDamage)
    :  m_arrowDamage(damage), m_poisonDamage(poisonDamage)
{}

std::vector<std::pair<phazeType, Involve>> PoisonArrow::operator()(std::shared_ptr<Character> self,
                                                                   std::shared_ptr<Character> enemy) {

    noused(self);
    /*std::pair<phazeType, Involve> startDamage = {phazeType::Start, [this, enemy]() mutable {
        enemy->getDamage(m_arrowDamage);
        std::cout<< "damaged by arrow" << std::endl;
        return 0;
    }};*/
    std::pair<phazeType, Involve> instantDamage = {phazeType::Instantly, [this, enemy]() mutable {
        enemy->getDamage(m_arrowDamage);
        std::cout<< "damaged by arrow" << std::endl;
        return 0;
    }};
    int rounds = 3;
    std::pair<phazeType, Involve> dot = {phazeType::End, [this, enemy, rounds]() mutable {
        enemy->getDamage(m_poisonDamage);
        std::cout<< "damaged by poison" << std::endl;
        return --rounds;
    }};
    return {/*startDamage,*/ instantDamage, dot};
}


