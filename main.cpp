#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"
#include "Clases/MapaTMX.h"
#include "Clases/maniMenu.h"
#include "Clases/Game.h"
#include "Clases/GameOver.h"
#include "Clases/Puntaje.h"

int main() {
    state estado = MENU;
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);

    maniMenu menu(1536, 850);
    Game *juego = new Game(window);
    GameOver gameover;
    Puntaje puntaje;

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
                    menu.events(event);
                    break;
            }
        }

        // DIBUJO Escena
        //cout << estado << endl;
        switch (estado) {
            case MENU:
                estado = menu.draw(window);
                break;
            case JUEGO:
                estado = juego->loop(window);
                if (estado != JUEGO) {
                    delete juego;
                    juego = new Game(window);
                }
                menu.setNextState(MENU);
                break;
            case GAMEOVER:
                estado = gameover.draw(window);
                menu.setNextState(MENU);
                break;
            case TABLE:
                estado = puntaje.draw(window);
                menu.setNextState(MENU);
                break;
            case EXIT:
                window.close();
                break;
        }
    }
    return EXIT_SUCCESS;
}
