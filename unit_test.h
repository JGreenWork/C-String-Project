#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include"my_string.h"
Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_get_capacity_on_init_default_returns_8(char* buffer, int length);
Status test_does_size_increase_when_you_use_push(char* buffer, int length);
Status test_does_capacity_increase_when_you_use_push(char* buffer, int length);
Status test_does_push_place_characters_in_correct_spot(char* buffer, int length);
Status test_does_pop_reduce_size_correctly(char* buffer, int length);
Status test_does_capacity_decrease_when_you_use_pop(char* buffer, int length);
Status test_does_push_resize_capacity_correctly(char*buffer, int length);
Status test_does_pop_remove_a_character_correctly(char* buffer, int length);
Status test_can_c_str_init_handle_weird_characters(char* buffer, int length);
Status test_can_compare_handle_pear_vs_pears(char* buffer, int length);
Status test_does_at_return_correct_character(char* buffer, int length);
Status test_does_init_c_str_resize_properly(char* buffer, int length);
#endif
