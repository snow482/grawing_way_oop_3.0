#include "Heal.hpp"



Heal::Heal(int healPoints)
    : m_additionalHp(healPoints)
{}

std::vector<std::pair<phazeType, Involve>> Heal::operator()(std::shared_ptr<Character> self,
                                                            std::shared_ptr<Character> enemy) {
    noused(enemy);
    std::pair<phazeType, Involve> instantHeal = {phazeType::Instantly, [this, self]() mutable {
        self->addHp(m_additionalHp);
        std::cout << "Healing" << std::endl;
        return 0;
    }};
    return {instantHeal};
}