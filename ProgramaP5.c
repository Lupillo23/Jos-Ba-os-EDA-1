#include<stdio.h>
#include<stdlib.h>

//Cola
typedef struct{
    int* array[10];
    size_t tail;
    size_t count;
} queue;

queue* queue_init();
void enqueue(queue *q, int *value);
int dequeue(queue *q);

//Pila
typedef struct{
    int array[10];
    size_t top;
    size_t count;
} stack;

stack* stack_init();
int stack_empty(stack *s);
int stack_pop(stack *s, int *value);

//Ejecución
int main(){
    int value;
    int opc = 0;
    stack *s = stack_init();
    queue *q = queue_init();
    
    printf("Bienvenido al Sistema de Turnos\n");
    printf("Opciones disponibles:\n");
    printf("1-Formarse\n2-Salir\n");
    scanf("%d",&opc);

    while(opc == 1){
        if(stack_empty(s)){
            printf("Ya no hay turnos disponibles\n");
            printf("Último elemento en el tope de la pila: %d\n", value);
            printf("Último elemento formado en la cola: %d\n", value);
        }
        
        stack_pop(s,&value);
        enqueue(q,&value);
        
        printf("El elemento se encuentra formado en la cola con el turno %d \n", value);
        printf("\n");
        printf("Bienvenido al Sistema de Turnos\n");
        printf("Opciones disponibles:\n");
        printf("1-Formarse\n2-Salir\n");
        scanf("%d",&opc);
    }
    
    printf("Último elemento en el tope de la pila: %d\n", value+1);
    printf("Último elemento formado en la cola: %d\n", value);
    
    free(s);
    return 0;
}

//Inicializar pila
stack* stack_init(){
    stack *s = (stack*)malloc(1 * sizeof(stack));
    s->top = 9;
    s->count = 10;
    for(int i=0; i<10; i++){
        s->array[i] = 10-i;
    }
    return s;
}

//Pila vacía
int stack_empty(stack *s){
    return s->top == -1;
}

//Extraer valor de la pila
int stack_pop(stack *s, int *value){
    if(stack_empty(s)){
        return 0;
    }
    *value = s->array[s->top];
    s->top--;
    s->count--;
    return 1;
}

//Inicializar Cola
queue* queue_init(){
    queue* q = (queue*)calloc(1, sizeof(queue));
    q->tail = 0;
    q->count = 0;
    return q;
}

//Ingresar valor en la cola
void enqueue(queue* q, int *value){
    if(q->count >= 10 ){
        printf("Cola llena");
    }
    else{
        q->array[q->tail] = value;
        q->count++;
        q->tail++;
    }
}

