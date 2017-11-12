#include <stdio.h>
#include "CUnit/Basic.h"
#include "lib/huffman_tree.h"

void create_huffman_tree_node_test()
{
	int item1 = 5;
	int frequency1 = 10;
	int item2 = 50;
	int frequency2 = 20;
	unsigned char aux = '*';

	huffman_tree* tree1 = create_huffman_tree_node(&item1,frequency1,NULL,NULL);

	CU_ASSERT_EQUAL(*((int*)get_huffman_node_item(tree1)), 5);
	CU_ASSERT_EQUAL(get_huffman_node_frequency(tree1), 10);
	CU_ASSERT_PTR_NULL(get_left_huffman_node(tree1));
	CU_ASSERT_PTR_NULL(get_right_huffman_node(tree1));

	huffman_tree* tree2 = create_huffman_tree_node(&item2,frequency2,NULL,NULL);

	CU_ASSERT_EQUAL(*((int*)get_huffman_node_item(tree2)), 50);
	CU_ASSERT_EQUAL(get_huffman_node_frequency(tree2), 20);
	CU_ASSERT_PTR_NULL(get_left_huffman_node(tree2));
	CU_ASSERT_PTR_NULL(get_right_huffman_node(tree2));


	huffman_tree* father = create_huffman_tree_node(&aux, (get_huffman_node_frequency(tree1) + get_huffman_node_frequency(tree2)), tree1, tree2);

	CU_ASSERT_EQUAL(*((unsigned char*)get_huffman_node_item(father)), '*');
	CU_ASSERT_EQUAL(get_huffman_node_frequency(father), 30);
	CU_ASSERT_PTR_NOT_NULL(get_left_huffman_node(father));
	CU_ASSERT_PTR_NOT_NULL(get_right_huffman_node(father));
}


void huffman_tree_swap_test()
{
	int item1 = 20;
	int frequency1 = 5;
	int item2 = 30;
	int frequency2 = 10;

	huffman_tree* tree1 = create_huffman_tree_node(&item1,frequency1,NULL,NULL);
	huffman_tree* tree2 = create_huffman_tree_node(&item2,frequency2,NULL,NULL);

	huffman_tree_swap(tree1, tree2);

	// Primeiro Nó
	CU_ASSERT_EQUAL(*((int*)get_huffman_node_item(tree1)), 30);
	CU_ASSERT_EQUAL(get_huffman_node_frequency(tree1), 10);

	// Segundo Nó
	CU_ASSERT_EQUAL(*((int*)get_huffman_node_item(tree2)), 20);
	CU_ASSERT_EQUAL(get_huffman_node_frequency(tree2), 5);;

}


int main() 
{
   // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
   return CU_get_error();

	CU_pSuite pSuite = NULL;

	// Add a suite to the registry
	pSuite = CU_add_suite("Huffman_Tree_Test_Suite", 0, 0);

	// Always check if add was successful
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// Add the test to the suite
	if (NULL == CU_add_test(pSuite, "create_huffman_tree_node_test", create_huffman_tree_node_test)) 
	{
		CU_cleanup_registry();
	  	return CU_get_error();
	}

	if (NULL == CU_add_test(pSuite, "huffman_tree_swap_test", huffman_tree_swap_test)) 
	{
		CU_cleanup_registry();
	  	return CU_get_error();
	}

   // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);

   // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}