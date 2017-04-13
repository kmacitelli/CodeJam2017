#include <iostream>
using namespace std;

int isTidy(int);
void outputTidiness(int, int);



int main()
{
	int numTestCases = 0;
	int currentElement = 0;
	int lastTidy;
	int currentElIsTidy = 1;
	

	cin >> numTestCases;
	
	//Input all elements, if theyre tidy and > greatest known tidy num, they are the new greatest tidy num
	for (int i = 0; i < numTestCases; i++)
	{	
		lastTidy = 0;
		cin >> currentElement;
		
		for (int j=0; j<=currentElement; j++)
		{
			currentElIsTidy = isTidy (j);
			
			if ((currentElIsTidy)&&(j>lastTidy))
			{
				lastTidy = j;
			}
		}
		
		outputTidiness(i, lastTidy);
		
	}
	
	
}

//Passed by value so this method doesn't modify currentElement in main
int isTidy(int numToCheck)
{
	//Get last 2 digits of the number
	int lastDigit = numToCheck%10;
	numToCheck = numToCheck/10;
	int currentDigit = numToCheck%10;
	numToCheck = numToCheck/10;
	
	//Holds whether tidy
	int isTidy = 1;
	
	if (lastDigit<currentDigit) 
	{
		isTidy = 0;
	}
	
	while (numToCheck>0)
	{	
		if (lastDigit<currentDigit)
		{
			isTidy = 0;
		}
		
		lastDigit = currentDigit;
		currentDigit = numToCheck%10;
		numToCheck = numToCheck/10;
	}
	
	if (lastDigit<currentDigit)
	{
		isTidy = 0;
	}
	
	
	return isTidy;
}

void outputTidiness(int k, int lastT)
{
	cout << "Case #" << k+1 << ": " << lastT << "\n";
}
