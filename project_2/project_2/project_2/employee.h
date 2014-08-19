// class employee declaration

#include <string>
using namespace std;

class Employee
{
public:

	Employee(void); // constructor
    void setName(string name); // Sets the name for the employee
    string getName(); // Gets the Name of the employee
    void setPayRate(double payRate); // Sets the Pay Rate for this employee
    void setHoursWorked(int hoursWorked); // Sets the hours worked for this employee
    double calcPay(); // Returns the total pay giving time and a half for hours worked over 40
    double calcFit(); // calculates fed income tax
    double calcFica(); // calculates social security tax

private:

   string m_name; // name of employee
   int m_hoursWorked; // hours worked by employee
   double m_payRate; // pay rate for employee
   double m_grossPay; // gross pay of the employees
};