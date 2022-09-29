#include <cassert>
#include <iostream>
#include "ListSequence.hpp"

class unit_tests_ListSequence
{
  private:
    static void test_Get()
    {
      int b = 1;
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      ListSequence<int>* ls = new ListSequence<int>(a, 6);

      assert(ls->GetFirst() == 0);
      assert(ls->GetLast() == 5);
      for(int i = 0; i < 6; i++) assert(ls->Get(3) == 3);
      assert(ls->GetLength() == 6);

      delete [] a;
      delete ls;
    }

    static void test_Set()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      ListSequence<int>* ls = new ListSequence<int>(a, 6);

      ls->InsertAt(3, 33);
      assert(ls->Get(3) == 33);
      for(int i = 4; i < 6; i++) assert(ls->Get(i) == i - 1);
      assert(ls->GetLength() == 7);

      ls->Append(10);
      assert(ls->GetLast() == 10);
      assert(ls->Get(6) == 5);

      ls->Prepend(-3);
      assert(ls->GetFirst() == -3);
      assert(ls->Get(1) == 0);

      delete [] a;
      delete ls;
    }

    static void test_GetSubsequence()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      ListSequence<int>* ls = new ListSequence<int>(a, 6);

      ListSequence<int>* sub = (ListSequence<int>*) ls->GetSubsequence(1, 4);
      for(int i = 0; i < 3; i++) assert(sub->Get(i) == i + 1);
      for(int i = 0; i < 6; i++) assert(ls->Get(i) == i);

      delete [] a;
      delete ls;
      delete sub;
    }

    static void test_Concat()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      int* b = new int[3];
      for(int i = 0; i < 3; i++) b[i] = i + 6;
      
      ListSequence<int>* ls = new ListSequence<int>(a, 6);
      ListSequence<int>* ls2 = new ListSequence<int>(b, 3);
      ListSequence<int>* cr = (ListSequence<int>*) ls->Concat(ls2);
      assert(cr->GetLength() == 9);

      for(int i = 0; i < 5; i++) assert(ls->Get(i) == i);
      for(int i = 0; i < 3; i++) assert(ls2->Get(i) == i + 6);
      for(int i = 0; i < 8; i++) assert(cr->Get(i) == i);

      delete [] a;
      delete [] b;
      delete ls;
      delete ls2;
      delete cr;
    }

    static void test_Remove()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;
      
      ListSequence<int>* ls = new ListSequence<int>(a, 6);

      ls->Remove(5);
      assert(ls->GetLast() == 4);

      ls->Remove(0);
      assert(ls->GetFirst() == 1);

      ls->Remove(2);
      assert(ls->Get(1) == 2);
      assert(ls->Get(2) == 4);

      delete [] a;
      delete ls;
    }
  public:
    static void Run()
    {
      test_Get();
      test_Set();
      test_GetSubsequence();
      test_Concat();
      test_Remove();
      std::cout << "ListSequence tests finished successfully. \n";
    }
};