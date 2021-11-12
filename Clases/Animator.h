#ifndef MAIN_CPP_ANIMATOR_H
#define MAIN_CPP_ANIMATOR_H


#include <SFML/Graphics.hpp>

class Animator : public sf::Sprite {
    int fila, columna, columnaActual;
    int fps, fpsActual;
public:
    Animator();

    void setFila(int fila);
    void setFps(int fps);

    void setAnimation(int fila);
    void setColumna(int columna);
    void animate();

};


#endif //MAIN_CPP_ANIMATOR_H
