#include <stdio.h>
#include "my_string.h"
//remember that :colorscheme default will stop this madness

int main(int argc, char* argv[])
{
   MY_STRING hWord;

   hWord =  my_string_init_c_str("The quick brown fox jumped over the lazy dogs.");
   printf("%d/%d : %s\n", hWord->get_size(hWord), hWord->get_capacity(hWord),
      hWord->c_str(hWord));
   hWord->push_back(hWord, '!');
   hWord->push_back(hWord, '!');
   printf("%d/%d : %s\n", hWord->get_size(hWord), hWord->get_capacity(hWord),
      hWord->c_str(hWord));
   hWord->pop_back(hWord);
   printf("%d/%d : %s\n", hWord->get_size(hWord), hWord->get_capacity(hWord),
      hWord->c_str(hWord));

   printf("The character at index 4 is: %c\n", *hWord->at(hWord, 4));

   printf("Type at least 2 words separated by spaces: ");
   hWord->extraction(hWord, stdin);
   printf("%d/%d : %s\n", hWord->get_size(hWord), hWord->get_capacity(hWord),
      hWord->c_str(hWord));
   hWord->extraction(hWord, stdin);
   printf("%d/%d : %s\n", hWord->get_size(hWord), hWord->get_capacity(hWord),
      hWord->c_str(hWord));

   hWord->destroy(&hWord);
   return 0;
}
