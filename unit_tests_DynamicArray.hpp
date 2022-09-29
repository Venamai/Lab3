#include <cassert>
#include <iostream>
#include "DynamicArray.hpp"


class unit_tests_DynamicArray
{
  private:
    static void test_Get()
    {
      int* a = new int[5];
      for(int i = 0; i < 5; i++) a[i] = i;

      DynamicArray<int>* da = new DynamicArray<int>(a, 5);
      assert(da->Get(0) == 0);
      assert(da->Get(2) == 2);
      assert(da->Get(4) == 4);
      assert(da->GetCount() == 5);
      assert(da->GetSize() == 10);
      delete [] a;
      delete da;
    }

    static void test_Set()
    {
      int* a = new int[5];
      for(int i = 0; i < 5; i++) a[i] = i;

      DynamicArray<int>* da = new DynamicArray<int>(a, 5);
      da->Set(0, 1);
      
      assert(da->Get(0) == 1);
      assert(da->Get(1) == 0);
      for(int i = 1; i < 6; i++) assert(da->Get(i) == i - 1);

      assert(da->GetCount() == 6);
      assert(da->GetSize() == 10);

      da->Resize(7);
      da->Set(5, 11);

      assert(da->Get(5) == 11);

      delete [] a;
      delete da;
    }

    static void test_Remove()
    {
      int* a = new int[5];
      for(int i = 0; i < 5; i++) a[i] = i;

      DynamicArray<int>* da = new DynamicArray<int>(a, 5);

      da->Remove(0);
      assert(da->Get(0) == 1);
      assert(da->GetCount() == 4);
      assert(da->GetSize() == 10);

      delete [] a;
      delete da;
    }

    static void test_Resize()
    {
      int* a = new int[5];
      for(int i = 0; i < 5; i++) a[i] = i;
      DynamicArray<int>* da = new DynamicArray<int>(a, 5);

      da->Resize(2);
      assert(da->GetSize() == 2);
      assert(da->GetCount() == 2);
      assert(da->Get(0) == 0);
      assert(da->Get(1) == 1);

      delete [] a;
      delete da;
    }
  
  public:
    static void Run()
    {
      test_Get();
      test_Set();
      test_Remove();
      test_Resize();
      std::cout << "DynamicArray tests finished successfully. \n";
    }
};
