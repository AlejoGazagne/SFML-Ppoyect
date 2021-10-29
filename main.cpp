#include <iostream>
#include <SFML/Graphics.hpp>
#include "Clases/personaje.h"
#include "Clases/Ataque.h"
#include "Clases/MapaTMX.h"

int look_empty(Ataque *ataque[]);

int main() {
    int time = 70, i;
    sf::Vector2i cPos;
    //
    const float gravity = 1;
    bool isJumping = false;
    //Crear ventana y mostrar el mapa
    sf::RenderWindow window(sf::VideoMode(1536, 850), "Proyecto Info II");
    window.setFramerateLimit(60);
    sf::View camera;

    camera.reset({0, 0, 850, 480});
    window.setView(camera);
    camera.zoom(2);

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
    for(int ii = 0; ii < 100; ii++){
        ataque[ii] = nullptr;
    }
    sf::Texture tx_ataque;
    if(!tx_ataque.loadFromFile("assets/espada.png"))
        return EXIT_FAILURE;

    //Mapa miMapa("mapa.txt");
    MapaTMX miMapa("assets/Mapa/Mapa.tmx", tx_player);
    player = miMapa.getPlayer();

    sf::Texture tx_Mapa;
    sf::Sprite image_Mapa;

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update world parameters

        // Mover player
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player->moverDerecha();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player->moverIzquierda();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            isJumping = true;
            player->saltar();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(time >= 40){
                int idx = look_empty(ataque);
                if(idx >= 0){
                    ataque[idx] = new Ataque(player->getPos(), player->getAng(), tx_ataque);
                    time = 0;
                }
            }
        }
        time++;

        //Gravity logic
        if(player->getPos().y < 850 && isJumping == false){
            player->gravity();
        }
        isJumping = false;

        player->colisiones(miMapa.getList());

        //CREO PUNTERO ATAQUE
        for(int ii = 0; ii < 100; ii++){
            if(ataque[ii]!= nullptr){
                ataque[ii]->simular();
                if(ataque[ii]->getTimeout() < 0){
                    delete ataque[ii];
                    ataque[ii] = nullptr;
                }
            }
        }

        //Movimiento de camara
        if(player->getPos().x > 1200 ){
            cPos.x = 2030;
        }
        if(player->getPos().x < 1200){
            cPos.x = 850;
        }
        if(player->getPos().y > 480){
            cPos.y = 480;
        }
        // Draw all elements
        window.clear();
        camera.setCenter(cPos.x, cPos.y);
        window.setView(camera);
        miMapa.dibujar(window);
        player->dibujar(window);
        for(int ii = 0; ii < 100; ii++){
            if(ataque[ii]!= nullptr){
                ataque[ii]->dibujar(window);
            }
        }
        window.display();

    }
    return EXIT_SUCCESS;
}
int look_empty(Ataque *ataque[]){
    for(int ii = 0; ii < 100; ii++){
        if(ataque[ii] == nullptr)
            return ii;
    }
    return -1;
}