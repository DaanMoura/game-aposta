#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  char* pData = NULL;
  char response[512] = {'\n'};
  int x, y;

  int teste;
  srand(time(NULL));
  teste=rand()%100;

  pData = getenv("QUERY_STRING");
  if (pData == NULL) {

    snprintf(response, sizeof response, "Error parsing the data.\n");
  } else if (sscanf(pData,
                    "x=%d&y=%d",
                    &x,
                    &y) != 2) {

    snprintf(response, sizeof response, "Invalid input: the values must be numeric.\n");
  } else {

    snprintf(response, sizeof response, "%d + %d = %d.\n", x, y, x + y);
  }

  printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);

  printf("<!DOCTYPE html>");

  printf("<html lang=\"en\">");

  printf("<head>");

  printf("<meta charset=\"utf-8\">");
  printf("<title>Sum</title>");

  printf("</head>");

  printf("<body>");

  printf("<!-- page content -->");
  printf("%s", response);
  printf("<br>Aleatório: %d", teste);

  printf("</body>");

  printf("</html>");

  return 0;
}
