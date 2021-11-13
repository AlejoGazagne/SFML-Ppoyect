#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"
#include "Clases/MapaTMX.h"
#include "Clases/maniMenu.h"
#include "Clases/Game.h"

int main() {
    int wasd = 1;
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);

    maniMenu menu(1536, 850);
    Game juego(window);


    // Main loop
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    while(wasd == 1){
                                        wasd = juego.loop(window);
                                    }
                                    break;
                                case 1:
                                    std::cout << "Has apretado el boton controles" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "Has apretado el boton puntajes" << std::endl;
                                    break;
                                case 3:
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
        window.clear();
        menu.draw(window);
        window.display();
    }





return EXIT_SUCCESS;
}
