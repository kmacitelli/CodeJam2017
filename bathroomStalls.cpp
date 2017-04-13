#include <iostream>
using namespace std;

int pickStall (int*, int);
int computeLS(int*, int);
int computeLR(int*, int);

int main()
{
	int numStalls;
	int numTestCases;
	
	cin >> numTestCases;
	
	int numberStalls;
	int numberPeople;
	
	int stallPicked;
	
	
	for (int i=0; i<numTestCases; i++)
	{
		cin >> numberStalls;
		cin >> numberPeople;
		
		//Array to keep track of which stalls are occupied
		int* stalls = new int[numberStalls+2];
		
		//Initialize array elements
		stalls[0]=1;
		stalls[numberStalls+1]=1;
		
		for (int j=1; j<=numberStalls; j++)
		{
			stalls[j]=0;
		} 
		
		for (int k=0; k<numberPeople; k++)
		{
			stallPicked = pickStall(stalls, numStalls);
			stalls[stallPicked] = 1;
		}
		
		
	}
}

int pickStall (int* stallArray, int nStalls)
{
	int ls, lr;
	int currentMinL;
	int totalMinL=-1;
	int indexTotalMinL = -1;
	int currentMaxL = -1;
	int totalMaxL = -1;
	int indexTotalMaxL = -1;
	
	for (int i=0; i<nStalls+2; i++)
	{
		//If stall is unoccupied
		if (stallArray[i]==0)
		{
			//Distance to closest L and R neighbor
			ls = computeLS(stallArray, i);
			lr = computeLS(stallArray, i);
			
			if (ls<lr)
			{
				currentMinL = ls;
				currentMaxL = lr;
			}
			else
			{
				currentMinL = lr;
				currentMaxL = ls;
			}
			
			if (currentMinL > totalMinL)
			{
				totalMinL = currentMinL;
				indexTotalMinL = i;
			}
			else if (currentMinL == totalMinL)
			{
				//choose one in which max(Ls, Rs) is maximal
				if (currentMaxL>totalMaxL)
				{
					indexTotalMinL = i;
				}
				else if (currentMaxL==totalMaxL)
				{
					//If those the same, choose leftmost, which means ignore new one since we are going left to right through array
				}

				
			}
		}
	}
	return indexTotalMinL;
}

int computeLS(int* stallArray, int currentIndex)
{
	int currentElement = 0;
	int i=0;

	while (currentElement == 0)
	{
		currentElement = stallArray[currentIndex-i];
		i++;
	}
	
	return i-1;
}

int computeLR(int* stallArray, int currentIndex)
{
	int currentElement = 0;
	int i=0;

	while (currentElement == 0)
	{
		currentElement = stallArray[currentIndex+i];
		i++;
	}
	
	return i-1;
}
