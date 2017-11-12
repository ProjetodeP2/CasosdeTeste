#include <stdio.h>
#include "CUnit/Basic.h"
#include "lib/linked_list.h"


void create_list_test()
{
  node* list1 = create_list();
  CU_ASSERT_PTR_NULL(list1);
}

void add_int_list_end_test()
{
  node* list1 = create_list();
  list1 = add_int_list_end(list1, 3);
  list1 = add_int_list_end(list1, 4);
  list1 = add_int_list_end(list1, 5);
  CU_ASSERT_EQUAL(*((int*)list1->item), 3);
  CU_ASSERT_EQUAL(*((int*)list1->next->item), 4);
  CU_ASSERT_EQUAL(*((int*)list1->next->next->item), 5);
}

void add_unsigned_char_list_end_test()
{
  node* list1 = create_list();

  list1 = add_int_list_end(list1, '*');
  list1 = add_int_list_end(list1, 'a');
  list1 = add_int_list_end(list1, 'b');

  CU_ASSERT_EQUAL(*((unsigned char*)list1->item),'*');
  CU_ASSERT_EQUAL(*((unsigned char*)list1->next->item), 'a');
  CU_ASSERT_EQUAL(*((unsigned char*)list1->next->next->item), 'b');
}

void is_list_empty_test()
{
  node *aux = create_list();
  CU_ASSERT_EQUAL(is_list_empty(aux), 1);
}

void remove_last_list_node_test()
{
  node* list1 = create_list();

  list1 = add_int_list_end(list1, 3);
  list1 = add_int_list_end(list1, 4);

  list1 = remove_last_list_node(list1);
  CU_ASSERT_PTR_NULL(list1->next);
}

void copy_int_list_test()
{
  node* list1 = create_list();
  node* list2 = create_list();
  
  list1 = add_int_list_end(list1, 3);
  list1 = add_int_list_end(list1, 4);
  list1 = add_int_list_end(list1, 5);

  list2 = copy_int_list(list1);

   CU_ASSERT_EQUAL(*((int*)list1->item), *((int*)list2->item));
   CU_ASSERT_EQUAL(*((int*)list1->next->item), *((int*)list2->next->item));
   CU_ASSERT_EQUAL(*((int*)list1->next->next->item), *((int*)list2->next->next->item));
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
  if (NULL == CU_add_test(pSuite, "add_int_list_end_test", add_int_list_end_test)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "add_unsigned_char_list_end_test", add_unsigned_char_list_end_test)) 
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
  if (NULL == CU_add_test(pSuite, "remove_last_list_node_test", remove_last_list_node_test))
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