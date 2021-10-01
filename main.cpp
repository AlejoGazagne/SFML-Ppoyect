#include <iostream>
#include <SFML/Graphics.hpp>

#include "Clases/personaje.h"

int main() {
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 990), "Proyecto Info II");
    window.setFramerateLimit(60);
    sf::Texture texture1;
    sf::Sprite image1;

    if (!texture1.loadFromFile("../assets/mapa1Final.png")) {
        return EXIT_FAILURE;
    }
    image1.setTexture(texture1);

    //Creo el primer personaje
    sf::Texture texture;
    sf::Sprite image;
    if (!texture.loadFromFile("../assets/PJ.png")) {
        return EXIT_FAILURE;
    }
    image.setTexture(texture);
    Personaje player1(200, 680, texture);

    //Creo el segundo personaje
    sf::Texture texture2;
    sf::Sprite image2;
    if (!texture2.loadFromFile("../assets/PJ2.png")) {
        return EXIT_FAILURE;
    }
    image2.setTexture(texture2);
    Personaje player2(1000, 680, texture2);

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update world parameters

        // player1.move(3,4);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player1.moverDerecha();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player1.moverIzquierda();
        }
        //Mover player 2
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
            player2.moverDerecha();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
            player2.moverIzquierda();
        }

        // Draw all elements
        window.clear();
        window.draw(image1);
        player1.dibujar(window);
        player2.dibujar(window);
        window.display();

    }
    return EXIT_SUCCESS;
}