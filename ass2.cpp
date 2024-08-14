#include <iostream> // Include the standard input-output stream library
#include <string>   // Include the standard string library
using namespace std; // Use the standard namespace

// Forward declaration of the StudData class
class StudData;

class Student {
    string name;         // Student's name
    int roll_no;         // Student's roll number
    string cls;          // Student's class
    string division;     // Student's division
    string dob;          // Student's date of birth
    string bloodgroup;   // Student's blood group
    static int count;    // Static member to keep track of the number of students

public:
    // Default Constructor
    Student() : name(""), roll_no(0), cls(""), division(""), dob("dd/mm/yyyy"), bloodgroup("") {
        count++; // Increment count when a new Student object is created
    }

    // Parameterized Constructor
    Student(const string& n, int r, const string& c, const string& d, const string& b) 
        : name(n), roll_no(r), cls(c), division(d), dob(d), bloodgroup(b) {
        count++; // Increment count with parameterized constructor
    }

    // Copy Constructor
    Student(const Student& other) 
        : name(other.name), roll_no(other.roll_no), cls(other.cls), division(other.division), dob(other.dob), bloodgroup(other.bloodgroup) {
        count++; // Increment count with copy constructor
    }

    // Destructor
    ~Student() {
        count--; // Decrement count when a Student object is destroyed
    }

    // Static member function to get the count of students
    static int getCount() {
        return count; // Return the static count
    }

    // Inline member functions
    inline void getData(StudData* st); // Declare function to get student data
    inline void dispData(const StudData* st) const; // Declare function to display student data
};

class StudData {
    string caddress;  // Student's contact address
    long int telno;   // Student's telephone number
    long int dlno;    // Student's driving license number

public:
    // Default Constructor
    StudData() : caddress(""), telno(0), dlno(0) {}

    // Destructor
    ~StudData() {}

    // Function to get student's additional data
    void getStudData() {
        cout << "Enter Contact Address: "; // Prompt for contact address
        cin.ignore(); // Clear newline left by previous input
        getline(cin, caddress); // Get contact address from user
        cout << "Enter Telephone Number: "; // Prompt for telephone number
        cin >> telno; // Get telephone number from user
        cout << "Enter Driving License Number: "; // Prompt for driving license number
        cin >> dlno; // Get driving license number from user
    }

    // Function to display student's additional data
    void dispStudData() const {
        cout << "Contact Address: " << caddress << endl; // Display contact address
        cout << "Telephone Number: " << telno << endl; // Display telephone number
        cout << "Driving License Number: " << dlno << endl; // Display driving license number
    }
};

// Inline function to get student data
inline void Student::getData(StudData* st) {
    cout << "Enter Student Name: "; // Prompt for student name
    cin.ignore(); // Clear newline left by previous input
    getline(cin, name); // Get student name from user
    cout << "Enter Roll Number: "; // Prompt for roll number
    cin >> roll_no; // Get roll number from user
    cout << "Enter Class: "; // Prompt for class
    cin.ignore(); // Clear newline left by previous input
    getline(cin, cls); // Get class from user
    cout << "Enter Division: "; // Prompt for division
    getline(cin, division); // Get division from user
    cout << "Enter Date of Birth: "; // Prompt for date of birth
    getline(cin, dob); // Get date of birth from user
    cout << "Enter Blood Group: "; // Prompt for blood group
    getline(cin, bloodgroup); // Get blood group from user
    st->getStudData(); // Call function to get additional student data
}

// Inline function to display student data
inline void Student::dispData(const StudData* st) const {
    cout << "Student Name: " << name << endl; // Display student name
    cout << "Roll Number: " << roll_no << endl; // Display roll number
    cout << "Class: " << cls << endl; // Display class
    cout << "Division: " << division << endl; // Display division
    cout << "Date of Birth: " << dob << endl; // Display date of birth
    cout << "Blood Group: " << bloodgroup << endl; // Display blood group
    st->dispStudData(); // Call function to display additional student data
}

// Initialize static member count
int Student::count = 0;

int main() {
    const int MAX_STUDENTS = 100; // Define maximum number of students
    Student stud1[MAX_STUDENTS]; // Array to store Student objects
    StudData stud2[MAX_STUDENTS]; // Array to store StudData objects
    int n = 0; // Counter for number of students
    char ch; // Variable to check if user wants to add more students

    do {
        if (n >= MAX_STUDENTS) { // Check if the maximum number of students is reached
            cout << "Cannot add more students. Database is full." << endl; // Print message if full
            break; // Exit loop if full
        }

        stud1[n].getData(&stud2[n]); // Get data for the nth student
        n++; // Increment student counter
        cout << "Do you want to add another student (y/n): "; // Ask user if they want to add another student
        cin >> ch; // Get user's choice
    } while (ch == 'y' || ch == 'Y'); // Continue loop if user enters 'y' or 'Y'

    for (int i = 0; i < n; i++) { // Loop through all entered students
        cout << "---------------------------------------------------------------" << endl; // Print separator
        stud1[i].dispData(&stud2[i]); // Display data for the ith student
    }

    cout << "---------------------------------------------------------------" << endl; // Print separator
    cout << "Total Students: " << Student::getCount() << endl; // Display total number of students
    cout << "---------------------------------------------------------------" << endl; // Print separator

    return 0; // Exit the program
}
