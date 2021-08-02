#include "FireFist.hpp"


FireFist::FireFist(std::string skillName, int fireDamage)
    : m_skillName(skillName), m_fireDamage(fireDamage)
{}

int FireFist::operator()(std::shared_ptr<Character> self, std::shared_ptr<Character> enemy) {
    //noused(self);
    enemy->getDamage(m_fireDamage);
    return 0;
}


