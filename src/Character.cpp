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
void Character::attack(std::shared_ptr<Character>& enemy, int skillNum) {
    m_skills[skillNum]->Use(shared_from_this(), enemy);
}
void Character::addSkill(std::shared_ptr<Skill> skill) {
    m_skills.push_back(skill);
}
std::vector<std::string> Character::printSkills() const {
    std::vector<std::string> value;
    for (auto& it : m_skills) {
        value.push_back(it->skillNamePrint());
    }
    return value;
}

void Character::setPoison(int turns, int damage) {
    m_poisonTurns = turns;
    m_poisonDamage = damage;
}
void Character::setParalyse(int turns) {
    m_paralysedTurns = turns;
}
void Character::setShield(int turns) {
    m_shieldTurns = turns;
}
int Character::getParalyseCondition() const {
    return m_paralysedTurns;
}
int Character::getShieldCondition() const {
    return m_shieldTurns;
}
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


