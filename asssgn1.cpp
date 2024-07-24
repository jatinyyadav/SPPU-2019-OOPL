/*
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded opreeator+ to add two complex number.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read complex numbers.
*/
#include <iostream>
using namespace std;

class Complex
{
  float real;
  float img;

public:
  // default constructor
  Complex()
  {
    real = 0;
    img = 0;
  }

  //parametrised constructor
  Complex(float r,float i){
  	real=r;
  	img=i;
  	}
  	
  //copy constructor
  Complex(const Complex& other) {
        real = other.real;
        cout << "Copy constructor called" << endl;
    }

  
  Complex operator+(Complex);
  Complex operator*(Complex);

  // overloaded >> and << to take input and give output
  friend istream &operator>>(istream &input, Complex &t)
  {
    cout << "Enter the real part: ";
    input >> t.real;
    cout << "Enter the imaginary part: ";
    input >> t.img;
    return input;
  }

  friend ostream &operator<<(ostream &output, const Complex &t)
  {
    output << t.real << "+" << t.img << "i";
    return output;
  }
};

Complex Complex::operator+(Complex c1) // Overloading + operator
{
  Complex temp;
  temp.real = real + c1.real;
  temp.img = img + c1.img;
  return temp;
}

Complex Complex::operator*(Complex c2) // Overloading * Operator
{
  Complex tmp;
  tmp.real = real * c2.real - img * c2.img;
  tmp.img = real * c2.img + img * c2.real;
  return tmp;
}

int main()
{
  Complex C1, C2, C3, C4;
  char b;
  bool flag = true;

  while (flag)
  {
    cout << "Enter Real and Imaginary part of the Complex Number 1 : \n";
    cin >> C1;
    cout << "Enter Real and Imaginary part of the Complex Number 2 : \n";
    cin >> C2;

    bool f = true;
    while (f)
    {
      cout << "Complex Number 1 : " << C1 << endl;
      cout << "Complex Number 2 : " << C2 << endl;
      cout << "**********MENU**********" << endl;
      cout << "1. Addition of Complex Numbers" << endl;
      cout << "2. Multiplication of Complex Numbers" << endl;
      cout << "3. Exit\n";
      int a;
      cout << "Enter your choice from above MENU (1 to 3) : ";
      cin >> a;

      switch (a)
      {
      case 1:
        C3 = C1 + C2;
        cout << "Addition : " << C3 << endl;
        break;
      case 2:
        C4 = C1 * C2;
        cout << "Multiplication : " << C4 << endl;
        break;
      case 3:
        cout << "Thanks for using this program!!\n";
        flag = false;
        f = false;
        break;
      default:
        cout << "Invalid choice! Please enter a number between 1 and 3.\n";
        break;
      }

      if (a != 3)
      {
        cout << "Do you want to perform another operation (y/n) : ";
        cin >> b;
        if (b == 'y' || b == 'Y')
        {
          f = true;
        }
        else
        {
          cout << "Thanks for using this program!!\n";
          flag = false;
          f = false;
        }
      }
    }
  }

  return 0;
}
