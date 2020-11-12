#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "astronauta.h"

stAstronauta crearAstronauta(){
    stAstronauta astronauta;

    astronauta.id = ultimoAstronautaID(ARCH_ASTRONAUTAS);

    printf("\nIngrese el nombre del astronauta: ");
    fflush(stdin);
    gets(astronauta.nombre);

    printf("\nIngrese el apellido del astronauta: ");
    fflush(stdin);
    gets(astronauta.apellido);

    printf("\nIngrese el apodo del astronauta: ");
    fflush(stdin);
    gets(astronauta.apodo);

    printf("\nIngrese la edad del astronauta: ");
    scanf("%i", &astronauta.edad);

    printf("\nIngrese la nacionalidad del astronauta: ");
    fflush(stdin);
    gets(astronauta.nacionalidad);

    printf("\nIngrese la especialidad del astronauta: ");
    fflush(stdin);
    gets(astronauta.especialidad);

    printf("\nIngrese las horas acumuladas del astronauta: ");
    scanf("%i", &astronauta.horasAcumuladas);

    printf("\nIngrese las misiones realizadas del astronauta: ");
    scanf("%i", &astronauta.misionesRealizadas);

    printf("\nIngrese las horas en la ISS del astronauta: ");
    scanf("%i", &astronauta.horasISS);

    astronauta.estado = 1;


    return astronauta;
}

int ultimoAstronautaID(char nombreArch[]){
    stAstronauta astronauta;
    int id = -1;

    FILE *pArchAstronautas = fopen(nombreArch, "rb");

    if(pArchAstronautas){
        fseek(pArchAstronautas, sizeof(stAstronauta) * (-1), SEEK_END);
        if(fread(&astronauta, sizeof(stAstronauta), 1, pArchAstronautas) > 0){
            id = astronauta.id;
        }

        fclose(pArchAstronautas);
    }

    id++;
    return id;
}

void mostrarAstronauta(stAstronauta astronauta){
    printf("\n -----------------------------------------------------");
    printf("\n  ID:                          %i", astronauta.id);
    printf("\n  Nombre:                      %s", astronauta.nombre);
    printf("\n  Apellido:                    %s", astronauta.apellido);
    printf("\n  Apodo:                       %s", astronauta.apodo);
    printf("\n  Edad:                        %i", astronauta.edad);
    printf("\n  Nacionalidad:                %s", astronauta.nacionalidad);
    printf("\n  Especialidad:                %s", astronauta.especialidad);
    printf("\n  Horas Acumuladas:            %i", astronauta.horasAcumuladas);
    printf("\n  Misiones Realizadas:         %i", astronauta.misionesRealizadas);
    printf("\n  Horas en la ISS:             %i", astronauta.horasISS);
    printf("\n  Estado:                      %i", astronauta.estado);
    printf("\n -----------------------------------------------------\n");
}
