/*PÁGINA CONDICIONAL(caso a aposta não for válida)
  campo para a aposta*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Módulo para ler o arquivo da variável T
int lerT(char *nome)
{
    char aux[10];
    strcpy(aux, nome);
    strcat(aux, "T.txt");
    int T;
    FILE *arquivo=fopen(aux, "r");
    fscanf(arquivo, "%d", &T);
    fclose(arquivo);
    return T;
}

//Módulo para ler o dinheiro
float lerDinheiro(char *nome)
{
    char aux[10];
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
    char times[51][50], nome[10];
    int T;

    //Lendo a URL
    pData=getenv("QUERY_STRING");
    sscanf(pData, "name=%s", nome);//Leitura do nome

    //Atribuição do dinheiro
    float money=lerDinheiro(nome);

    //Leitura do arquivo de times
    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);

    T=lerT(nome);//Atriuição de T

    //[GERAR HTML]
    printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);
    printf("<!DOCTYPE html>");
    printf("<html lang=\"pt\">");
    printf("<html>");
    //HEAD
    printf("<head>");
    printf("<meta charset=\"utf-8\">");
    printf("<title>Bolão Virtual</title>");
    printf("<link rel=\"icon\" type=\"image/png\" href=\"http://cap.dc.ufscar.br/~743525/ball.png\"/>");
    printf("<link rel=\"stylesheet\" href=\"http://cap.dc.ufscar.br/~743525/jogo.css\">");
    printf("</head>");
    //BODY
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
    printf("<label><input name=\"x\" size=\"3\" required></label><br>");
    printf("<input type=\"submit\" value=\"Apostar\">");
    printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);//Campo oculto
    printf("</form>");
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
}
