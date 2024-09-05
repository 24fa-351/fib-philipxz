#include <stdio.h>
#include <stdlib.h> // atoi() function

unsigned long fibonacci_recursive(int num)
{
   if (num <= 1)
      return num;
   return fibonacci_recursive(num - 1) + fibonacci_recursive(num - 2);
}

unsigned long fibonacci_iterative(int num)
{
   if (num <= 1)
   {
      return num;
   }

   int first_fibonacci_num = 0, second_fibonacci_num = 1, next_fibonacci_num;

   for (int ix = 2; ix <= num; ix++)
   {
      next_fibonacci_num = first_fibonacci_num + second_fibonacci_num;
      first_fibonacci_num = second_fibonacci_num;
      second_fibonacci_num = next_fibonacci_num;
   }

   return second_fibonacci_num;
}

int main(int argc, char *argv[])
{
   int command_line_integer = atoi(argv[1]);
   char command_line_letter = argv[2][0];
   char integer_in_file[100];
   const char *filename = argv[3];


   FILE *file_pointer = fopen(filename, "r");
   fgets(integer_in_file, 100, file_pointer);
   fclose(file_pointer);

   // Subtract 1 as the first number in fibonacci sequence is 0
   int num_to_fibonacci = command_line_integer + atoi(integer_in_file) - 1;
   unsigned long fibonacci_result;

   if (command_line_letter == 'r')
   {
      fibonacci_result = fibonacci_recursive(num_to_fibonacci);
   }
   if (command_line_letter == 'i')
   {
      fibonacci_result = fibonacci_iterative(num_to_fibonacci);
   }

   printf("%lu", fibonacci_result);
   return 0;
}
