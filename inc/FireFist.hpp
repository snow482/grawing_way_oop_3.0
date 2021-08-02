#pragma once
#include <functional>
#include "Character.hpp"

enum class fazeType {
    Start,
    Instantly,
    End
};

struct FireFist {
public:
    FireFist(std::string skillName, int fireDamage);
    ~FireFist() = default;

    int operator()(std::shared_ptr<Character> self,
                    std::shared_ptr<Character> enemy);


private:
    std::string m_skillName;
    int m_fireDamage = 0;
};

