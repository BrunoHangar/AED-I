#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* esquerda;
    struct Node* direita;
} Node;

Node* criarNo(char data) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = data;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

int procurar(char arr[], int inicio, int fim, char valor) {
    int i;
    for (i = inicio; i <= fim; i++) {
        if (arr[i] == valor)
            return i;
    }
    return -1;
}

Node* construirArvore(char inOrder[], char preOrder[], int inicio, int fim, int* preIndex) {
    if (inicio > fim)
        return NULL;

    Node* novoNo = criarNo(preOrder[*preIndex]);
    (*preIndex)++;

    if (inicio == fim)
        return novoNo;

    int inIndex = procurar(inOrder, inicio, fim, novoNo->data);

    novoNo->esquerda = construirArvore(inOrder, preOrder, inicio, inIndex - 1, preIndex);
    novoNo->direita = construirArvore(inOrder, preOrder, inIndex + 1, fim, preIndex);

    return novoNo;
}

void percorrerPosOrdem(Node* no) {
    if (no == NULL)
        return;

    percorrerPosOrdem(no->esquerda);
    percorrerPosOrdem(no->direita);
    printf("%c", no->data);
}

int main() {
    int C;
    scanf("%d", &C);
    getchar(); // Para consumir o caractere de nova linha após a leitura de C

    while (C--) {
        int N;
        scanf("%d", &N);
        getchar(); // Para consumir o caractere de nova linha após a leitura de N

        char preOrder[N + 1];
        char inOrder[N + 1];
        scanf("%s", preOrder);
        scanf("%s", inOrder);
        getchar(); // Para consumir o caractere de nova linha após a leitura de inOrder

        int preIndex = 0;
        Node* raiz = construirArvore(inOrder, preOrder, 0, N - 1, &preIndex);

        percorrerPosOrdem(raiz);
        printf("\n");

    }

    return 0;
}
