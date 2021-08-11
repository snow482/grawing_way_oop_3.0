#include "FireFist.hpp"



FireFist::FireFist(int fireDamage)
    : m_fireDamage(fireDamage)
{}

std::vector<std::pair<phazeType, Involve>> FireFist::operator()(std::shared_ptr<Character> self,
                                                                std::shared_ptr<Character> enemy) {
    noused(self);
    std::pair<phazeType, Involve> startDamage = {phazeType::Start, [this, enemy]() mutable {
        enemy->getDamage(m_fireDamage);
        std::cout<< "damaged by arrow" << std::endl;
        return 0;
    }};

    std::pair<phazeType, Involve> instantDamage = {phazeType::Instantly, [this, enemy]() mutable {
        enemy->getDamage(m_fireDamage);
        std::cout<< "damaged by arrow" << std::endl;
        return 0;
    }};
    std::pair<phazeType, Involve> endDamage = {phazeType::End, [this, enemy]() mutable {
        enemy->getDamage(m_fireDamage);
        std::cout<< "damaged by arrow" << std::endl;
        return 0;
    }};
    return {startDamage, instantDamage, endDamage};
}


