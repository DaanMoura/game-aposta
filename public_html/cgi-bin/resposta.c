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

int lerT()
{
    int T;
    FILE *arquivo=fopen("T.txt", "r");
    fscanf(arquivo, "%d", &T);
    fclose(arquivo);
    return T;
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
    int A, B, X, Y, T;
    char times[51][50];

    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);

    T=lerT();

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
    printf("<link rel=\"icon\" type=\"image/png\" href=\"http://cap.dc.ufscar.br/~743525/ball.png\"/>");
    printf("<link rel=\"stylesheet\" href=\"http://cap.dc.ufscar.br/~743525/jogo.css\">");
    printf("</head>");
    printf("<body>");
    printf("<div class=fundo>");
    printf("<div class=container>");
    printf("<img src=\"http://cap.dc.ufscar.br/~743525/bolao.png\" width=\"320\" height=\"205\" />");
    printf("</div>");
    printf("<div id=jogo>");
    printf("<h2>%s</h2>", times[T]); //TIME
    printf("<h3>Seu palpite: %d X %d</h3>", X, Y);
    printf("<h3>Resultado: %d X %d</h3>", A, B);
    if(X==A && Y==B)
    {
        printf("<audio autoplay>");
        printf("<source src=\"http://cap.dc.ufscar.br/~743525/acerto.mp3\" type=\"audio/mpeg\">");
        printf("</audio>");
        aux=2*deal;
        printf("Na mosca!\nVocê ganhou $%.2f\n", aux);
    }
    else if(A==B && X==Y)
    {
        printf("<audio autoplay>");
        printf("<source src=\"http://cap.dc.ufscar.br/~743525/acerto.mp3\" type=\"audio/mpeg\">");
        printf("</audio>");
        aux=deal;
        printf("Realmente teve empate.\nVocê ganhou $%.2f\n", aux);
    }
    else if((A>B && X>Y)||(A<B && X<Y))
    {
        printf("<audio autoplay>");
        printf("<source src=\"http://cap.dc.ufscar.br/~743525/acerto.mp3\" type=\"audio/mpeg\">");
        printf("</audio>");
        aux=deal;
        printf("Você acertou o time vencedor.\nVocê ganhou $%.2f\n", aux);
    }
    else if(X!=A || Y!=B)
    {
        printf("<audio autoplay>");
        printf("<source src=\"http://cap.dc.ufscar.br/~743525/erro.mp3\" type=\"audio/mpeg\">");
        printf("</audio>");
        aux=(-1)*deal;
        printf("ERROU!!\nVocê perdeu $%.2f\n", deal);
    }
    money=money+aux;
    if(money<=0)
    {
        printf("<br><a href=lose.cgi>Continuar</a><br>");
    }
    else if(money>=100)
    {
        printf("<br><a href=win.cgi>Continuar</a><br>");
    }
    else
    {
        printf("<br><a href=newgame.cgi>Continuar</a><br>");
    }
    printf("<b>Dinheiro: $%.2f</b>", money);
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    criarDinheiro(money);

    return 0;
}
