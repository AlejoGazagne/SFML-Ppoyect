#include "SFML/Graphics.hpp"
#include <iostream>
#include "Clases/maniMenu.h"

int menu(){
    sf::RenderWindow window (sf::VideoMode(1536, 850), "Proyecto Info II");

    // Menu
    maniMenu menu(600,450);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(menu.GetPressedItem()){
                                case 0:
                                    std::cout<<"Has apretado el boton jugar"<<std::endl;
                                    break;
                                case 1:
                                    std::cout<<"Has apretado el boton opciones"<<std::endl;
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }
    window.clear();
    menu.draw(window);
    window.display();

}

