#include "lib.h"

void menu()
{
    int op, valor;

    //--------- iniciando a estrutura --------------------//
    Tno *arvore = NULL;

    do
    {
        //--------------- Exibir menu ---------------------//
        system("cls");
        puts("\n\t\t\t\tARVORE BINARIA BALANCEADA - AVL\n");
        puts("\t1  - INSERIR ELEMENTO\n \t2  - IMPRIMIR ARVORE\n\t0  - SAIR");
        printf("\nINFORME SUA OPCAO:\n");
        scanf("%d", &op); // Escolha da Opção

        switch (op)
        {
        case 1:
        {
            printf("Informe um elemento: ");
            scanf("%d", &valor);
            arvore = inserir(arvore, valor);
            imprime(arvore);
            break;
        }

        case 2:
        {
            imprime(arvore);
            break;
        }

        default:
            puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
            break;
        }
    } while (op != 0);
}

int altura_AVL(Tno *a)
{
    int alt_esq = 0, alt_dir = 0;
    if (a == NULL)
        return 0;
    else
    {
        alt_esq = altura_AVL(a->esq);
        alt_dir = altura_AVL(a->dir);

        if (alt_esq > alt_dir)
            return (1 + alt_esq);

        else
        {
            return (1 + alt_dir);
        }
    }
}

int calcula_FB(Tno *a)
{
    return (altura_AVL(a->esq) - altura_AVL(a->dir));
}

Tno *rotacao_simples_esquerda(Tno *a)
{
}
Tno *rotacao_simples_direita(Tno *a)
{
}
Tno *balanceio_esquerda(Tno *a)
{
}

Tno *balanceio_direita(Tno *a)
{
}
Tno *balanceamento(Tno *a)
{
    int fator = calcula_FB(a);
    if(fator > 1)
        return balanceio_esquerda(a);
    else if(fator<-1)
        return balanceio_direita(a);
    else
    return a

}
Tno *inserir(Tno *a, int elemento)
{
    if (a == NULL) // Se tiver elemento na árvore
    {
        (Tno *)malloc(sizeof(Tno));
        a->elemento = elemento;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }
    else // tem elemento
    {
        if (a->elemento > elemento)
            a->esq = inserir(a->esq, elemento);
        else
            a->dir = inserir(a->dir, elemento);

        a = balanceamento(a);
    }
}

void imprime(Tno *a)
{
    if (a == NULL)
    {
        return;
    }
    printf("%d", a->elemento);

    if (a->esq != NULL)
        printf("(E:%d)", a->esq->elemento);
    if (a->dir != NULL)
        printf("(D:%d)", a->dir->elemento);
    printf("\n");

    imprime(a->esq);
    imprime(a->dir);
}
