#include <iostream>

using std::endl;

void shop(int &balance,int &hp,int &attack);
void cave(int &balance,int &hp,int &attack);



int main(){
    int playerC;
    int balance = 1000;
    int hp = 500;
    int attack = 50;

    do{
        std::cout << "=============="<< endl;
        std::cout << "     MENU" << endl;
        std::cout << "=============="<< endl;
        std::cout << "    1.Shop" << endl;
        std::cout << "    2.Cave" << endl;
        std::cout << "    3.View" << endl;
        std::cout << "    4.Quit" << endl;
        std::cout << "You have " << hp << " and " << balance << " gold" << endl << endl;
        std::cout << "Where are you going?: ";
        std::cin >> playerC;

        switch(playerC){
            case 1:
                shop(balance,hp,attack);
                break;
            case 2:
                std::cout << "Entering the cave...\n";
                cave(balance,hp,attack);
                break;
            case 3:
                std::cout << "HP: " << hp << endl << "Attack: " << attack << endl <<"Balance: " << balance << endl; 
                break;
            case 4:
                std::cout << "Exiting..." << endl;
                break;
        }
    } while(playerC != 4);
    return 0;
}

void shop(int &balance,int &hp,int &attack){
    int choice;
    do{
        std::cout << endl << "1.+50hp - 100 gold  |  2.+10 Attack - 150 gold  |  3.Back  |  Balance: " << balance <<endl;
        std::cout << "What do you want to buy?: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                if(balance >= 100){
                    balance -= 100;
                    hp += 50;
                    std::cout << endl << "You have in balance : " << balance << " and " << hp << " hp" << endl;
                }
                else{
                    std::cout << endl << "Not enough gold!" << endl;
                }
                break;
            case 2:
                if(balance >= 150){
                    balance -= 150;
                    attack += 10;
                    std::cout << endl << "You now have " << attack << " attack and " << balance << " gold left." << endl;
                }
                else{
                    std::cout << endl << "Not enough gold!" << endl;
                }
                break;
            case 3:
                std::cout << endl << "Returning to menu..." << endl;
                break;
        }
    }while(choice != 3);
}

void cave(int &balance, int &hp,int &attack){
    int choice;
    char yon; // y or n
    int dragonHp = 1000;
    int dragonAttack = 100;
    int slimeHp = 200;
    int slimeAttack = 50;

    std::cout << "1.Dragon Cave    2.Slime Cave    3.Back" << endl;
    std::cin >> choice;

    switch(choice){
        case 1:
            std::cout << "You found a dragon do you want to view his info?(y or n): " << endl;
            std::cin >> yon;
            
            if(yon == 'y'){
                std::cout << "He is a boss" <<endl;
                std::cout << "The dragon's hp is " << dragonHp << " and the attack is " << dragonAttack << endl;
            }
            else{
                return;
            }
            std::cout << "Want to interact with the dragon?";
            std::cin >> yon;
        break;

            if(yon =='y'){
                std::cout << "1.Attack the Dragon     2.Run" << endl; 
                std::cin >> choice;
                switch(choice){
                    case 1:
                        while(dragonHp != 0 && hp != 0){
                            if(dragonHp > 0 && hp > 0){
                                dragonHp -= attack;
                                std::cout << "You attacked the dragon and now it has " << dragonHp << " Hp" << endl;
                            }
                            if(hp > 0 && dragonHp > 0){
                                hp -= dragonAttack;
                                std::cout << "You have now " << hp << " Hp" << endl;
                            }
                        }
                        if(hp <= 0){
                            hp = 0;
                            std::cout << "You lose!";
                            exit(0);
                        }
                        else if (dragonHp <= 0){
                            dragonHp = 0;
                            std::cout << "You win!";
                            balance += 200;
                            hp += 100;
                            std::cout << "Because you beat the dragon you got 200 gold and 100 hp" << endl;
                        }
                        break;

                    case 2:
                        break;
                    }
            }else{return;}
        
        case 2:{
            std::cout << "Do you want some information about slime?(y or n): ";
            std::cin >> yon;

            if(yon == 'y'){
                std::cout << "The slime has " << slimeHp << " Hp " << "and " << slimeAttack << " attack" << endl;
            }
            else{
                return;
            }

            std::cout << "Want to interact with the slime?(y or n): ";
            std::cin >> yon;

            if(yon == 'y'){
                std::cout << "1.Attack     2.Run";
                std::cin >> choice;
                switch(choice){
                    case 1:
                        while(slimeHp != 0 && hp != 0){
                            if(slimeHp > 0 && hp > 0){
                                slimeHp -= attack;
                                std::cout << "You attacked the slime and now it has " << slimeHp << " Hp" << endl;
                            }
                            if(hp > 0 && slimeHp > 0){
                                hp -= slimeAttack;
                                std::cout << "You have now " << hp << " Hp" << endl;
                            }
                        }
                        if(hp <= 0){
                            hp = 0;
                            std::cout << "You lose!";
                            exit(0);
                        }
                        else if (slimeHp <= 0){
                            slimeHp = 0;
                            std::cout << "You win!";
                            balance += 200;
                            hp += 100;
                            std::cout << "Because you beat the slime you got 100 gold and 50 hp" << endl;
                        }
                        break;

                    case 2:
                        break;
                    }
            }
            else{return;}

        }
    }
}