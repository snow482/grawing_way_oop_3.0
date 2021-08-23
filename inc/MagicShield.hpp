#pragma once
#include <functional>
#include <Character.hpp>
#include <Phazes.hpp>


class MagicShield {
public:
    MagicShield(int rounds);
    std::vector<std::pair<phazeType, Involve>> operator()(std::weak_ptr<Character> self,
                                                          std::weak_ptr<Character> enemy);

private:
    int m_rounds;
};

/*
 если щит заюзан, то setDamage(урон зануляется)

 занулить дамаг от оппонента
 */
