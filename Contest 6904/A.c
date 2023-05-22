#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int key;
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Cria um novo nó na árvore
Node* criarNo(int chave) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->key = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Insere um nó na árvore
Node* inserir(Node* raiz, int chave) {
    // Se a árvore estiver vazia, cria um novo nó
    if (raiz == NULL)
        return criarNo(chave);

    // Se a chave for menor que a chave da raiz, insere à esquerda
    if (chave < raiz->key)
        raiz->esquerda = inserir(raiz->esquerda, chave);

    // Se a chave for maior que a chave da raiz, insere à direita
    else if (chave > raiz->key)
        raiz->direita = inserir(raiz->direita, chave);

    // Retorna a raiz (sem alterações) caso a chave já exista na árvore
    return raiz;
}

// Busca um nó na árvore
Node* buscar(Node* raiz, int chave) {
    // Se a árvore estiver vazia ou a chave for encontrada na raiz, retorna a raiz
    if (raiz == NULL || raiz->key == chave)
        return raiz;

    // Se a chave for menor que a chave da raiz, busca à esquerda
    if (chave < raiz->key)
        return buscar(raiz->esquerda, chave);

    // Se a chave for maior que a chave da raiz, busca à direita
    return buscar(raiz->direita, chave);
}

// Função para percorrer a árvore em ordem infixa (e-r-d)
int OrdemInfixa(Node* raiz) {
    if (raiz != NULL) {
        OrdemInfixa(raiz->esquerda);
        printf("%d ", raiz->key);
        OrdemInfixa(raiz->direita);
    }
    return 1;
}

// Função para percorrer a árvore em ordem prefixa (r-e-d)
int OrdemPrefixa(Node* raiz) {
   if (raiz != NULL) {
        OrdemPrefixa(raiz->direita);
        OrdemPrefixa(raiz->esquerda);
        printf("%d ", raiz->key);
    }
    return 2;
}

// Função para percorrer a árvore em ordem posfixa (e-d-r)
int OrdemPosfixa(Node* raiz) {
   if (raiz != NULL) {
        OrdemPosfixa(raiz->esquerda);
        OrdemPosfixa(raiz->direita);
        printf("%d ", raiz->key);
    }
    return 3;
}

int main() {
    Node* raiz = NULL;
    int ordem, i;
    char leitura, aux;
    
    while (i = 0; i < MAX; i++) {
        scanf("%c", &leitura);
        if(leitura == 'I') {
            scanf("%c", &aux);
            inserir(aux);
        }
        else if(leitura == 'P') {
            scanf("%c", &aux);
            buscar(aux);
        }
    } 
    
    // Impressão da árvore
    printf("Árvore binária de busca em ordem: ");
    
    ordem = OrdemInfixa(raiz);
    //ordem = OrdemPrefixa(raiz);
    //ordem = OrdemPosfixa(raiz);
    printf("\n");

    return 0;
}
