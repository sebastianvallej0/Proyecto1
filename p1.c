#include <stdio.h>
#include <string.h>

#define mxP 100

typedef struct {
    char nombre[100];
    int cantidad;
    float precio;
} Pr;
 
void aP(Pr *prs, int *nP);
void eP(Pr *prs, int nP);
void delP(Pr *prs, int *nP);
void lP(Pr *prs, int nP);

int main() {
    Pr prs[mxP];
    int nP = 0;
    char opcion;

    do {
        printf("==== Bienvenido a Smart Tech ====\n");
        printf("==== Elija la opcion requerida ====\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Mostrar factura\n");
        printf("6. Salir\n");

        printf("Ingrese una opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                aP(prs, &nP);
                break;
            case '2':
                eP(prs, nP);
                break;
            case '3':
                delP(prs, &nP);
                break;
            case '4':
                lP(prs, nP);
                break;
            case '5':
                mostrarFactura(prs, nP);
                break;
            case '6':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción erronea. Por favor, ingrese otro valor e intente nuevamente.\n");
                break;
        }

        printf("\n");
    } while (opcion != '6');

    return 0;
}

void aP(Pr *prs, int *nP) {
    if (*nP == mxP) {
        printf("Se ha alcanzado el límite máximo de productos.\n");
        return;
    }

    Pr nuevoProducto;

    printf("Ingrese el nombre del producto: ");
    scanf("%49s", nuevoProducto.nombre);

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &nuevoProducto.cantidad);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevoProducto.precio);

    prs[*nP] = nuevoProducto;
    (*nP)++;

    printf("Producto agregado correctamente.\n");
}

void eP(Pr *prs, int nP) {
    if (nP == 0) {
        printf("No hay productos para editar.\n");
        return;
    }

    char nombre[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%49s", nombre);

    for (int i = 0; i < nP; i++) {
        if (strcmp(prs[i].nombre, nombre) == 0) {
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &prs[i].cantidad);

            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &prs[i].precio);

            printf("Producto editado correctamente.\n");
            return;
        }
    }

    printf("No se encontró el producto con el nombre ingresado.\n");
}

void delP(Pr *prs, int *nP) {
    if (*nP == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }

    char nombre[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%49s", nombre);

    for (int i = 0; i < *nP; i++) {
        if (strcmp(prs[i].nombre, nombre) == 0) {
            for (int j = i; j < *nP - 1; j++) {
                prs[j] = prs[j + 1];
            }
            (*nP)--;
            printf("Producto eliminado correctamente.\n");
            return;
        }
    }

    printf("No se encontró el producto con el nombre ingresado.\n");
}

void lP(Pr *prs, int nP) {
    if (nP == 0) {
        printf("No hay productos para listar.\n");
        return;
    }

    printf("==== Lista de productos ====\n");
    printf("Nombre\t\tCantidad\tPrecio\n");

    for (int i = 0; i < nP; i++) {
        printf("%s\t\t%d\t\t%.2f\n", prs[i].nombre, prs[i].cantidad, prs[i].precio);
    }
}

void mostrarFactura(Pr *prs, int nP) {
    if (nP == 0) {
        printf("No hay productos en la factura.\n");
        return;
    }

    printf("==== Bienvenido al sistema de facturación de Smart Tech ====\n");
    printf("Producto\t\tCantidad\tPrecio\n");

    float total = 0.0;
    for (int i = 0; i < nP; i++) {
        printf("%s\t\t%d\t\t%.2f\n", prs[i].nombre, prs[i].cantidad, prs[i].precio);
        total += prs[i].precio * prs[i].cantidad;
    }
    printf("Total\t\t\t\t%.2f\n", total);
}
