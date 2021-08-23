#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>


struct FireFist {
public:
    FireFist(int fireDamage);
    ~FireFist() = default;

    std::vector<std::pair<phazeType, Involve>> operator()(std::weak_ptr<Character> self,
                                                          std::weak_ptr<Character> enemy);
private:
    int m_fireDamage = 0;
};

