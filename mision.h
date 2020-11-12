#ifndef MISION_H_INCLUDED
#define MISION_H_INCLUDED

#define ARCH_MISIONES "archMisiones.dat"

/// ESTRUCTURA MISION
typedef struct{
    int id;
    int idNave;
    char estado[30]; // (Listo, En vuelo, Retornada, Cancelada, Fallida)
    char destino[30]; // (EEI, Órbita terrestre, Luna, etc)
    char cargamento[30];// (Satélite, Insumos para la EEI, el Auto de Elon Musk, etc)
    ///FALTA TRIPULANTES, (FUE CONSULTADO POR MAIL)
    char detalleMision;
}stMision;

#endif // MISION_H_INCLUDED
