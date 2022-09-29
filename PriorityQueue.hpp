#pragma once
#include "BinaryHeap.hpp"
#include "IPriorityQueue.hpp"

template<class T>
class PriorityQueue : IPriorityQueue<T> 
{
  private:
    BinaryHeap<T>* heap;

  public:
    PriorityQueue(T* items, size_t len) : heap(new BinaryHeap<T>(items, len))  {};
    PriorityQueue()                     : heap(new BinaryHeap<T>())            {};
    
    ~PriorityQueue() { delete this->heap; }

  public:
    bool IsEmpty() { return heap->IsEmpty(); }
    int GetLength() { return heap->GetLength(); }
    virtual void Enqueue(T item) override { heap->Insert(item); }
    virtual T Dequeue() override { return heap->Extract(); }

    virtual T Peek(const size_t i) const override { return heap->Peek(i); }
    virtual T PeekFirst() const override { return heap->Peek(0); }
    virtual T PeekLast() const override { return heap->Peek(heap->GetLength() - 1); }

    PriorityQueue<T>* Map(T (*f) (T))
    {
      BinaryHeap<T>* mapped = heap->Map(f);

      int len = mapped->GetLength();
      T* arr =  new T[len];

      for(int i = 0; i < len; i++) 
        arr[i] = mapped->Extract();
      
      PriorityQueue<T>* pQ = new PriorityQueue<T>(arr, len);
      delete mapped;
      delete [] arr;
      return pQ;
    }

    PriorityQueue<T>* Where(bool (*f) (T))
    {
      BinaryHeap<T>* whered = heap->Where(f);

      int len = whered->GetLength();
      T* arr =  new T[len];

      for(int i = 0; i < len; i++) 
        arr[i] = whered->Extract();
      
      PriorityQueue<T>* pQ = new PriorityQueue<T>(arr, len);
      delete whered;
      delete [] arr;
      return pQ;
    }

    T Reduce(T (*f) (T, T), T c)
    {
      T reduced = heap->Reduce(f, c);
      return reduced;
    }

    void Print()
    {
      heap->Print();
    }
};