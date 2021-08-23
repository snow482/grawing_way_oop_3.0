#include "Controller.hpp"
#include "Character.hpp"
#include "FireFist.hpp"
#include "PoisonArrow.hpp"
#include "Heal.hpp"
#include "Paralysis.hpp"
#include "VampiricClaw.hpp"
#include "MagicShield.hpp"


void Controller::info() {
    std::cout << "Good day, today is the fight day!\n"
                 "For you information, you should pick the character wood you like\n"
                 "Number for picking you can find below, skills info under the characters \n"
                 "\n"
                 "[1]Vasya Monk     [2]Sonya Paladin  [3]Venya Ranger  [4]Ekaterina Sorcerer  [5]Cleric Fedor\n"
                 "\n"
                 "[1]Fire fist      [1]Fire fist      [1]Poison arrow  [1]Vampiric claw       [1]Fire fist\n"
                 "[2]Vampiric Claw  [2]Heal           [2]Heal          [2]Poison arrow        [2]Vampiric claw\n"
                 "[3]Heal           [3]Paralysis      [3]Magic Shield  [3]Magic shield        [3]Heal\n"
                 "                                                     [4]Paralysis\n"
                 "Pleace, pick the character and write the number:\n"
                 "\n";
}

std::shared_ptr<Character> Controller::pickCharacter(int number) {
    switch (number) {
        case 1:
            {
                auto monk = std::make_shared<Character>("Vasya Monk", 64, 64);
                monk->addSkill("FireFist",FireFist(20));
                monk->addSkill("VampiricClaw", VampiricClaw(20, 20, 2));
                monk->addSkill("Heal",Heal(10));
                return monk;
            }
        case 2:
            {
                auto paladin = std::make_shared<Character>("Sonya Paladin", 86, 86);
                paladin->addSkill("FireFist", FireFist(30));
                paladin->addSkill("Heal",Heal(20));
                paladin->addSkill("Paralysis",Paralysis(1));
                return paladin;
            }
        case 3:
            {
                auto ranger = std::make_shared<Character>("Venya Ranger", 86, 86);
                ranger->addSkill("PoisonArrow",PoisonArrow(17, 5, 3));
                ranger->addSkill("Heal",Heal(15));
                ranger->addSkill("MagicShield",MagicShield(1));
                return ranger;
            }
        case 4:
            {
                auto sorcerer = std::make_shared<Character>("Ekaterina Sorcerer", 55, 55);
                sorcerer->addSkill("VampiricClaw",VampiricClaw(30, 20, 2));
                sorcerer->addSkill("PoisonArrow",PoisonArrow(20, 10, 2));
                sorcerer->addSkill("MagicShield",MagicShield(1));
                sorcerer->addSkill("Paralysis",Paralysis(2));
                return sorcerer;
            }
        case 5:
            {
                auto cleric = std::make_shared<Character>("Cleric Fedor", 75, 75);
                cleric->addSkill("FireFist",FireFist(15));
                cleric->addSkill("VampiricClaw",VampiricClaw(40, 40, 1));
                cleric->addSkill("Heal", Heal(40));
                return cleric;
            }
        default: throw std::exception("pick character from 1 to 5");
    }
}

void Controller::characterPulling(std::shared_ptr<Character>& player) {
    int characterNumber = 0;
    while(player == nullptr) {
        try {
            std::cin >> characterNumber;
            player = pickCharacter(characterNumber);
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}

void Controller::characterCreating() {
    info();
    characterPulling(m_player1);
    characterPulling(m_player2);
}

void Controller::playerQueue() {
    int firstThrower, secondThrower = 0;
    std::cout << "Initiative throws" << std::endl;
    std::cout << "Rolling, who will attack\n";
    do {
        firstThrower = m_player1->queueThrow();
        secondThrower = m_player2->queueThrow();
    } while (firstThrower == secondThrower);

    std::cout << m_player1->getName() <<" rolled: " << firstThrower << "\n"
              << m_player2->getName() << " rolled: " << secondThrower << "\n";

    if (firstThrower < secondThrower) {
        std::cout << m_player2->getName() << " attacking first\n";
        std::cout << std::endl;
        //std::swap(m_player1, m_player2);
    }
    else {
        std::cout << m_player1->getName() << " attacking first\n";
        std::cout << std::endl;
    }

}

void Controller::playerInput(std::shared_ptr<Character> attacker,
                             std::shared_ptr<Character> enemy,
                             int phazeType,
                             int playerChoise) {
    if (playerChoise <= attacker->printSkills().size()) {
        switch (playerChoise) {
            case 1: attacker->addSkill("FireFist", nullptr);
                attacker->addInvolve(phazeType::Start,std::function<int()>());
                break;
            case 2: attacker->addSkill("PoisonArrow", nullptr);
                break;
            case 3: attacker->addSkill("VampiricClaw", nullptr);
                break;
            case 4: attacker->addSkill("Heal", nullptr);
                break;
            case 5: attacker->addSkill("MagicShield", nullptr);
                break;
            case 6: attacker->addSkill("Paralysis", nullptr);
            default: std::cout << "You should chose the skill or you can't do it on this round!" << std::endl;
                break;
        }
    }
    else {
        std::cout << "need chose right skill number" << std::endl;
    }
}

void Controller::fight() {
    while (m_player1->hpQuantity() > 0 && m_player2->hpQuantity() > 0) {

        m_player1->nextTurn();
        m_player2->nextTurn();
        int firstPlayerAttackNumber = 0;
        int secondPlayerAttackNumber = 0;

        std::cout << m_player1->getName() << " - hp: "
                  << m_player1->hpQuantity() << "\n";
        std::cout << m_player2->getName() << " - hp: "
                  << m_player2->hpQuantity() << "\n";
        std::cout << std::endl;
        //TODO надо написать поочередно идущие игровые фазы и вызывать из них скилы


void Controller::nextStartPhaze() {
    for(auto it = m_startPhaze.begin(); it != m_startPhaze.end();) {
        int count = (*it)();
        if(count != 0)
            ++it;
        else
            it = m_startPhaze.erase(it);
    }
}

void Controller::nextInstantPhaze() {
    for(auto it = m_instantPhaze.begin(); it != m_instantPhaze.end();) {
        int count = (*it)();
        if(count != 0)
            ++it;
        else
            it = m_instantPhaze.erase(it);
    }
}

void Controller::nextEndPhaze() {
    for(auto it = m_endPhaze.begin(); it != m_endPhaze.end();) {
        int count = (*it)();
        if(count != 0)
            ++it;
        else
            it = m_endPhaze.erase(it);
    }
}

void Controller::addInvolve(phazeType phaze, Involve involve) {

    if(phaze == phazeType::Start)
        m_startPhaze.push_back(involve);

    if(phaze == phazeType::Instantly)
        m_instantPhaze.push_back(involve);

    if(phaze == phazeType::End)
        m_endPhaze.push_back(involve);
}



        //TODO дописать, в какую фазу, что будет отрабатывать
        // типа если if (phaze == phazeType::start или в enum[0] ) { m_startPhaze.push_back(кол-во воздействий конкретного скила) }
        // вывел скилы printSkills()
        // getSkill()
        // что то с addInvolve(какая фаза, колличество воздействий)
        // распихать скилы по векторам


        /*if (m_player1->hpQuantity() > 0) {
            std::cout << m_player1->getName()<< " please write number of attack" << std::endl;
            if (m_player1->getParalyseCondition() == 0) {
                for (auto& it : m_player1->printSkills()) {
                    std::cout << it << std::endl;
                }
                std::cin >> firstPlayerAttackNumber;
            }
            else {
                std::cout << "I'm paralysed" << std::endl;
            }
            if (m_player2->getShieldCondition() == 0) {
                playerInput(m_player1, m_player2, firstPlayerAttackNumber);
            }
            else {
                std::cout << "Hey! " << m_player2->getName()  << ", nice block!" << std::endl;
            }
        }
        else {
            std::cout << m_player2->getName() << " Winner!" << std::endl;
        }

        std::cout << m_player1->getName() << " - hp: "
                  << m_player1->hpQuantity() << "\n";
        std::cout << m_player2->getName() << " - hp: "
                  << m_player2->hpQuantity() << "\n";
        std::cout << std::endl;

        if (m_player2->hpQuantity() > 0) {
            std::cout << m_player2->getName() << " please write number of attack" << std::endl;

            if (m_player2->getParalyseCondition() == 0) {
                for (auto& it : m_player2->printSkills()) {
                    std::cout << it << std::endl;
                }
                std::cin >> secondPlayerAttackNumber;
            }
            else {
                std::cout << "I'm paralysed" << std::endl;
            }

            if (m_player1->getShieldCondition() == 0) {
                playerInput(m_player2, m_player1, secondPlayerAttackNumber);
            } else {
                std::cout << "Hey! " << m_player1->getName() << ", nice block!" << std::endl;
            }
        }
        else {
            std::cout << m_player1->getName() << " Winner!" << std::endl;
        }*/
    }
}


