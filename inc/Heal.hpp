#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>


class Heal {
public:
    Heal(int healPoints);
    ~Heal() = default;

    std::vector<std::pair<phazeType, Involve>> operator()(std::shared_ptr<Character> self,
                                                          std::shared_ptr<Character> enemy);
private:
    int m_additionalHp = 15;
};