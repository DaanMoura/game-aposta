#include <stdio.h>
#include <stdlib.h>
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

void criarAposta(float aposta, char *nome)
{
    char aux[20];
    strcpy(aux, nome);
    strcat(aux, "deal.txt");
    FILE *arquivo=fopen(aux, "w");
    fprintf(arquivo, "%f", aposta);
    fclose(arquivo);
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

int main()
{
    char *pData=NULL;
    float deal;
    int T;
    char times[51][50], nome[50];

    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);

    pData=getenv("QUERY_STRING");
    sscanf(pData, "x=%f&name=%s", &deal, nome);

    float money=lerDinheiro(nome);

    if(money>=1)
    {

    }
    else
    {
        deal=money;
    }

    T=lerT(nome);

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
    if(deal>money)
    {
        printf("<p>Dinheiro insuficiente. Faça outra aposta</p>");
        printf("<br><form action=\"newaposta.cgi\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    else if(deal<1 && money>=1)
    {
        printf("<p>A aposta mínima é $1. Faça outra aposta</p>");
        printf("<br><form action=\"newaposta.cgi\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    else
    {
        printf("<div id=jogo>");
        printf("<h2>%s</h2>", times[T]); //TIME
        printf("<b>Dinheiro: $%.2f</b><br>", money); //Dinheiro
        printf("<b>Aposta: $%.2f</b>", deal);
        //Formulario
        printf("<form action=\"resposta.cgi\">");
        printf("Qual o seu palpite?<br>");
        printf("<select name=\"a\">");
        printf("<option value=\"0\" selected>0");
        printf("<option value=\"1\">1");
        printf("<option value=\"2\">2");
        printf("<option value=\"3\">3");
        printf("<option value=\"4\">4");
        printf("</select>x");
        printf("<select name=\"b\">");
        printf("<option value=\"0\" selected>0");
        printf("<option value=\"1\">1");
        printf("<option value=\"2\">2");
        printf("<option value=\"3\">3");
        printf("<option value=\"4\">4");
        printf("</select>");
        printf("<br>");
        printf("<input type=\"submit\" value=\"Vai!\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("</form>");
        printf("</div>");
    }
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    criarAposta(deal, nome);

    return 0;
}
