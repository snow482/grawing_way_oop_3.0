#include "Paralysis.hpp"


Paralysis::Paralysis(std::string& skillName)
    : m_skillName(skillName)
{}

int Paralysis::operator()(std::shared_ptr<Character> self,
                            std::shared_ptr<Character> enemy) {
    //noused(self);
    //enemy->setParalyse(m_turns);
}
