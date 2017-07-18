/*PÁGINA 1
  Gera dinheiro aletório
  Campo para aposta*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
    char times[51][50];
    int T; //T irá informar a linha arquivo time.txt
    char nome[50], aux[50];
    float money;

    //Lendo a URL
    pData=getenv("QUERY_STRING");
    sscanf(pData, "name=%s", nome); //Armazenando o nome
    
    //Lendo o arquivo de times
    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);
    
    //Sorteando o dinheiro
    srand(time(NULL));
    money=rand()%31 + 30;

    //Criando o arquivo que guardará o dinheiro
    strcpy(aux, nome);
    strcat(aux, "money.txt");
    FILE *pMoney = fopen(aux, "w");
    fprintf(pMoney, "%f", money);
    fclose(pMoney);

    //Sorteio de T(linha a ser lida de time.txt) e chamada da função
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
    printf("<audio autoplay>");
    printf("<source src=\"http://cap.dc.ufscar.br/~743525/start.mp3\" type=\"audio/mpeg\">");
    printf("</audio>");
    printf("<div class=fundo>");
    printf("<div class=container>");
    printf("<img src=\"http://cap.dc.ufscar.br/~743525/bolao.png\" width=\"320\" height=\"205\" />");
    printf("</div>");
    printf("<div id=jogo>");
    printf("<h2>%s</h2>", times[T]); //TIME
   	printf("<b>Dinheiro: $%.2f</b>", money); //Dinheiro
    //formulario
    printf("<form action=\"game2.cgi\">");
    printf("Qual a sua aposta?<br>");
    printf("<label><input name=\"x\" size=\"3\"></label><br>");
    printf("<input type=\"submit\" value=\"Apostar\">");
    printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);//Campo oculto para passar o nome pra URL da próxima página
    printf("</form>");
    printf("</div>");
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
}
