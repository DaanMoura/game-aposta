/*PÁGINA INICIAL DA NOVA PARTIDA
  campo para aposta
  ou aposta automática
  sorteia uma linha do arquivo de times*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Módulo para ler o arquivo que o dinheiro está armazenado
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

//Módulo para criar arquivo da variável T
void criarT(int T, char *nome)
{
    char aux[20];
    strcpy(aux, nome);
    strcat(aux, "T.txt");
    FILE *arquivo=fopen(aux, "w");
    fprintf(arquivo, "%d", T);
    fclose(arquivo);
}

int main()
{
    char *pData=NULL;
    char times[51][50], nome[50];
    int T;

    //Lendo a URL
    pData=getenv("QUERY_STRING");
    sscanf(pData, "name=%s", nome);

    float money=lerDinheiro(nome);//Declaração e atribuição da variável money

    //Lendo o arquivo de times
    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);

    //Sorteio de T(linha a ser lida de time.txt) e chamada da função
    srand(time(NULL));
    T=rand()%11;
    criarT(T, nome);

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
    //audio
    printf("<audio volume=\"0.1\" autoplay>");
    printf("<source src=\"http://cap.dc.ufscar.br/~743525/apito.mp3\" type=\"audio/mpeg\">");
    printf("</audio>");
    printf("<div class=fundo>");
    printf("<div class=container>");
    printf("<img src=\"http://cap.dc.ufscar.br/~743525/bolao.png\" width=\"320\" height=\"205\" />");
    printf("</div>");
    printf("<div id=jogo>");
    printf("<h2>%s</h2>", times[T]); //TIME
   	printf("<b>Dinheiro: $%.2f</b>", money); //Dinheiro
    //Formulario
    if(money<1)
    {   //Caso o dinheiro for menor que $1, a aposta é automaticamente o valor do dinheiro(ver game2.c linha 68)
        printf("<p>Você tem menos que $1.<br>Aposta automática: <b>$%.2f</b></p>", money);
        printf("<br><form action=\"game2.cgi\">");
	    printf("<input type=\"hidden\" name=\"x\" value=\"%f\">", money);
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    else
    {   //Fluxo padrão
        printf("<form action=\"game2.cgi\">");
        printf("Qual a sua aposta?<br>");
        printf("<label><input name=\"x\" size=\"3\"></label><br>");
        printf("<input type=\"submit\" value=\"Apostar\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("</form>");
    }
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
}
