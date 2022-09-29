#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"
template <class T> class ArraySequence : public Sequence<T>
{
  private:
    DynamicArray<T>* buffer;
    size_t count;
  public:
    ArraySequence(T* items, int count)            : buffer(new DynamicArray<T>(items, count)), count(count)     {}
    ArraySequence()                               : count(0), buffer(new DynamicArray<T>(1))                    {}
    ArraySequence(const DynamicArray<T>* array)   : buffer(new DynamicArray<T>(array)), count(array->GetCount()) {}

    ~ArraySequence() { delete this->buffer; }

  public:

    virtual T GetFirst() const override       { return this->buffer->Get(0); }                                             
    virtual T GetLast() const override        { return this->buffer->Get(this->count - 1); }                                              
    virtual T Get(int index) const override   { return this->buffer->Get(index); }
    virtual int GetLength() const override    { return this->count; }
    virtual bool IsEmpty() const override     { return !this->count ? true : false; }

    virtual void Append(T item) override      { this->InsertAt(this->count, item); }                                             
    virtual void Prepend(T item) override     { this->InsertAt(0, item); }    
       

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override
    {
      if (startIndex < 0 || startIndex >= this->count || endIndex < 0 || endIndex > this->count || startIndex >= endIndex) throw std::out_of_range("ArraySequence::GetSubsequence(int int) index out of range");
      ArraySequence<T>* subseq = new ArraySequence();
      for(int i = startIndex; i < endIndex; i++) subseq->Append(this->buffer->Get(i));
      return subseq;
    }
                                             
                                          
    virtual void InsertAt(int index, T item) override
    {
      if(index < 0  || index > this->count) throw std::out_of_range("ArraySequence::InsertAt(T int) index out of range");
      DynamicArray<T>* b = this->buffer;
      if(this->count == b->GetSize()) b->Resize(b->GetSize() * 2);
      this->buffer->Set(index, item);
      this->count++;
    }                

    virtual Sequence<T>* Concat(Sequence<T>* list) override
    {
      list = (ArraySequence<T>*) list;
      ArraySequence<T>* newSeq = new ArraySequence(this->buffer);
      for (int i = 0; i < list->GetLength(); i++) newSeq->Append(list->Get(i));
      return (Sequence<T>*) newSeq;
    }

    virtual void Remove(int index) override
    {
      this->buffer->Remove(index);
      this->count--;
      size_t bufferSize = this->buffer->GetSize();
      if(bufferSize >= 3 * this->count) this->buffer->Resize(0.5 * bufferSize);
    }                  
};