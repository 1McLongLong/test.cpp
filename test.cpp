#include <iostream>
#include <algorithm>
#include <new>
#include <ostream>
#include <string>
#include <string_view>

/* 
struct date {
  int day;
  int month;
  int year;

  void print()
  {
    std::cout << day << '/' << month << '/' << year << '\n';
  }
};

int main()
{
  date mine = {01, 01, 2004};
  mine.print();
}
 */

/* 
struct Person
{
  std::string name;
  int age;

  void kisses(const Person& person)
  {
    std::cout << name << " hugs " << person.name << '\n';
  }
};

int main()
{
  Person joe = {"joe", 21};
  Person kate = {"kate", 23};
  
  kate.kisses(joe);
  return 0;
}
*/

/* 
struct IntPair {
  int x;
  int y;
  void print() {std::cout << "Pair(" << x << ", " << y << ")\n";}
};

int main()
{
	IntPair p1 = {1, 2};
	IntPair p2 = {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	return 0;
} */

/* 
struct IntPair {
  int x;
  int y;
  void print() {std::cout << "Pair(" << x << ", " << y << ")\n";}
  int isEqual(IntPair &pair)
  {
    return (x == pair.x && y == pair.y);
  }
};

int main()
{
	IntPair p1 = {1, 2};
	IntPair p2 = {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
} */

/* 
struct Date
{
  int year;
  int month;
  int day;

  void print() const
  {
    std::cout << year << '/' << month << '/' << day <<'\n';
  }
};

int main()
{
  Date today = { 2020, 10, 14 }; // const
  
  today.print();
  return 0;
} */

/* 
struct Something
{
  void print()
  {
    std::cout << "non-const\n";
  }

  void print() const
  {
    std::cout << "const\n";
  }
};

int main()
{
  Something s1;
  s1.print();

  const Something s2;
  s2.print();

  return 0;
} */

// Accessors && Mutators

/* class Date
{
  int m_year;
  int m_month;
  int m_day;
public:
  int getday() const {return m_day;}
  void setday(int day) {m_day = day;}
  int getmonth() const {return m_month;}
  void setmonth(int month) {m_month = month;}
  int getyear() const {return m_year;}
  void setyear(int year) {m_year = year;}
};


int main()
{
  Date d;

  d.setyear(2004);
  d.setmonth(11);
  d.setday(9);
  std::cout << d.getyear() << '\n';
} */

/* 
class Employee
{
	std::string m_name;

public:
	void setName(std::string name) { m_name = name; }
  const std::string& getName() const { return m_name; }
};

int main()
{
	Employee joe;
	joe.setName("Joe");
	std::cout << joe.getName() << '\n';

	return 0;
} */


/* int main()
{
  int x = 5;

  {
    int& ref = x;   // ref is a reference to x
    std::cout << ref << '\n'; // prints value of ref (5)
  } // ref is destroyed here -- x is unaware of this

  std::cout << ref << '\n'; // prints value of ref (5)
  std::cout << x << '\n'; // prints value of x (5)

  return 0;
} // x destroyed here */


// Encapsulation
// example
/* class Employee
{
  std::string m_name;
  char m_firstInitial;

  public:
  void setName(std::string name)
  {
    m_name = name;
    m_firstInitial = name[0];
  }

  void print() const
  {
    std::cout << "Employee " << m_name << " has first initial " << m_firstInitial << '\n';
  }
};

int main()
{
  Employee e;
  e.setName("John");
  e.print();

  e.setName("Mark");
  e.print();

  return 0;
}
 */

// Best version of Encapsulation
/* class Yogurt
{
  std::string m_flavor;

  public:
  void setFlavor(std::string flavor) { m_flavor = flavor; }

  const std::string& getFlavor() const { return m_flavor; }
};

// Best: non-member function print() is not part of the class interface
void print(const Yogurt& y)
{
  std::cout << "The yogurt has flavor " << y.getFlavor() << '\n';
}

int main()
{
  Yogurt y;
  y.setFlavor("cherry");
  print(y);

  return 0;
} */

// Constructors
/* 
class Cat
{
  private:
    std::string name;
    std::string color;
    std::string favorite_toy;

  public:
    void print_cat()
    {
      std::cout << "Name: " << name << std::endl;
      std::cout << "Color: " << color << std::endl;
      std::cout << "Favourite Toy: " << favorite_toy << std::endl << '\n';
    }
    // constructor with no parameters, we initialize member variables to defaults
    Cat()
    {
      name = "Unknown";
      color = "Unknown";
      favorite_toy = "Unknown";
    }
    // constructor with a single parameter, we use it to intitialize the cat name
    Cat(std::string n)
    {
      name = n;
      color = "Unknown";
      favorite_toy = "Unknown";
    }
    // constructor parameters can have default values such as the default favorite 
    // toy value "Laser Pointer", we can also define constructors outside the 
    // Class such as this example, as long as we leave function declaration 
    // (i.e. prototype) in the class
    Cat(std::string n, std::string c, std::string ft = "Laser Pointer");

};

// we use the syntax ClassName::ClassName( ... ) to define the constructor 
// outside the class...
Cat::Cat(std::string n, std::string c, std::string ft)
{
  name = n;
  color = c;
  favorite_toy = ft;
}

int main()
{
  // the constructor with no parameters will be called
  Cat cat1;
  std::cout << "Cat 1..." << std::endl;
  cat1.print_cat();
  
  // the constructor that accepts a single argument will be called
  Cat cat2("Spot");
  std::cout << "Cat 2..." << std::endl;
  cat2.print_cat();
  
  // the constructor that accepts 3 arguments will be called, but the default 
  // value will be used for the 3rd argument
  Cat cat3("Garfield", "Orange");
  std::cout << "Cat 3..." << std::endl;
  cat3.print_cat();
  
  return 0;
}
 */



// "this" pointer 
/* class MyClass 
{
  public:
    int my_variable;
    void set_variable(int my_variable) {
      this->my_variable = my_variable; // we use "this" pointer to avoid conflict
    }
};

int main() 
{
  MyClass obj;
  obj.set_variable(42);
  std::cout << "My variable: " << obj.my_variable << std::endl;
  return 0;
}
*/

// Initialization list

// A class with a default constructor AND parametrized constructor 
/*  
class Major
{
  public:
    std::string name;

    // we initialize member variable name to the value "Undeclared"
    Major() : name("Undeclared")
  {
    // we can still put code in the instructor that will run after the members 
    // are initialized, to do other work a constructor may need to do
    std::cout << "Major Constructor (Undeclared)" << std::endl;
  } 

    // init member variable name to the value of the parameter name
    Major(std::string name) : name(name)
  {
    std::cout << "Major Constructor (" << name << ")" << std::endl;
  }
};

// A class with NO default constructor
class Minor
{
  public:
    std::string m_name;

    // init member variable name to the value of the parameter name
    Minor(std::string name) : m_name(name) {}
};

class Student
{
  public:
    std::string name;
    int start_year;
    int grad_year;

    // We can initialize a const member variable like this, but it will take 
    // on the same vaue for every object instance
    // const std::string id = "abc";

    // If we wish to provide potentially different values for the const member 
    // variables of objects, we need to use member initializer lists as below!
    // const std::string id;

    // If a class has a default constructor AND a parameterized constructor, then
    // BOTH the default constructor AND the parameterized constructor will be 
    // called to create objects *if* in addition to the below declaration of 
    // the member variable major we also initialized it in the constructor
    // body with something like:
    //
    // Major major("something");
    //
    // ONLY if we initialize the object in a member initializer list can we 
    // prevent this from happening and only create the object once.  This is 
    // important for performance reasons, as otherwise we are calling two 
    // constructors when only one is needed!
    Major major;

    // We must use member initializer lists to initialize reference member 
    // variables like &minor1
    Minor &minor1;

    // If an object member variable only has a parametrized constructor, then 
    // we must also initialize the member variable using a member initializer 
    // list.
    Minor minor2;

    Student(std::string name, int start_year, std::string major,
        Minor &minor) :
      name(name),
      start_year(start_year),
      grad_year(start_year + 4),
      major(Major(major)),
      minor1(minor),
      minor2(Minor("Physics"))
      {
        std::cout << "Student Object Constructed!" << std::endl;
      }
};

int main()
{
  int year = 2024;
  Minor minor("Economics");
  Student s1("John", year, "Computer Science", minor);

  std::cout << "Name: " << s1.name << std::endl
    << "Start Year: " << s1.start_year << std::endl
    << "Grad Year: " << s1.grad_year << std::endl
    << "Major: " << s1.major.name << std::endl
    << "Minor1: " << s1.minor1.m_name << std::endl
    << "Minor2: " << s1.minor2.m_name << std::endl;
  return 0;
}
 */

// Pointers and References

/* int main()
{
  std::string str = "HI THIS IS BRAIN";

  std::string* stringPTR = &str;
  std::string& stringREF = str;

  std::cout << "Address of string: " << &str << '\n';
  std::cout << "Value of pointer: " << stringPTR << '\n';
  std::cout << "Address of reference: " << &stringREF << '\n';

  std::cout << "Value of string: " << str << '\n';
  std::cout << "Dereference of pointer: " << *stringPTR << '\n';
  std::cout << "Value of reference: " << stringREF << '\n';
  return 0;
} */

/*
void replace_string(std::string &str, const std::string &s1, const std::string &s2) 
{
  size_t start_pos = 0;
  while ((start_pos = str.find(s1, start_pos)) != std::string::npos) {
    str.erase(start_pos, s1.length());
    str.insert(start_pos, s2);
    start_pos += s2.length();
  }
}

int main()
{
  std::string text = "hello world, hello universe";
  std::string s1 = "hello";
  std::string s2 = "hi";
  replace_string(text, s1, s2);
  std::cout << text << '\n';
}
*/

/* int main()
{
  int *ptr = new(std::nothrow) int;
  if (ptr == NULL)
    return 0;
  *ptr = 21;
  std::cout << *ptr << '\n';
} */

/* 
int main()
{
  std::cout << "Enter a positive integer: ";
  std::size_t length = 0;
  std::cin >> length;

  int* array = new int[length];

  std::cout << "I just allocated an array of integers of length " << length << '\n';

  array[0] = 5;

  delete[] array;
  // no need to set array to NULL here because it's going out of scope immediately after this anyway
  return 0;
} */

/* 
std::size_t getNameCount()
{
  std::cout << "How many names would you like to enter? ";
  std::size_t length = 0;
  std::cin >> length;

  return length;
}

void getNames(std::string* names, std::size_t length)
{
  for (std::size_t i = 0; i < length; ++i)
  {
    std::cout << "Enter name #" << i + 1 << ": ";
    std::getline(std::cin >> std::ws, names[i]);
  }
}

void printNames(std::string* names, std::size_t length)
{
  std::cout << "\nHere is your sorted list:\n";

  for (std::size_t i = 0; i < length; ++i)
    std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
}

int main()
{
  std::size_t length = getNameCount();
  std::string* names = new std::string[length];

  getNames(names, length);
  std::sort(names, names + length);
  printNames(names, length);

  delete[] names;
  return 0;
}
 */


void f(int &i)
{
  int &a = i;
  std::cout << a << '\n';
}

int main()
{
  int i = 21;
  f(i);
  std::cout << i << '\n';
}









