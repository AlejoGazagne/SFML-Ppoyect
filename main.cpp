#include <iostream>
#include <SFML/Graphics.hpp>

#include "Clases/personaje1.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1536, 990), "Proyecto Info II");
    window.setFramerateLimit(60);
    sf::Texture texture1;
    sf::Sprite image1;

    if (!texture1.loadFromFile("../assets/mapa1Final.png")) {
        std::cout << "Error al cargar textura, verifique la ruta";
        return EXIT_FAILURE;
    }
    image1.setTexture(texture1);
    image1.setPosition(0, 0);

    sf::Texture texture;
    sf::Sprite image;
    if (!texture.loadFromFile("../assets/PJ.png")) {
        std::cout << "Error al cargar textura, verifique la ruta";
        return EXIT_FAILURE;
    }
    image.setTexture(texture);
    //image.setPosition(-10, 0);

    Personaje1 player1(200, 680, texture);

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update world parameters

        // player.move(3,4);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player1.moverDerecha();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player1.moverIzquierda();
        }

        // Draw all elements
        window.clear();
        window.draw(image1);
        player1.dibujar(window);
        window.display();

    }
    return EXIT_SUCCESS;
}