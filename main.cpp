#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"

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
    if (!texture.loadFromFile("../assets/Idle.png")) {
        return EXIT_FAILURE;
    }
    image.setTexture(texture);
    Personaje player1(200, 680, texture);

    //CREO TEXTURA DEL ATAQUE
    sf::Texture tx_ataque;   //CAMBIOOOOO
    if(!tx_ataque.loadFromFile("ataque.png"))


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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Ataque = new ataque(100,100,0,tx_ataque);
        }
        //CREO PUNTERO ATAQUE
        Ataque *ataque = nullptr;

        if(ataque!= nullptr)
        ataque->simular();

        // Draw all elements
        window.clear();
        window.draw(image1);
        player1.dibujar(window);
        if(ataque!= nullptr){
            ataque->dibujar(window);
        }
        window.display();

    }
    return EXIT_SUCCESS;
}