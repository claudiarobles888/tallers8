#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAXproductos 5
#define MAXcaracteres 50
#define MAXmateriales 50

void menuPrincipal(int opcion, float recursoDisponible, int tiempo[MAXproductos], char producto[MAXproductos][MAXcaracteres], float precio[MAXproductos], int cantidad[MAXmateriales], char nombremateriales[MAXproductos][MAXmateriales][MAXcaracteres], int mrequeridos[MAXproductos])
{
    switch (opcion)
    {
    case 1: // Inventario
    {
        int tipodeFuncion;
        printf("Seleccione la funcion que desea realizar\n1. ingresar producto\n2.Eliminar Producto\n3.Editar Producto\n");
        scanf("%d", &tipodeFuncion);

        if (tipodeFuncion == 1)
        {
            ingresarProducto(cantidad, producto, nombremateriales, mrequeridos, tiempo);
        }
        else if (tipodeFuncion == 2)
        {
            eliminarProducto(producto, tiempo);
        }
        else if (tipodeFuncion == 3)
        {
            editarProducto(producto, tiempo);
        }
        {
            printf("Opción no válida.\n");
        }
    }
    break;

    case 2: // Cotización
    {
        int tipoCotizacion;
        printf("Seleccione el tipo de cotizacion:\n1. Por tiempo\n2. Por cantidad\n");
        scanf("%d", &tipoCotizacion);

        if (tipoCotizacion == 1)
        {
            cotizacionPorTiempo(tiempo, producto, recursoDisponible);
        }
        else if (tipoCotizacion == 2)
        {
            cotizacionPorCantidad(producto, precio, recursoDisponible);
        }
        else
        {
            printf("Ingrese una opcion valida.\n");
        }
    }
    break;

    case 3: // Productos a la venta
        printf("Los productos disponibles a la venta son:\n");
        printf("1. Placa Base\n2. Microcontrolador\n3. Sensor de temperatura\n4. Circuito Impreso (PCB)\n5. Pantalla LCD\n");
        break;

    default:
        printf("Opcion no valida.\n");
        break;
    }
}

// Ingreso de productos
void ingresarProducto(int cantidad[MAXmateriales], char producto[MAXproductos][MAXcaracteres],
                      char nombremateriales[MAXproductos][MAXmateriales][MAXcaracteres], int mrequeridos[MAXproductos], int tiempo[MAXproductos])
{
    for (int i = 0; i < MAXproductos; i++)
    {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        getchar(); // Limpiar buffer
        fgets(producto[i], MAXcaracteres, stdin);
        producto[i][strcspn(producto[i], "\n")] = 0; // Remover salto de línea

        printf("Ingrese el tiempo de fabricacion de %s: ", producto[i]);
        scanf("%d", &tiempo[i]);

        printf("Ingrese la cantidad de materiales requeridos para %s: ", producto[i]);
        scanf("%d", &mrequeridos[i]);
        getchar(); // Limpiar buffer

        for (int j = 0; j < mrequeridos[i]; j++)
        {
            printf("Ingrese el nombre del material %d: ", j + 1);
            fgets(nombremateriales[i][j], MAXcaracteres, stdin);
            nombremateriales[i][j][strcspn(nombremateriales[i][j], "\n")] = 0;

            printf("Ingrese la cantidad de %s: ", nombremateriales[i][j]);
            scanf("%d", &cantidad[j]);
            getchar(); // Limpiar buffer
        }
    }
}

// Eliminar producto
void eliminarProducto(char producto[MAXproductos][MAXcaracteres], int tiempo[MAXproductos])
{
    char nombre[MAXcaracteres];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    getchar(); // Limpiar buffer
    fgets(nombre, MAXcaracteres, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (int j = 0; j < MAXproductos; j++)
    {
        if (strcmp(producto[j], nombre) == 0)
        {
            strcpy(producto[j], "ELIMINADO"); // Eliminar el producto
            tiempo[j] = 0;                    // Reiniciar tiempo
            printf("Producto %s eliminado exitosamente\n", nombre);
            return;
        }
    }
    printf("Producto %s no encontrado\n", nombre);
}

// Editar producto
void editarProducto(char producto[MAXproductos][MAXcaracteres], int tiempo[MAXproductos])
{
    char nombre[MAXcaracteres];
    printf("Ingrese el nombre del producto que desea editar: ");
    getchar(); // Limpiar buffer
    fgets(nombre, MAXcaracteres, stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    for (int j = 0; j < MAXproductos; j++)
    {
        if (strcmp(producto[j], nombre) == 0)
        {
            printf("Producto encontrado: %s\n", producto[j]);

            printf("Ingrese el nuevo nombre del producto (deje en blanco si no desea cambiar): ");
            char productoEditado[MAXcaracteres];
            fgets(productoEditado, MAXcaracteres, stdin);
            productoEditado[strcspn(productoEditado, "\n")] = 0;

            if (strlen(productoEditado) > 0)
            {
                strcpy(producto[j], productoEditado);
            }

            printf("Ingrese el nuevo tiempo de fabricación de %s: ", producto[j]);
            int tiempoEditado;
            scanf("%d", &tiempoEditado);

            if (tiempoEditado >= 0)
            {
                tiempo[j] = tiempoEditado;
            }
            printf("Producto actualizado exitosamente\n");
            return;
        }
    }
    printf("Producto %s no encontrado\n", nombre);
}

// Cotización por tiempo
void cotizacionPorTiempo(int tiempo[MAXproductos], char producto[MAXproductos][MAXcaracteres], float recursoDisponible)
{
    int productoEscogido;
    float tarifa;

    printf("Seleccione el producto para la cotización por tiempo (1-%d):\n", MAXproductos);
    for (int i = 0; i < MAXproductos; i++)
    {
        printf("%d. %s\n", i + 1, producto[i]);
    }

    scanf("%d", &productoEscogido);
    if (productoEscogido < 1 || productoEscogido > MAXproductos)
    {
        printf("Producto no valido.\n");
        return;
    }

    printf("Ingrese la tarifa por unidad de tiempo: ");
    scanf("%f", &tarifa);

    float cotizacion = tiempo[productoEscogido - 1] * tarifa;
    printf("La cotizacion por tiempo para %s es: %.2f\n", producto[productoEscogido - 1], cotizacion);

    if (recursoDisponible >= cotizacion)
    {
        printf("Sí se puede fabricar el producto seleccionado.\n");
    }
    else
    {
        printf("No se puede fabricar. Recurso disponible: %.2f\n", recursoDisponible);
        printf("Recurso necesario: %.2f\n", cotizacion);
    }
}

// Cotización por cantidad
void cotizacionPorCantidad(char producto[MAXproductos][MAXcaracteres], float precio[MAXproductos], float recursoDisponible)
{
    int productoEscogido, cantidadEscogida;

    printf("Seleccione el producto para la cotizacion por cantidad (1-%d):\n", MAXproductos);
    for (int i = 0; i < MAXproductos; i++)
    {
        printf("%d. %s\n", i + 1, producto[i]);
    }

    scanf("%d", &productoEscogido);
    if (productoEscogido < 1 || productoEscogido > MAXproductos)
    {
        printf("Producto no válido.\n");
        return;
    }

    printf("Ingrese la cantidad de productos: ");
    scanf("%d", &cantidadEscogida);

    printf("Ingrese el precio por unidad: ");
    scanf("%f", &precio[productoEscogido - 1]);

    float total = cantidadEscogida * precio[productoEscogido - 1];
    printf("La cotización por cantidad para %s es: %.2f\n", producto[productoEscogido - 1], total);

    if (recursoDisponible >= total)
    {
        printf("Sí se puede fabricar el producto seleccionado.\n");
    }
    else
    {
        printf("No se puede fabricar. Recurso disponible: %.2f\n Recurso necesario: %.2f.\n", recursoDisponible, total);
    }
}
