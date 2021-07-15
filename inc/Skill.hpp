#pragma once
#include <memory>
#include <string>


// магия
#define noused(x) (void)(x)

// создание Character, чтобы можно было к нему обращаться
// но класс Skill ни чего о нем не знал
class Character;

// Skills - базовый класс для скилов, другие скилы будут наследоваться от него
class Skill {
public:
    explicit Skill(std::string skillName);
    virtual ~Skill() = default;
    //ссылка на Character, но ни чего не знает о нем
    virtual void Use(std::shared_ptr<Character> self,
                     std::shared_ptr<Character> enemy) = 0;
    std::string skillNamePrint() const;

private:
    std::string m_skillName;
};
