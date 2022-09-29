#include "menu.h"



using namespace std;
int ask(const char* msgs[], int n)
{
  int choice = -1;
  string err = "";
  while (choice < 0 || choice >= n) {
    cout << err << endl;
    err = "Wrong input";
    for (int i = 0; i < n; i++) cout << msgs[i] << endl;
    cout << "Enter option: ";
    cin >> choice;
  }
  if(!choice) choice -= 20;
  return choice;
}

void clean(BinarySearchTree<int>* bst1, BinarySearchTree<double>* bst2, BinarySearchTree<Complex>* bst3, BinarySearchTree<string>* bst4, BinarySearchTree<char>* bst5, BinarySearchTree<Student>* bst6)
{  
  if(bst1) { delete bst1; }
  if(bst2) { delete bst2; }
  if(bst3) { delete bst3; }
  if(bst4) { delete bst4; }
  if(bst5) { delete bst5; }
  if(bst6) { delete bst6; }

}

void menu()
{
  const char* MAIN[] = {
    "0. Quit",
    "1. Create BinarySearchTree",
    "2. BinarySearchTree operations",
    "3. Run tests",
    "4. Run 100",
    "5. Run 10^5",
    "6. Run 10^7"
  };
  int main_size = 7;

  const char* CREATE[] = {
    "0. Quit",
    "1. Integers",
    "2. Floats",
    "3. Complex numbers",
    "4. Strings",
    "5. Symbols",
    "6. Students"
  };

  int create_size = 7;

  const char* TREE_OPERATIONS[] = {
    "0. Quit",
    "1. Insert",
    "2. Remove",
    "3. Search",
    "4. Traverse",
    "5. Get substree",
    "6. Merge"
  };
  int tree_operations_size = 7;

  BinarySearchTree<int>* bst1      = 0;
  BinarySearchTree<double>* bst2   = 0;
  BinarySearchTree<Complex>* bst3  = 0;
  BinarySearchTree<string>* bst4   = 0;
  BinarySearchTree<char>* bst5     = 0;
  BinarySearchTree<Student>* bst6  = 0;

  auto get_len = []()
  {
    int len;
    cout << "Enter number of elements: \n";
    cin >> len;
    while(len <= 0) {
      cout << "Inappropriate number of elements.\n";
      cout << "Enter number of elements: \n";
      cin >> len;
    }
    return len;
  };
  auto get_int_array = [](int len)
  {
    cout << "Enter ints: \n";
    int* a = new int[len];
    for(int i = 0 ; i < len; i++) cin >> a[i];
    return a;
  };
  auto get_double_array = [](int len)
  {
    cout << "Enter elements: \n";
    double* ar = new double[len];
    for(int i = 0 ; i < len; i++) cin >> ar[i];
    return ar;
  };
  auto get_Complex_array = [](int len)
  {
    cout << "Enter elements: \n";
    Complex* arr = new Complex[len];
    double Re;
    double Im;
    for(int i = 0 ; i < len; i++) {
      cout << "Enter Re: ";
      cin >> Re;
      cout << "Enter Im: ";
      cin >> Im;
      arr[i] = Complex(Re, Im);
    }
    return arr;
  };
  auto get_string_array = [](int len)
  {
    cout << "Enter strings: \n";
    string* array = new string[len];
    for(int i = 0 ; i < len; i++) cin >> array[i];
    return array;
  };
  auto get_char_array = [](int len)
  {
    cout << "Enter chars: \n";
    char* array = new char[len];
    for(int i = 0 ; i < len; i++) cin >> array[i];
    return array;
  };
  auto get_Student_array = [](int len)
  {
    cout << "Enter Students: \n";
    Student* array = new Student[len];
    int id;
    string firstName;
    string middleName;
    string lastName;
    for(int i = 0 ; i < len; i++) {
      cout << "ID: ";
      cin >> id;
      cout << "First name: ";
      cin >> firstName;
      cout << "Middle name: ";
      cin >> middleName;
      cout << "Last name: ";
      cin >> lastName;
      array[i] = Student(id, firstName, middleName, lastName);
    }
    return array;
  };
  auto big_Tree_Test = [](int len, BinarySearchTree<int>* bst1)
  {
    bst1 = new BinarySearchTree<int>();

    clock_t t1 = clock();
    int tmp;
    for (int i = 0; i < len; i++) {
      tmp = rand();
      bst1->Insert(tmp);
    }
    clock_t t2 = clock();
    cout << "Insertion took: " << difftime(t2, t1) / CLOCKS_PER_SEC << '\n';
    cout << "Merge will took nearly double the insertion time.\n";

    t1 = clock();
    bst1->Search(rand());
    t2 = clock();
    cout << "Search took: " << difftime(t2, t1) / CLOCKS_PER_SEC << '\n';

    t1 = clock();
    bst1->ToString("RNL");
    t2 = clock();
    cout << "Traverse took: " << difftime(t2, t1) / CLOCKS_PER_SEC << '\n';

    t1 = clock();
    bst1->GetSubtree(tmp);
    t2 = clock();
    cout << "GetSubtree took: " << difftime(t2, t1) / CLOCKS_PER_SEC << '\n';
  };

  

  int option = 0;
  while(option >= 0) {
    switch(option) {
      case 0:
        option = ask(MAIN, main_size);
        break;

      case 1:
        clean(bst1, bst2, bst3, bst4, bst5, bst6);
        bst1 = 0;
        bst2 = 0;
        bst3 = 0;
        bst4 = 0;
        bst5 = 0;
        bst6 = 0;

        option = ask(CREATE, create_size) + main_size - 1;
        break;

      case 2:
        option = ask(TREE_OPERATIONS, tree_operations_size) + main_size + create_size - 2;
        break;
      case 3: //Run tests
        unit_tests_ArraySequence::Run();
        unit_tests_DynamicArray::Run();
        unit_tests_LinkedList::Run();
        unit_tests_ListSequence::Run();
        unit_tests_BinaryHeap::Run();
        unit_tests_PriorityQueue::Run();
        unit_tests_BinarySearchTree::Run();

        option = 0;
        break;
      case 4:
      {
        int len = 100;
        clean(bst1, bst2, bst3, bst4, bst5, bst6);
        bst1 = 0;
        bst2 = 0;
        bst3 = 0;
        bst4 = 0;
        bst5 = 0;
        bst6 = 0;
        bst1 = new BinarySearchTree<int>(); 
        big_Tree_Test(len, bst1);
        option = 0;
      }
        break;
      case 5:
      {
        int len = 100000;
        clean(bst1, bst2, bst3, bst4, bst5, bst6);
        bst1 = 0;
        bst2 = 0;
        bst3 = 0;
        bst4 = 0;
        bst5 = 0;
        bst6 = 0;
        bst1 = new BinarySearchTree<int>(); 
        big_Tree_Test(len, bst1);
        option = 0;
      }
        break;
      case 6:
      {
        int len = 10000000;
        clean(bst1, bst2, bst3, bst4, bst5, bst6);
        bst1 = 0;
        bst2 = 0;
        bst3 = 0;
        bst4 = 0;
        bst5 = 0;
        bst6 = 0;
        bst1 = new BinarySearchTree<int>(); 
        big_Tree_Test(len, bst1);
        option = 0;
      }
        break;
      
      
      case 7: //Create int bst
      {
        int len = get_len();
        int* a = get_int_array(len);
        Stack<int>* stack1 = new Stack<int>(a, len, 1);
        bst1 = new BinarySearchTree<int>(stack1);
        delete stack1;
        delete [] a;
        option = 0;
      }
        break;
      case 8: //Create double bst
      {
        int len = get_len();
        double* ar = get_double_array(len);
        Stack<double>* stack2 = new Stack<double>(ar, len, 1);
        bst2 = new BinarySearchTree<double>(stack2);
        delete stack2;
        delete [] ar;
        option = 0;
      }
        break;
      case 9: //Create Complex bst
      {
        int len = get_len();
        Complex* arr = get_Complex_array(len);
        Stack<Complex>* stack3 = new Stack<Complex>(arr, len, 1);
        bst3 = new BinarySearchTree<Complex>(stack3);
        delete stack3;
        delete [] arr;
        option = 0;
      }
        break;

      case 10: //Create string bst
      {
        int len = get_len();
        string* array = get_string_array(len);
        Stack<string>* stack4 = new Stack<string>(array, len, 1);
        bst4 = new BinarySearchTree<string>(stack4);
        delete stack4;
        delete [] array;
        option = 0;
      }
        break;
      case 11: //Create char bst
      {
        int len = get_len();
        char* array = get_char_array(len);
        Stack<char>* stack5 = new Stack<char>(array, len, 1);
        bst5 = new BinarySearchTree<char>(stack5);
        delete stack5;
        delete [] array;
        option = 0;
      }
        break;
      case 12: //Create Student bst
      {
        int len = get_len();
        Student* array = get_Student_array(len);
        Stack<Student>* stack6 = new Stack<Student>(array, len, 1);
        bst6 = new BinarySearchTree<Student>(stack6);
        delete stack6;
        delete [] array;
        option = 0;
      }
        break;
      case 13: //Insert
      {
        if(bst1) {

          int n;
          cout << "Enter int: \n";
          cin >> n;
          bst1->Insert(n);

        } else if(bst2) {

          double f;
          cout << "Enter flaot: \n";
          cin >> f;
          bst2->Insert(f);

        } else if(bst3) {

          double Re;
          double Im;
          cout << "Enter Re: ";
          cin >> Re;
          cout << "Enter Im: ";
          cin >> Im;
          bst3->Insert(Complex(Re, Im));
          
        } else if(bst4) {

          string str;
          cout << "Enter string: \n";
          cin >> str;
          bst4->Insert(str);
          
        } else if(bst5) {

          char c;
          cout << "Enter char: \n";
          cin >> c;
          bst5->Insert(c);
          
        } else if(bst6) {

          int id;
          string firstName;
          string middleName;
          string lastName;

          cout << "ID: ";
          cin >> id;
          cout << "First name: ";
          cin >> firstName;
          cout << "Middle name: ";
          cin >> middleName;
          cout << "Last name: ";
          cin >> lastName;

          bst6->Insert(Student(id, firstName, middleName, lastName));
          
        } else {
          std::cout << "No stack created\n";
        }
        option = 0;
      }
        break;
      case 14: //Remove
      {
        if(bst1) {
          int n;
          cout << "Enter int: \n";
          cin >> n;
          if(bst1->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { bst1->Remove(n); }

        } else if(bst2) {
          double f;
          cout << "Enter flaot: \n";
          cin >> f;

          if(bst2->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { bst2->Remove(f); }

        } else if(bst3) {
          double Re;
          double Im;
          cout << "Enter Re: ";
          cin >> Re;
          cout << "Enter Im: ";
          cin >> Im;

          if(bst3->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { bst3->Remove(Complex(Re, Im)); }
          
        } else if(bst4) {
          string str;
          cout << "Enter string: \n";
          cin >> str;

          if(bst4->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { bst4->Remove(str); }
          
        } else if(bst5) {
          char c;
          cout << "Enter char: \n";
          cin >> c;

          if(bst5->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { bst5->Remove(c); }
          
        } else if(bst6) {
          int id;
          string firstName;
          string middleName;
          string lastName;

          cout << "ID: ";
          cin >> id;
          cout << "First name: ";
          cin >> firstName;
          cout << "Middle name: ";
          cin >> middleName;
          cout << "Last name: ";
          cin >> lastName;

          if(bst6->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { bst6->Remove(Student(id, firstName, middleName, lastName)); }

        } else {
          std::cout << "No bst created\n";
        }
        option = 0;
      }
        break;
      case 15: //Search
      {
        if(bst1) {
          int n;
          cout << "Enter int: \n";
          cin >> n;
          if(bst1->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { cout << "Result: " << bst1->Search(n) << endl; }

        } else if(bst2) {
          double f;
          cout << "Enter flaot: \n";
          cin >> f;

          if(bst2->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { cout << "Result: " << bst2->Search(f) << endl; }

        } else if(bst3) {
          double Re;
          double Im;
          cout << "Enter Re: ";
          cin >> Re;
          cout << "Enter Im: ";
          cin >> Im;

          if(bst3->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { cout << "Result: " << bst3->Search(Complex(Re, Im)) << endl; }
          
        } else if(bst4) {
          string str;
          cout << "Enter string: \n";
          cin >> str;

          if(bst4->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { cout << "Result: " << bst4->Search(str) << endl; }
          
        } else if(bst5) {
          char c;
          cout << "Enter char: \n";
          cin >> c;

          if(bst5->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { cout << "Result: " << bst5->Search(c) << endl; }
          
        } else if(bst6) {
          int id;
          string firstName;
          string middleName;
          string lastName;

          cout << "ID: ";
          cin >> id;
          cout << "First name: ";
          cin >> firstName;
          cout << "Middle name: ";
          cin >> middleName;
          cout << "Last name: ";
          cin >> lastName;

          if(bst6->IsEmpty()) { cout << "BinarySearchTree is empty\n"; } else { cout << "Result: " << bst6->Search(Student(id, firstName, middleName, lastName)) << endl; }

        } else {
          std::cout << "No bst created\n";
        }
        option = 0;
      }
        break;
      case 16: //Traverse
      {
        if(bst1) {

          cout << bst1->ToString() << endl;

        } else if(bst2) {

          cout << bst2->ToString() << endl;
          
        } else if(bst3) {

          // cout << bst3->ToString() << endl;
          
        } else if(bst4) {
          // cout << bst4->ToString() << endl;
                 
        } else if(bst5) {

          cout << bst5->ToString() << endl;
          
        } else if(bst6) {

          // cout << bst6->ToString() << endl;
          
        } else {
          std::cout << "No bst created\n";
        }
        option = 0;
      }
        break;
      case 17: //Get subtree
      {
        if(bst1) {

          cout << bst1->ToString() << endl;

        } else if(bst2) {

          cout << bst2->ToString() << endl;
          
        } else if(bst3) {

          // cout << bst3->ToString() << endl;
          
        } else if(bst4) {
          // cout << bst4->ToString() << endl;
                 
        } else if(bst5) {

          cout << bst5->ToString() << endl;
          
        } else if(bst6) {

          // cout << bst6->ToString() << endl;
          
        } else {
          std::cout << "No bst created\n";
        }
        option = 0;
      }
        break;    
      case 18: //Merge
      {
        int len = get_len();
         if(bst1) {

          int* a = get_int_array(len);
          Stack<int>* stack1 = new Stack<int>(a, len, 1);
          BinarySearchTree<int>* bst = new BinarySearchTree<int>(stack1);
          bst1->Merge(bst);
          delete stack1;
          delete bst;
          delete [] a;

        } else if(bst2) {

          double* ar = get_double_array(len);
          Stack<double>* stack2 = new Stack<double>(ar, len, 1);
          BinarySearchTree<double>* bst = new BinarySearchTree<double>(stack2);
          bst2->Merge(bst);
          delete stack2;
          delete bst;
          delete [] ar;
          
        } else if(bst3) {

          Complex* arr = get_Complex_array(len);
          Stack<Complex>* stack3 = new Stack<Complex>(arr, len, 1);
          BinarySearchTree<Complex>* bst = new BinarySearchTree<Complex>(stack3);
          bst3->Merge(bst);
          delete stack3;
          delete bst;
          delete [] arr;

          
        } else if(bst4) {
          string* array = get_string_array(len);
          Stack<string>* stack4 = new Stack<string>(array, len, 1);
          BinarySearchTree<string>* bst = new BinarySearchTree<string>(stack4);
          bst4->Merge(bst);
          delete stack4;
          delete bst;
          delete [] array;
                 
        } else if(bst5) {

          char* array = get_char_array(len);
          Stack<char>* stack5 = new Stack<char>(array, len, 1);
          BinarySearchTree<char>* bst = new BinarySearchTree<char>(stack5);
          bst5->Merge(bst);
          delete stack5;
          delete bst;
          delete [] array;
          
        } else if(bst6) {

          Student* array = get_Student_array(len);
          Stack<Student>* stack6 = new Stack<Student>(array, len, 1);
          BinarySearchTree<Student>* bst = new BinarySearchTree<Student>(stack6);
          bst6->Merge(bst);
          delete stack6;
          delete bst;
          delete [] array;
          
        } else {
          std::cout << "No bst created\n";
        }
        option = 0;
      }
        break; 
      default:
        option = 0;
    }
  }
  clean(bst1, bst2, bst3, bst4, bst5, bst6);
}