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

void limparArquivos(char *nome)
{
    char aux[50];
    strcpy(aux, nome);
    strcat(aux, "money.txt");
    remove(aux);
    strcpy(aux, nome);
    strcat(aux, "T.txt");
    remove(aux);
    strcpy(aux, nome);
    strcat(aux, "deal.txt");
    remove(aux);
    strcpy(aux, nome);
}

int main()
{
    char *pData=NULL;
    char nome[50];
    pData=getenv("QUERY_STRING");
    sscanf(pData,"name=%s", nome);
    float money=lerDinheiro(nome);

    printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);
    printf("<!DOCTYPE html>");
    printf("<html lang=\"pt\">");
    printf("<html>");
    printf("<head>");
    printf("<meta charset=\"utf-8\">");
    printf("<title>Bolão Virtual</title>");
    printf("<link rel=\"icon\" type=\"image/png\" href=\"http://cap.dc.ufscar.br/~743525/ball.png\"/>");
    printf("<link rel=\"stylesheet\" href=\"http://cap.dc.ufscar.br/~743525/win.css\">");
    printf("</head>");
    printf("<body>");
    printf("<div class=fundo>");
    printf("<div class=container>");
    printf("<img src=\"http://cap.dc.ufscar.br/~743525/bolao.png\" width=\"320\" height=\"205\" />");
    printf("</div>");
    printf("<b>Dinheiro: $%.2f</b><br>", money); //Dinheiro
    printf("<h3>YOU WIN</h3>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Início</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    limparArquivos(nome);

    return 0;
}
