#pragma once
#include <cstring>
#include <iostream>

template <class T> class DynamicArray
{
  private:
    T* ptr;
    size_t size;
    size_t count;
  private:
    

  public:
    ~DynamicArray()
    {
      delete [] this->ptr;
    }

    DynamicArray(T* items, size_t count) : size(count * 2), count(count)
    {
      if (items == NULL || count == 0) throw "DynamicArray() called with empty array";
      this->ptr = new T[count * 2];
      for(int i = 0; i < count; i++) this->ptr[i] = items[i];
      // memcpy(this->ptr, items, count * sizeof(T));
    }
    DynamicArray(size_t size) : count(0)
    {
      this->size = !size ? 1 : size;

      this->ptr = new T[this->size];
      this->size = size;
    }
    DynamicArray(const DynamicArray<T>* dynamicArray)
    {
      size_t daLen = dynamicArray->GetCount();
      this->ptr = new T[daLen * 2];
      this->size = daLen * 2;
      this->count = 0;
      for(int i = 0; i < daLen; i++) this->Set(i, dynamicArray->Get(i));
    }

  public:
    size_t GetSize() const
    {
      return this->size;
    }

    size_t GetCount() const
    {
      return this->count;
    }

    T Get(int index) const
    {
      if (index >= this->count || index < 0) throw std::out_of_range ("DynamicArray::Get() index out of range");
      return this->ptr[index];
    }

    
    void Set(int index, T value)
    {
      if(index > this->count || index < 0) throw std::out_of_range ("DynamicArray::Set() index out of range");
      if(this->count == this->size) this->Resize(this->count + 1);
      memmove(this->ptr + (index + 1), this->ptr + index, (this->count++ - index) * sizeof(T));
      this->ptr[index] = value;
    }

    void Remove(int index)
    {
      if(index > this->count || index < 0) throw std::out_of_range ("DynamicArray::Set() index out of range");
      memmove(this->ptr + index, this->ptr + (index + 1), (this->count-- - index - 1) * sizeof(T));
    }

    //newSize is multiplier for number of elements like newSize * sizeof(T)
    void Resize(size_t newSize)
    {
      T* newPtr = new T[newSize];
      size_t sizeToCpy = (newSize > this->size) ? this->size : newSize;
      memcpy(newPtr, this->ptr, sizeToCpy * sizeof(T));
      this->size = newSize;
      this->count = sizeToCpy;
      delete [] this->ptr;
      this->ptr = newPtr;
    }
};
