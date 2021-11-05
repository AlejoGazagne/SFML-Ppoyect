#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"
#include "Clases/MapaTMX.h"
#include "Clases/maniMenu.h"

int look_empty(Ataque *ataque[]);

int menu();

int main() {
    int time = 70, a = 0;
    sf::Vector2i cPos;
    // Variables gravedad
    float jumpF = 400;
    float gravityAcceleration = 9.8;
    // Gravedad
    int mass = 57;
    sf::Clock delta;
    float deltaTime;
    bool whileJump;

    //a = menu();

    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);
    sf::View camera;

    camera.reset({0, 0, 850, 480});
    window.setView(camera);
    camera.zoom(2);

    //maniMenu menu(600,450);

    //Creo el personaje
    sf::Texture tx_player;
    sf::Sprite image_player;
    if (!tx_player.loadFromFile("assets/personaje.png")) {
        return EXIT_FAILURE;
    }
    image_player.setTexture(tx_player);
    Personaje *player;

    //CREO TEXTURA DEL ATAQUE
    Ataque **ataque = new Ataque *[100];
    for (int ii = 0; ii < 100; ii++) {
        ataque[ii] = nullptr;
    }
    sf::Texture tx_ataque;
    if (!tx_ataque.loadFromFile("assets/espada.png"))
        return EXIT_FAILURE;

    //Mapa miMapa("mapa.txt");
    MapaTMX miMapa("assets/Mapa/Mapa.tmx", tx_player);
    player = miMapa.getPlayer();

    sf::Texture tx_Mapa;
    sf::Sprite image_Mapa;

    // Main loop
    while (window.isOpen()) {
        deltaTime = delta.restart().asSeconds();
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update world parameters

        // Mover player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->moverDerecha(deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player->moverIzquierda(deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !player->getJumping()) {
            player->setSpeedvalue(jumpF / mass);
        }
        //cout << player->getPos().x << "\t" << player->getPos().y << endl;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (time >= 40) {
                int idx = look_empty(ataque);
                if (idx >= 0) {
                    ataque[idx] = new Ataque(player->getPos(), player->getAng(), tx_ataque);
                    time = 0;
                }
            }
        }
        time++;

        player->colisiones(miMapa.getList(), deltaTime);

        //CREO PUNTERO ATAQUE
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] != nullptr) {
                ataque[ii]->simular();
                if (ataque[ii]->getTimeout() < 0) {
                    delete ataque[ii];
                    ataque[ii] = nullptr;
                }
            }
        }

        //Movimiento de camara
        if (player->getPos().x > 1200) {
            cPos.x = 2030;
        }
        if (player->getPos().x < 1200) {
            cPos.x = 850;
        }
        cPos.y = 480;

        // Draw all elements
        window.clear();
        //menu.draw(window);
        camera.setCenter(cPos.x, cPos.y);
        window.setView(camera);
        miMapa.dibujar(window);
        player->dibujar(window);
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] != nullptr) {
                ataque[ii]->dibujar(window);
            }
        }
        auto list = miMapa.getList();

#ifdef DEBUG
        for (int ii = 0; ii < list.getSize(); ii++) {
            sf::RectangleShape cuadrado({list.get(ii)->width, list.get(ii)->height});
            cuadrado.setPosition({list.get(ii)->left, list.get(ii)->top});
            cuadrado.setOutlineColor(sf::Color::Red);
            cuadrado.setOutlineThickness(2);
            cuadrado.setFillColor(sf::Color::Transparent);
            window.draw(cuadrado);
        }
#endif
        window.display();

    }
    return EXIT_SUCCESS;
}

int look_empty(Ataque *ataque[]) {
    for (int ii = 0; ii < 100; ii++) {
        if (ataque[ii] == nullptr)
            return ii;
    }
    return -1;
}
