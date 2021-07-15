#pragma once
#include "Skill.hpp"


class FireFist : public Skill {
public:
    explicit FireFist(int fireDamage);
    void Use(std::shared_ptr<Character> self,
             std::shared_ptr<Character> enemy) override;
private:
    int m_fireDamage = 0;
};

