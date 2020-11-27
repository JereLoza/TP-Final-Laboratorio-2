#include "NodoMision.h"
#include "mision.h"
#include <stdio.h>

nodoMision* inicMis ()
{
    return NULL;
}

nodoMision * nuevoNodo (stMision mision){
    nodoMision* nueva = (nodoMision*) malloc (sizeof(nodoMision));

    nueva->nuevo = mision;
    nueva->ste = inicMis();

    return nueva;
}

nodoMision* buscarUltimo(nodoMision* lista)
{
    if(lista){
    if(!(lista->ste == NULL)){
        lista = buscarUltimo(lista->ste);
    }
    }
    return lista;
}

nodoMision* agregarFinal (nodoMision* lista, nodoMision* nuevo)
{

    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodoMision* aux;
        aux = buscarUltimo (lista);
        aux->ste = nuevo;
    }

    return lista;

}

int retID (nodoMision* nuevo)
{
    int aux;

    aux = nuevo->nuevo.id;

    return aux;
}

int retIDNave (nodoMision* nuevo)
{
    int aux;

    aux = nuevo->nuevo.idNave;

    return aux;
}

stMision modificarxID(stMision cual)
{
    char continuar;
    char continuar2;
    int ayuda;
    char ayuda2[30];
    tripulantes* tripulanteElim;

            do
            {
                system("cls");
                mostrarMenu1();
                fflush(stdin);
                continuar = getch();
                system("cls");
                switch(continuar)
                {
                    case 'a':
                        printf("Ingrese el nuevo ESTADO: \t");
                        gets(&cual.estado);
                    break;
                    case 'b':
                        printf("Ingrese el nuevo DESTINO: \t");
                        gets(&cual.destino);
                    break;
                    case 'c':
                        printf("Ingrese el nuevo CARGAMENTO: \t");
                        gets(&cual.cargamento);
                    break;
                    case 'd':
                        system("cls");
                        mostrarMenu2;
                        do{
                        switch(continuar2)
                        {
                        case 'a':
                        printf("Ingrese el nombre del Astronauta\t");
                        gets(&ayuda2);
                        tripulanteElim = agregarPpioTripu(cual.equipo,crearNodoTripulantes(buscaAstronautaPorApodo(arbol,ayuda2)));
                        break;
                        case 'b':
                        mostrarTripulantes(cual.equipo);
                        printf("ingrese el id del tripulante que desea eliminar: \t");
                        scanf("%d", &ayuda);
                        tripulanteElim = borrarxID(cual.equipo, ayuda);
                        break;
                        }
                        }while(continuar2 != ESC);
                        system("cls");
                    break;
                    case 'e':
                        printf("Ingrese el nuevo DETALLE DE MISION: \t");
                        gets(&cual.detalleMision);
                    break;
                }
            } while(continuar != ESC);

    return lista;
}

void mostrarMenu1 ()
{
    printf("\nDesea modificar el ESTADO (a)");
    printf("\nDesea modificar el DESTINO (b)");
    printf("\nDesea modificar el CARGAMENTO (c)");
    printf("\nDesea modificar el EQUIPO (d)");
    printf("\nDesea modificar el DETALLE DE MISION (e)");
}

void mostrarMenu2 ()
{
    printf("\nDesea agregar un miembro (a)");
    printf("\nDesea quitar un miembro (b)");
}

void mostrarLista (nodoMision* lista)
{
    if(lista)
    {
        mostrarLista(lista->ste);
        mostrarMision(lista->nuevo);
    }
}
