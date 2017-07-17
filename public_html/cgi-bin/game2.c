/*PÁGINA 2  
  campo para palpite
  resposta caso o valor apostado não for válido*/
#include <stdio.h>
#include <stdlib.h>
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

//Módulo para criar o arquivo com o valor apostado
void criarAposta(float aposta, char *nome)
{
    char aux[20];
    strcpy(aux, nome);
    strcat(aux, "deal.txt");
    FILE *arquivo=fopen(aux, "w");
    fprintf(arquivo, "%f", aposta);
    fclose(arquivo);
}

//Módulo para ler T
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
    
    //Leitura do arquivo de times
    FILE *arquivo = fopen("time.txt", "r");
    T=0;
    while(fscanf(arquivo, "%s", times[T])!=EOF)
    {
        T++;
    }
    fclose(arquivo);
    
    //Lendo a URL
    pData=getenv("QUERY_STRING");
    sscanf(pData, "x=%f&name=%s", &deal, nome);//Leitura da aposta e do nome do jogador

    float money=lerDinheiro(nome);//Declaração e atribuição da variável money

    //Se o dinheiro for menor que 1, o valor da aposta é automáticamente igual o dinheiro
    if(money<1)
    {
        deal=money;
    }

    T=lerT(nome);//Atriuição de T

    //[GERANDO HTML]
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
    if(deal>money)
    {   //A aposta não tem como ser maior que o dinheiro 
        printf("<p>Dinheiro insuficiente. Faça outra aposta</p>");
        printf("<br><form action=\"newaposta.cgi\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    else if(deal<1 && money>=1)
    {   //A aposta mínima é $1
        printf("<p>A aposta mínima é $1. Faça outra aposta</p>");
        printf("<br><form action=\"newaposta.cgi\">");
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);
        printf("<input type=\"submit\" value=\"Continuar\">");
        printf("</form><br>");
    }
    else
    {   //Fluxo padrão:
        printf("<div id=jogo>");
        printf("<h2>%s</h2>", times[T]); //Time
        printf("<b>Dinheiro: $%.2f</b><br>", money); //Dinheiro
        printf("<b>Aposta: $%.2f</b>", deal); //Aposta
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
        printf("<input type=\"hidden\" name=\"name\" value=\"%s\">", nome);//Campo oculto
        printf("</form>");
        printf("</div>");
    }
    printf("<a href=\"http://cap.dc.ufscar.br/~743525/game.html\"><h2>Sair</h2></a>\n");
    printf("</div>");
    printf("</body>");
    printf("</html>");

    criarAposta(deal, nome);//Criar arquivo para guardar a aposta

    return 0;
}
