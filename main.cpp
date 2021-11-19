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
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);

    // IMPRIMIR POR PANTALLA LOS PUNTAJES
    sf::Text Olddata;
    sf::Font font;
    sf::Texture texture1;
    sf::Sprite image1;
    if (!font.loadFromFile("assets/letra.ttf")) {
        //handle error
    }

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
                break;
        }
    }
    return EXIT_SUCCESS;
}
