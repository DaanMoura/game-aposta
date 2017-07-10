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

int main()
{
    char times[51][50];
    int T;
    float money=lerDinheiro();
    srand(time(NULL));

    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);


    T=rand()%11;
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
    printf("<h2>%s</h2>", times[T]); //TIME
   	printf("<b>Dinheiro: $%.2f</b>", money); //Dinheiro
    //Formulario
    if(money<1)
    {
        printf("<p>Você tem menos que $1.<br>Aposta automática: <b>$%.2f</b></p>", money);
        printf("<a href=\"game2.cgi\">Continuar</a>");
    }
    else
    {
        printf("<form action=\"game2.cgi\">");
        printf("Qual a sua aposta?<br>");
        printf("<label><input name=\"x\" size=\"3\"></label><br>");
        printf("<input type=\"submit\" value=\"Apostar\">");
        printf("</form>");
    }
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Início</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
}
