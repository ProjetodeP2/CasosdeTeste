#include <stdio.h>
#include "CUnit/Basic.h"
#include "lib/linked_list.h"


void create_list_test()
{
  node* list1 = create_list();
  CU_ASSERT_PTR_NOT_NULL(list1);
}

void add_int_end_test()
{
  int x = 3;
  int y = 4;
  int z = 5;
  node* list1 = create_list();
  CU_ASSERT_EQUAL(*((int*)add_int_end_test(list1, &x)->item), 3);
  CU_ASSERT_EQUAL(*((int*)add_int_end_test(list1, &y)->item), 4);
  CU_ASSERT_EQUAL(*((int*)add_int_end_test(list1, &z)->item), 5);
}

void add_unsigned_char_end_test()
{
  node* list1 = create_list();
  unsigned char x = '*';
  unsigned char y = 'a';
  unsigned char z = 'b';
  CU_ASSERT_EQUAL(*((unsigned char*)add_unsigned_char_end(list1, &x)->item), '*');
  CU_ASSERT_EQUAL(*((unsigned char*)add_unsigned_char_end(list1, &y)->item), 'a');
  CU_ASSERT_EQUAL(*((unsigned char*)add_unsigned_char_end(list1, &z)->item), 'b');
}

void is_list_empty_test()
{
  node *aux = create_list();
  CU_ASSERT_EQUAL(is_list_empty(aux), 1);
}

void remove_last_node_int()
{
  int x = 3;
  node* list1 = create_list();
  CU_ASSERT_EQUAL(*((int*)add_int_end_test(list1, &x)->item), 3);

  CU_ASSERT_PTR_NOT_NULL(*((int*)remove_last_node_int(list1));
}

void copy_int_list_test()
{
  int x = 3;
  int y = 4;
  int z = 5;
  node* list1 = create_list();
  node* list2 = create_list();
  
  list1 = add_int_end(list1, &x);
  list1 = add_int_end(list1, &y);
  list1 = add_int_end(list1, &z);

  list2 = copy_int_list(list1);
  CU_ASSERT_EQUAL(*((int*)list1->item,             *((int*)list2->item);
  CU_ASSERT_EQUAL(*((int*)list1->next->item,       *((int*)list2->next->item);
  CU_ASSERT_EQUAL(*((int*)list1->next->next->item, *((int*)list2->next->next->item);
}

int main() 
{
  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry())
   return CU_get_error();

  CU_pSuite pSuite = NULL;
  // Add a suite to the registry
  pSuite = CU_add_suite("list_test_suite", 0, 0);
  // Always check if add was successful
  if (NULL == pSuite) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  // Add the tests to the suite
  if (NULL == CU_add_test(pSuite, "create_list_test", create_list_test)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "add_int_end_test", add_int_end_test) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "add_unsigned_char_end_test", add_unsigned_char_end_test)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "is_list_empty_test", is_list_empty_test))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "copy_int_list_test", copy_int_list_test))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "remove_last_node_int", remove_last_node_int))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }  


  // Sets the basic run mode, CU_BRM will show maximum output of run details
  // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
  CU_basic_set_mode(CU_BRM_VERBOSE);
  // Run the tests and show the run summary
  CU_basic_run_tests();
  return CU_get_error();
}