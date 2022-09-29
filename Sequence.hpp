#pragma once
template <class T> class Sequence
{
  public:
    virtual T GetFirst() const                                                = 0;
    virtual T GetLast() const                                                 = 0;
    virtual T Get(int index) const                                            = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const   = 0;
    virtual int GetLength() const                                             = 0;
    virtual bool IsEmpty() const                                              = 0;
    virtual void Append(T item)                                               = 0;
    virtual void Prepend(T item)                                              = 0;
    virtual void InsertAt(int index, T item)                                  = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list)                            = 0; 
    virtual void Remove(int index)                                            = 0;
};