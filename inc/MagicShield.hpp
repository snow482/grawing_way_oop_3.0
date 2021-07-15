#pragma once
#include "Skill.hpp"


class MagicShield : public Skill {
public:
    explicit MagicShield(int turns, int damage);
    void Use(std::shared_ptr<Character> self,
                      std::shared_ptr<Character> enemy) override;

private:
    int m_turns;
    int m_blockedDamage;
};

/*
 если щит заюзан, то setDamage(урон зануляется)

 занулить дамаг от оппонента
 */
