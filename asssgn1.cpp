/*
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded opreeator+ to add two complex number.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read complex numbers.
*/
#include <iostream>  // Include the standard input-output stream library
using namespace std;  // Use the standard namespace

// Define a class named Complex to represent a complex number
class Complex
{
  // Private member variables to hold the real and imaginary parts of the complex number
  float real;
  float img;

public:
  // Default constructor initializing real and imaginary parts to 0
  Complex()
  {
    real = 0;
    img = 0;
  }

  // Parameterized constructor initializing real and imaginary parts with provided values
  Complex(float r, float i){
  	real = r;
  	img = i;
  }
  	
  // Copy constructor that initializes a new Complex object with the values of another Complex object
  Complex(const Complex& other) {
        real = other.real;  // Copy the real part
        cout << "Copy constructor called" << endl;  // Output message for demonstration
    }

  // Function to overload the + operator for adding two complex numbers
  Complex operator+(Complex);

  // Function to overload the * operator for multiplying two complex numbers
  Complex operator*(Complex);

  // Friend function to overload the >> operator for inputting complex numbers
  friend istream &operator>>(istream &input, Complex &t)
  {
    cout << "Enter the real part: ";  // Prompt user to enter the real part
    input >> t.real;  // Input the real part
    cout << "Enter the imaginary part: ";  // Prompt user to enter the imaginary part
    input >> t.img;  // Input the imaginary part
    return input;  // Return the input stream
  }

  // Friend function to overload the << operator for outputting complex numbers
  friend ostream &operator<<(ostream &output, const Complex &t)
  {
    output << t.real << "+" << t.img << "i";  // Output the complex number in the format real+imagi
    return output;  // Return the output stream
  }
};

// Define the overloaded + operator to add two complex numbers
Complex Complex::operator+(Complex c1)
{
  Complex temp;  // Create a temporary Complex object to store the result
  temp.real = real + c1.real;  // Add the real parts
  temp.img = img + c1.img;  // Add the imaginary parts
  return temp;  // Return the result
}

// Define the overloaded * operator to multiply two complex numbers
Complex Complex::operator*(Complex c2)
{
  Complex tmp;  // Create a temporary Complex object to store the result
  tmp.real = real * c2.real - img * c2.img;  // Multiply the real and imaginary parts using the formula
  tmp.img = real * c2.img + img * c2.real;  // Multiply and add to form the imaginary part
  return tmp;  // Return the result
}

int main()
{
  Complex C1, C2, C3, C4;  // Create four Complex objects
  char b;  // Variable to store user input for continuing or exiting
  bool flag = true;  // Flag to control the outer loop

  while (flag)
  {
    cout << "Enter Real and Imaginary part of the Complex Number 1 : \n";
    cin >> C1;  // Input the first complex number
    cout << "Enter Real and Imaginary part of the Complex Number 2 : \n";
    cin >> C2;  // Input the second complex number

    bool f = true;  // Flag to control the inner loop
    while (f)
    {
      // Display the complex numbers
      cout << "Complex Number 1 : " << C1 << endl;
      cout << "Complex Number 2 : " << C2 << endl;

      // Display the menu
      cout << "**********MENU**********" << endl;
      cout << "1. Addition of Complex Numbers" << endl;
      cout << "2. Multiplication of Complex Numbers" << endl;
      cout << "3. Exit\n";
      
      int a;  // Variable to store user choice
      cout << "Enter your choice from above MENU (1 to 3) : ";
      cin >> a;  // Input the choice

      // Perform the operation based on user choice
      switch (a)
      {
      case 1:
        C3 = C1 + C2;  // Add the complex numbers
        cout << "Addition : " << C3 << endl;  // Display the result
        break;
      case 2:
        C4 = C1 * C2;  // Multiply the complex numbers
        cout << "Multiplication : " << C4 << endl;  // Display the result
        break;
      case 3:
        cout << "Thanks for using this program!!\n";
        flag = false;  // Set the flag to exit the outer loop
        f = false;  // Set the flag to exit the inner loop
        break;
      default:
        cout << "Invalid choice! Please enter a number between 1 and 3.\n";
        break;
      }

      if (a != 3)  // Check if the user wants to perform another operation
      {
        cout << "Do you want to perform another operation (y/n) : ";
        cin >> b;  // Input the user's choice
        if (b == 'y' || b == 'Y')
        {
          f = true;  // Continue the inner loop
        }
        else
        {
          cout << "Thanks for using this program!!\n";
          flag = false;  // Set the flag to exit the outer loop
          f = false;  // Set the flag to exit the inner loop
        }
      }
    }
  }

  return 0;  // Return 0 to indicate successful execution
}
