//Inheritance Assignment

/* Imagine a publishing company which does marketing for book and audio cassette versions Create a class publication that stores the title (a string) and price (type floats of publications From this class derive two classes book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the hook and tape claan, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values. */

#include<iostream>

#include<cstring>

#include<exception>

#include<ios>

#include<limits>

using namespace std;

class publication {

  protected:

    string title;

  float price;

  public:

    publication(string t = "No-title", float p = 0.0): title(t), price(p) {}

};

class books: public publication {

  int pages;

  public:

    books(string t = "No title", float p = 0.0, int pa = 0): publication(t, p), pages(pa) {}

  void getb();

  void displayb();

};

class tape: public publication {

  float min;

  public:

    tape(string t = "No title", float p = 0.0, float m = 0.00): publication(t, p), min(m) {}

  void gett();

  void displayt();

};

void books::getb() {

  cout << "Enter the details of the book: " << endl;

  cout << "Enter the title of the book:" << flush;

  cin.ignore(1, '\n');

  //cin.ignore(numeric_limits<streamsize>::max(), '\n');

  getline(cin, title);

  cout << "Enter the price of the book:" << flush;

  cin >> price;

  cout << "Enter the pages of the book:" << endl;

  cin >> pages;

  try

  {

    if (pages > 500 && pages < 1500)

    {

      if (price > 100 && price < 2000) {

        displayb();

      }

    } else throw (pages);

  } catch (int i)

  {

    cout << "Caught exception in function of book:" << endl;

    cout << "You entered an invalid data" << endl;

    title = "0";

    price = 0.0;

    pages = 0;

    displayb();

    throw;

  }

}

void books::displayb() //member function of derived class1 books

{

  cout << "The book you entered is:" << endl;

  cout << "The entered title is :" << title << endl;

  cout << "The entered price is :" << price << endl;

  cout << "The entered pages are :" << pages << endl;

}

void tape::gett() {

  cout << "Enter the details of the tape:" << endl;

  cout << "Enter the title of the tape:" << flush;

  cin.ignore(1, '\n');

  getline(cin, title);

  cout << "Enter the price of the tape:" << flush;

  cin >> price;

  cout << "Enter the playing time (in minutes):" << flush;

  cin >> min;

  try

  {

    if (min > 30.00 && min < 90.00) {

      if (price > 500 && price < 1000) {

        displayt();

      }

    } else

      throw (min);

  } catch (float f)

  {

    cout << "caught exception in the function of tape" << endl;

    cout << "you entered an invalid data" << endl;

    title = "0";

    price = 0.0;

    min = 0.0;

    displayt();

    throw;

  }

}

void tape::displayt()

{

  cout << "the details of tape you entered is:" << endl << endl;

  cout << "the entered title is:" << title << endl;

  cout << "the entered price is :" << price << endl;

  cout << "the entered play time is :" << min << endl;

}

int main() {

  books b;

  tape t;

  int choice;

  cout << "Do you want to buy a book(press 1) or a tape (press 2):" << flush;

  cin >> choice;

  switch (choice)

  {

  case 1:

    try

    {

      b.getb();

    } catch (int i)

    {

      cout << "caught exception in int main()" << endl;

    }

    break;

  case 2:

    try {

      t.gett();

    } catch (float f) {

      cout << "caught exception in int main()" << endl;

    }

    break;

  default:

    cout << "entered bad choice! Try again" << endl;

  }

  return 0;

}
