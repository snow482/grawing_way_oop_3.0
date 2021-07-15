#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>
#include "Skill.hpp"


// Character - базовый класс
// std::enable_shared_from_this<Character> - шаблонная магия (статический полиморфизм)
class Character : public std::enable_shared_from_this<Character> {
public:
    Character(std::string name, int hp, int maxHp);
    ~Character() = default;

    void nextTurn();
    int queueThrow() const;

    std::string getName() const;
    int hpQuantity() const;
    void getDamage(int damage);

    void addHp(int hp);
    int getMaxHp() const;
    void attack(std::shared_ptr<Character>& enemy, int skillNum);
    void addSkill(std::shared_ptr<Skill> skill);
    std::vector<std::string> printSkills() const;

    void setPoison(int turns, int damage);
    void setParalyse(int turns);
    void setShield(int turns);
    int getParalyseCondition() const;
    int getShieldCondition() const;
private:
    std::string m_name;
    int m_hp = 0;
    int m_maxHp = 0;
    std::vector<std::shared_ptr<Skill>> m_skills;
    int m_poisonTurns = 0;
    int m_poisonDamage = 0;
    int m_paralysedTurns = 0;
    int m_shieldTurns = 0;
};
