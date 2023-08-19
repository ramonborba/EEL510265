#include <cstring>
#include <iostream>

using namespace std;

char * ReverseString(char *pStr){
   int len = strlen(pStr); // numero de caracteres
   char *s = &(pStr[0]); // s aponta para o inicio da string
   char *e = &(pStr[len-1]); // e aponta para o final da string
   char temp;

   do {
      // troca caracteres das extremidades
      temp = *s;
      *s = *e;
      *e = temp;
      // move para dentro da string a partir das extremidades
      ++s;
      --e;
   } while (s < e); // repete ate' a metade da string
   return pStr;
}

int main() {
   char str[30];
   strcpy(str, "Esta eh uma string de teste.");
   char *ch = &str[0];
   for (unsigned i = 0; i < strlen(str); i++)
      cout << *ch++;
   cout << endl << endl << ReverseString(str) << endl;
   return 0;
}
