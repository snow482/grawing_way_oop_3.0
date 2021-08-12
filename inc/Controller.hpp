#pragma once
#include <iostream>
#include <filesystem>
#include <Character.hpp>
#include <Phazes.hpp>


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
                     std::shared_ptr<Character> enemy, int phazeType, int playerChoise);
private:
    std::shared_ptr<Character> m_player1 = nullptr;
    std::shared_ptr<Character> m_player2 = nullptr;
};


//