/*

------------------------DAY1---------------------------------------

C/C++
---Pre-processor
expanded c/c++ code
---Compiler
object code
---Link/build
.lib->
Executable file

Code segment 
Data segment - global, static, literal (physical constatnts)
Stack - local variable, activation recird
Heap - dynamic memory allocation

C++ object model/BJARNE model : the size of the object is influenced by the no static data memers of the class.
The functuons if any shall be a single copy on the code segnmet wandd would be shared by all obect of teh same class


Function execution phased :-
1) Function Prologue 
2) Business Logic
3) Epilogue


Suppotyd several calling conventions :
a) __cdecl
2) __stdcall - hybrid of PASCAL and __cdecl
3) __thiscall
4) _fastcall


Standard template library

1) Generice Programming - language feature
2) operator overloading - language feature
3) PIMPL model - Design feature
4) RAII - design feature
5) Smartpointers - Design feature
6) Adapters - design feature

template<typename T=double> class CA
{

    public:
};

CA<int> obj;
CA<> obj1; // Default type


RAII - Resource acquistion is initilization

class CA
{

prvate :
    int*p;

public CA:
    CA() 
    {
        p = new(nothrow) int (0);
    }

    void print()
    {
        cout << "Data" << *p << endl;
    }

    operator boo()
    {
        return p == NULL ? false : true;
    }

    ~CA()
    {
        delete p;
    }
}



*/

/*
--------------------DAY 2-------------------------------------------------------

Shallow Copy :

#include<iostream>
using namespace std;

class CA{
private :
    int a, b;
public :
    CA(int x = 0, int y = 0) : a(x), b(y)
    {
        cout << "Constructor called" << endl;
    }

    ~CA() {
        cout << "Destructor called " << endl;
    }

    void print() const { cout << "a : " << a << " b : " << b << endl; }
};

//**********************Wrapper class****************** Adapter class for memory management of CA
class CB {
private: 
    CA* p;
public :
    CB(int x = 0, int y = 0) {
        p = new(nothrow) CA(x, y);
    }

    ~CB() {
        delete p;
    }

    void print() const { p->print(); }

    CB(const CB& x)
    {
        p = new(nothrow) CA(*(x.p)); // will call CA copy constructor
    }

    CB& operator=(const CA& x)
    {
        *(this->p) = *(x.p); // will call CA assignment function
        return *this
    }
};

int main()
{
    CB obj1(10, 20);
    obj1.print();
    CB obj2(obj1);
    obj2.print();

    CB obj3(40, 50), obj4;
    obj4 = obj3;
    obj3.print();
    obj4.print();


    return 0
}


-------------------------------

class CA() 
{ 
    CA *p;
publc:
    CA* operator->()
    {
        return p;
    }
};

int main()
{
    CA *p = new(nothrow) CA[5];
    p[0].print();
    p[1]->print();  (p[1].operator ->())->print();
    delete []p;
    return 0;
}


---------------------------
SMART Pointer
---------------------------

class SmartPointer 
{
private :
    CA* p;
public:
    // Copy constructor, constructor, destructor, asssignment operator overloading

    CA* GetCAAddress()
    {
        return p;
    }

    CA* operator&()
    {
        return p;
    }

    CA* operator->()
    {
        return p;
    }

    CA& operator*()
    {
        return *p;
    }

}

int main()
{
    SmartPointer obj1;

    CA* q = obj1.p; // Error, cannot access private memebers
    CA* q = obj1.GetCAAddress();
    CA* q = &obj1;
    obj1->print();

    (*obj1)->print();
}


#include<iostream>
using namespace std;

class CA{
private :
    int a, b;
public :
    CA(int x = 0, int y = 0) : a(x), b(y)
    {
        cout << "Constructor called" << endl;
    }

    ~CA() {
        cout << "Destructor called " << endl;
    }

    void print() const { cout << "a : " << a << " b : " << b << endl; }
};

//**********************Wrapper class****************** Adapter class for memory management of CA
class CB {
private: 
    CA* p;
public :
    CB(int x = 0, int y = 0) {
        p = new(nothrow) CA(x, y);
    }

    ~CB() {
        if( p != NULL)
            delete p;
    }

    void print() const { p->print(); }

    CB(const CB& x)
    {
        p = new(nothrow) CA(*(x.p)); // will call CA copy constructor
    }

    CB& operator=(const CA& x)
    {
        *(this->p) = *(x.p); // will call CA assignment function
        return *this
    }

    const CA* operator->()
    {
        cout << "operator ->() called" << endl;
        return p;
    }

    const CA* operator&()
    {
        cout << "operator &() called" << endl;
        return p;
    }

    CA& operator*()
    {
        cout << "operator *() called" << endl;
        return *p;
    }
};

int main()
{
    CB obj1(10, 20);
    obj1->print();
    (*obj1).print();

    CA* q= &obj1;
    q->print();

    return 0
}
-----------
class SmartPointer
{

private :
    CA* p;

public :
    Smartpointer() : p(nullptr) { }
    SmartPointer(CA *q) :p(q) { }

    ~SmartPointer()
    {
        if( p != nullptr)
            delete p;
    }

    void release()
    {
        if( p != nullptr)
            delete p;
    }

    // overload ->, &, *
};

int main()
{
    SmartPointer s1;
    s1->print();


    s1 = new(nothrow) CA;
    Smartpointer s2 = new(nothrow) CA;
    Smartpointer s2(new(nothrow) CA);
}


------
GENERIC SMART POINTER CLASS
-----------------


template<typename T> class SmartPointer
{
    private :
        T* p;
    public :
        Smartpointer() : p(nullptr) { }
        SmartPointer(T *q) :p(q) { }

        ~SmartPointer()
        {
            if( p != nullptr)
                delete p;
        }

        void release()
        {
            if( p != nullptr)
                delete p;
        }

        // overload ->, &, *
}

int main()
{
    Smartpointer<CA> s2 = new(nothrow) CA;
}

--------------------------------------------------------------
CONST CORRECTNESS
-------------------

class CA
{

private :

public :

    CA() { }
    ~CA() { }

    void print() // Readonly business
    {

    }

    void input() // Writeonly business
    {

    }
}

int main()
{
    CA obj1(10, 20); // Read write object
    obj1.input(); // write operation
    obj1.print(); // read operation

    const CA obj2(40, 50);
    obj2.input() //flag error
    obj2.print(); // flag error

    return 0;
}


class CA
{
public:
    void input(); // void input(CA* const this);
    void print(); // void print(CA* const this);

    void print() const; // void print(const CA* const this);

    CA& operator=(const CA &x)
    {
        this->a = x.a;
        this->b = x.b;
        return *this;
    }

    CA(const CA& x)
    {

    }

    CA obj1;
    obj1.print(); // CA::input(&obj1); ==> CA::input(CA*) 


    const CA obj2;
    obj2.print(); // CA::input(&obj1); ==> CA::input(const CA*) 


    CA obj4;
    CA obj5(50, 60);
    obj4 = obj5;

    const CA obj6(70, 80);
    obj4 = obj6;
}

--------------------------------------------
STANDARD TEMPLATE LIBRARY
--------------------------------------------

1) Container classes
2) Iterator classes - pointer to data held in container classes
3) Allocator classes
4) Algorithms

#include<iostream>
#include<stack>

int main()
{
    stack<int> s1;
    cout << "Initial size of stack:" << s1.size() << endl;
    cout << "Pushing" << endl;
    for(int i = 0; i < 5; i++)
    {
        s1.push(i);
        cout << "Current Top : " << s1.top() << endl;
    } 

    cout << "Size of stack after pushing:" << s1.size() << endl;

    cout << "Popping" << endl
    while(!s.empty())
    {
        s1.pop();
    }
    return 0;
}


STL LIST
#include<list> -> doubly linked list
#include<iostream>

using namespace std;

int main()
{
    list<int> ls1;
    cout << "Initial size of list" << ls1.size() << endl;

    for(int  i= 0; i < 5; i++)
    {
        ls1.push_back(i);
        //ls1.push_front(i);
    }

    cout << "Size of list" << ls1.size() << endl;

    // create an iterator and initialize it to the start of the list
    list<int>::iterator itr = ls1.begin();

    while(itr != ls1.end())
    {
        cout << *itr << endl; // itr.operator*()
        itr++; // itr.operator++(int)
    }

    ls1.sort();
    itr = ls1.begin();

    while(itr != ls1.end())
    {
        cout << *itr << endl; // itr.operator*()
        itr++; // itr.operator++(int)
    }


}

STL List 2

#include<iostream>
#include<list>

class CA
{
private :
    int a, b;
public :
    CA (int x= 0, int y = 0) : a(x), b(y) { }
    void print const() { cout << a << " " << b << endl; }
};

int main()
{
    list<CA> ls1;
    for(int i = 0; i < 5; i++)
    {
        ls1.push_back(CA(i, i + 10));
    }

    list<CA>::iterator itr = ls1.begin();

    while(itr != ls1.end())
    {
        itr->print();
        itr++;
    }

    return 0;
}


ALGORITHS

#include<iostream>
#include<list>
#include<alogrithm>

using namespace std;

void OddEven(int x)
{
    if(x % 2 == 1)
        cout << x << " is odd" << endl;
    else
        cout << x << " is even" << endl;
}

int main()
{
    list<int> ls1;
    for(int i = 0; i < 100; i++)
    {
        ls1.push_back(i);
    }

    for_each(ls1.begin(), ls1.end(), OddEven);

    return 0;
}

FUNCTOR

#include<iostream>
#include<list>
#include<algorithm>

class CA
{
private :
    int a, b;
public :
    CA (int x= 0, int y = 0) : a(x), b(y) { }
    void print const() { cout << a << " " << b << endl; }

    // Functor
    void operator()(CA &x) const() { cout << x.a << " " << x,b << endl; }
};

void Print(const CA &x)
{
    x.print();
}

int main()
{
    list<CA> ls1;
    for(int i = 0; i < 5; i++)
    {
        ls1.push_back(CA(i, i + 10));
    }

    list<CA>::iterator itr = ls1.begin();

    while(itr != ls1.end())
    {
        itr->print();
        itr++;
    }

    CA obj1
    for_each(ls1.begin(), ls1.end(), Print);
    for_each(ls1.begin(), ls1.end(), obj1); // obj1.operator() (object_from_list)

    return 0;
}


-------------------------------------
CASTING OPERATORS:-
-------------------------------------

Casting operators are generic functions in C++. THere are 4 different types of casting operators
a) reinterpret_cast
b) static_cast
c) dynamic_cast
d) const_cast

a) reinterpret_cast
    this casting operator is also called as
        - C style cast
        - unsage cast
        - dangerous cast
        - forced cast

Esentially meaning use it carefully, or use it only if you are sure
double *p;
int *q;
C style 
    q= (int *)p
C++ style
    q = reinterpret_cast<int *>(p);

template<typename T1, typename T2> T1 reinterpret_cast(T2 x)
{

}

Example :
class CA
{

public :
    void fun1() { cout << "CA::fun1 called" << endl; }
}

class CB
{

public :
    void fun2() { cout << "CB::fun1 called" << endl; }
}

int main()
{
    CA *p = new(nothrow) CA;
    p->fun1();

    return 0;
}


b) static cast
This casting operator is also called as
- safe cast
- compile-time cast
- two way casting operator
    - Upcasting : converting derived kind to base kind
    - Downcasting : converting base kind to derived kind


class circle
{

public:
    virtual void draw() { }
};

class circle : public shape
{
public :
    void draw() { }
};

class rectangle : public shape
{
public :
    void draw() { }
};


void FindShape(shape *p)
{
    circle *c = static_cast<circle *>(p)
    rectangle *r = static_cast<rectange *>(p);
    if(c != NULL)
    {
        cout << "object is circle" << endl;
    }
    if (r != NULL)
    {
        cout << "object is rectangle" << endl;
    }
}

int main()
{
    circle *c = new(nothrow) circle;
    FindShape(c);
    return 0
}

c) dynamic_cast
This casting operator will onky work on POLYMORPHIC class objects and no other type
Also called as :
    - safe cast
    - runtime cast
    - one-way casting operator - only supports down casting

class circle
{

public:
    virtual void draw() { }
};

class circle : public shape
{
public :
    void draw() { }
};

class rectangle : public shape
{
public :
    void draw() { }
};


void FindShape(shape *p)
{
    circle *c = dynamic_cast<circle *>(p)
    rectangle *r = dynamic_cast<rectange *>(p);
    if(c != NULL)
    {
        cout << "object is circle" << endl;
    }
    if (r != NULL)
    {
        cout << "object is rectangle" << endl;
    }
}

int main()
{
    circle *c = new(nothrow) circle;
    FindShape(c);
    return 0
}

SEE VIRTUAL TABLE
virtual table is on data stack (vtable)




d) const_cast
This casting operator can be used to remove const-ness of a const object, so that object can be modified i we so wish
the success of this operator on an const object is not gauranteed ona all platforms
prefer 'mutaable' qualified iver const_Cast if you want to be sure about the changes to an const object on all platforms



-------------------------------------------------------------
//BAD IDEA
CA *p = new CA;
if(p != NULL)
{

}

try
{
    CA *p = new CA;
}
catch(bad_alloc &x)
{
    cout << x.what() << endl;
}


CA *p = new(nothrow) CA;
if(p != NULL)
{

}


CA *p = new CA; => (CA*) operator new(size(CA));

void* operator new(size_t size)
{
    if allocation fails
        return bad_alloc();
    else
        return address;
}


---------------------------------------------
TYpe Inference - AUTO
---------------------------------------------

#include<iostream>
using namespace std;

template<typename T1, typename T2> 
T1 Add (T1 x, T2 x)
{
    return x + y;
}

int main()
{
    float x;
    x = Add(45.21f, 200);
    cout << x << endl;
    x = Add(300, 45.21f);
    return 0;
}


template<typename T1, typename T2, typename T3> 
T3 Add (T1 x, T2 x)
{
    return x + y;
}

int main()
{
    float x;
    x = Add<float, int, float>(45.21f, 200);
    cout << x << endl;
    x = Add<int, float, float>(300, 45.21f);
    return 0;
}

template<typename T1, typename T2, typename T3> 
T1 Add (T2 x, T3 x)
{
    return x + y;
}

int main()
{
    float x;
    x = Add<float>(45.21f, 200);
    cout << x << endl;
    x = Add<float>(300, 45.21f);
    return 0;
}


// Modern approach - c++ 11 standards
template<typename T1, typename T2> auto Add(T1 x, T2 y) -> decltype(x + y)
{
    return x + y;
}

// Modern approach - c++ 14 standards
template<typename T1, typename T2> auto Add(T1 x, T2 y)
{
    return x + y;
}

int main()
{
    float x;
    x = Add(42.1f, 300);
    x = Add(300, 42.1f);
}

 


*/

#include <iostream>

using namespace std;

void Add()
{
    cout << "End" << endl;
}

int main()
{

    char *s;
    string p = "abhijeet";

    s = &p[0];

    cout << *s << endl;

    auto abc = new int[5];
    return 0;


}