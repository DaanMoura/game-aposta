#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *pData=NULL;
    char resposta[512] = {'\n'};
    int x;

    pData=getenv("QUERY_STRING");
    if(pData==NULL)
    {
        snprintf(resposta, sizeof resposta, "Erro\n");
    }
    else if(sscanf(pData, "x=%d", &x)!=1)
    {
        snprintf(resposta, sizeof resposta, "Valor inválido\n");
    }
    else
    {
        if(x>5)
        {
            //printf("Vocês estão muito apaixonados <3\n");
            snprintf(resposta, sizeof resposta, "Vocês estão muito apaixonados <3\n");
        }
        else
        {
            //printf("Você precisa conversar mais com o(a) parceiro(a)\n");
            snprintf(resposta, sizeof resposta, "Você precisa conversar mais com o(a) parceiro(a)\n");
        }
    }

    printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);

    printf("<!DOCTYPE html>");

    printf("<html lang=\"en\">");

    printf("<head>");

    printf("<link rel=\"stylesheet\" href=\"http://cap.dc.ufscar.br/~743525/amor.css\">");

    printf("<meta charset=\"utf-8\">");
    printf("<title>Sum</title>");

    printf("</head>");

    printf("<body>");

    printf("<!-- page content -->");

    printf("%s", resposta);

    printf("</body>");

    printf("</html>");

    return 0;
}
