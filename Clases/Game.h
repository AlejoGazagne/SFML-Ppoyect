#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H
#include "LinkedList.h"
#include <stack>
#include <queue>
#include "enemigos.h"
#include "Coin.h"
#include "Vida.h"

enum fases {
    WIN,
    GAME,
    GAMEOVER,
    };

int look_empty(Ataque *ataque[]);

class Game {
    sf::Window window;
    sf::View camera;
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
    // Personaje
    sf::Texture tx_player;
    sf::Sprite image_player;
    Personaje *player;
    // Ataque
    Ataque **ataque = new Ataque *[100];
    sf::Texture tx_ataque;
    // Mapa
    MapaTMX *miMapa;
    sf::Texture tx_Mapa;
    sf::Sprite image_Mapa;
    // ENEMIGOS
    Enemigos *enem;
    LinkedList<Enemigos*> en;

    fases state;

    // Tiempo de juego
    int tiempoJuego = 0;
    int puntaje;

    //coin Con tiled
    LinkedList<int >lista;



public:

    Game(sf::RenderWindow &window) {
        camera.reset({0, 0, 850, 480});
        window.setView(camera);
        camera.zoom(2);

        // CREO LA TEXTURA DEL PERSONAJE
        if (!tx_player.loadFromFile("assets/juntos.png")) {
            cout << "No se pudo cargar juntos.png" << endl;
        }
        image_player.setTexture(tx_player);

        //CREO TEXTURA DEL ATAQUE
        for (int ii = 0; ii < 100; ii++) {
            ataque[ii] = nullptr;
        }
        if (!tx_ataque.loadFromFile("assets/espada.png"))
            cout << "No se pudo cargar espada.png" << endl;

        miMapa = new MapaTMX("assets/Mapa/Mapa.tmx", tx_player, &en, lista);
        player = miMapa->getPlayer();



    }

    int loop(sf::RenderWindow &window){
        deltaTime = delta.restart().asSeconds();

        //Vida
        Vida vida();


        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (time >= 40) {
                int idx = look_empty(ataque);
                if (idx >= 0) {
                    ataque[idx] = new Ataque(player->getPos(), player->getLeft(), tx_ataque);
                    time = 0;
                }
            }
        }


        player->colisiones(miMapa->getList(), deltaTime);

        //CREO PUNTERO ATAQUE
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] != nullptr) {
                ataque[ii]->simular();
                if(ataque[ii]->dibujar(window, miMapa->getList()) == true){
                    delete ataque[ii];
                    ataque[ii] = nullptr;
                }
            }
        }

        //Movimiento de camara
        if (player->getPos().x > 1200) {
            cPos.x = 2030;
            player->dibujar(window);
        }
        if (player->getPos().x < 1200) {
            cPos.x = 850;
        }
        cPos.y = 480;




        /*if(tiempoJuego/60 > 10){
            tiempoJuego = 0;
            state = GAMEOVER;
            return state+1;
        }*/

        time++;
        tiempoJuego++;
        // Draw all elements
        window.clear();
        camera.setCenter(cPos.x, cPos.y);
        window.setView(camera);
        miMapa->dibujar(window);
        player->dibujar(window);
        for (en.iterInit(); !en.iterEnd(); en.iterNext()) {
            window.draw(en.iterGet()->getSprite());
        }
        //vida.draw(window);
        /*for(int ii = 1; ii < coinVec.size(); ii++){
            coinVec[ii]->draw(window);
        }
        for(int ii = 0; ii < coinVec.size(); ii++){
            if(player->isCollindingWhithCoin(coinVec[ii])){
                coinVec[ii]->setPos({500000,50000});
            }
        }*/
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] != nullptr) {
                ataque[ii]->dibujar(window, miMapa->getList());
            }
        }
        auto list = miMapa->getList();

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

        return GAME;
    }

    int look_empty(Ataque *ataque[]) {
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] == nullptr)
                return ii;
        }
        return -1;
    }

};

#endif //MAIN_CPP_GAME_H
