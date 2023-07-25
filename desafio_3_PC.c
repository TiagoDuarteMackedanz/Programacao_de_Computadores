//Tiago Duarte Mackedanz - Turma: M11 - Programação de Computadores

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Struct Produto
typedef struct produto {
    char nome[50];
    double preco;
    int id;
    struct produto *prox;
} Produto;

//Declarando Funcoes
void adicionarProduto(Produto **lista);
void removerProduto(Produto **lista);
void imprimirLista(Produto *lista);
void carregarLista(Produto **lista);
void salvarLista(Produto *lista);
void liberarLista(Produto **lista);

//Funcao Principal
int main() {
    Produto *lista = NULL;
    int menu;

    printf("Gerenciador de Produtos:\n");

    do {
        printf("\n #1# - Adicionar Produto\n #2# - Remover Produto\n #3# - Imprimir Lista\n #4# - Carregar Lista do Arquivo 'produtos.bin'\n #5# - Salvar Lista Atual no Arquivo 'produtos.bin'\n #0# - Sair\n");
        printf("\nDigite a Opcao Desejada: ");
        scanf("%d", &menu);

    switch (menu) {
    case 1:
        printf("\n#1# - Adicionar Produto:\n");
        adicionarProduto(&lista);
        break;
    case 2:
        printf("\n#2# - Remover Produto:\n");
        removerProduto(&lista);
        break;
    case 3:
        printf("\n#3# - Imprimir Lista:\n");
        imprimirLista(lista);
        break;
    case 4:
        printf("\n#4# - Carregar Lista do Arquivo 'produtos.bin':\n");
        liberarLista(&lista);
        carregarLista(&lista);
        break;
    case 5:
        printf("\n#5# - Salvar Lista Atual no Arquivo 'produtos.bin':\n");
        salvarLista(lista);
        break;
    case 0:
        liberarLista(&lista);
        printf("\nPrograma Encerrado.\n");
        break;
    default:
        if ((menu<0) || (menu>5)) {
		printf("\nNenhuma Operacao Valida Selecionada!\n");
		}
        break;
    }
    } 
    while (menu!=0);
    printf("Voce Saiu!\n");
    
    return 0;
}

//Funcao #1# - Adicionar Produto
void adicionarProduto(Produto **lista) {
    Produto *p, *novo;
    novo = (Produto*) malloc(sizeof(Produto));
    printf("\nDigite o Nome do Produto: ");
    scanf("%s", novo->nome);
    printf("Digite o Preco do Produto: ");
    scanf("%lf", &novo->preco);
    printf("Digite o ID do Produto: ");
    scanf("%d", &novo->id);
    novo->prox = NULL;
    if (*lista == NULL || novo->preco <= (*lista)->preco) {
        novo->prox = *lista;
        *lista = novo;
    } else {
        p = *lista;
        while (p->prox != NULL && p->prox->preco < novo->preco) {
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
    }
    printf("\nProduto Adicionado com Sucesso!\n");
}

//Funcao #2# - Adicionar Remover Produto
void removerProduto(Produto **lista) {
    Produto *p, *anterior = NULL;
    int id;
    printf("\nDigite o ID do Produto a ser Removido: ");
    scanf("%d", &id);
    p = *lista;
    while (p != NULL && p->id != id) {
        anterior = p;
        p = p->prox;
    }
    if (p == NULL) {
        printf("\nProduto nao Encontrado na Lista.\n");
        return;
    }
    if (anterior == NULL) {
        *lista = p->prox;
    } else {
        anterior->prox = p->prox;
    }
    free(p);
    printf("\nProduto Removido com Sucesso!\n");
}

//Funcao #3# - Imprimir Produto
void imprimirLista(Produto *lista) {
    Produto *p;
    printf("\nLista de Produtos em Ordem Crescente de Preco:\n");
    for (p = lista; p != NULL; p = p->prox) {
        printf("\nNome: %s\nPreco: %.2lf\nID: %d\n", p->nome, p->preco, p->id);
    }
}

//Funcao #4# - Carregar Lista do Arquivo "produtos.bin"
void carregarLista(Produto **lista) {
    FILE *arquivo;
    Produto *p, *novo;

    if ((arquivo = fopen("produtos.bin", "rb")) == NULL) {
        printf("\nErro ao Abrir Arquivo 'produtos.bin'.\n");
        return;
    }

    while (!feof(arquivo)) {
        novo = (Produto*) malloc(sizeof(Produto));
        if (novo == NULL) {
            printf("\nErro ao alocar memória para novo produto.\n");
            break;
        }

        if (fread(novo, sizeof(Produto), 1, arquivo) != 1) {
            free(novo); 
            break;
        }

        novo->prox = NULL;

        if (*lista == NULL || novo->preco <= (*lista)->preco) {
            novo->prox = *lista;
            *lista = novo;
        } else {
            p = *lista;
            while (p->prox != NULL && p->prox->preco < novo->preco) {
                p = p->prox;
            }
            novo->prox = p->prox;
            p->prox = novo;
        }
    }
    printf("\nLista Carregada com Sucesso!\n");
    fclose(arquivo);
}

//Funcao #5# - Salvar Lista Atual no Arquivo "produtos.bin"
void salvarLista(Produto *lista) {

    FILE *arquivo;
    Produto *p;

    if ((arquivo = fopen("produtos.bin", "wb")) == NULL) {
        printf("\nErro ao Criar Arquivo 'produtos.bin'.\n");
        return;
    }

    for (p = lista; p != NULL; p = p->prox) {
        if (fwrite(p, sizeof(Produto), 1, arquivo) != 1) {
            printf("\nErro ao Escrever no Arquivo 'produtos.bin'.\n");
            fclose(arquivo);
            return;
        }
    }
    fclose(arquivo);
    printf("\nLista salva com sucesso!\n");
}

//Funcao #0# - Programa Encerrado
void liberarLista(Produto **lista) {
    Produto *p, *prox;
    for (p = *lista; p != NULL; p = prox) {
        prox = p->prox;
        free(p);
    }
    *lista = NULL;
}
