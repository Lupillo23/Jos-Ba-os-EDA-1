#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
}typedef node;

struct list{
    node* head;
    size_t count;
}typedef list;

node* create_node(int value){
    node* n = (node*)calloc(1, sizeof(node));
    n->next = NULL;
    return n;
}

list* init_list(){
    list *l = (list*)calloc(1, sizeof(list));
    l->head = NULL;
    l->count = 0;
    return l; // agregar esta línea
}

void insertAtEnd(list *l, int value){
    node *nn = create_node(value);
    nn->value = value;

    if(l->head == NULL){
        nn->next = nn;
        l->head = nn;
    }
    else{
        nn->next = l->head;
        node *last = l->head;
        while(last->next != l->head){
            last = last->next;
        }
        last->next = nn;
    }
    ++l->count;
}

int search(list *l, int key){
    if(l->head == NULL){
        return 0;
    }
    else{
        node* ptr = l->head;
        do{
            if(ptr->value == key) return 1;
            ptr = ptr->next;
        }while(ptr != l->head);
    }
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
    int key;
    list* l = init_list();

    insertAtEnd(l,3);
    insertAtEnd(l,4);
    insertAtEnd(l,5);
    insertAtEnd(l,6);
    insertAtEnd(l,189);
    
    printf("Bienvenido, va a realizar una búsqueda.\n");
    printf("Ingrese el valor buscado:\n");
    scanf("%d",&key);
    
    if(search(l,key) == 1){
        printf("El valor %d se encuentra en la lista.\n", key);
    }
    else{
        printf("El valor %d no se encuentra en la lista.\n", key);
    }
    
    printf("Imprimiendo lista...\n");
    list_print(l);
    return 0;
}
