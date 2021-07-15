#include "PoisonArrow.hpp"
#include "Character.hpp"


PoisonArrow::PoisonArrow(int damage, int turns, int poisonDamage)
    : Skill("Poison Arrow"), m_arrowDamage(damage), m_turns(turns), m_poisonDamage(poisonDamage)
{}

void PoisonArrow::Use(std::shared_ptr<Character> self,
                      std::shared_ptr<Character> enemy) {
    enemy->getDamage(m_arrowDamage);
    enemy->setPoison(m_turns, m_poisonDamage);
    std::cout<< "poisoned" << std::endl;
    noused(self);
}


