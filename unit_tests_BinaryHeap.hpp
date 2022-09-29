#include <cassert>
#include "BinaryHeap.hpp"

class unit_tests_BinaryHeap
{
  private:
    static void test_Constructor_Extract__Peek_IsEmpty_MaxHeap()
    {

      int* a = new int[10];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;
      a[6] = 10;
      a[7] = 14;
      a[8] = 8;
      a[9] = 7;
      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 10);

      assert(bh->Peek(0) == 16);
      assert(bh->Peek(bh->GetLength() - 1) == 1);

      assert(bh->IsEmpty() == false);
      assert(bh->Extract() == 16);
      assert(bh->Extract() == 14);
      assert(bh->Extract() == 10);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 8);
      assert(bh->Extract() == 7);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 3);
      assert(bh->Extract() == 2);
      assert(bh->Extract() == 1);
      assert(bh->IsEmpty() == true);

      delete [] a;
      delete bh;
    }
    static void test_Constructor_Extract__Peek_IsEmpty_MinHeap()
    {

      int* a = new int[10];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;
      a[6] = 10;
      a[7] = 14;
      a[8] = 8;
      a[9] = 7;
      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 10);
      assert(bh->Peek(0) == 1);
      assert(bh->Peek(bh->GetLength() - 1) == 16);

      assert(bh->IsEmpty() == false);
      assert(bh->Extract() == 1);
      assert(bh->Extract() == 2);
      assert(bh->Extract() == 3);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 7);
      assert(bh->Extract() == 8);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 10);
      assert(bh->Extract() == 14);
      assert(bh->Extract() == 16);
      assert(bh->IsEmpty() == true);

      delete [] a;
      delete bh;
    }

    static void test_Insert_MaxHeap() 
    {
      int* a = new int[6];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);
      bh->Insert(17);
      assert(bh->Extract() == 17);
      bh->Insert(5);
      bh->Insert(0);
      assert(bh->Extract() == 16);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 5);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 3);
      assert(bh->Extract() == 2);
      assert(bh->Extract() == 1);
      assert(bh->Extract() == 0);
      bh->Insert(-7);
      assert(bh->Extract() == -7);

      delete bh;
      delete [] a;
    }

    static void test_Insert_MinHeap() 
    {
      int* a = new int[6];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);
      
      bh->Insert(-17);
      assert(bh->Extract() == -17);
      bh->Insert(5);
      bh->Insert(0);
      
      assert(bh->Extract() == 0);
      assert(bh->Extract() == 1);
      assert(bh->Extract() == 2);
      assert(bh->Extract() == 3);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 5);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 16);
      bh->Insert(7);
      assert(bh->Extract() == 7);

      delete bh;
      delete [] a;
    }

    static void test_Search_MaxHeap()
    {
      int* a = new int[6];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);
      assert(bh->Search(3) == true);
      assert(bh->Search(-2) == false);
      assert(bh->Extract() == 16);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 3);
      assert(bh->Extract() == 2);
      assert(bh->Extract() == 1);
      assert(bh->Search(16) == false);
      delete [] a;
      delete bh;
    }

    static void test_Search_MinHeap()
    {
      int* a = new int[6];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);
      assert(bh->Search(3) == true);
      assert(bh->Search(-2) == false);
      assert(bh->Extract() == 1);
      assert(bh->Extract() == 2);
      assert(bh->Extract() == 3);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 16);   
      assert(bh->Search(16) == false);
      delete [] a;
      delete bh;
    }

    static void test_Delete_MaxHeap()
    {
      int* a = new int[6];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;
      

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);

      bh->Delete(16);
      bh->Delete(3);
      bh->Delete(2);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 1);

      delete [] a;
      delete bh;
    }

    static void test_Delete_MinHeap()
    {
      int* a = new int[6];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;
      

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);

      bh->Delete(16);
      bh->Delete(3);
      bh->Delete(1);
      bh->Delete(2);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 9);

      delete [] a;
      delete bh;
    }

    static void test_GetSubtree()
    {
      int* a = new int[10];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;
      a[6] = 10;
      a[7] = 14;
      a[8] = 8;
      a[9] = 7;

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 10);

      BinaryHeap<int>* bh2 = bh->GetSubtree(1);
      assert(bh2->Extract() == 1);
      delete bh2;
      bh2 = bh->GetSubtree(9);
      assert(bh2->Extract() == 9);
      assert(bh2->Extract() == 8);
      assert(bh2->Extract() == 7);
      assert(bh2->Extract() == 4);
      assert(bh2->Extract() == 3);
      assert(bh2->Extract() == 2);
      assert(bh2->Extract() == 1);

      assert(bh->Extract() == 16);
      assert(bh->Extract() == 14);
      assert(bh->Extract() == 10);
      assert(bh->Extract() == 9);
      assert(bh->Extract() == 8);
      assert(bh->Extract() == 7);
      assert(bh->Extract() == 4);
      assert(bh->Extract() == 3);
      assert(bh->Extract() == 2);
      assert(bh->Extract() == 1);

      delete [] a;
      delete bh;
      delete bh2;
    }

    static int Double(int n) { return n * 2; }

    static void test_Map_MinHeap()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);

      BinaryHeap<int>* mapped = bh->Map(Double);

      for(int i = 0; i <= 5; i++) assert(bh->Extract() == i);
      for(int i = 0; i <= 5; i++) assert(mapped->Extract() == i * 2);

      delete [] a;
      delete bh;
      delete mapped;
    }


    static bool isOdd(int n) { return (n % 2) ? true : false; }

    static void test_Where()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 6);

      BinaryHeap<int>* whered = bh->Where(isOdd);
      for(int i = 5; i >= 1; i--) {
        int b = whered->Extract();
        assert(b == 1 || b == 0);
      }
      delete [] a;
      delete bh;
      delete whered;
    }

    static int reduceF(int n1, int n2) { return 2*n1 + 3*n2; }

    static void test_Reduce()
    {
      int a[3] = {1, 2, 3};
      BinaryHeap<int>* bh = new BinaryHeap<int>(a, 3);
      assert(bh->Reduce(reduceF, 4) == 144);
      delete bh;
    }

  public:
    static void Run()
    {
      test_Constructor_Extract__Peek_IsEmpty_MinHeap();
      test_Insert_MinHeap();
      test_Search_MinHeap();
      // test_GetSubtree();
      test_Delete_MinHeap();
      test_Map_MinHeap();
      test_Where();
      test_Reduce();
      std::cout << "BinaryHeap tests finished successfully. \n";
    }
};
