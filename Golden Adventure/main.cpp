//Golden Adventure 1.0.1 alpha
//Maybe a gui in beta
//It wasn't fun to introduce the armor system.
//For any error you can contact me on discord: siksthazine,x @siksthazine or i think you can edit the code in github.
/*News from alpha version 1.0.1: alpha version 1.0.1 includes changes to the code to make it shorter and remove unnecessary code,
I added the armor mechanism and modified some dragon and slime codes to introduce the armor system.*/
//time : 21:57,It lasted: 2 hours and 15 minutes 
//i use arch linux btw 
#include <iostream>

using std::endl;

void shop(int &balance,int &hp,int &attack,int &armor);
void cave(int &balance,int &hp,int &attack,int &armor);


int main(){
    //player
    int playerC;
    int balance = 1000;
    int hp = 500;
    int attack = 50;
    int armor = 1;

    do{
        //menu
        std::cout << "======================"<< endl;
        std::cout << "   Golden Adventure   " << endl;
        std::cout << "  A game make by Siks" << endl; // Sks Entertainment
        std::cout << "======================"<< endl;
        std::cout << "       1.Shop" << endl;
        std::cout << "       2.Cave" << endl;
        std::cout << "       3.View" << endl;
        std::cout << "       4.Quit" << endl;
        std::cout << "You have " << hp << " hp," << balance << " gold " << "and " << armor << " armor" << endl << endl;
        std::cout << "Where are you going?: ";
        std::cin >> playerC;

        //options
        switch(playerC){
            case 1:
                shop(balance,hp,attack,armor);
                break;
            case 2:
                std::cout << "Entering the cave...\n";
                cave(balance,hp,attack,armor);
                break;
            case 3:
                std::cout << "HP: " << hp << endl << "Attack: " << attack << endl <<"Balance: "<< balance << endl << "Armor: " << armor << endl; 
                break;
            case 4:
                std::cout << "Exiting..." << endl;
                break;
            default:
                std::cout << "Error" << endl ;
                break;
        }
    } while(playerC != 4);
    return 0;
}

void shop(int &balance,int &hp,int &attack,int &armor){ //shop
    int choice;
    do{
        std::cout << endl << "1.+50 Hp - 100 gold  |  2.+10 Attack - 150 gold  |  3.+1 Armor - 100 gold |  4.Back  |  Balance: " << balance <<endl;
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
                if(balance >= 100){
                    balance -= 100;
                    armor += 1;
                    std::cout << endl << "You have in balance : " << balance << " and " << armor << " armor" << endl;
                }
                else{
                    std::cout << endl << "Not enough gold!" << endl;
                }
                break;
            case 4:
                std::cout << endl << "Returning to menu..." << endl;
                break;
            default :
                std::cout << "Error" << endl;
                break;
        }
    }while(choice != 4);
}

void cave(int &balance, int &hp,int &attack,int &armor){ //cave 
    int choice;
    char yon; // y or n
    //enemies
    int dragonHp = 1000;
    int dragonAttack = 100;
    int slimeHp = 200;
    int slimeAttack = 50;

    std::cout << "1.Dragon Cave    2.Slime Cave    3.Back" << endl;
    std::cin >> choice;

    switch(choice){
        //dragon
        case 1:
            std::cout << "You enter in the dragon cave and you find the dragon(hp = " << dragonHp << " attack = " << dragonAttack << ".What do you want do to?" <<endl;
            std::cout << "1.Attack the Dragon     2.Run" << endl; 
            std::cin >> choice;
            switch(choice){
                case 1: // rewritten in 1.0.1
                    while(dragonHp > 0 && hp > 0){
                        if(dragonHp > 0){
                            dragonHp -= attack;
                            std::cout << "You attacked the dragon and now it has " << dragonHp << " Hp" << endl;
                        }
                        if(slimeHp > 0 && hp > 0){
                            if(armor > 0){
                                hp -= dragonAttack *(1- armor * 0.01);
                                armor -= 1;
                                std::cout << "You have now " << hp << " Hp" << endl;
                            }
                            else{
                                hp -= dragonAttack;
                                std::cout << "You have now " << hp << " Hp" << endl;
                            }
                        }
                    }

                    if(hp <= 0){
                        hp = 0;
                        std::cout << "You lose!" << endl;
                        return;
                    }
                    else if (dragonHp <= 0){
                        dragonHp = 0;
                        std::cout << "You win!" << endl;
                        balance += 200;
                        hp += 100;
                        std::cout << "Because you beat the dragon you got 200 gold and 100 hp" << endl;
                    }

                    break;
                case 2:
                    break;
                default:
                    std::cout << "Error" << endl;
                    break;
                }

            //slime        
            case 2:
                std::cout << "You enter in the slime cave and you find the slime(hp = " << slimeHp << " attack = " << slimeAttack << ".What do you want do to?" <<endl;
                std::cout << "1.Attack the slime     2.Run" << endl; 
                std::cin >> choice;
                switch(choice){
                    case 1:// rewritten in 1.0.1
                        while(slimeHp > 0 && hp > 0){
                            if(slimeHp > 0){
                                slimeHp -= attack;
                                std::cout << "You attacked the slime and now it has " << slimeHp << " Hp" << endl;
                            }
                            if(slimeHp > 0 && hp > 0){
                                if(armor > 0){ //It wasn't fun to introduce the armor system.
                                    hp -= slimeAttack * (1 - armor * 0.01);
                                    armor -= 1; 
                                    std::cout << "You have now " << hp << " Hp" << endl;
                                }
                                else{
                                    hp -= slimeAttack;
                                    std::cout << "You have now " << hp << " Hp" << endl;
                                }
                            }
                        }
                        if(hp <= 0){
                            hp = 0;
                            std::cout << "You lose!" << endl;
                            return;
                        }
                        else if (slimeHp <= 0){
                            slimeHp = 0;
                            std::cout << "You win!" << endl;
                            balance += 100;
                            hp += 50;
                            std::cout << "Because you beat the slime you got 100 gold and 50 hp" << endl;
                        }
                        break;
                    case 2:
                        break;
                    default:
                        std::cout << "Error" << endl;
                        break;
            }
    }
}