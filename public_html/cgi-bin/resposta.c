#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float lerDinheiro(char *nome)
{
    char aux[20];
    strcpy(aux, nome);
    strcat(aux, "money.txt");
    float money;
    FILE *arquivo = fopen(aux, "r");
    fscanf(arquivo, "%f", &money);
    fclose(arquivo);
    return money;
}

int lerT(char *nome)
{
    char aux[20];
    strcpy(aux, nome);
    strcat(aux, "T.txt");
    int T;
    FILE *arquivo=fopen(aux, "r");
    fscanf(arquivo, "%d", &T);
    fclose(arquivo);
    return T;
}

float lerAposta(char *nome)
{
    char aux[20];
    strcpy(aux, nome);
    strcat(aux, "deal.txt");
    float deal;
    FILE *arquivo=fopen(aux, "r");
    fscanf(arquivo, "%f", &deal);
    fclose(arquivo);
    return deal;
}

void criarDinheiro(float money, char *nome)
{
    char aux[20];
    strcpy(aux, nome);
    strcat(aux, "money.txt");
    FILE *arquivo=fopen(aux, "w");
    fprintf(arquivo, "%f", money);
    fclose(arquivo);
}

int main()
{
    char *pData=NULL;
    char nome[50];
    int A, B, X, Y, T;
    pData=getenv("QUERY_STRING");
    sscanf(pData,"a=%d&b=%d&name=%s", &X, &Y, nome);

    float deal=lerAposta(nome);
    float money=lerDinheiro(nome);
    float aux;
    char times[51][50];

    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);

    T=lerT(nome);

    srand(time(NULL));
    A=rand()%5;
    B=rand()%5;

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
        printf("<br><form action=\"lose.cgi\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    else if(money>=100)
    {
        printf("<br><form action=\"win.cgi\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    else
    {
        printf("<br><form action=\"newgame.cgi\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    printf("<b>Dinheiro: $%.2f</b>", money);
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    criarDinheiro(money, nome);

    return 0;
}
