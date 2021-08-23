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

    void nextStartPhaze();
    void nextInstantPhaze();
    void nextEndPhaze();

    void addInvolve(phazeType phaze, Involve involve); //TODO дописать


    //TODO
    // вывел скилы printSkills()
    // getSkill()
    // что то с addInvolve(какая фаза, колличество воздействий)
    // распихать скилы по векторам


    //TODO подумать над лямбдой состояния, которая будет возвращать текущее состояние противника и себя
    // типа, находится сейчас противник под щитом или парализован ли я, чтобы нанести удар и тд
    // - еще по поводу отмены атаки, если под щитом, то есть дамаг не наносится, если я под считом
private:
    void info();
    std::shared_ptr<Character> pickCharacter(int number);
    void characterPulling(std::shared_ptr<Character>& player);
    void playerInput(std::shared_ptr<Character> attacker,
                     std::shared_ptr<Character> enemy, int phazeType, int playerChoise);
private:
    std::shared_ptr<Character> m_player1 = nullptr;
    std::shared_ptr<Character> m_player2 = nullptr;

    std::vector<Involve> m_startPhaze;
    std::vector<Involve> m_instantPhaze;
    std::vector<Involve> m_endPhaze;
};
