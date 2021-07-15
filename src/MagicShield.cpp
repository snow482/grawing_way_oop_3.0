#include "MagicShield.hpp"
#include "Character.hpp"


MagicShield::MagicShield(int turns, int damage)
    : Skill("Magic Shield"), m_turns(turns), m_blockedDamage(damage)
{}

void MagicShield::Use(std::shared_ptr<Character> self,
                      std::shared_ptr<Character> enemy) {
    self->setShield(m_turns);
    //self->getDamage(m_blockedDamage); TODO
    noused(enemy);
}

