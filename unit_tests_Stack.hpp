#include <cassert>
#include <iostream>
#include "Stack.hpp"


class unit_tests_Stack
{
  private:
    static void test_Get_As()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 1);
      assert(s->GetLength() == 6);
      assert(s->Pop() == 5);
      assert(s->GetLength() == 5);

      for(int i = s->GetLength() - 1; i >= 0; i--) assert(s->Pop() == i);
      
      delete [] a;
      delete s;
    }

    static void test_Set_As()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 1);

      s->Push(-1);
      assert(s->GetLength() == 7);
      assert(s->Pop() == -1);

      delete [] a;
      delete s;
    }


    static int Double(int n) { return n * 2; }

    static void test_Map_As()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 1);

      Stack<int>* mapped = s->Map(Double);

      for(int i = 5; i >= 0; i--) assert(s->Pop() == i);
      for(int i = 5; i >= 0; i--) assert(mapped->Pop() == i * 2);

      delete [] a;
      delete s;
      delete mapped;
    }


    static bool isOdd(int n) { return (n % 2) ? true : false; }

    static void test_Where_As()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 1);

      Stack<int>* whered = s->Where(isOdd);
      for(int i = 5; i >= 0; i--) {
        assert(whered->Pop() == i % 2);
      }

      delete [] a;
      delete s;
      delete whered;
    }

    static int reduceF(int n1, int n2) { return 2*n1 + 3*n2; }

    static void test_Reduce_As()
    {
      int a[3] = {1, 2, 3};

      Stack<int>* s = new Stack<int>(a, 3, 1);
      
      int b = s->Reduce(reduceF, 4);
      assert(b == 144);

      delete s;
    }

    static void test_GetSubsequence_As()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 1);

      Stack<int>* sub = s->GetSubsequence(1, 4);

      for(int i = 2; i >= 0; i--) assert(sub->Pop() == i + 1);
      for(int i = 5; i >= 0; i--) assert(s->Pop() == i);

      delete [] a;
      delete s;
      delete sub;
    }

    static void test_FindSubsequence_As()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;
      Stack<int>* s = new Stack<int>(a, 6, 1);

      int b[3] = {2, 3, 4};

      bool f = s->FindSubsequence(b, 3);
      assert(f == true);
      b[1] = 5;
      assert(s->FindSubsequence(b, 3) == false);
      assert(s->FindSubsequence(b, 2) == false);

      delete [] a;
      delete s;
    }

    static void test_Concat_As()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      int* b = new int[3];
      for(int i = 0; i < 3; i++) b[i] = i + 6;
      
      Stack<int>* s = new Stack<int>(a, 6, 1);
      Stack<int>* s2 = new Stack<int>(b, 3, 1);
      Stack<int>* cr = (Stack<int>*) s->Concat(s2);
      assert(cr->GetLength() == 9);

      for(int i = 5; i >= 0; i--) assert(s->Pop() == i);
      for(int i = 8; i >= 0; i--) assert(cr->Pop() == i);
      assert(s2->GetLength() == 0);
      

      delete [] a;
      delete [] b;
      delete s;
      delete s2;
      delete cr;
    }


    static void test_Get_Ls()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 2);
      assert(s->GetLength() == 6);
      assert(s->Pop() == 5);
      assert(s->GetLength() == 5);

      for(int i = s->GetLength() - 1; i >= 0; i--) assert(s->Pop() == i);
      
      delete [] a;
      delete s;
    }

    static void test_Set_Ls()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 2);

      s->Push(-1);
      assert(s->GetLength() == 7);
      assert(s->Pop() == -1);

      delete [] a;
      delete s;
    }

    static void test_Map_Ls()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 2);

      Stack<int>* mapped = s->Map(Double);

      for(int i = 5; i >= 0; i--) assert(s->Pop() == i);
      for(int i = 5; i >= 0; i--) assert(mapped->Pop() == i * 2);

      delete [] a;
      delete s;
      delete mapped;
    }

    static void test_Where_Ls()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 2);

      Stack<int>* whered = s->Where(isOdd);
      for(int i = 5; i >= 0; i--) {
        assert(whered->Pop() == i % 2);
      }

      delete [] a;
      delete s;
      delete whered;
    }

    static void test_Reduce_Ls()
    {
      int a[3] = {1, 2, 3};

      Stack<int>* s = new Stack<int>(a, 3, 2);
      
      int b = s->Reduce(reduceF, 4);
      assert(b == 144);

      delete s;
    }

    static void test_GetSubsequence_Ls()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      Stack<int>* s = new Stack<int>(a, 6, 2);

      Stack<int>* sub = s->GetSubsequence(1, 4);

      for(int i = 2; i >= 0; i--) assert(sub->Pop() == i + 1);
      for(int i = 5; i >= 0; i--) assert(s->Pop() == i);

      delete [] a;
      delete s;
      delete sub;
    }

    static void test_FindSubsequence_Ls()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;
      Stack<int>* s = new Stack<int>(a, 6, 2);

      int b[3] = {2, 3, 4};

      bool f = s->FindSubsequence(b, 3);
      assert(f == true);
      b[1] = 5;
      assert(s->FindSubsequence(b, 3) == false);
      assert(s->FindSubsequence(b, 2) == false);

      delete [] a;
      delete s;
    }

    static void test_Concat_Ls()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      int* b = new int[3];
      for(int i = 0; i < 3; i++) b[i] = i + 6;
      
      Stack<int>* s = new Stack<int>(a, 6, 2);
      Stack<int>* s2 = new Stack<int>(b, 3, 2);
      Stack<int>* cr = (Stack<int>*) s->Concat(s2);
      assert(cr->GetLength() == 9);

      for(int i = 5; i >= 0; i--) assert(s->Pop() == i);
      for(int i = 8; i >= 0; i--) assert(cr->Pop() == i);
      assert(s2->GetLength() == 0);
      

      delete [] a;
      delete [] b;
      delete s;
      delete s2;
      delete cr;
    }

  public:
    static void Run()
    {
      std::cout << "\nYou'll need to choose sequence type multiple times due to stack constructor is called often during test. Choose the same type.\n\n";
      test_Get_As();
      test_Set_As();
      test_Map_As();
      test_Where_As();
      test_Reduce_As();
      test_GetSubsequence_As();
      test_FindSubsequence_As();
      test_Concat_As();

      test_Get_Ls();
      test_Set_Ls();
      test_Map_Ls();
      test_Where_Ls();
      test_Reduce_Ls();
      test_GetSubsequence_Ls();
      test_FindSubsequence_Ls();
      test_Concat_Ls();
      std::cout << "Stack tests finished successfully. \n";
    }
};