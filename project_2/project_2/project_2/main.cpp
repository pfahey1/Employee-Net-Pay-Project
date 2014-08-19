/*
Program: tax calculator

Description: program that creates an array of objects to calcuate employees taxes from a file

Author: Paul Fahey

Date: 4/21/2011

Modifications: none
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "employee.h"
using namespace std;

int main(int argc,char *argv[])
{
	Employee employees[10]; // constructor creates an array of objects
	ifstream inDatafile(argv[1], ios::in); // an object for  file input is created
	
	
	if (!inDatafile) 
	{
		cout << argv[1] << " employees.dat could not be opened" << endl;
		return 0;
	}
	
	    string name; 
		int hoursWorked;
		double payRate;
	    int counter = 0;
		double totalgross = 0.00;
	    double totalnet = 0.00;
	    double totalfed = 0.00;
	    double totalss = 0.00;
	
	for(int x = 0; x <= 9; x++) // loop used for file calculations using an array of objects
	{
		 counter = x;
         inDatafile >> name >> hoursWorked >> payRate; // takes in the file for calculations 

		employees[x].setName(name); // sets the employee name
		employees[x].setHoursWorked(hoursWorked); // sets the hours worked by the employee
		employees[x].setPayRate(payRate); // sets the payrate of the employee
		employees[x].getName(); // grabs the name of the employee from setName
		employees[x].calcPay(); // calculates the gross pay of the employee
		employees[x].calcFit(); // calculates the federal tax withheld from the employee
		employees[x].calcFica(); // calculates the social security tax withheld from the employee

		// displays the results from the calculate
		cout << employees[x].getName()<<endl;
		cout << "Net Pay: " << setprecision(2) << fixed << "$" << employees[x].calcPay() - (employees[x].calcFit() + employees[x].calcFica()) << endl;
		cout << "Federal Tax: " << setprecision(2) << fixed << "$"  << employees[x].calcFit() << endl;
		cout << "Social Security Tax: " << setprecision(2) << fixed << "$" << employees[x].calcFica() << endl;
		
		cout << endl;
		cout << endl;
		
		// calculates the total gross pay, net pay, federal income tax withhled, and social security tax withheld from all the employees combined 
		totalgross = totalgross + employees[x].calcPay();
		totalnet = totalnet + employees[x].calcPay() - (employees[x].calcFit() + employees[x].calcFica());
		totalfed = totalfed + employees[x].calcFit();
		totalss = totalss + employees[x].calcFica();
	}
	
	cout << "Number of Employees: " << counter + 1 << endl; // displays the number of employees that were in the file

	cout << endl;
	
	//displays the total gross pay, net pay, federal income tax withhled, and social security tax withheld from all the employees combined 
    cout << "Totals:" << endl;
	cout << endl;
	cout << "Total Gross Pay: " << setprecision(2) << fixed << "$" << totalgross << endl;
    cout << "Total Net Pay: " << setprecision(2) << fixed << "$" << totalnet << endl;
    cout << "Total Federal Income Tax: " << setprecision(2) << "$" << fixed << totalfed<< endl;
    cout << "Total Social Security Tax: " << setprecision(2) << fixed << "$" << totalss << endl;
	cout << endl;
}