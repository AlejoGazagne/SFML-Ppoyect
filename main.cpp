#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"
#include "Clases/MapaTMX.h"
#include "Clases/maniMenu.h"
#include "Clases/Game.h"
#include "Clases/GameOver.h"
#include <fstream>
#include "main.h"

int main() {
    state estado = MENU;
    int wasd = 0;
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);

    maniMenu menu(1536, 850);
    Game juego(window);
    GameOver gameover;

    while (window.isOpen()) {
        sf::Event event;

        // Verifico eventos
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

            switch (estado) {
                case MENU:
                    estado = menu.events(event);
                    break;
                case JUEGO:
                    estado = juego.events(event);
                    break;
                case GAMEOVER:
                    estado = gameover.events(event);
            }
        }

        // DIBUJO Escena
        switch (estado) {
            case MENU:
                menu.draw(window);
                break;
            case JUEGO:
                juego.loop(window);
                break;
            case GAMEOVER:
                gameover.draw(window);
                /*if(wasd = 480){
                    estado = MENU;
                }*/
                break;
        }
        wasd++;
    }
    return EXIT_SUCCESS;
}
