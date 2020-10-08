#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int left(int, int, char x[10][10], string, int);
int right(int, int, char x[10][10], string, int);
int up(int, int, char x[10][10], string, int);
int down(int, int, char x[10][10], string, int);

int main()
{
	ifstream inputFile;
	
	
	char grid[10][10];
	int gridnum, dirtrue[4];
	string dir[4] = { "to the left","to the right","going up","going down" };
	string word[5] = { "WIT","OBJECT","DEBUG","CODE","CLASS" };
	

	cout << "Enter '1' to search grid 1 and '2' to search grid 2: ";
	cin >> gridnum;
	cout << endl;

	switch (gridnum)
	{
	case 1:
		inputFile.open("Lab3_WordSearch1.txt");
		
		break;

	case 2:
		inputFile.open("Lab3_WordSearch2.txt");
		break;
	default:
		cout << "Not a valid grid number.";
		break;
	}


	//display grid

	cout << "Displaying the grid..." << endl << endl;
	for (unsigned int r = 0; r < 10; r++)
	{
		for (unsigned int c = 0; c < 10; c++)
		{
			inputFile >> grid[r][c];
			cout << grid[r][c] << " ";
		}
		cout << endl;
	}
	


	//seach funciton
	
		for (unsigned int w = 0; w < 5; w++)//count five words
		{	
			cout << endl;
			cout << "Searching for " << word[w]<<endl;
			for (unsigned int r = 0; r < 10; r++)//index rows 
			{
				for (unsigned int c = 0; c < 10; c++)//index columns
				{
				
					if (grid[r][c] == word[w][0]) //does spot = first letter?
					{
					
						dirtrue[0] = left(r, c, grid, word[w], word[w].length());
						dirtrue[1] = right(r, c, grid, word[w], word[w].length());
						dirtrue[2]= up(r, c, grid, word[w], word[w].length());
						dirtrue[3] = down(r, c, grid, word[w], word[w].length());
						for (unsigned int i = 0; i < 4; i++)
						{
							//cout << dirtrue[i] << endl; debug statement
							if (dirtrue[i] == 1)
							{
								cout << word[w] << " found at <" << r << "," << c << "> " << dir[i] << endl;
							}
						}
					}
				}
			}
		}
	

	inputFile.close();
	return 0;
}

int left(int r,int c, char grid[10][10], string word,int length)
{
	int correct = 0;
	if (grid[r][c - length+1] == word[length - 1])
	{
		for (int i = 0; i < length; i++)
		{
			if (grid[r][c - i] == word[i])
			{
				correct++;
					if (correct == length)
					{
						return 1;
					}
			}
		}
	}
	return 0;
}
int right(int r, int c, char grid[10][10], string word, int length)
{
	int correct = 0;
	if (grid[r][c + length-1] == word[length - 1])
	{
		for (int i = 0; i < length; i++)
		{
			if (grid[r][c + i] == word[i])
			{
				correct++;
					if (correct == length)
					{
						return 1;
					}
			}
		}
	}
	return 0;
}
int up(int r, int c, char grid[10][10], string word, int length)
{
	int correct = 0;
	if (grid[r - length+1][c] == word[length - 1])
	{
		for (int i = 0; i < length; i++)
		{
			if (grid[r-i][c] == word[i])
			{
				correct++;
					if (correct == length)
					{
						return 1;
					}
			}
		}
	}
	return 0;
}
int down(int r, int c, char grid[10][10], string word, int length)
{
	int correct = 0;
	if (grid[r + length-1][c] == word[length-1])
	{
		for (int i = 0; i < length; i++)
		{
			if (grid[r+i][c] == word[i])
			{
				correct++;
					if (correct == length)
					{
						return 1;
					}
			}
		}
	}
	return 0;
}
