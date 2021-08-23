#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>

class VampiricClaw {
public:
    VampiricClaw(int vampiricDamage, int vampiricHp, int rounds);
    ~VampiricClaw() = default;

    std::vector<std::pair<phazeType, Involve>> operator()(std::shared_ptr<Character> self,
                                                          std::weak_ptr<Character> enemy);
private:
    int m_vampiricDamage = 0;
    int m_vampiricHp = 0;
    int m_rounds = 0;
};

