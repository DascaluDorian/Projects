#include <stdio.h>
#include <string.h>

void find_frequency(char [], int [], int *nummber);

int main()
{
   char string[100];
   int c, count[26] = {0};
   int number=0;

   printf("Input a string\n");
   gets(string);

   find_frequency(string, count, &number);

   printf("Character Count\n");

   for (c = 0 ; c < 26 ; c++)
        if(count[c] != 0)
        {
            printf("%c \t  %d \n", c + 'a', (count[c]*100)/number);
        }


   return 0;
}

void find_frequency(char s[], int count[], int *number) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z' )
      {
        count[s[c]-'a']++;
        *number=*number+1;
      }
      c++;
   }
}
