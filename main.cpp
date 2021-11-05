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
    int mass = 60;
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
        deltaTime = delta.restart().asSeconds();
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update world parameters

        // Mover player
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            player->moverDerecha(deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            player->moverIzquierda(deltaTime);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && whileJump == false){
            player->setSpeedvalue(jumpF/mass);
            whileJump = true;
        }
        if(whileJump){
            player->saltar(deltaTime);
            if(player->getPos().y > 770){
                whileJump = false;
                player->setSpeedvalue(0);
            }

        }
        cout<<player->getPos().x<<"\t"<<player->getPos().y<<endl;
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
///////////////////////////////////////////////////////////////////////////
        /*switch(event.key.code){
            case sf::Keyboard::Up:
                menu.MoveUp();
                break;
            case sf::Keyboard::Down:
                menu.MoveDown();
                break;
            case sf::Keyboard::Return:
                switch(menu.GetPressedItem()){
                case 0:
                    std::cout<<"Has apretado el boton jugar"<<std::endl;
                    break;
                case 1:
                    std::cout<<"Has apretado el boton opciones"<<std::endl;
                    break;
                case 2:
                    window.close();
                    break;
                }
            break;
        }*/
//////////////////////////////////////////////////////////////////////////
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
        //if(player->getPos().y > 480){
            cPos.y = 480;
        //}
        // Draw all elements
        window.clear();
        //menu.draw(window);
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

int menu(){
    sf::RenderWindow window (sf::VideoMode(1536, 850), "Menu");

    // Menu
    maniMenu menu(600,450);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(menu.GetPressedItem()){
                            case 0:
                                std::cout<<"Has apretado el boton jugar"<<std::endl;
                                break;
                            case 1:
                                std::cout<<"Has apretado el boton opciones"<<std::endl;
                                break;
                            case 2:
                                window.close();
                                break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }
    window.clear();
    menu.draw(window);
    window.display();

    return EXIT_SUCCESS;
}