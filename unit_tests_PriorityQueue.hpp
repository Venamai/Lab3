#include <cassert>
#include "BinaryHeap.hpp"
#include "PriorityQueue.hpp"

class unit_tests_PriorityQueue
{
  private:
    static void test_Create_Enqueue_Dequeue_MinHeap()
    {
      int* a = new int[6];
      a[0] = 4;
      a[1] = 1;
      a[2] = 3;
      a[3] = 2;
      a[4] = 16;
      a[5] = 9;

      PriorityQueue<int>* pQ = new PriorityQueue<int>(a, 6);
      PriorityQueue<int>* pQ2 = new PriorityQueue<int>();

      assert(pQ->PeekFirst() == 1);
      assert(pQ->PeekLast() == 9);

      pQ->Enqueue(7);
      pQ->Enqueue(21);
      pQ->Enqueue(0);
      
      assert(pQ->PeekFirst() == 0);
      assert(pQ->PeekLast() == 4); 
      
      assert(pQ->Dequeue() == 0);
      assert(pQ->Dequeue() == 1);
      assert(pQ->Dequeue() == 2);
      assert(pQ->Dequeue() == 3);
      assert(pQ->Dequeue() == 4);
      assert(pQ->Dequeue() == 7);
      assert(pQ->Dequeue() == 9);
      assert(pQ->Dequeue() == 16);
      assert(pQ->Dequeue() == 21);
          
      delete pQ;

      pQ2->Enqueue(5);
      assert(pQ2->Dequeue() == 5);
      pQ2->Enqueue(5);
      pQ2->Enqueue(1);
      pQ2->Enqueue(4);
      assert(pQ2->Dequeue() == 1);
      assert(pQ2->Dequeue() == 4);
      assert(pQ2->Dequeue() == 5);

      delete pQ2;
      delete [] a;
    }

    static int Double(int n) { return n * 2; }
    static void test_Map_MinHeap()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      PriorityQueue<int>* pQ = new PriorityQueue<int>(a, 6);

      PriorityQueue<int>* mapped = pQ->Map(Double);

      for(int i = 0; i <= 5; i++) assert(pQ->Dequeue() == i);
      for(int i = 0; i <= 5; i++) assert(mapped->Dequeue() == i * 2);

      delete [] a;
      delete pQ;
      delete mapped;
    }

    static bool isOdd(int n) { return (n % 2) ? true : false; }
    static void test_Where_MinHeap()
    {
      int* a = new int[6];
      for(int i = 0; i < 6; i++) a[i] = i;

      PriorityQueue<int>* pQ = new PriorityQueue<int>(a, 6);

      PriorityQueue<int>* whered = pQ->Where(isOdd);


      for(int i = 0; i <= 5; i++) assert(pQ->Dequeue() == i);
      for(int i = 5; i >= 0; i--) {
        int t = whered->Dequeue();
        assert(t == 1 || t == 0);
      }

      delete [] a;
      delete pQ;
      delete whered;
    }

    static int reduceF(int n1, int n2) { return 2*n1 + 3*n2; }
    static void test_Reduce()
    {
      int a[3] = {1, 2, 3};

      PriorityQueue<int>* pQ = new PriorityQueue<int>(a, 3);
      
      int b = pQ->Reduce(reduceF, 4);
      assert(b == 144);

      delete pQ;
    }
  public:
    static void Run()
    {
      test_Create_Enqueue_Dequeue_MinHeap();
      test_Map_MinHeap();
      test_Where_MinHeap();
      test_Reduce();
      std::cout << "PriorityQueue tests finished successfully. \n";
    }
};