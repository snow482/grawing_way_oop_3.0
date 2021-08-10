#include "Heal.hpp"



Heal::Heal(int healPoints)
    : m_additionalHp(healPoints)
{}

std::vector<std::pair<phazeType, Involve>> Heal::operator()(std::shared_ptr<Character> self,
                                                            std::shared_ptr<Character> enemy) {
    noused(enemy);
    if (self->hpQuantity() != self->getMaxHp()) {
        self->addHp(m_additionalHp);
        std::cout << "healing" << std::endl;
    }
    else {
        std::cout << "full HP!" << std::endl;
    }
}