#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#define ARCH_NAVES "archNaves.dat"

/// ESTRUCTURA NAVE
typedef struct{
    int id;
    char tipoNave[30]; // (Starship, Falcon 9, Falcon Heavy)
    int cantVuelos;
    int horasAcumuladas;
    int estado; // (0- mantenimiento 1- Lista para su uso 2- Actualmente en misión 3- De baja)
}stNave;



#endif // NAVE_H_INCLUDED
