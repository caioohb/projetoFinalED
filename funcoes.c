#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar um novo nó com a chave fornecida
struct TreeNode* criarNo(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

// Função para inserir um valor na posição apropriada na ABB
struct TreeNode* inserir(struct TreeNode* root, int key) {
    if (root == NULL) {
        return criarNo(key);
    }

    if (key < root->key) {
        root->left = inserir(root->left, key);
    } else if (key > root->key) {
        root->right = inserir(root->right, key);
    }

    return root;
}

// Função para encontrar o nó com o valor mínimo na ABB
struct TreeNode* encontrarMinimo(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Função para remover um nó com a chave fornecida da ABB
struct TreeNode* removerNo(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = removerNo(root->left, key);
    } else if (key > root->key) {
        root->right = removerNo(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = encontrarMinimo(root->right);
        root->key = temp->key;
        root->right = removerNo(root->right, temp->key);
    }

    return root;
}

// Função para buscar um valor na ABB e retornar verdadeiro se encontrado, falso caso contrário
int buscar(struct TreeNode* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (root->key == key) {
        return 1;
    } else if (key < root->key) {
        return buscar(root->left, key);
    } else {
        return buscar(root->right, key);
    }
}

// Função para percorrer a árvore em ordem (inorder)
void percorrerEmOrdem(struct TreeNode* root) {
    if (root != NULL) {
        percorrerEmOrdem(root->left);
        printf("%d ", root->key);
        percorrerEmOrdem(root->right);
    }
}

// Função para percorrer a árvore em pré-ordem (preorder)
void percorrerPreOrdem(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        percorrerPreOrdem(root->left);
        percorrerPreOrdem(root->right);
    }
}

// Função para percorrer a árvore em pós-ordem (postorder)
void percorrerPosOrdem(struct TreeNode* root) {
    if (root != NULL) {
        percorrerPosOrdem(root->left);
        percorrerPosOrdem(root->right);
        printf("%d ", root->key);
    }
}

// Função para encontrar o valor mínimo presente na ABB
int encontrarValorMinimo(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }
    return root->key;
}

// Função para encontrar o valor máximo presente na ABB
int encontrarValorMaximo(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }
    return root->key;
}

// Função para liberar a memória alocada para os nós da árvore
void liberarArvore(struct TreeNode* root) {
    if (root != NULL) {
        liberarArvore(root->left);
        liberarArvore(root->right);
        free(root);
    }
}
