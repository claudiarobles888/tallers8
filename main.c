#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAXproductos 5
#define MAXcaracteres 50
#define MAXmateriales 50

int main()
{
    char producto[MAXproductos][MAXcaracteres] = {{0}}; // Inicializar los nombres de productos vacíos
    int tiempo[MAXproductos] = {0};                     // Inicializar en 0
    int mrequeridos[MAXproductos] = {0};
    int cantidad[MAXmateriales] = {0}; // Almacenará cantidad por material
    char nombremateriales[MAXproductos][MAXmateriales][MAXcaracteres] = {{{0}}};
    float precio[MAXproductos] = {0}; // Inicializa precios en 0
    float recursoDisponible = 0;
    int opcion, opc2;

    printf("----Optimax----\n");

    do
    {
        // Mostrar el menú principal
        printf("Seleccione la funcion a realizar:\n");
        printf("1. Inventario\n");
        printf("2. Cotizacion\n");
        printf("3. Productos a la venta\n");

        scanf("%d", &opcion);

        menuPrincipal(opcion, recursoDisponible,  tiempo, producto, precio,cantidad, nombremateriales, mrequeridos);

        // Preguntar si quiere realizar otra operación
        printf("¿Desea realizar una nueva función?\n1. Sí\n2. No\n");
        scanf("%d", &opc2);
    } while (opc2 == 1);

    return 0;
}