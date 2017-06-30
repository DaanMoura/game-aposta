#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A, B, X, Y;
    float money, deal, aux;
    //Começa com um dinheiro aleatório de $10 a $100
    //Objetivo: conseguir $1000
    //O jogo é de apostas
    //Se acertar o resultado exato ganha o que apostou
    //Se acertar pelo menos o time ganhador(ou se houve empate) ganha a metade da aposta
    //Se errar tudo, perde o que apostou
    //Perde se zerar o dinheiro
    //Ganha se conseguir o objetivo($1000)

    srand(time(NULL));
    money=rand()%91 + 10;
    do
    {
        printf("Dinheiro: $%.2f\n", money);
        if(money<1)
        {
            deal=money;
            printf("Você tem menos que $1\nAposta automática: $%.2f\n", deal);
        }
        else
        {
            printf("Faça a sua aposta:\n  >> ");
            scanf("%f", &deal);
            while(deal>money || deal<1)
            {
                if(deal>money)
                {
                    printf("Dinheiro insuficiente. Faça outra aposta\n  >> ");
                }
                else
                {
                    printf("A aposta mínima é $1. Faça outra aposta\n  >> ");
                }
                scanf("%f", &deal);
            }
        }

        A=rand()%5;
        B=rand()%5;

        printf("Qual o seu palpite?\n  >> ");
        scanf("%d %d", &X, &Y);

        printf("Placar: %d x %d\n", A, B);
        if(X==A && Y==B)
        {
            aux=deal;
            printf("Na mosca!\nVocê ganhou $%.2f\n", aux);
        }
        else if(A==B && X==Y)
        {
            aux=deal/2;
            printf("Realmente teve empate.\nVocê ganhou $%.2f\n", aux);
        }
        else if((A>B && X>Y)||(A<B && X<Y))
        {
            aux=deal/2;
            printf("Você acertou o time vencedor.\nVocê ganhou $%.2f\n", aux);
        }
        else if(X!=A || Y!=B)
        {
            aux=(-1)*deal;
            printf("Que pena...\nVocê perdeu $%.2f\n", deal);
        }

        money=money+aux;
        printf("\n---------\n");

    }while(money>0 && money<1000);
    if(money<=0)
    {
        printf("GAME OVER\n");
        printf("Dinheiro: $%.2f\n", money);
    }
    if(money>=1000)
    {
        printf("YOU WIN\n");
        printf("Dinheiro: $%.2f\n", money);
    }

    return 0;
}
