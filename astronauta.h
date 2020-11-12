#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED

#define ARCH_ASTRONAUTAS "archAstronautas.dat"
/// ESTRUCTURA ASTRONAUTA
typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char apodo[30];
    int edad;
    char nacionalidad[30];
    char especialidad[30]; // (piloto, astrofísico, ingeniero espacial, biólogo, etc)
    int horasAcumuladas;
    int misionesRealizadas;
    int horasISS;
    int estado; // (1- Activo 2- Retirado)
}stAstronauta;

stAstronauta crearAstronauta();
int ultimoAstronautaID(char nombreArch[]);
void mostrarAstronauta(stAstronauta astronauta);

#endif // ASTRONAUTA_H_INCLUDED
