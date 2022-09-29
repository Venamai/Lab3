#pragma once

#include "ArraySequence.hpp"
// #include "PriorityQueue.hpp"

template <class T>
class BinaryHeap
{
  private:
    Sequence<T>* buffer;

  public:
    BinaryHeap(T* items, size_t len)
    {
      if(!len || items == nullptr) throw std::invalid_argument("BinaryHeap(T*, size_t) empty array given.");
      buffer = new ArraySequence<T>(items, len);

      T plug = buffer->GetFirst(); //To make it able to say roor's index is 1
      buffer->Prepend(plug);
      for (int i = len / 2; i >= 1; i--) 
        MinHeapify(i);        
    }

    BinaryHeap(Sequence<T>* sequence) : buffer(sequence) {}

    BinaryHeap()
    {
      T* fake = new T[1];
      buffer = new ArraySequence<T>(fake, 1);
      delete [] fake;
    }

   ~BinaryHeap() { delete (ArraySequence<T>*) this->buffer; }

  private:
    void Swap(int i, int k)
    {
      T tmpi = buffer->Get(i);
      T tmpk = buffer->Get(k);
      buffer->Remove(i);
      buffer->InsertAt(i, tmpk);
      buffer->Remove(k);
      buffer->InsertAt(k, tmpi);
    }
    void MaxHeapify(int i)
    {
      int len = buffer->GetLength() - 1;
      int l = 2*i;
      int r = 2*i + 1;
      int largest;

      largest = (l <= len && buffer->Get(l) > buffer->Get(i)) ? l : i;

      if(r <= len && buffer->Get(r) > buffer->Get(largest))
        largest = r;

      if (largest != i) {
        Swap(i, largest);
        MaxHeapify(largest);
      }
    }
    void MinHeapify(int i)
    {
      int len = buffer->GetLength() - 1;
      int l = 2*i;
      int r = 2*i + 1;
      int lowest;

      lowest = (l <= len && buffer->Get(l) < buffer->Get(i)) ? l : i;

      if(r <= len && buffer->Get(r) < buffer->Get(lowest))
        lowest = r;

      if (lowest != i) {
        Swap(i, lowest);
        MinHeapify(lowest);
      }
    }
    // void ForEach(size_t i, void(*action) (T))
    // {
    //   PriorityQueue<int>* queue = new PriorityQueue();
    //   queue->Enqueue(i);
    //   while(!queue->IsEmpty()) {
    //     int index = queue->Dequeue();
    //     action(buffer->Get(index));
    //     if (2*index <= this->GetLength()) queue->Enqueue(2*index);
    //     if (2*index + 1 <= this->GetLength()) queue->Enqueue(2*index + 1);
    //   }
    //   delete queue;
    // }


  public:

    bool IsEmpty()  { return buffer->GetLength() == 1; }
    int GetLength() { return buffer->GetLength() - 1; }

    T Peek(const size_t i)
    {
      if(buffer->IsEmpty()) throw std::logic_error("BinaryHeap::Peek(cont int) heap is empty.");
      T item = buffer->Get(i + 1);
      return item;
    }

    void Insert(T item)
    {
      int i = buffer->GetLength();
      buffer->Append(item);
      while(item < buffer->Get(i / 2) && (i / 2)) { 
        Swap(i, i / 2);
        i /= 2;
      }
    }

    T Extract()
    {
      if(buffer->GetLength() == 1) throw std::logic_error("BinaryHeap::Extract() heap is empty.");
      T rootExtracted = buffer->Get(1);

      int lastIndex = buffer->GetLength() - 1;

      Swap(1, lastIndex);
      buffer->Remove(lastIndex);

      int newRootIndx = 1;
      MinHeapify(newRootIndx);
      return rootExtracted;
    }

    bool Search(const T item) const
    {
      for(int i = 1; i < this->buffer->GetLength(); i++) 
        if(this->buffer->Get(i) == item)
          return true;

      return false;
    }

    void Delete(T item)
    {
      int len = this->buffer->GetLength() - 1;
      if(!len)
        throw std::logic_error("BinaryHeap::Delete(T) heap is empty.");
      
      for(int i = 1; i <= len; i++) {
        if (this->buffer->Get(i) == item) {
          Swap(i, len);
          this->buffer->Remove(len);
          MinHeapify(i);
          return;          
        }
      }
      throw std::logic_error("BinaryHeap::Delete(T) no such element found to delete.");
    }

    BinaryHeap<T>* GetSubtree(T item)
    {
      int len = this->buffer->GetLength();
      if(!len)
        throw std::logic_error("BinaryHeap::GetSubtree(T) heap is empty.");

      ArraySequence<T>* a = new ArraySequence<T>();
      auto fill_a = [&](T item) { a->Append(item); };
      for(int i = 1; i <= len; i++) {
        if (this->buffer->Get(i) == item) {
          // ForEach(i, fill_a);
          return new BinaryHeap(a);
        }
      }
    }

    BinaryHeap<T>* Map(T (*f) (T))
    {
      int bufLen = this->buffer->GetLength() - 1;
      T* mappedArray = new T[bufLen];
      for(int i = 1; i <= bufLen; i++) { mappedArray[i - 1] = f(this->buffer->Get(i)); }
      BinaryHeap<T>* bh = new BinaryHeap<T>(mappedArray, bufLen);
      delete [] mappedArray;
      return bh;
    }

    BinaryHeap<T>* Where(bool (*f) (T))
    {
      int bufLen = this->buffer->GetLength() - 1;
      T* wheredArray = new T[bufLen];
      for(int i = 1; i <= bufLen; i++) { wheredArray[i - 1] = f(this->buffer->Get(i)); }
      BinaryHeap<T>* bh = new BinaryHeap<T>(wheredArray, bufLen);
      delete [] wheredArray;
      return bh;
    }

    T Reduce(T (*f) (T, T), T c)
    {
      T result = f(this->buffer->Get(1), c);
      for(int i = 2; i <= this->buffer->GetLength() - 1; i++) {
        result = f(this->buffer->Get(i), result);
      }
      return result;
    }

    // bool FindSubtree(BinaryHeap<T>* tree)
    // {

    // }

    void Print()
    {
      for(int i = 1; i < this->buffer->GetLength(); i++) std::cout << this->buffer->Get(i) << std::endl;
      std::cout << '\n';
    }


};