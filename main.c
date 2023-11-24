#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main() {
    // Ponteiro para o nó raiz da árvore
    struct TreeNode* root = NULL;

    // Variáveis para armazenar a escolha do usuário e o valor a ser manipulado
    int choice, key;

    do {
        // Menu de operações
        printf("\nEscolha uma operacao:\n");
        printf("1. Inserir valor\n");
        printf("2. Remover valor\n");
        printf("3. Buscar valor\n");
        printf("4. Percorrer em ordem\n");
        printf("5. Percorrer pre-ordem\n");
        printf("6. Percorrer pos-ordem\n");
        printf("7. Encontrar valor minimo\n");
        printf("8. Encontrar valor maximo\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &choice);

        // Executar a operação escolhida pelo usuário
        switch (choice) {
            case 1:
                // Inserir valor na árvore
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &key);
                root = inserir(root, key);
                break;
            case 2:
                // Remover valor da árvore
                printf("Digite o valor a ser removido: ");
                scanf("%d", &key);
                root = removerNo(root, key);
                break;
            case 3:
                // Buscar valor na árvore
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &key);
                if (buscar(root, key)) {
                    printf("%d encontrado na arvore.\n", key);
                } else {
                    printf("%d nao encontrado na arvore.\n", key);
                }
                break;
            case 4:
                // Percorrer a árvore em ordem
                printf("Percorrendo a arvore em ordem: ");
                percorrerEmOrdem(root);
                printf("\n");
                break;
            case 5:
                // Percorrer a árvore em pré-ordem
                printf("Percorrendo a arvore em pre-ordem: ");
                percorrerPreOrdem(root);
                printf("\n");
                break;
            case 6:
                // Percorrer a árvore em pós-ordem
                printf("Percorrendo a arvore em pos-ordem: ");
                percorrerPosOrdem(root);
                printf("\n");
                break;
            case 7:
                // Encontrar o valor mínimo na árvore
                printf("Valor minimo na arvore: %d\n", encontrarValorMinimo(root));
                break;
            case 8:
                // Encontrar o valor máximo na árvore
                printf("Valor maximo na arvore: %d\n", encontrarValorMaximo(root));
                break;
            case 0:
                // Sair do programa
                break;
            default:
                // Opção inválida
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (choice != 0);

    // Liberação de memória
    liberarArvore(root);

    return 0;
}
