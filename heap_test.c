#include <stdio.h>
#include "CUnit/Basic.h"
#include "lib/huffman_heap.h"


void create_heap_test()
{
  CU_ASSERT_PTR_NOT_NULL(create_heap());
}

void get_parent_index_test()
{
  heap *aux = create_heap();
  CU_ASSERT_EQUAL(get_parent_index(aux, 0), 0);
  CU_ASSERT_EQUAL(get_parent_index(aux, 1), 0);
  CU_ASSERT_EQUAL(get_parent_index(aux, 2), 1);
  CU_ASSERT_EQUAL(get_parent_index(aux, 3), 1);
  CU_ASSERT_EQUAL(get_parent_index(aux, 4), 2);
  CU_ASSERT_EQUAL(get_parent_index(aux, 5), 2);
}

void get_left_index_test()
{
  heap *aux = create_heap();
  CU_ASSERT_EQUAL(get_left_index(aux, 0), 0);
  CU_ASSERT_EQUAL(get_left_index(aux, 1), 2);
  CU_ASSERT_EQUAL(get_left_index(aux, 2), 4);
  CU_ASSERT_EQUAL(get_left_index(aux, 3), 6);
  CU_ASSERT_EQUAL(get_left_index(aux, 4), 8);
}

void get_right_index_test()
{
  heap *aux = create_heap();
  CU_ASSERT_EQUAL(get_right_index(aux, 0), 1);
  CU_ASSERT_EQUAL(get_right_index(aux, 1), 3);
  CU_ASSERT_EQUAL(get_right_index(aux, 2), 5);
  CU_ASSERT_EQUAL(get_right_index(aux, 3), 7);
  CU_ASSERT_EQUAL(get_right_index(aux, 4), 9);
}

void enqueue_huffman_heap_test()
{
  heap *aux = create_heap();
  huffman_tree *node = NULL;
  unsigned char *item_of_node = NULL; 

  int i;
  for (i = 65; i <= 90; ++i)
  {
    item_of_node = (unsigned char*)malloc(sizeof(unsigned char));
    *item_of_node = (unsigned char)i;
    node = create_huffman_tree_node(item_of_node, i, NULL, NULL);
    enqueue_huffman_heap(aux, node);
  }

  CU_ASSERT_EQUAL(aux->size, 26);
  CU_ASSERT_EQUAL(*(unsigned char*)(((huffman_tree*)aux->data[1])->item), 'A');
  CU_ASSERT(((huffman_tree*)aux->data[1])->frequency <= ((huffman_tree*)aux->data[2])->frequency);
  //
  item_of_node = (unsigned char*)malloc(sizeof(unsigned char));
  *item_of_node = '*';
  node = create_huffman_tree_node(item_of_node, 1000, NULL, NULL);
  enqueue_huffman_heap(aux, node);
  
  CU_ASSERT_EQUAL(aux->size, 27);
  CU_ASSERT_EQUAL(*(unsigned char*)(((huffman_tree*)aux->data[27])->item), '*');
}

void dequeue_n_min_heapify_test()
{
  heap *aux = create_heap();
  huffman_tree *node = NULL;
  unsigned char *item_of_node = NULL; 

  int i;
  for (i = 65; i <= 90; ++i)
  {
    item_of_node = (unsigned char*)malloc(sizeof(unsigned char));
    *item_of_node = (unsigned char)i;
    node = create_huffman_tree_node(item_of_node, i, NULL, NULL);
    enqueue_huffman_heap(aux, node);
  }  
  CU_ASSERT_EQUAL(aux->size, 26);
  CU_ASSERT_EQUAL(*(unsigned char*)(huffman_tree*)dequeue_of_huffman_heap(aux)->item, 'A');
  CU_ASSERT_EQUAL(aux->size, 25);
  CU_ASSERT_EQUAL(*(unsigned char*)(huffman_tree*)dequeue_of_huffman_heap(aux)->item, 'B');
  CU_ASSERT_EQUAL(aux->size, 24);




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