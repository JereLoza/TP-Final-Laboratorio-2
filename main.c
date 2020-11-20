#include <stdio.h>
#include <stdlib.h>

#define ESC 27
#define ARCH_MISIONES "archMisiones.dat"
#define ARCH_NAVES "archNaves.dat"

int main()
{
    char opcion;

    do{
        system("cls");
        menuPrincipal();
        opcion = getch();
        system("cls");

        switch(opcion){
            case 'a':
                menuAstronauta();
            break;
            case 'b':
                menuNaves();
            break;
            case 'c':
                menuMisiones();
            break;
            case 'd':
                /// ACA VA EL APARTADO ADMINISTRADOR DE MISIONES (POSIBLEMENTE NO VAYA)
            break;
        }

    }while(opcion!=ESC);

    system("cls");

    return 0;
}

void menuPrincipal(){
    printf("\tSpace X - Administrador");
    printf("\n\n");
    printf("a) Administrar astronautas.\n");
    printf("b) Administrar naves.\n");
    printf("c) Adminitrar misiones.\n");
    printf("d) Administrador de misiones.\n"); /// (POSIBLEMENTE NO VAYA)
    printf("\n\n");
    printf("Presiona ESC para salir...");
}

void menuAstronauta(){
    char opcion;

    do{
        system("cls");
        textoMenuAstronauta();
        opcion = getch();
        system("cls");

        switch(opcion){
            case 'a':
                /// ACA IRIA LA CARGA DE NUEVO ASTRONAUTA
            break;
            case 'b':
                /// ACA SE BORRARIAN LOS ASTRONAUTAS
            break;
            case 'c':
                /// ACA IRIA LA MODIFICACION DE UN ASTRONAUTA
            break;
            case 'd':
                /// ACA SE BUSCARIA UN ASTRONAUTA DADO
            break;
            case 'e':
                /// ACA SE MOSTRARIAN LOS ASTRONAUTAS DISPONIBLES
            break;
        }

        system("pause");
    }while(opcion!=ESC);

    system("cls");
}

void textoMenuAstronauta(){
    printf("\tSpace X - Astronautas");
    printf("\n\n");
    printf("a) Cargar nuevo astronauta.\n");
    printf("b) Borrar un astronauta.\n");
    printf("c) Modificar datos del astronauta.\n");
    printf("d) Buscar astronauta por apodo.\n");
    printf("e) Mostrar todos los astronautas.\n");
    printf("\n\n");
    printf("Presiona ESC para salir...");
}

void menuNaves(){
    char opcion;

    do{
        system("cls");
        textoMenuNaves();
        opcion = getch();
        system("cls");

        switch(opcion){
            case 'a':
                /// ACA SE AGREGARIAN HORAS DE VUELO
            break;
            case 'b':
                /// ACA SE CAMBIARIA EL ESTADO DE LA NAVE
            break;
            case 'c':
                /// ACA SE MOSTRARIAN LAS NAVES
            break;
        }

        system("pause");
    }while(opcion!=ESC);

    system("cls");
}

void textoMenuNaves(){
    printf("\tSpace X - Naves");
    printf("\n\n");
    printf("a) Agregar horas de vuelo.\n");
    printf("b) Cambiar estado de la nave.\n");
    printf("c) Mostrar naves.\n");
    printf("\n\n");
    printf("Presiona ESC para salir...");
}

void menuMisiones(){
    char opcion;

    do{
        system("cls");
        textoMenuMisiones();
        opcion = getch();
        system("cls");

        switch(opcion){
            case 'a':
                /// ACA IRIA LA CARGA DE NUEVA MISION
            break;
            case 'b':
                /// ACA SE CAMBIARIA EL ESTADO DE LA MISION
            break;
            case 'c':
                /// ACA SE MOSTRARIAN LAS MISIONES LISTAS
            break;
            case 'd':
                /// ACA SE MOSTRARIAN TODAS LAS MISIONES
            break;
        }

        system("pause");
    }while(opcion!=ESC);

    system("cls");
}

void textoMenuMisiones(){
    printf("\tSpace X - Misiones");
    printf("\n\n");
    printf("a) Agregar nueva mision.\n");
    printf("b) Cambiar estado de la mision.\n");
    printf("c) Mostrar misiones listas.\n");
    printf("d) Mostrar todas las misiones.\n");
    printf("\n\n");
    printf("Presiona ESC para salir...");
}
