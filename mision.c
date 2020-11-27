#include <string.h>
#include <stdio.h>
#include "mision.h"
#include "astronauta.h"
#include "NodoMision.h"
#define ESC 27
#define EST_A "listo"

///MISIONES(ST) --------------------------------------------------------------------------------------------------------

stMision crearMision(filaMision* estadoA, filaMision* estadoB, arbolAstronautas* arbol)
{
    tripulantes* lista = inicList();
    char continuar;
    stMision nuevita;

    if (buscarUltimaID(estadoA) < buscarUltimaID(estadoB)) ///Busca la ID mas grande entre las dos filas que existen, luego le agrega +1 a esa id
    {
        nuevita.id = buscarUltimaID(estadoB) + 1;
    }
    else
    {
        nuevita.id = buscarUltimaID(estadoA) + 1;
    }


    if (buscarUltimaIDNave(estadoA) < buscarUltimaIDNave(estadoB))
    {
        nuevita.idNave = buscarUltimaIDNave(estadoB) + 1;
    }
    else
    {
        nuevita.idNave = buscarUltimaIDNave(estadoA) + 1;
    }

    printf("\nIngrese el ESTADO de la mision: \t");
    gets(&nuevita.estado);
    printf("\nIngrese el DESTINO de la mision: \t");
    gets(&nuevita.destino);
    printf("\nIngrese el CARGAMENTO de la mision: \t");
    gets(&nuevita.cargamento);
    do
    {
       lista = agregarPpioTripu(lista,crearNodoTripulantes(buscarAstronautaApodo())) ;
       printf("\nDesea seguir ingresando? ESC para 'no' \n");
       continuar = getch();
    }while(continuar != ESC);
    printf("Ingrese el DETALLE de la mision: \t");
    gets(&nuevita.detalleMision);

    return nuevita;
}

stMision extraerFila(filaMision* fila)
{
    stMision aux = NULL;

    if (fila->cabecera != NULL)
    {
        aux = verPrimero(fila->cabecera);

        fila->cabecera = borrarPrimero(fila->cabecera);

        if(fila->cabecera == NULL)
        {
            fila->fin = inicFila();
        }
    }

    return aux;

}

void mostrarMision (stMision misionx)
{
    printf("\n----------------------------------------------");
    printf("\nEl id de la mision es: \t%d", misionx.id);
    printf("\nEl id de la nave es: \t%d", misionx.idNave);
    printf("\nEl ESTADO de la mision es: \t"); puts(misionx.estado);
    printf("\nEl DESTINO de la mision es: \t"); puts(misionx.destino);
    printf("\nEl CARGAMENTO de la mision es: \t"); puts(misionx.cargamento);
    printf("\nEl DETALLE DE MISION es: \t"); puts(misionx.detalleMision);
    printf("\n----------------------------------------------")
}

void mostrarTripulantes (tripulantes* lista)
{
    while(lista != NULL)
    {
        mostrarAstronauta(lista->astronauta);
        lista=lista->sig;
    }
}

///FILA--------------------------------------------------------------------------------------------------------

filaMision * agregar (filaMision* cola, stMision nueva)
{
    nodoMision* nuevo = nuevoNodo(nueva);
    if(!(cola->cabecera))
    {
        cola->cabecera = nuevo;
        cola->fin = nuevo;
    }
    else
    {
        cola->cabecera = agregarFinal(cola->cabecera, nuevo);
        cola->fin = nuevo;
    }

    return cola;
}

void inicFila(filaMision* nueva)
{
    nueva->cabecera = inicMis();
    nueva->fin = inicMis();
}

stMision verPrimero (nodoMision* lista)
{
    stMision aux = NULL;
    if (lista)
    {
        aux = lista->nuevo;
    }
    return aux;
}

nodoMision* borrarPrimero (nodoMision* lista) ///Debe retornar el nuevo primero!
{
    nodoMision* aux = lista;

    if (lista)
    {
        lista = lista->ste;
        free(aux);
    }

    return lista;

}

void decideYCrea(filaMision* fila, filaMision* descarte, stMision unamision)
{
    filaMision* aux = inicFila();

    if (strcmpi(unamision.estado, EST_A)==0) ///Si el estado coincide
    {
        fila = agregar(fila, unamision);
        printf("\nSe agrego a la lista de LISTOS");
    }
    else
    {
        descarte = agregar(descarte, unamision);
        printf("\nSe agrego a lista de OTROS");
    }
}

int buscarUltimaID (filaMision* fila)
{
    int aux = 0;
    if (fila->cabecera != NULL)
    {
    aux = retID(fila->fin);
    }

    return aux;
}

int buscarUltimaIDNave (filaMision* fila)
{
    int aux = 0;
    if(fila->cabecera != NULL)
    {
        aux = retIDNave(fila->fin);
    }

    return aux;
}

stMision cambiarEstado(stMision xd)
{
    nodoMision* aux;
    if(fila)
    {
        aux = buscarNodo(id,fila->cabecera);
    }
     aux = modificarxID(id,aux,);

}

nodoMision* buscarNodo(int id, nodoMision* aux)
{
    while (id != aux->nuevo.id)
    {
        aux = aux->ste;
    }

    return aux
}
void cambioDeEstado (nodoMision* lista, char nombreArch[], int ID)
{
    stMision aux;
    int flag = 0;

    FILE* pArchLista = fopen(nombreArch,"r+b");

    if(pArchLista)
    {
        while ((flag == 0) && fread(&aux,sizeof(stMision),1,pArchLista)>0)
        {
            if(aux.id == ID)
            {
                flag = 1;
            }
        }
         aux = modificarxID(aux);
         fseek(pArchLista, sizeof(stMision)* (-1),1);
         fwrite(&aux,sizeof(stMision),1, pArchLista);

        fclose(pArchLista);
    }
}
void archTofilaMision (filaMision* fila, char nombreArch[])
{
    stMision aux;

    FILE *pArchFila = fopen(nombreArch, "rb");

    if(pArchFila){
        while(fread(&aux, sizeof(stMision), 1, pArchFila) > 0){
            fila->cabecera = agregarFinal(fila->cabecera, nuevoNodo(aux));
        }
              fseek(pArchFila, sizeof(stMision) * (-1), SEEK_END);
              fread(&aux, sizeof(stMision))
              fila->fin = nuevoNodo(aux);
        fclose(pArchFila);
    }

}

void filaMisionToArch(nodoMision* cabecera, char nombreArch[]){
    stMision aux;

    FILE *pArchFila = fopen(nombreArch, "ab");

    if(pArchFila){
            while(aux != NULL){
                fwrite(&(cabecera.nuevo), sizeof(nodoMision), 1 , pArchFila); ///El fin de la cola siempre va al final del archivo.
                cabecera = cabecera->ste;
            }

        fclose(pArchFila);
    }

///TRIPULANTES------------------------------------------------------------------------------------

tripulantes* crearNodoTripulantes(stAstronauta nuevo)
{
    tripulantes* tripu = (tripulantes*) malloc (sizeof(tripulantes));

    tripu->astronauta = nuevo;
    tripu->sig = inicLista();

    return tripu;
}

tripulantes* inicLista ()
{
    return NULL;
}

tripulantes* agregarPpioTripu(tripulantes* lista, tripulantes* nodo)
{
    if(!lista){
            lista = nodo;
    }
    else
    {
        nodo->sig = lista;
        lista = nodo;
    }

    return lista;
}

tripulantes* borrarxID (tripulantes* lista,int _id)
{
    tripulantes* aux = lista->sig;
    tripulantes* aux2; ///para agarrar el dato
    tripulantes* aux3;

    while(aux)
    {
        if(aux->astronauta.id == _id)
        {
            aux3->sig = aux->sig;
            aux2 = aux;
            aux = aux->sig;
            free(aux2);
        }
        aux3 = aux;
        aux = aux->sig;
    }

    return aux2;
}
