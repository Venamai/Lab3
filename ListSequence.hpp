#pragma once
#include "Sequence.hpp"
#include "LinkedList.hpp"

template <class T> class ListSequence : public Sequence<T>
{
  private:
    LinkedList<T>* buffer;
    size_t size;
  public:
    ListSequence(T* items, int count)         : buffer(new LinkedList<T>(items, count)), size(count)     {}
    ListSequence()                            : buffer(new LinkedList<T>()), size(0)                     {}
    ListSequence(const LinkedList<T>* list)   : buffer(new LinkedList<T>(list)), size(list->GetSize())   {}
    ~ListSequence() { delete this->buffer; }
  public:
    virtual T GetFirst() const override         { return this->buffer->GetFirst(); }                                             
    virtual T GetLast() const override          { return this->buffer->GetLast(); }                                              
    virtual T Get(int index) const override     { return this->buffer->Get(index);}     
    virtual int GetLength() const override      { return this->size; }            
    virtual bool IsEmpty() const override       { return this->size ? true : false; }        

    virtual void Append(T item) override        { this->InsertAt(this->size, item); }                                             
    virtual void Prepend(T item) override       { this->InsertAt(0, item); }                  

    virtual void InsertAt(int index, T item) override
    {
      if(index > this->size || index < 0) throw std::out_of_range("ListSequence::InsertAt(T int) index out of range");
      this->buffer->InsertAt(index, item);
      this->size++;
    } 

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override {
      if (startIndex < 0 || startIndex >= this->size || endIndex < 0 || endIndex > this->size || startIndex >= endIndex) throw std::out_of_range("ListSequnce::GetSubsequence(int int) index out of range");
      ListSequence<T>* subseq = new ListSequence();
      for(int i = startIndex; i < endIndex; i++) subseq->Append(this->buffer->Get(i));
      return subseq;
    }                                         
                            
    virtual Sequence<T>* Concat(Sequence <T> *list) override
    {
      list = (ListSequence<T>*) list;
      ListSequence<T>* newSeq = new ListSequence(this->buffer);
      for(int k = 0; k < list->GetLength(); k++) newSeq->Append(list->Get(k));
      return (Sequence<T>*) newSeq;
    }

    virtual void Remove(int index)
    {
      if(index < 0 || index >= this->size) throw std::out_of_range("ListSequence::Remove(int) index out of range\n");
      this->buffer->Remove(index);
      this->size--;
    }
};