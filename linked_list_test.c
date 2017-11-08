#include <stdio.h>
#include "CUnit/Basic.h"
#include "lib/linked_list.h"


void create_list_test()
{
  CU_ASSERT_PTR_NOT_NULL(create_list());
}

void is_list_empty_test()
{
  node *aux = create_list();
  CU_ASSERT_EQUAL(is_list_empty(aux), true);
}

void add_int_end_test()
{
  node *aux = create_list();
  CU_ASSERT_EQUAL(add_int_end_test(aux, 0), 0);
}

int main() 
{
  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry())
   return CU_get_error();

  CU_pSuite pSuite = NULL;
  // Add a suite to the registry
  pSuite = CU_add_suite("sum_test_suite", 0, 0);
  // Always check if add was successful
  if (NULL == pSuite) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  // Add the tests to the suite
  if (NULL == CU_add_test(pSuite, "create_heap_test", create_heap_test)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "get_parent_index_test", get_parent_index_test)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "get_left_index_test", get_left_index_test)) 
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "get_right_index_test", get_right_index_test))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "enqueue_huffman_heap_test", enqueue_huffman_heap_test))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuite, "dequeue_n_min_heapify_test", dequeue_n_min_heapify_test))
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