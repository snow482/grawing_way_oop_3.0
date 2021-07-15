#include "../inc/Skill.hpp"

Skill::Skill(std::string skillName)
    : m_skillName(skillName)
{}

std::string Skill::skillNamePrint() const {
    return m_skillName;
}
