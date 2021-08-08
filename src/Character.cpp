#include <fstream>
#include <stdexcept>

#include "Character.hpp"


Character::Character(std::string name, int hp, int maxHp)
    :m_name(name), m_hp(hp), m_maxHp(maxHp)
{}

int Character::queueThrow() const {
    return rand() % 20;
}
std::string Character::getName() const {
    return m_name;
}
int Character::hpQuantity() const {
    return m_hp;
}
void Character::getDamage(int damage) {
    m_hp -= damage;
}
void Character::addHp(int hp) {
    m_hp += hp;
}
int Character::getMaxHp() const {
    return m_maxHp;
}
/*void Character::attack(std::shared_ptr<Character>& enemy, int skillNum) {
    m_skills[skillNum](shared_from_this(), enemy);
}*/
void Character::addSkill(std::string skillName, Skill skill) {
    m_skills[skillName] = skill;
}
std::vector<std::string> Character::printSkills() const {
    std::vector<std::string> value;
    for (auto& [name,_] : m_skills) {
        value.push_back(name);
    }
    return value;
}

void Character::nextStartPhaze() {
    for(auto it = m_startPhaze.begin(); it != m_startPhaze.end();) {
        int count = (*it)();
        if(count != 0)
            ++it;
        else
            it = m_startPhaze.erase(it);
    }
}

void Character::nextInstantPhaze() {
    for(auto it = m_instantPhaze.begin(); it != m_instantPhaze.end();) {
        int count = (*it)();
        if(count != 0)
            ++it;
        else
            it = m_instantPhaze.erase(it);
    }
}

void Character::nextEndPhaze() {
    for(auto it = m_endPhaze.begin(); it != m_endPhaze.end();) {
        int count = (*it)();
        if(count != 0)
            ++it;
        else
            it = m_endPhaze.erase(it);
    }
}


//переписать на фазы (старт конец середина)
void Character::nextTurn() {
    if (m_poisonTurns > 0) {
        m_hp -= m_poisonDamage;
        m_poisonTurns -= 1;
    }
    if(m_paralysedTurns > 0) {
        m_paralysedTurns -= 1;
    }
    if(m_shieldTurns > 0) {
        m_shieldTurns -= 1;
    }
}


