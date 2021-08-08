#include "VampiricClaw.hpp"


VampiricClaw::VampiricClaw(int vampiricDamage, int vampiricHp)
    : m_vampiricDamage(vampiricDamage), m_vampiricHp(vampiricHp)
{}

std::vector<std::pair<phazeType, Involve>> VampiricClaw::operator()(std::shared_ptr<Character> self,
                                                                    std::shared_ptr<Character> enemy) {

    std::pair<phazeType, Involve> instantDamage = {phazeType::Instantly, [this, enemy]() mutable {
        enemy->getDamage(m_vampiricDamage);
        std::cout << "damaged by vampiric claw" << std::endl;
        return 0;
    }};

    int rounds = 2;
    std::pair<phazeType, Involve> vampiric = {phazeType::End, [this, self, rounds]() mutable {
        if (self->hpQuantity() != self->getMaxHp()) {
            self->addHp(m_vampiricHp);
            std::cout << "drinked hp" << std::endl;
        }
        else {
            std::cout << "full HP!" << std::endl;
        }
    }};
    return {};
}