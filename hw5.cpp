//Chris Talent	
//Oct 19 2015
//HW5
// This program takes in diagonal length and aspect ratio of a 
// screen, then calculates the height and width of that screen.

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void main();

struct ScreenDimension
{
	ScreenDimension()
		: m_diagonal(0)
		, m_aspect(0)
	{}

	ScreenDimension(double diagonal, double aspect)
		: m_diagonal(diagonal)
		, m_aspect(aspect)
	{}
	
	double getHeight()
	{
		return sqrt((m_diagonal * m_diagonal) / (1 + (m_aspect * m_aspect)));
	}

	double getWidth()
	{
		return m_aspect * getHeight();
	}

	double m_diagonal;
	double m_aspect;
};

void main()
{
	bool done(false);
	do
	{
		char choice;
		double diagonal = 0;
		double aspect = 0;
		cout << "Calculate dimenisons? (y/n)" << endl;
		cin >> choice;
		if (choice == 'y')
		{
			cout << "Enter diagonal length" << endl;
			cin >> diagonal;
			cout << "Enter aspect ratio as decimal" << endl;
			cin >> aspect;

			ScreenDimension* screenDimension = new ScreenDimension(diagonal, aspect);

			cout << "Height: " << screenDimension->getHeight() << endl;
			cout << "Width: " << screenDimension->getWidth() << endl;
			
			delete screenDimension;
		}
		else
		{
			done = true;
		}
	} while (!done);
}