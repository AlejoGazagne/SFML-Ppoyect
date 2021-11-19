#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"
#include "Clases/MapaTMX.h"
#include "Clases/maniMenu.h"
#include "Clases/Game.h"
#include <fstream>

int main() {
    int wasd = 1;
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);

    // IMPRIMIR POR PANTALLA LOS PUNTAJES
    sf::Text Olddata;
    sf::Font font;
    sf::Texture texture1;
    sf::Sprite image1;
    if(!font.loadFromFile("assets/letra.ttf")){
        //handle error
    }

    maniMenu menu(1536, 850);
    Game juego(window);

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
                                    while(menu.GetPressedItem() == 0){
                                        wasd = juego.loop(window);
                                        menu.setSeleccion(wasd);
                                    }
                                    break;
                                    case 1:{
                                        ifstream ifs;
                                        std::string oldData;
                                        ifs.open("Tabla.txt");
                                        if(ifs.is_open()){
                                            while (!ifs.eof()){
                                                oldData += ifs.get();
                                            }
                                            ifs >> oldData;
                                            ifs.close();
                                        }
                                        Olddata.setFont(font);
                                        Olddata.setFillColor(sf::Color::White);
                                        Olddata.setString(oldData);
                                        Olddata.setPosition(500,500);

                                        window.draw(Olddata);

                                        break;
                                    }
                                case 2:
                                    window.close();
                                    break;
                                case 3:
                                    maniMenu menu(1536, 850);
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
