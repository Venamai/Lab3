#include <iostream>
#include <cstring>
#include <time.h>
#include "Stack.hpp"
#include "unit_tests_ArraySequence.hpp"
#include "unit_tests_DynamicArray.hpp"
#include "unit_tests_LinkedList.hpp"
#include "unit_tests_ListSequence.hpp"
#include "unit_tests_Stack.hpp"
#include "unit_tests_BinaryHeap.hpp"
#include "unit_tests_PriorityQueue.hpp"
#include "unit_tests_BinarySearchTree.hpp"
#include "BinaryHeap.hpp"
#include "PriorityQueue.hpp"
#include "BinarySearchTree.hpp"
#include "Complex.hpp"
#include "Student.hpp"

int ask(const char*, int);
void clean(BinarySearchTree<int>*, BinarySearchTree<double>*, BinarySearchTree<Complex>*, BinarySearchTree<std::string>*, BinarySearchTree<char>*, BinarySearchTree<Student>*);
void menu();
