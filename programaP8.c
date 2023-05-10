#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
    struct node* prev;
}typedef node;

struct list{
    node* head;
    size_t count;
}typedef list;

node* create_node(int value){
    node* n = (node*)calloc(1, sizeof(node));
    n->value = value;
    n->next = NULL;
    return n;
}

list* init_list(){
    list *l = (list*)calloc(1, sizeof(list));
    l->head = NULL;
    l->count = 0;
    return l; // agregar esta línea
}

void connect(node *l, node *r){
    if(l) l->next = r;
    if(r) r->prev = l;
}

void insertAtEnd(list *l, int value){
    node *nn = create_node(value);
    nn->value = value;

    if (l->head == NULL) {
        connect(nn, nn);
        l->head = nn;
    } else {
        nn->next = l->head;
        node *last = l->head;
        while (last->next != l->head) {
            last = last->next;
        }
        last->next = nn;
        connect(nn, l->head);
    }
    ++l->count;
}



node* get_node(list* l, int ix){
    if(l->count < 1) return NULL;
    ix %= l->count;
    node* n = l->head;
    for(int i = 0; (i < ix) && (ix >= 0); ++i)
        n = n->next;
    for(int i = 0; (i > ix) && (ix < 0); --i)
        n = n->prev;
    return n;
}

int delete(list* l, int key) {
    if (l->head == NULL) {
        return 0;
    } else {
        node* current = l->head;
        node* previous = NULL;

        // Buscar el nodo con el valor especificado
        do {
            if (current->value == key) {
                // Si es el primer nodo de la lista
                if (previous == NULL) {
                    // Actualizar el puntero de la cabeza de la lista
                    l->head = current->next;

                    // Si la lista solo tenía un elemento
                    if (current->next == current) {
                        l->head = NULL;
                    } else {
                        // Actualizar el enlace del último nodo con el nuevo primer nodo
                        node* last = l->head;
                        while (last->next != current) {
                            last = last->next;
                        }
                        last->next = l->head;
                    }
                } else {
                    // Actualizar los enlaces de los nodos vecinos
                    previous->next = current->next;
                }

                free(current);
                --l->count;
                return 1;
            }

            previous = current;
            current = current->next;
        } while (current != l->head);
    }

    return 0; // El valor no se encontró en la lista
}


void delete_2(int value){
    if(value == 1){
        printf("Eliminación exitosa\n");
    }
    else{
        printf("El valor no existe en la lista.\n");
    }
}

void insert(list* l, int value, int ix) {
    node* nn = create_node(value);
    if (!l->head) {
        connect(nn, nn);
        l->head = nn;
    } else {
        node* n = get_node(l, ix - 1);
        connect(nn, n->next);
        connect(n, nn);
        if (ix == 0) {
            l->head = nn;
        }
    }
    ++l->count;
}

void list_print(list *l){
    if(l->head == NULL){
        printf("La lista está vacía.\n");
        return;
    }
    
    node* temp = l->head;
    
    do{
        printf("%d->", temp->value);
        temp = temp->next;
    }while(temp != l->head);
    
    printf("\n");
}

int main(){
    int op, key, pos;
    list* l = init_list();

    insertAtEnd(l,3);
    insertAtEnd(l,4);
    insertAtEnd(l,5);
    insertAtEnd(l,6);
    insertAtEnd(l,189);
    
    printf("Bienvenido, va a realizar una operación.\n");
    printf("1 Insertar\n2 Eliminar\n");
    scanf("%d", &op);

    switch(op){
        case 1:
            printf("Ingrese el valor a insertar:\n");
            scanf("%d", &key);
            printf("Posición dentro de la pila:\n");
            scanf("%d", &pos);
            insert(l, key, pos);
            break;
        case 2:
            printf("Ingrese el valor a eliminar:\n");
            scanf("%d", &key);
            int aux = delete(l, key);
            delete_2(aux);
            break;
        default:
            fprintf(stderr,"Opción no válida.");
            break;
    }

    printf("Imprimiendo lista...\n");
    list_print(l);
    return 0;
}
