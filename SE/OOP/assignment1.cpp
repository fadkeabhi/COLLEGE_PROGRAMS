/*

Implement a class Complex which represents the Complex Number data type. Implement the following

1. Constructor (including a default constructor which creates the complex number( 0+0i). 

2. Overload operator to add two complex numbers.

3. Overload operator to multiply two complex numbers. 

4. Overload operators << and >> to print and read Complex Numbers.

*/

#include <iostream>

using namespace std;

 

class Complex

{

private:

    int real, img;

public:

    Complex(int r = 0, int i =0)

    {  real = r;   img = i; }

    friend ostream & operator << (ostream &out, const Complex &c);

    friend istream & operator >> (istream &in,  Complex &c);

Complex operator+(Complex const &obj)

{

Complex res;

res.real = real + obj.real;

res.img = img + obj.img;

return res;

}

Complex operator*(Complex const &obj)

{

Complex res;

res.real = (real*obj.real) - (img * obj.img);

res.img = (real*obj.img) + (img * obj.real);

return res;

}

};

 

ostream & operator << (ostream &out, const Complex &c)

{

    out << c.real;

    out << "+i" << c.img << endl;

    return out;

}

 

istream & operator >> (istream &in,  Complex &c)

{

    cout << "Enter Real Part ";

    in >> c.real;

    cout << "Enter Imaginary Part ";

    in >> c.img;

    return in;

}

 

int main()

{

   Complex c1,c2,c3,c4;

cout<<"Enter First complex number : \n";

   cin >> c1;

cout<<"Enter Second complex number : \n";

   cin >> c2;

   cout << "addition is ";

c3 = c2 + c1;

   cout << c3;

   cout << "multiplication is ";

c4 = c2 * c1;

   cout << c4;

   return 0;

}

