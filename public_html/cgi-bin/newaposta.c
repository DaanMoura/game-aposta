#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int main()
{
    char *pData=NULL;
    char times[51][50], nome[50];
    int T;
    //int i;

    pData=getenv("QUERY_STRING");
    sscanf(pData, "name=%s", nome);

    float money=lerDinheiro(nome);


    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);


    //T=rand()%11;
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
    printf("<div id=jogo>");
    printf("<h2>%s</h2>", times[T]); //TIME
   	printf("<b>Dinheiro: $%.2f</b>", money); //Dinheiro
    //Formulario
    printf("<form action=\"game2.cgi\">");
    printf("Qual a sua aposta?<br>");
    printf("<label><input name=\"x\" size=\"3\"></label><br>");
    printf("<input type=\"submit\" value=\"Apostar\">");
    printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
    printf("</form>");
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
}
