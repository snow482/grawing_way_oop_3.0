#pragma once
#include <functional>
#include "Character.hpp"


struct FireFist {
public:
    FireFist(std::string skillName, int fireDamage);
    ~FireFist() = default;

    void fireFistUse(std::shared_ptr<Character> self,
                    std::shared_ptr<Character> enemy);

    enum class fazeType {
        Start,
        Instantly,
        End
    };

    std::function<void(std::shared_ptr<Character>,
                       std::shared_ptr<Character>)> fireFist;
private:
    std::string m_skillName;
    int m_fireDamage = 0;
};

