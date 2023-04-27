#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void push_back(Node** head, char data);
int fPalindromo(char* word);

int main() {
    char word[100];
    printf("Bienvenido al revisor de palabras\n");
    printf("Ingrese la palabra: ");
    scanf("%s", word);
    if (fPalindromo(word)) {
        printf("Es un palindromo.\n");
    } else {
        printf("No es un palindromo.\n");
    }
    return 0;
}

void push_back(Node** head, char data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

int fPalindromo(char* word){
    Node* head = NULL;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        push_back(&head, word[i]);
    }
    Node* first = head;
    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    while (first != last && last->next != first) {
        if (first->data != last->data) {
            return 0;
        }
        first = first->next;
        last = last->prev;
    }
    return 1;
}
