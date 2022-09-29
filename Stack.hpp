#pragma once
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include <iostream>

template <class T> class Stack
{
  private:
    Sequence<T>* buffer;
    int choice;
  
  public:
    Stack(int choice) 
    {
    //   int choice;
    //   std::cout << "Choose how to create a stack:\n 1. ArraySequnce\n 2. ListSequence\n";
    //   std::cin >> choice;
    //   std::cout << choice << std::endl;
    //   while(choice != 1 && choice != 2) {
    //     std::cout << "Wrong choice.\n";
    //     std::cin >> choice;
    //   }
      
      switch(choice) {
        case 1:
          this->buffer = new ArraySequence<T>();
          break;
        case 2:
          this->buffer = new ListSequence<T>();
          break;
        default:
          throw std::invalid_argument("Something went wrong in Stack constructor\n");

      }
      this->choice = choice;
    }
    Stack(T* items, int count, int choice) 
    {
      // int choice;
      // std::cout << "Choose how to create a stack:\n 1. ArraySequnce\n 2. ListSequence\n";
      // std::cin >> choice;
      // while(choice != 1 && choice != 2) {
      //   std::cout << "Wrong choice.\n";
      //   std::cin >> choice;
      // }
      switch(choice) {
        case 1:
        this->buffer = new ArraySequence<T>(items, count);
          break;
        case 2:
          this->buffer = new ListSequence<T>(items, count);
          break;
        default:
          throw std::invalid_argument("Something went wrong in Stack constructor\n");
      }
      this->choice = choice;
    }
    ~Stack()  
    {
      switch(this->choice) {
        case 1:
          delete (ArraySequence<T>*) this->buffer; 
          break;
        case 2:
          delete (ListSequence<T>*) this->buffer; 
          break;
        default:
          std::cout << "Something went wrong in Stack constructor\n";
      }
    }
  public:

    int GetLength() const { return this->buffer->GetLength(); }
    bool IsEmpty() const { return this->buffer->IsEmpty(); }

    void Push(T item) { this->buffer->Append(item); }

    T Pop()
    {
      if(this->buffer->GetLength() == 0) throw std::out_of_range("Stack::Pop() stack is empty");
      T el = this->buffer->GetLast();
      this->buffer->Remove(this->buffer->GetLength() - 1);
      return el;
    }

    Stack<T>* Map(T (*f) (T))
    {
      int bufLen = this->buffer->GetLength();
      T* mappedArray = new T[bufLen];
      for(int i = 0; i < bufLen; i++) { mappedArray[i] = f(this->buffer->Get(i)); }
      Stack<T>* s = new Stack<T>(mappedArray, bufLen, 1);
      delete [] mappedArray;
      return s;
    }

    Stack<T>* Where(bool (*f) (T))
    {
      int bufLen = this->buffer->GetLength();
      T* wheredArray = new T[bufLen];
      for(int i = 0; i < bufLen; i++) { wheredArray[i] = f(this->buffer->Get(i)); }
      Stack<T>* s = new Stack<T>(wheredArray, bufLen, 1);
      delete [] wheredArray;
      return s;
    }

    T Reduce(T (*f) (T, T), T c)
    {
      T result = f(this->buffer->Get(0), c);
      for(int i = 1; i < this->buffer->GetLength(); i++) {
        result = f(this->buffer->Get(i), result);
      }
      return result;
    }

    Stack<T>* Concat(Stack<T>* stack)
    {
      Stack<T>* newStack = new Stack(1);
      for(int i = 0; i < this->buffer->GetLength(); i++) newStack->Push(this->buffer->Get(i));
      Stack<T>* tmpStack = new Stack(1);
      int stackLen = stack->GetLength();
      for(int i = 0; i < stackLen; i++) tmpStack->Push(stack->Pop());
      for(int i = 0; i < stackLen; i++) newStack->Push(tmpStack->Pop());
      delete tmpStack;
      return newStack;
    }

    Stack<T>* GetSubsequence(int startIndex, int endIndex)
    {
      int count = this->buffer->GetLength();
      if (startIndex < 0 || startIndex >= count || endIndex < 0 || endIndex > count || startIndex >= endIndex) throw std::out_of_range("Stack::GetSubsequence(int int) index out of range");
      Stack<T>* sub = new Stack<T>(1);
      for (int i = startIndex; i < endIndex; i++) sub->Push(this->buffer->Get(i));
      return sub;
    }

    bool FindSubsequence(T* items, int count)
    {
      if(items == NULL || count == 0) throw std::invalid_argument("FindSubsequence(T* int) empty array given");
      int matches = 0;
      for (int i = 0; i < this->buffer->GetLength(); i++) {
        if(items[0] == this->buffer->Get(i)){
          matches++;
          for(int k = 1; k < count; k++) {
            if(++i >= this->buffer->GetLength()) break;
            if(this->buffer->Get(i) != items[k]) break;
            matches++;
          }
          if(matches == count) return true;
          matches = 0;
        }
      }
      return false;
    }

    void hanoiPrint()
    {
      std::cout << "[ ";
      for(int i = 0; i < this->buffer->GetLength(); i++) {
        std::cout << this->buffer->Get(i) << ' ';
      }
      std::cout << ']';
      std::cout << '\n';
    }
};