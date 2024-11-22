#define MAXproductos 5
#define MAXcaracteres 50
#define MAXmateriales 50

void ingresarProducto(int cantidad[MAXmateriales], char producto[MAXproductos][MAXcaracteres],
                      char nombremateriales[MAXproductos][MAXmateriales][MAXcaracteres], int mrequeridos[MAXproductos], int tiempo[MAXproductos]);

void eliminarProducto(char productos[MAXproductos][MAXcaracteres], int tiempos[MAXproductos]);

void menuPrincipal(int opcion, float recursoDisponible ,int tiempo[MAXproductos], char producto[MAXproductos][MAXcaracteres], float precio[MAXproductos], int cantidad[MAXmateriales], char nombremateriales[MAXproductos][MAXmateriales][MAXcaracteres], int mrequeridos[MAXproductos]);
void editarProducto(char producto[MAXproductos][MAXcaracteres], int tiempo[MAXproductos]);
void cotizacionPorTiempo(int tiempo[MAXproductos], char producto[MAXproductos][MAXcaracteres], float recursoDisponible);
void cotizacionPorCantidad(char producto[MAXproductos][MAXcaracteres], float precio[MAXproductos], float recursoDisponible);