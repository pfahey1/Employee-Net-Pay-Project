// class employee function definitions

#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

Employee::Employee(void)
  {
	string m_name; // initializes name of employee
    int m_hoursWorked = 0; // initializes hours worked by employees
    double m_payRate = 0.00; // initializes pay rate of employees
    double m_grossPay = 0.00; // initializes gross pay of employees
  } 

void Employee::setName(string name) // sets the name for the employees
	{
		m_name = name;
    }


string Employee::getName() // grabs the name of the employees from setName
	{
		return m_name;
    } 

void Employee::setPayRate(double payRate) // sets the pay rate for the employees
	{
		m_payRate = payRate;
    }

void Employee::setHoursWorked(int hoursWorked) // sets the hours worked for the employees
	{
		m_hoursWorked = hoursWorked;
    } 

double Employee::calcPay() // calculates the gross pay of the employees
	{
		int hoursOverTime = 0;
		
		if (m_hoursWorked > 40) 
		{
			hoursOverTime = (m_hoursWorked - 40);
		}
		
		m_grossPay = ((m_hoursWorked * m_payRate) + (hoursOverTime * (m_payRate * 1.5))); 
		return m_grossPay;
}

double Employee::calcFit() // calculates fed income tax withheld from the employee.
	{
		double fedtax = 0.00;
		
	if (m_grossPay > 116 && m_grossPay <= 200) 
		{
			fedtax = ((m_grossPay - 116) * .10);
		}
	
	else if (m_grossPay > 200 && m_grossPay <= 693) 
		{
			fedtax = (((m_grossPay - 200) * 0.15) + 8.40);
		}
	
	else if (m_grossPay > 693 && m_grossPay <= 1302) 
		{
			fedtax = (((m_grossPay - 693) * 0.25) + 82.35);
		}
	
	else if (m_grossPay > 1302 && m_grossPay <= 1624) 
		{
			fedtax = (((m_grossPay - 1302) * 0.27) + 234.60);
		}
	
	else if (m_grossPay > 1624 && m_grossPay <= 1687) 
		{
			fedtax = (((m_grossPay - 1624) * 0.30) + 321.54);
		}
	
	else if (m_grossPay > 1687 && m_grossPay <= 3344) 
		{
			fedtax = (((m_grossPay - 1687) * 0.28) + 340.44);
		}
	
	else if (m_grossPay > 3344 && m_grossPay <= 7225) 
		{
			fedtax = (((m_grossPay - 3344) * 0.33) + 804.40);
		}
	
	else if (m_grossPay > 7225) 
		{
			fedtax = (((m_grossPay - 7225) * 0.35) + 2085.13);
		}
		return fedtax;
} 

double Employee::calcFica() // calculates social security tax withheld from the employees
	{
		double sstax;
		sstax = m_grossPay * .0765;
		return sstax;
    }
