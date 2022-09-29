#pragma once
#include <iostream>

template <class T> class ListItem
{
  private:
    T value;
    ListItem<T>* prev;
    ListItem<T>* next;
  
  public:
    ListItem() : value(NULL), prev(NULL), next(NULL) {}
    ListItem(T value) : value(value), prev(NULL), next(NULL) {}
  
  public:
    T GetValue()                      { return this->value; }
    void SetValue(T value)          { this->value = value;  }

    ListItem<T>* GetPrev()           {  return this->prev;  }
    ListItem<T>* GetNext()           {  return this->next;  }

    void SetPrev(ListItem<T>* ptr)     {  this->prev = ptr; }
    void SetNext(ListItem<T>* ptr)     {  this->next = ptr; }
};


template <class T> class LinkedList {
  private:
    ListItem<T>* head;
    ListItem<T>* tail;
    size_t size;
  public:
    LinkedList (const T* items, size_t count) : size(count)
    {
      if(items == NULL || count == 0) throw "Linked list created from empty array";
      ListItem<T>* tmp = new ListItem<T>(items[0]);
      this->head = tmp;
      for (int i = 1; i < count; i++) 
      {
        ListItem<T>* item = new ListItem<T>(items[i]);
        item->SetPrev(tmp);
        tmp->SetNext(item);
        tmp = item;
      }
      this->tail = tmp;
    }

    LinkedList() : head(NULL), tail(NULL), size(0) {}

    LinkedList (const LinkedList <T>* list) 
    {
      this->size = list->GetSize();
      if(!this->size) {
        this->head = NULL;
        this->tail = NULL;
        return;
      }

      ListItem<T>* temp = list->GetHead();
      ListItem<T>* item = new ListItem<T>(temp->GetValue());
      this->head = item;
      while(temp->GetNext() != NULL) {
        temp = temp->GetNext();
        ListItem<T>* prev = item;
        item = new ListItem<T>(temp->GetValue());
        prev->SetNext(item);
        item->SetPrev(prev);
      }
      this->tail = item;
    }

    ~LinkedList()
    {
      ListItem<T>* item = this->head;
      while (item != NULL) {
        ListItem<T>* next = item->GetNext();
        delete item;
        item = next;
      }
    }

  public:
    ListItem<T>* GetHead() const { return this->head; }

    size_t GetSize() const { return this->size; }

    T GetFirst() 
    {
      if(!this->size) throw std::out_of_range ("LinkedList is empty");
      return this->head->GetValue();
    }

    T GetLast()
    {
      if(!this->size) throw std::out_of_range ("LinkedList is empty");
      return this->tail->GetValue();
    }

    T Get(int index)
    {
      if (index < 0 || index >= this->size) throw std::out_of_range("LinkedList::Get(int) index out of range");
      ListItem<T>* item = this->head;
      ListItem<T>* next = item->GetNext();
      for (int i = 0; i < index; i++) item = item->GetNext();
      return item->GetValue();
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {
      if (startIndex < 0 || startIndex >= this->size || endIndex < 0 || endIndex >= this->size || startIndex >= endIndex) throw std::out_of_range("LinkedList::GetSubList() index out of range");
      LinkedList<T>* sublist = new LinkedList<T>();
      for (int i = startIndex; i < endIndex; i++) sublist->Append(this->Get(i));
      return sublist;
    }

    void Prepend(T item) { this->InsertAt(0, item); }

    void Append(T item)  { this->InsertAt(this->size, item); }

    void InsertAt(int index, T item)
    {
      if (index < 0 || index > this->size) throw std::out_of_range("LinkedList::InsertAt() index out of range");
      
      ListItem<T>* newItem = new ListItem<T>(item);
      if(!this->size) {
        this->head = newItem;
        this->tail = newItem;
        this->size++;
        return;
      } else if(index == 0) {

        newItem->SetNext(this->head);
        this->head->SetPrev(newItem);
        this->head = newItem;

      } else if(index == this->size) {

        this->tail->SetNext(newItem);
        newItem->SetPrev(this->tail);
        this->tail = newItem;

      } else {

        ListItem<T>* iterator = this->head;
        for(int i = 0; i < index; i++) iterator = iterator->GetNext();
        iterator->GetPrev()->SetNext(newItem);
        newItem->SetPrev(iterator->GetPrev());
        newItem->SetNext(iterator);
        iterator->SetPrev(newItem);
      }
      this->size++;      
    }

    void Remove(int index)
    {
      if(index >= this->size || index < 0) throw std::out_of_range("LinkedList::Remove() index out of range");

      ListItem<T>* item = this->head;
      for(int i = 0; i < index; i++) item = item->GetNext();

      if(!index && this->size > 1) {
        ListItem<T>* next = item->GetNext();
        next->SetPrev(item->GetPrev());
        this->head = next;
      } else if (!index && this->size == 1) {
        this->head = NULL;
        this->tail = NULL;

      } else if (index == this->size - 1) {
        ListItem<T>* prev = item->GetPrev();
        prev->SetNext(item->GetNext());
        this->tail = prev;
      } else {
        (item->GetPrev())->SetNext(item->GetNext());
        (item->GetNext())->SetPrev(item->GetPrev());
      }
      delete item;
      this->size--;
    }
};