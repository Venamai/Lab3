#include <cassert>
#include "LinkedList.hpp"

class unit_tests_LinkedList
{
  private:
    static void test_Get()
    {
      int* a = new int[5];
      for(int i = 0; i < 5; i++) a[i] = i;

      LinkedList<int>* ll = new LinkedList<int>(a, 5);

      assert(ll->GetFirst() == 0);
      assert(ll->GetLast() == 4);
      assert(ll->Get(3) == 3);
      assert(ll->GetSize() == 5);

      delete [] a;
      delete ll;
    }

    static void test_Set()
    {
      int* a = new int[5];
      for(int i = 0; i < 5; i++) a[i] = i;

      LinkedList<int>* ll = new LinkedList<int>(a, 5);

      ll->InsertAt(3, 77);
      assert(ll->Get(3) == 77);
      assert(ll->Get(4) == 3);
      assert(ll->GetSize() == 6);

      ll->Append(7);
      assert(ll->GetLast() == 7);
      
      
      ll->Prepend(11);
      assert(ll->GetFirst() == 11);

      delete [] a;
      delete ll;
    }

    static void test_GetSubList()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      LinkedList<int>* ll = new LinkedList<int>(a, 6);

      LinkedList<int>* sub = ll->GetSubList(1, 5);
      for (int i = 0; i < 3; i++) assert(sub->Get(i) == i + 1);

      delete [] a;
      delete ll;
      delete sub;
    }

    static void test_Remove()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      LinkedList<int>* ll = new LinkedList<int>(a, 6);

      ll->Remove(0);
      assert(ll->GetFirst() == 1);
      assert(ll->GetSize() == 5);

      ll->Remove(4);
      assert(ll->GetLast() == 4);

      ll->Remove(2);
      assert(ll->Get(1) == 2);
      assert(ll->Get(2) == 4);

      for (int i = 0; i < 3; i++) ll->Remove(0);
      assert(ll->GetSize() == 0);

      delete [] a;
      delete ll;
    }
  public:
    static void Run()
    {
      test_Get();
      test_Set();
      test_GetSubList();
      test_Remove();
      std::cout << "LinkedList tests finished successfully. \n";
    }
};