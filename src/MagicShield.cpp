#include "MagicShield.hpp"


MagicShield::MagicShield(int rounds)
    : m_rounds(rounds)
{}

std::vector<std::pair<phazeType, Involve>> MagicShield::operator()(std::weak_ptr<Character> self,
                                                                   std::weak_ptr<Character> enemy) {
    int time = m_rounds;
    std::pair<phazeType, Involve> instantShieldUp = {phazeType::Instantly, [this, self]() mutable {
        auto selfPtr = self.lock();
        selfPtr->setShieldState(true);
        std::cout << "Under the shield (start)" << std::endl;
        return 0;
    }};
    std::pair<phazeType, Involve> endShieldDown = {phazeType::End, [this, self]() mutable {
        auto selfPtr = self.lock();
        selfPtr->setShieldState(false);
        std::cout << "Under the shield (end)" << std::endl;
        return 0;
    }};

    noused(enemy);
    return {instantShieldUp, endShieldDown};
}

