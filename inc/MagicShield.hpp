#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>


class MagicShield {
public:
    MagicShield(int rounds);
    std::vector<std::pair<phazeType, Involve>> operator()(std::shared_ptr<Character> self,
                                                          std::shared_ptr<Character> enemy);

private:
    int m_rounds;
    int m_blockedDamage;
};

/*
 если щит заюзан, то setDamage(урон зануляется)

 занулить дамаг от оппонента
 */
