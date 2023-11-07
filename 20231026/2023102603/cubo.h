#ifndef CUBO_H
#define CUBO_H

typedef struct {
    double lado;
} Cubo;

void InicializarCubo(Cubo *cubo, double lado);
double CalcularArea(Cubo *cubo);
double CalcularVolume(Cubo *cubo);

#endif // CUBO_H
