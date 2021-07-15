#include "inc/Controller.hpp"

#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Controller controller;
    try {
        controller.characterCreating();
        controller.playerQueue();
        controller.fight();
    }
    catch (...) {

    }

    return 0;
}

    /*std::shared_ptr<FireFist> fireFist = std::make_shared<FireFist>(25);
    std::shared_ptr<FireFist> nuckFireFist = std::make_shared<FireFist>(10);
    std::shared_ptr<PoisonArrow> poisonArrow = std::make_shared<PoisonArrow>(20);
    std::shared_ptr<Character> maniken = std::make_shared<Character>("manyaken", 52);


    maniken->addSkill(fireFist);
    maniken->addSkill(nuckFireFist);

    std::shared_ptr<Character> monk = std::make_shared<Character>("monah_Sani", 27);
    monk->addSkill(fireFist);
    monk->attack(maniken, 0);


    //std::shared_ptr<PoisonArrow> poisonArrow = std::make_shared<PoisonArrow>(20);*/






