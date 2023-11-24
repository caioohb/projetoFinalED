#ifndef FUNCOES_H
#define FUNCOES_H

// Definição da estrutura de um nó da árvore binária de busca (ABB)
struct TreeNode {
    int key;                 // Valor do nó
    struct TreeNode* left;   // Ponteiro para o filho esquerdo
    struct TreeNode* right;  // Ponteiro para o filho direito
};

// Protótipo da função para criar um novo nó com a chave fornecida
struct TreeNode* criarNo(int key);

// Protótipo da função para inserir um valor na posição apropriada na ABB
struct TreeNode* inserir(struct TreeNode* root, int key);

// Protótipo da função para encontrar o nó com o valor mínimo na ABB
struct TreeNode* encontrarMinimo(struct TreeNode* root);

// Protótipo da função para remover um nó com a chave fornecida da ABB
struct TreeNode* removerNo(struct TreeNode* root, int key);

// Protótipo da função para buscar um valor na ABB e retornar verdadeiro se encontrado, falso caso contrário
int buscar(struct TreeNode* root, int key);

// Protótipo da função para percorrer a árvore em ordem (inorder)
void percorrerEmOrdem(struct TreeNode* root);

// Protótipo da função para percorrer a árvore em pré-ordem (preorder)
void percorrerPreOrdem(struct TreeNode* root);

// Protótipo da função para percorrer a árvore em pós-ordem (postorder)
void percorrerPosOrdem(struct TreeNode* root);

// Protótipo da função para encontrar o valor mínimo presente na ABB
int encontrarValorMinimo(struct TreeNode* root);

// Protótipo da função para encontrar o valor máximo presente na ABB
int encontrarValorMaximo(struct TreeNode* root);

// Protótipo da função para liberar a memória alocada para os nós da árvore
void liberarArvore(struct TreeNode* root);

#endif
