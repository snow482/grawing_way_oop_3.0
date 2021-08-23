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
    if(!m_shieldUp && !m_paralysisUp)
        m_hp -= damage;
    std::cout << "You weapon to weak for my shield! hahahha" << std::endl;
}
void Character::setShieldState(bool state) {
   m_shieldUp = state;
}
bool Character::getParalysisState() {
    return m_paralysisUp;
}
void Character::setParalysisState(bool state) {
    m_paralysisUp = state;
}

void Character::addHp(int hp) {
    if(!m_paralysisUp)
        if(m_hp != m_maxHp)
            m_hp += hp;
        else
            std::cout << "full HP!" << std::endl;
    else {
        std::cout << "AM PRLST" << std::endl;
    }
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





//TODO по лямбде возвращающей состояние (под шилдой или нет)


