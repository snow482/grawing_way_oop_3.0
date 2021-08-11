#include "Paralysis.hpp"


Paralysis::Paralysis(int rounds)
    : m_rounds(rounds)
{}

std::vector<std::pair<phazeType, Involve>> Paralysis::operator()(std::shared_ptr<Character> self,
                                                                 std::shared_ptr<Character> enemy) {
    noused(self);
    int time = m_rounds;
    std::pair<phazeType, Involve> instantParalysis = {phazeType::Start,[this, enemy, time]() mutable {
        enemy->setParalysisState(true);

        return --time;
    }};
    return {}


}
