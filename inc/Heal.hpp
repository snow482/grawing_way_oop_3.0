#pragma once
#include "Skill.hpp"


class Heal : public Skill {
public:
    explicit Heal(int healPoints);
    void Use(std::shared_ptr<Character> self,
             std::shared_ptr<Character> enemy) override;
private:
    int m_additionalHp = 15;
};