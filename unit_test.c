#include<stdio.h>
#include"my_string.h"
#include"unit_test.h"

int main(int argc, char* argv[])
{
  Status(*tests[])(char*, int) =
        {
           test_init_default_returns_nonNULL,
           test_get_size_on_init_default_returns_0,
           test_get_capacity_on_init_default_returns_8,
           test_does_size_increase_when_you_use_push,
           test_does_capacity_increase_when_you_use_push,
           test_does_push_place_characters_in_correct_spot,
           test_does_pop_reduce_size_correctly,
           test_does_capacity_decrease_when_you_use_pop,
           test_does_push_resize_capacity_correctly,
           test_does_pop_remove_a_character_correctly,
           test_can_c_str_init_handle_weird_characters,
           test_can_compare_handle_pear_vs_pears,
           test_does_at_return_correct_character,
           test_does_init_c_str_resize_properly
        };
  int number_of_functions = sizeof(tests)/sizeof(tests[0]);
  int i;
  char buffer[500];
  int failure_count = 0, success_count=0;

  for(i=0; i<number_of_functions; i++)
  {
        if(tests[i](buffer, 500) == FAILURE)
        {
          printf("FAILED: Test %d failed miserably.\n", i);
          printf("\t%s\n", buffer);
          failure_count++;
        }
        else
        {
          printf("PASS: Test %d PASS\n",i);
          printf("\t%s\n", buffer);
          success_count++;
        }
  }
  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions,
        failure_count, number_of_functions);
  return 0;
}
