#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>
#include <Phazes.hpp>

class Character;
// Character - базовый класс
// std::enable_shared_from_this<Character> - шаблонная магия (статический полиморфизм)
using Skill = std::function<std::vector<std::pair<phazeType, Involve>>(std::shared_ptr<Character>, std::shared_ptr<Character>)>;

class Character : public std::enable_shared_from_this<Character> {
public:
    Character(std::string name, int hp, int maxHp);
    ~Character() = default;

    void nextTurn();
    int queueThrow() const;

    std::string getName() const;
    int hpQuantity() const;
    void getDamage(int damage);
    void setShieldState(bool state);
    bool getParalysisState();
    void setParalysisState(bool state);
    void addHp(int hp);
    int getMaxHp() const;
    //void attack(std::shared_ptr<Character>& enemy, int skillNum);
    void addSkill(std::string skillName, Skill skill);

    Skill getSkill(std::string skillName);

    std::vector<std::string> printSkills() const;


private:
    std::string m_name;
    int m_hp = 0;
    int m_maxHp = 0;
    std::map<std::string, Skill> m_skills;

    bool m_shieldUp;
    bool m_paralysisUp;

    int m_poisonTurns = 0;
    int m_poisonDamage = 0;
    int m_paralysedTurns = 0;
    int m_shieldTurns = 0;
};
