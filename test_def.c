#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"unit_test.h"
#include"my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if (hString == NULL)
  {
        hString->destroy(&hString);
        strncpy(buffer, "test_init_default_returns_nonNULL\n"
                        "my_string_init_default returns NULL", length);
        return FAILURE;
  }
  else
  {
        hString->destroy(&hString);
        strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
        return SUCCESS;
  }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  if (hString->get_size(hString) != 0)
  {
        status = FAILURE;
        printf("Expected a size of 0 but got %d\n", hString->get_size(hString));
        strncpy(buffer, "test_get_size_init_default_returns_0\n"
                "Did not receive 0 from get_size after init_default", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_get_size_init_default_returns_0\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_get_capacity_on_init_default_returns_8(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  if (hString->get_capacity(hString) != 8)
  {
        status = FAILURE;
        printf("Expected a capacity of 8 but got %d\n", hString->get_capacity(hString));
        strncpy(buffer, "test_get_capacity_on_init_default_returns_8\n"
                "Did not receive 8 from get_capacity after init_default", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_get_capacity_on_init_default_returns_8\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_does_size_increase_when_you_use_push(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int first, second;

  hString = my_string_init_default();
  first = hString->get_size(hString);
  hString->push_back(hString, 'a');
  second = hString->get_size(hString);
  if (first != (second-1))
  {
        status = FAILURE;
        printf("Expected size to increase by one but got %d\n", (second-first));
        strncpy(buffer, "test_does_size_increase_when_you_use_push\n"
                "Did not receive a size increase of one", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_size_increase_when_you_use_push\n", length);
  }
hString->destroy(&hString);
return status;
}
Status test_does_capacity_increase_when_you_use_push(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
 int first, second;

  hString = my_string_init_default();
  first = hString->get_capacity(hString);
  hString->push_back(hString, 'a');
  second = hString->get_capacity(hString);
  if (first != second)
  {
        status = FAILURE;
        printf("Expected capacity to remain the same but got %d\n", (second-first));
        strncpy(buffer, "test_does_capacity_increase_when_you_use_push\n"
                "Capacity did not remain the same", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_capacity_increase_when_you_use_push\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_does_push_place_characters_in_correct_spot(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  hString->push_back(hString, 'a');
  hString->push_back(hString, 'b');
  hString->push_back(hString, 'c');

  if (*(hString->at(hString, 0)) != 'a'||*(hString->at(hString, 1)) != 'b' ||*(hString->at(hString, 2)) != 'c')
  {
        status = FAILURE;
        printf("Expected first character to be 'a' but got '%c'\n", *(hString->at(hString,0)));
        strncpy(buffer, "test_does_push_place_characters_in_correct_spot\n"
                "Characters were not placed correctly", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_push_place_characters_in_correct_spot\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_does_pop_reduce_size_correctly(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int first, second;

  hString = my_string_init_default();
  hString->push_back(hString, 'a');
  first = hString->get_size(hString);
  hString->pop_back(hString);
 second = hString->get_size(hString);
  if (first != (second+1))
  {
        status = FAILURE;
        printf("Expected size to decrease by one but got %d\n", (first-second));
        strncpy(buffer, "test_does_pop_reducse_size_correctly\n"
                "Did not receive a size decrease of one", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_pop_reduce_size_correctly\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_does_capacity_decrease_when_you_use_pop(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int first, second;

  hString = my_string_init_default();
  hString->push_back(hString, 'a');
  first = hString->get_capacity(hString);
  hString->pop_back(hString);
  second = hString->get_capacity(hString);
  if (first != second)
  {
        status = FAILURE;
        printf("Expected capacity to remain the same but got %d\n", (first-second));
        strncpy(buffer, "test_does_capacity_decrease_when_you_use_pop\n"
                "Capacity did not remain the same", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_capacity_decrease_when_you_use_pop\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_does_push_resize_capacity_correctly(char*buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int first, second, i;

  hString = my_string_init_default();
  first = hString->get_capacity(hString);
  for(i=0;i<10;i++)
  {
        hString->push_back(hString, 'a');
  }
  second = hString->get_capacity(hString);
  if (first != (second/2))
  {
        status = FAILURE;
        printf("Expected capacity to double but got an increase of %d\n", (second-first));
        strncpy(buffer, "test_does_push_resize_capacity_correctly\n"
                "Capacity did not double", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_push_resize_capacity_correctly\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_does_pop_remove_a_character_correctly(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  hString->push_back(hString, 'a');
  hString->push_back(hString, 'b');
  hString->pop_back(hString);

  if (*(hString->at(hString,0))!= 'a')
  {
        status = FAILURE;
        printf("Expected 'a' but got an %c\n", *(hString->at(hString, 0)));
        strncpy(buffer, "test_does_pop_remove_a_character_correctly\n"
                "Character was not removed correctly", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_pop_remove_a_character_correctly\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_can_c_str_init_handle_weird_characters(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_str("a3#p");

  if(*(hString->at(hString,0))!= 'a' || *(hString->at(hString,1))!= '3' || *(hString->at(hString,2))!= '#' || *(hString->at(hString,3))!= 'p')
{
        status = FAILURE;
        printf("Expected 'a3#p but got %c%c%c%c\n", *(hString->at(hString, 0)), *(hString->at(hString, 1)), *(hString->at(hString, 2)), *(hString->at(hString, 3)));
        strncpy(buffer, "test_can_c_str_init_handle_weird_characters\n"
                "Character was not inialized correctly", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_can_c_str_init_handle_weird_characters\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_can_compare_handle_pear_vs_pears(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  Status status;

  hString1 = my_string_init_c_str("pear");
  hString2 = my_string_init_c_str("pears");

  if(hString1->string_compare(hString1, hString2)!= -1)
{
        status = FAILURE;
        printf("Expected -1 but got %d\n",hString1->string_compare(hString1, hString2));
        strncpy(buffer, "test_can_compare_handle_pear_vs_pears\n"
                "Comparison is not correct", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_can_compare_handle_pear_vs_pears\n", length);
  }
hString1->destroy(&hString1);
hString2->destroy(&hString2);
return status;
}

Status test_does_at_return_correct_character(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  hString->push_back(hString, 'a');
  hString->push_back(hString, 'b');
  hString->push_back(hString, 'c');

  if (*(hString->at(hString,2))!= 'c')
  {
        status = FAILURE;
        printf("Expected 'c' but got an %c\n", *(hString->at(hString, 2)));
        strncpy(buffer, "test_does_at_return_correct_character\n"
                "Character was not returned correctly", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_at_return_a_correct_character\n", length);
  }
hString->destroy(&hString);
return status;
}

Status test_does_init_c_str_resize_properly(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_str("O say can you see by the dawn's early light...");

  if(hString->get_capacity(hString) < 46)
{
        status = FAILURE;
        printf("Expected capacity greater than 46 but got %d\n", hString->get_capacity(hString));
        strncpy(buffer, "test_does_init_c_str_resize_properly\n"
                "String does not have sufficient capacity", length);
  }
  else
  {
        status=SUCCESS;
        strncpy(buffer, "test_does_init_c_str_resize_properly\n", length);
  }
hString->destroy(&hString);
return status;
}



