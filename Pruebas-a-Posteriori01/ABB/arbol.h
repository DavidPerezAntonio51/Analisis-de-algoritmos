struct Nodo
{
    int valor;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Nodo *nuevoNodo(int dato);

void insertar(struct Nodo *nodo, int dato);

void inorden (struct Nodo* nodo,int *A, int *i);