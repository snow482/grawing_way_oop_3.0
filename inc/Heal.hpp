#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>


class Heal {
public:
    Heal(int healPoints);
    ~Heal() = default;

    std::vector<std::pair<phazeType, Involve>> operator()(std::weak_ptr<Character> self,
                                                          std::weak_ptr<Character> enemy);
private:
    int m_additionalHp = 15;
};