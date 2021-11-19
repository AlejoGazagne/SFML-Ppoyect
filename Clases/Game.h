#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H
#include "LinkedList.h"
#include <stack>
#include <queue>
#include <fstream>
#include "enemigos.h"
#include "Coin.h"
#include "Vida.h"
#include "Coin.h"

enum fases {
    WIN,
    GAME = 1,
    GAMEOVER = 2,
    };

int look_empty(Ataque *ataque[]);

class Game {
    // CONTADORES
    int tiempoJuego = 0;
    int time = 70;
    // VENTANA
    sf::Window window;
    sf::View camera;
    // ESTADOS
    fases state;
    // VARIABLE GRABEDAD Y SALTO
    float jumpF = 400;
    float gravityAcceleration = 9.8;
    int mass = 57;
    sf::Clock delta;
    float deltaTime;
    bool whileJump;
    // Personaje
    sf::Vector2i cPos;
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
    LinkedList<Enemigos*> enemy;
    //COIN CON TILED
    Coin *moni;
    queue<Coin *> moneda;
    int puntaje = 0;
    // VIDA PERSONAJE
    Vida *vi;
    stack<Vida *> vida;
    sf::Font font;
    sf::Text life;
    sf::Text porVida;

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

        miMapa = new MapaTMX("assets/Mapa/Mapa.tmx", tx_player, &enemy, &moneda, &vida);
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
                if(ataque[ii]->dibujar(window, miMapa->getList(), enemy) == true){
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

        time++;
        tiempoJuego++;
        // Draw all elements
        window.clear();
        camera.setCenter(cPos.x, cPos.y);
        window.setView(camera);
        miMapa->dibujar(window);
        player->dibujar(window);
        for (int ii = 0; ii < enemy.getSize(); ii++) {
            enemy.get(ii)->mover(deltaTime, player->getPos().y, player->getPos().x, miMapa->getList());
            window.draw(enemy.get(ii)->getSprite());
            if(enemy.get(ii)->getVidas() == 0){
                delete this -> enemy.get(ii);
                enemy.remove(ii);
                puntaje = puntaje + 20;
            }
            /*if(enemy.get(ii)->getSprite().getGlobalBounds().intersects()){
                cout<<"Sacar vida"<<endl;
            }*/
        }
        if(enemy.getSize() == 0){
            state = GAMEOVER;
            return 1;
        }
        for(int ii = 0; ii < moneda.size(); ii++){
            moni = moneda.front();
            moni->draw(window);
            if(player->isCollindingWhithCoin(moni) == true){
                moneda.pop();
                puntaje = puntaje + 50;
            }
        }
        if(!font.loadFromFile("assets/letra.ttf")){
            //handle error
        }
        // DIBUJAR VIDAS
        for(int ii = 0; ii < vida.size(); ii++){
            vi = vida.top();
            vi->setPos(10,10);
            life.setFont(font);
            life.setColor(sf::Color::White);
            life.getCharacterSize();
            life.setString("x");
            porVida.setFont(font);
            porVida.setColor(sf::Color::White);
            porVida.getCharacterSize();
            std::string wasd = "" + vida.size();
            porVida.setString(wasd);
            if (player->getPos().x > 1200) {
                life.setPosition(sf::Vector2f(1340, 5));
                porVida.setPosition(sf::Vector2f(1360, 5));
                vi->setPos(1300,10);
            }
            if (player->getPos().x < 1200) {
                life.setPosition(sf::Vector2f(40, 5));
                porVida.setPosition(sf::Vector2f(200, 5));
                vi->setPos(10,10);
            }
            /*if(vida.top()->getSprite().getGlobalBounds().intersects(image_player.getGlobalBounds())){
                cout<<"Sacar vida"<<endl;
            }*/
            window.draw(porVida);
            window.draw(life);
            window.draw(vi->getSprite());
        }

        for (int ii = 0; ii < 100; ii++) {
            if (ataque[ii] != nullptr) {
                ataque[ii]->dibujar(window, miMapa->getList(), enemy);
            }
        }

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
        ofstream ofs;
        ofs.open("Tabla.txt");
        ofs<<"Datos de la Partida"<<"\n"<<"Puntos:"<<puntaje<<"\n"<<"Tiempo:"<<tiempoJuego/60<<" Segundos"<<endl;
        ofs<<endl;
        ofs.close();
        return 0;
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
