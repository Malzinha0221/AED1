#include "cubo.h"

void InicializarCubo(Cubo *cubo, double lado) {
    cubo->lado = lado;
}

double CalcularArea(Cubo *cubo) {
    return 6 * cubo->lado * cubo->lado;
}

double CalcularVolume(Cubo *cubo) {
    return cubo->lado * cubo->lado * cubo->lado;
}
