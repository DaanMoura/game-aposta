#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float lerDinheiro()
{
    float money;
    FILE *arquivo = fopen("money.txt", "r");
    fscanf(arquivo, "%f", &money);
    fclose(arquivo);
    return money;
}

float lerAposta()
{
    float deal;
    FILE *arquivo=fopen("deal.txt", "r");
    fscanf(arquivo, "%f", &deal);
    fclose(arquivo);
    return deal;
}

void criarDinheiro(float money)
{
    FILE *arquivo=fopen("money.txt", "w");
    fprintf(arquivo, "%f", money);
    fclose(arquivo);
}

int main()
{
    float deal=lerAposta();
    float money=lerDinheiro();
    float aux;
    int A, B, X, Y;

    srand(time(NULL));
    A=rand()%5;
    B=rand()%5;

    char *pData=NULL;
    pData=getenv("QUERY_STRING");
    sscanf(pData,"a=%d&b=%d", &X, &Y);

    printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);
    printf("<!DOCTYPE html>");
    printf("<html lang=\"pt\">");
    printf("<html>");
    printf("<head>");
    printf("<meta charset=\"utf-8\">");
    printf("<title>Bolão Virtual</title>");
    printf("<link rel=\"stylesheet\" href=\"http://cap.dc.ufscar.br/~743525/game.css\">");
    printf("</head>");
    printf("<body>");
    printf("<div class=fundo>");
    printf("<h1>Bolão Virtual</h1>");
    printf("<div id=jogo>");
    printf("<h3>Seu palpite: %d X %d</h3>", X, Y);
    printf("<h3>Resultado: %d X %d</h3>", A, B);
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
    if(money<=0)
    {
        printf("<h2>GAME OVER</h2>");
    }
    else if(money>=1000)
    {
        printf("<h2>YOU WIN!!</h2>");
    }
    else
    {
        printf("<br><a href=newgame.cgi>Continuar</a><br>");
    }
    printf("<b>Dinheiro: $%.2f</b>", money);
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Início</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    criarDinheiro(money);

    return 0;
}
