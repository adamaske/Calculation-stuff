// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <string>
double Calculate(double, double, char);
int main()
{
	std::cout << "Enter an equation" << std::endl;
	//Get the entire line from stD::getline
	std::string equation;
	std::getline(std::cin, equation);
	double a = 0;
	double b = 0;
	
	char oper = '+';
	for (int i = 0; i < equation.size(); i++)
	{
		//Find where the operator is
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/') {
			//this is the operator, a and b = the previous and later
			//set operator to the current char in equation
			oper = equation[i];
			//Declare the strings that will be converted to doubles
			std::string j = "";
			std::string p = "";
			//Find how big the strings need to be so they are the exact size of the front and back
			//J.size  = i because it should be from equation[0] to the current equation[i-1] but since size is 1 larger than [] array possistion, just us i 
			j.resize(i);
			//P.size should be from the current equation[i] until equation[equation.size()-1] tehrefore equation.size - i is the leftovers
			p.resize(equation.size() - i);
			//Starting from 0 until i-1 sett the j[k] to equation[k]
			for (int k = 0; k < i; k++)
			{
				j[k] = equation[k];
			}
			//P should start from 0 and equal to equation[something]
			for (int k = i+1, c = 0; k < equation.size(); k++, c++)
			{
				p[c] = equation[k];
			}
			std::cout << j << ", " << p;
			system("pause");
			//std::stod(string) makes the string into a double
			a = std::stod(j);
			b = std::stod(p);
			
		}
	}
	std::cout << Calculate(a, b, oper);

}

double Calculate(double a, double b, char oper) {
	switch (oper) {
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	}
}