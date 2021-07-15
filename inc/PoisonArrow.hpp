#pragma once
#include "Skill.hpp"


class PoisonArrow : public Skill {
public:
    explicit PoisonArrow(int damage, int turns, int poisonDamage);
    void Use(std::shared_ptr<Character> self,
             std::shared_ptr<Character> enemy) override;
private:
    int m_arrowDamage;
    int m_turns;
    int m_poisonDamage;
};