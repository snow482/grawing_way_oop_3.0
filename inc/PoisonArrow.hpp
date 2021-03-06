#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>


class PoisonArrow {
public:
    PoisonArrow(int damage, int poisonDamage, int rounds);
    ~PoisonArrow() = default;

    std::vector<std::pair<phazeType, Involve>> operator()(std::weak_ptr<Character> self,
                                                          std::weak_ptr<Character> enemy);
private:

    int m_arrowDamage;
    int m_poisonDamage;
    int m_rounds;
};