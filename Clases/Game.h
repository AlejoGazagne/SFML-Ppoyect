<<<<<<< HEAD
#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H
#include <queue>

int look_empty(Ataque *ataque[]);
=======
//
// Created by martin on 12/11/21.
//

#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5

class Game {
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
<<<<<<< HEAD
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

=======
    sf::Texture tx_player;
    sf::Sprite image_player;
    Personaje *player;
    Ataque **ataque = new Ataque *[100];
    sf::Texture tx_ataque;
    MapaTMX *miMapa;
    sf::Texture tx_Mapa;
    sf::Sprite image_Mapa;
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
public:

    Game(sf::RenderWindow &window) {
        camera.reset({0, 0, 850, 480});
        window.setView(camera);
        camera.zoom(2);

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

        miMapa = new MapaTMX("assets/Mapa/Mapa.tmx", tx_player);
        player = miMapa->getPlayer();
    }
    int loop(sf::RenderWindow &window){

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
<<<<<<< HEAD
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {

        }*/
=======
        //cout << player->getPos().x << "\t" << player->getPos().y << endl;
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (time >= 40) {
                int idx = look_empty(ataque);
                if (idx >= 0) {
                    ataque[idx] = new Ataque(player->getPos(), player->getLeft(), tx_ataque);
                    time = 0;
                }
            }
        }
        time++;

        player->colisiones(miMapa->getList(), deltaTime);

        //CREO PUNTERO ATAQUE
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] != nullptr) {
                ataque[ii]->simular();
<<<<<<< HEAD
                if(ataque[ii]->dibujar(window, miMapa->getList()) == true){
=======
                if (ataque[ii]->getTimeout() < 0) {
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
                    delete ataque[ii];
                    ataque[ii] = nullptr;
                }
            }
        }

        //Movimiento de camara
        if (player->getPos().x > 1200) {
            cPos.x = 2030;
<<<<<<< HEAD
            player->dibujar(window);
=======
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
        }
        if (player->getPos().x < 1200) {
            cPos.x = 850;
        }
        cPos.y = 480;

        // Draw all elements
        window.clear();
<<<<<<< HEAD
=======
        //menu.draw(window);
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
        camera.setCenter(cPos.x, cPos.y);
        window.setView(camera);
        miMapa->dibujar(window);
        player->dibujar(window);
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] != nullptr) {
<<<<<<< HEAD
                ataque[ii]->dibujar(window, miMapa->getList());
=======
                ataque[ii]->dibujar(window);
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
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

        return 1;
    }
<<<<<<< HEAD

=======
>>>>>>> 5d8298107ccbc1fd0f3e651b3ada9c740f1b12a5
    int look_empty(Ataque *ataque[]) {
        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] == nullptr)
                return ii;
        }
        return -1;
    }

};

#endif //MAIN_CPP_GAME_H
