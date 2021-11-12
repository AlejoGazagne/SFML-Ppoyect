#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"
#include "Clases/MapaTMX.h"
#include "Clases/maniMenu.h"
#include "Clases/Game.h"

int look_empty(Ataque *ataque[]);

int menu();

int main() {
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);
    Game juego(window);

    // Main loop
    while (window.isOpen()) {
        juego.loop(window);
    }
    return EXIT_SUCCESS;
}
