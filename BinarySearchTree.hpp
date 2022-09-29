#pragma once
#include <iostream>
#include <cstring>
// #include <type_traits>

#include <regex>
#include "PriorityQueue.hpp"
#include "Pair.hpp"
#include "Stack.hpp"

using namespace std;

template <class T>
class Node
{
  private:
    T value;
    Node<T>* leftChild;
    Node<T>* rightChild;
    Node<T>* parent;
    int balanceFactor;
  public:
    Node(T item) : value(item), leftChild(nullptr), rightChild(nullptr), parent(nullptr) {}
  public:
    Node<T>* GetLeft()    { return this->leftChild; }
    Node<T>* GetRight()   { return this->rightChild; }
    Node<T>* GetParent()  { return this->parent; }
    int GetBalanceFactor() { return this->balanceFactor; }


    T GetValue()          { return this->value; }
    bool HasChildren()    { return leftChild != nullptr || rightChild != nullptr; }

    void SetLeft(Node<T>* node)    { this->leftChild = node; }
    void SetRight(Node<T>* node)   { this->rightChild = node; }
    void SetParent(Node<T>* node)  { this->parent = node; }
    void SetBalanceFactor(int n)   { this->balanceFactor = n; }

    bool operator == (const Node<T>* other) { return this->value == other->value; }
};

template <class T>
class BinarySearchTree
{
  private:
    Node<T>* root;
    int len;

  
  public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(Stack<T>* stack) : root(nullptr)
    {
      while(!stack->IsEmpty()) 
        this->Insert(stack->Pop());
      
    }
    ~BinarySearchTree()
    {
      auto del = [] (Node<T>* node)
      {
        delete node;
      };
      this->ForEachNode(del);
    }

  private:
    Node<T>* FindNode(T value)
    {
      if(root == nullptr) return nullptr;

      PriorityQueue<Node<T>*>* queue = new PriorityQueue<Node<T>*>();
      queue->Enqueue(root);
      while(queue->GetLength()) {
        Node<T>* node = queue->Dequeue();
        if(node->GetValue() == value) {
          delete queue;
          return node;
        }
        if(node->GetLeft()) queue->Enqueue(node->GetLeft());
        if(node->GetRight()) queue->Enqueue(node->GetRight());
      }
      delete queue;
      return nullptr;
    }

    Node<T>* TreeMin(Node<T>* node)
    {
      while(node->GetLeft() != nullptr) node = node->GetLeft();
      return node;
    }

    Node<T>* FindSuccessor(Node<T>* node)
    {
      if(node->GetRight() != nullptr) 
        return TreeMin(node->GetRight());

      Node<T>* parent = node->GetParent();
      while(parent != nullptr && node == parent->GetRight()) {
        node = parent;
        parent = node->GetParent();
      }
      return parent;
    }

    

    string AskTraverseOrder()
    {
      string s;
      cout << "Enter traverse order like NLR (Node Left Right): \n";
      cin >> s;
      while(!regex_match(s, regex("[NLR]{3}")) || s.length() != 3) {
        cout << "Wrong input. Try again: \n";
        cin >> s;
      }
      return s;
    }

    void ForEachNode(void (*action) (Node<T>*), Node<T>* firstNode = nullptr) 
    {
      if(!root) return;
      PriorityQueue<Node<T>*>* queue = new PriorityQueue<Node<T>*>();
      Node<T>* start = firstNode ? firstNode : root;
      queue->Enqueue(start);
      
      while(!queue->IsEmpty()) {
        Node<T>* node = queue->Dequeue();
        
        if(node->GetLeft()) queue->Enqueue(node->GetLeft());
        if(node->GetRight()) queue->Enqueue(node->GetRight());
        action(node);
      }
      delete queue;
    }

    template <typename K, typename G> 
    void ForEachValue(void (*action) (T, K (*) (T), G), K (*foo) (T), G store, Node<T>* firstNode = nullptr) 
    {
      if(!root) return;
      PriorityQueue<Node<T>*>* queue = new PriorityQueue<Node<T>*>();
      Node<T>* start = firstNode ? firstNode : root;
      queue->Enqueue(start);
      
      while(!queue->IsEmpty()) {
        Node<T>* node = queue->Dequeue();
        
        if(node->GetLeft()) queue->Enqueue(node->GetLeft());
        if(node->GetRight()) queue->Enqueue(node->GetRight());
        action(node->GetValue(), foo, store);
      }
      delete queue;
    }

    string Traverse(void (*action) (Node<T>*), string order)
    {
      string row = "";
      if(!root) return row;
      Stack<Pair<Node<T>*, bool>>* stack = new Stack<Pair<Node<T>*, bool>>(1);
      stack->Push(Pair<Node<T>*, bool>(this->root, false));
      while(!stack->IsEmpty()) {
        Pair<Node<T>*, bool> pair = stack->Pop();
        if(pair.GetSecond()) {
          Node<T>* el = pair.GetFirst();
          // if(!(is_same<T, Complex>::value || is_same<T, Student>::value))
          row += "[ " + to_string(el->GetValue()) + " ] ";
          
          action(el);
        } else {
          for(int i = order.length() - 1; i >= 0; i--) {
            switch(order[i]) {
              case 'N':
                stack->Push(Pair<Node<T>*, bool>(pair.GetFirst(), true));
                break;
              case 'L':
                if(pair.GetFirst()->GetLeft()) { stack->Push(Pair<Node<T>*, bool>(pair.GetFirst()->GetLeft(), false)); }
                break;
              case 'R':
                if(pair.GetFirst()->GetRight()) { stack->Push(Pair<Node<T>*, bool>(pair.GetFirst()->GetRight(), false)); }
                break;
              default:
                throw std::invalid_argument("BinarySearchTree::Traverse(void (Node<T>*), string) wrong order option.");
            }
          }
        }
      }
      delete stack;
      return row;
    }

    int GetHeight(Node<T>* node)
    {
      if(!node) return 0;
      Node<T>* leftHeight = GetHeight(node->GetLeft());
      Node<T>* rightHeight = GetHeight(node->GetRight());
      return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

  public:

    bool IsEmpty() { return root == nullptr; }
    
    void Insert(T value)
    {
      // if(this->FindNode(value)) return;
      Node<T>* insert = new Node<T>(value);
      Node<T>* tmp = root;
      Node<T>* parent = nullptr;
      while(tmp != nullptr) {
        parent = tmp;
        tmp = value < tmp->GetValue() ? tmp->GetLeft() : tmp->GetRight();
      }
      insert->SetParent(parent);
      if(parent ==  nullptr) {
        root = insert;
      } else if(value < parent->GetValue()) {
        parent->SetLeft(insert);
      } else if(value > parent->GetValue()) {
        parent->SetRight(insert);
      } else {
        return;
      }
      this->len++;
    }

    void Remove(T value)
    {
      Node<T>* node = this->FindNode(value);
      Node<T>* parent = node->GetParent();
      auto set_child_to_parent = [&](Node<T>* child)
      {
        if(parent) 
          parent->GetLeft() == node ? parent->SetLeft(child) : parent->SetRight(child);
      };
      if(!node->HasChildren()) {

        set_child_to_parent(nullptr);
        if(!parent) this->root = nullptr;

      } else if(node->GetLeft() == nullptr || node->GetRight() ==  nullptr) {

        Node<T>* child = node->GetLeft() ? node->GetLeft() : node->GetRight();
        set_child_to_parent(child);
        child->SetParent(parent);
        if(!parent) this->root = child;
        

      } else {
        Node<T>* successor = FindSuccessor(node);

        if (node->GetRight() == successor) {
          set_child_to_parent(successor);
          successor->SetLeft(node->GetLeft());
        } else {
          successor->GetParent()->SetLeft(successor->GetRight());
          successor->GetRight()->SetParent(successor->GetParent());
          successor->SetParent(node->GetParent());
          successor->SetLeft(node->GetLeft());
        }
        if(!parent) this->root = successor;
        
      }
      delete node;
      this->len--;
    }

    bool Search(T value)
    {
      return this->FindNode(value) != nullptr;
    }

    string ToString(string defaultOrder = "0")
    {
      string order = defaultOrder == "0" ? this->AskTraverseOrder() : defaultOrder;
      auto plug = [](Node<T>* node) {};
      return this->Traverse(plug, order);
    }

    void FromString()
    {}

    string GetPrint()
    {
      string s;
      auto plug = [] (T item) { return item; };
      auto foo = [] (T value, T (*f) (T), string* s) {
        *s += to_string(value) + " -> ";
      };
      this->ForEachValue<T, string*>(foo, plug, &s);
      return s;
    }

    BinarySearchTree<T>* Map(T (*f) (T))
    {
      // Stack<T>* stack = new Stack<T>(1);
      BinarySearchTree<T>* newTree = new BinarySearchTree<T>();
      auto foo = [] (T value, T (*f) (T), BinarySearchTree<T>* tree) {
        T mapped = f(value);
        tree->Insert(mapped);
      };
      this->ForEachValue<T, BinarySearchTree<T>*>(foo, f, newTree);
      // BinarySearchTree<T>* newTree = new BinarySearchTree<T>(stack);
      // delete stack;
      return newTree;
    }

    BinarySearchTree<T>* Where(bool (*f) (T))
    {
      Stack<T>* stack = new Stack<T>(1);
      auto foo = [] (T value, bool (*f) (T), Stack<T>* stack) {
        bool whered = f(value);
        if(whered) stack->Push(value);
      };
      this->ForEachValue<bool, Stack<T>*>(foo, f, stack);
      BinarySearchTree<T>* newTree = new BinarySearchTree<T>(stack);
      delete stack;
      return newTree;
    }

    void Merge(BinarySearchTree<T>* tree)
    {
      auto plug = [] (T item) { return item; };
      auto add = [](T value, T (*f) (T), BinarySearchTree<T>* recipient)
      {
        recipient->Insert(value);
      };
      tree->ForEachValue<T, BinarySearchTree<T>*>(add, plug, this);
    }

    BinarySearchTree<T>* GetSubtree(T value)
    {
      Node<T>* match = FindNode(value);
      if(!match) throw std::logic_error("BinarySearchTree::GetSubtree(T) no such value found.");

      BinarySearchTree<T>* newTree = new BinarySearchTree<T>();

      auto plug = [] (T item) { return item; };
      auto add = [] (T value, T (*f) (T), BinarySearchTree<T>* recipient)
      {
        recipient->Insert(value);
      };

      ForEachValue<T, BinarySearchTree<T>*>(add, plug, newTree, match);
      return newTree;
    }
};
