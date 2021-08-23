#include "Paralysis.hpp"


Paralysis::Paralysis(int rounds)
    : m_rounds(rounds)
{}

std::vector<std::pair<phazeType, Involve>> Paralysis::operator()(std::weak_ptr<Character> self,
                                                                 std::weak_ptr<Character> enemy) {
    noused(self);
    int time = m_rounds;
    std::pair<phazeType, Involve> instantParalysis = {phazeType::Start,[this, enemy, time]() mutable {
        auto enemyPtr = enemy.lock();
        enemyPtr->setParalysisState(true);

        return --time;
    }};
    return {}


}
