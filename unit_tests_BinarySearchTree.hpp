#include <cassert>
#include <time.h>
#include "BinarySearchTree.hpp"

using namespace std;
class unit_tests_BinarySearchTree
{
  private:
    static void test_Create_Insert_toString()
    {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();
      assert(tree->ToString("NLR") == "");
      assert(tree->ToString("NRL") == "");
      assert(tree->ToString("LRN") == "");
      assert(tree->ToString("RLN") == "");
      assert(tree->ToString("LNR") == "");
      assert(tree->ToString("RNL") == "");

      tree->Insert(3);

      assert(tree->ToString("NLR") == "[ 3 ] ");
      assert(tree->ToString("NRL") == "[ 3 ] ");
      assert(tree->ToString("LRN") == "[ 3 ] ");
      assert(tree->ToString("RLN") == "[ 3 ] ");
      assert(tree->ToString("LNR") == "[ 3 ] ");
      assert(tree->ToString("RNL") == "[ 3 ] ");

      tree->Insert(2);
      tree->Insert(1);
      tree->Insert(5);
      tree->Insert(4);
      tree->Insert(7);
      tree->Insert(6);
      tree->Insert(8);

      assert(tree->ToString("NLR") == "[ 3 ] [ 2 ] [ 1 ] [ 5 ] [ 4 ] [ 7 ] [ 6 ] [ 8 ] ");
      assert(tree->ToString("NRL") == "[ 3 ] [ 5 ] [ 7 ] [ 8 ] [ 6 ] [ 4 ] [ 2 ] [ 1 ] ");
      assert(tree->ToString("LRN") == "[ 1 ] [ 2 ] [ 4 ] [ 6 ] [ 8 ] [ 7 ] [ 5 ] [ 3 ] ");
      assert(tree->ToString("RLN") == "[ 8 ] [ 6 ] [ 7 ] [ 4 ] [ 5 ] [ 1 ] [ 2 ] [ 3 ] ");
      assert(tree->ToString("LNR") == "[ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] ");
      assert(tree->ToString("RNL") == "[ 8 ] [ 7 ] [ 6 ] [ 5 ] [ 4 ] [ 3 ] [ 2 ] [ 1 ] ");
      delete tree;
    }

    static void test_Remove()
    {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();
      // int* a = new int[10];
      tree->Insert(4);
      
      tree->Insert(1);

      tree->Insert(3);
      tree->Insert(16);
      tree->Insert(9);

      tree->Remove(1);
      assert(tree->ToString("NLR") == "[ 4 ] [ 3 ] [ 16 ] [ 9 ] ");

      tree->Remove(3);
      assert(tree->ToString("NLR") == "[ 4 ] [ 16 ] [ 9 ] ");

      tree->Remove(16);
      tree->Remove(4);
      assert(tree->ToString("NLR") == "[ 9 ] ");
      
      tree->Remove(9);
      assert(tree->ToString("NLR") == "");
      delete tree;
    }

    static int Double(int n) { return n * 2; }
    static void test_Map()
    {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      BinarySearchTree<int>* b = tree->Map(Double);
      assert(b->ToString("NLR") == "");
      delete b;
      tree->Insert(4);
      tree->Insert(1);
      tree->Insert(3);
      tree->Insert(2);
      tree->Insert(16);
      tree->Insert(9);
      tree->Insert(10);
      tree->Insert(14);
      tree->Insert(8);
      tree->Insert(7);

      b = tree->Map(Double);
      assert(b->ToString("NLR") == "[ 8 ] [ 2 ] [ 6 ] [ 4 ] [ 32 ] [ 18 ] [ 16 ] [ 14 ] [ 20 ] [ 28 ] ");
      delete b;
      delete tree;
    }

    static bool isOdd(int n) { return (n % 2) ? true : false; }
    static void test_Where()
    {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      BinarySearchTree<int>* b = tree->Where(isOdd);
      assert(b->ToString("NLR") == "");
      delete b;

      tree->Insert(4);
      tree->Insert(1);
      tree->Insert(3);
      tree->Insert(2);
      tree->Insert(16);
      tree->Insert(9);
      tree->Insert(10);

      b = tree->Where(isOdd);
      assert(tree->ToString("NLR") == "[ 4 ] [ 1 ] [ 3 ] [ 2 ] [ 16 ] [ 9 ] [ 10 ] ");
      cout << b->ToString("NLR") << '\n';
      assert(b->ToString("NLR") == "[ 3 ] [ 1 ] [ 9 ] ");

      delete b;
      delete tree;
    }



    static void test_Merge()
    {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();
      BinarySearchTree<int>* tree2 = new BinarySearchTree<int>();

      tree->Merge(tree2);
      assert(tree->ToString("NLR") == "");
      assert(tree2->ToString("NLR") == "");

      tree->Insert(4);
      tree->Insert(1);
      tree->Insert(3);
      tree->Insert(2);
      tree->Insert(16);
      tree->Insert(9);
      tree->Insert(10);
      

      tree->Merge(tree2);
      assert(tree->ToString("NLR") == "[ 4 ] [ 1 ] [ 3 ] [ 2 ] [ 16 ] [ 9 ] [ 10 ] ");
      assert(tree2->ToString("NLR") == "");

      tree2->Insert(5);
      tree2->Insert(6);
      tree2->Insert(3);
      tree2->Insert(22);

      tree->Merge(tree2);
      assert(tree->ToString("NLR") == "[ 4 ] [ 1 ] [ 3 ] [ 2 ] [ 16 ] [ 9 ] [ 5 ] [ 6 ] [ 10 ] [ 22 ] ");
      assert(tree2->ToString("NLR") == "[ 5 ] [ 3 ] [ 6 ] [ 22 ] ");

      delete tree;
      delete tree2;
    }

    static void test_GetSubtree()
    {
      BinarySearchTree<int>* tree = new BinarySearchTree<int>();

      tree->Insert(4);
      tree->Insert(1);
      tree->Insert(3);
      tree->Insert(2);
      tree->Insert(16);
      tree->Insert(9);
      tree->Insert(10);

      BinarySearchTree<int>* tree2 = tree->GetSubtree(1);

      assert(tree->ToString("NLR") == "[ 4 ] [ 1 ] [ 3 ] [ 2 ] [ 16 ] [ 9 ] [ 10 ] ");
      assert(tree2->ToString("NLR") == "[ 1 ] [ 3 ] [ 2 ] ");
      delete tree2;

      tree2 = tree->GetSubtree(16);
      cout << tree2->ToString("NLR") << '\n';
      assert(tree2->ToString("NLR") == "[ 16 ] [ 9 ] [ 10 ] ");
      delete tree2;

      tree2 = tree->GetSubtree(9);
      cout << tree2->ToString("NLR") << '\n';
      assert(tree2->ToString("NLR") == "[ 9 ] [ 10 ] ");
      delete tree2;

      delete tree;
    }

  public:
    static void Run()
    {
      test_Create_Insert_toString();
      test_Remove();
      test_Map();
      test_Where();
      test_Merge();
      test_GetSubtree();
      cout << "BinarySearchTree tests finished successfully. \n";
    }

};