#include <cassert>
#include <iostream>
#include "ArraySequence.hpp"

class unit_tests_ArraySequence
{
  private:
    static void test_Get()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      ArraySequence<int>* as = new ArraySequence<int>(a, 6);

      assert(as->GetFirst() == 0);
      assert(as->GetLast() == 5);
      for(int i = 0; i < 6; i++) assert(as->Get(3) == 3);
      assert(as->GetLength() == 6);

      delete [] a;
      delete as;
    }

    static void test_Set()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      ArraySequence<int>* as = new ArraySequence<int>(a, 6);

      as->InsertAt(3, 33);
      assert(as->Get(3) == 33);
      for(int i = 4; i < 6; i++) assert(as->Get(i) == i - 1);
      assert(as->GetLength() == 7);

      as->Append(10);
      assert(as->GetLast() == 10);
      assert(as->Get(6) == 5);

      as->Prepend(-3);
      assert(as->GetFirst() == -3);
      assert(as->Get(1) == 0);

      delete [] a;
      delete as;
    }

    static void test_GetSubsequence()
    {
      int b = 1;
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;
      
      ArraySequence<int>* as = new ArraySequence<int>(a, 6);

      ArraySequence<int>* sub = (ArraySequence<int>*) as->GetSubsequence(1, 4);
      for(int i = 0; i < 3; i++) assert(sub->Get(i) == i + 1);
      for(int i = 0; i < 6; i++) assert(as->Get(i) == i);

      delete [] a;
      delete as;
      delete sub;
    }

    static void test_Concat()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      int* b = new int[3];
      for(int i = 0; i < 3; i++) b[i] = i + 6;
      
      ArraySequence<int>* as = new ArraySequence<int>(a, 6);
      ArraySequence<int>* as2 = new ArraySequence<int>(b, 3);
      ArraySequence<int>* cr = (ArraySequence<int>*) as->Concat(as2);
      assert(cr->GetLength() == 9);

      for(int i = 0; i < 5; i++) assert(as->Get(i) == i);
      for(int i = 0; i < 3; i++) assert(as2->Get(i) == i + 6);
      for(int i = 0; i < 8; i++) assert(cr->Get(i) == i);

      delete [] a;
      delete [] b;
      delete as;
      delete as2;
      delete cr;
    }

    static void test_Remove()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;
      
      ArraySequence<int>* as = new ArraySequence<int>(a, 6);

      as->Remove(5);
      assert(as->GetLast() == 4);

      as->Remove(0);
      assert(as->GetFirst() == 1);

      as->Remove(2);
      assert(as->Get(1) == 2);
      assert(as->Get(2) == 4);

      delete [] a;
      delete as;
    }
  public:
    static void Run()
    {
      test_Get();
      test_Set();
      test_GetSubsequence();
      test_Concat();
      test_Remove();
      std::cout << "ArraySequence tests finished successfully. \n";
    }
};