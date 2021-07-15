#include "Paralysis.hpp"
#include "Character.hpp"

Paralysis::Paralysis(int turns)
    : Skill("Paralysis"), m_turns(turns)
{}

void Paralysis::Use(std::shared_ptr<Character> self,
                    std::shared_ptr<Character> enemy) {
    noused(self);
    enemy->setParalyse(m_turns);
}
