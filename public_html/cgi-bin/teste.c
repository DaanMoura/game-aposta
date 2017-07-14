#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int teste;
  srand(time(NULL));
  teste=rand()%100;

  printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);

  printf("<!DOCTYPE html>");

  printf("<html lang=\"en\">");

  printf("<head>");

  printf("<meta charset=\"utf-8\">");
  printf("<title>TESTE!!</title>");

  printf("</head>");

  printf("<body>");

  printf("<!-- page content -->");
  printf("<h1>SOU UMA PÁGINA DE TESTE</h1>");
   printf("<p>Aleatório: %d</p>", teste);

  printf("</body>");

  printf("</html>");

  return 0;
}
