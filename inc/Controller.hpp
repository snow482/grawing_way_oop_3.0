#pragma once
#include <iostream>
#include <filesystem>
#include "Character.hpp"


class Controller {
public:
    Controller() = default;
    ~Controller() = default;

    void characterCreating();
    void playerQueue();
    void fight();

private:
    void info();
    std::shared_ptr<Character> pickCharacter(int number);
    void characterPulling(std::shared_ptr<Character>& player);
    void playerInput(std::shared_ptr<Character> attacker,
                     std::shared_ptr<Character> enemy, int playerChoise);
    //std::vector<std::shared_ptr<Character>> m_playersVec = {nullptr, nullptr};
private:
    std::shared_ptr<Character> m_player1 = nullptr;
    std::shared_ptr<Character> m_player2 = nullptr;
};


//