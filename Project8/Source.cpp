
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <array>
#include<sstream>
#include<cstring>

using namespace std;

int conversion_to_int(string info)
	{
	int value;
	stringstream convert(info);
			
			
			if (!(convert >> value))
				{
				value = 0;
				
				}
return value;
}


int main (){

	array <int,2> world;
	array <int,4> robot;
	vector <int> wall;
	vector <int> beeper;

	vector<int>::iterator walls;
	vector<int>::iterator beepers;

	string temp;

	ifstream inputWorld("input world.txt");

	if (inputWorld.is_open())
	{
		while (!inputWorld.eof())
		{

			inputWorld >> temp;

			if (temp == "World")
			{
				inputWorld >> temp;
				world[0] = conversion_to_int(temp);
				inputWorld >> temp;
				world[1] = conversion_to_int(temp);
				
			}
			else if (temp == "Robot")
			{
				inputWorld >> temp;
				robot[0] = conversion_to_int(temp);
				inputWorld >> temp;
				robot[1] = conversion_to_int(temp);
				inputWorld >> temp;
				robot[2] = conversion_to_int(temp);
				inputWorld >> temp;
				robot[3] = conversion_to_int(temp);
			}
			else  if (temp == "Wall")
			{
				for (int i = 0; i < 2; i++)
				{
					int tempWall;
					inputWorld >> temp;
					tempWall = conversion_to_int(temp);
					wall.push_back(tempWall);
				}
			}
			else if (temp == "Beepers")
			{
				for (int i = 0; i < 3; i++)
				{
					int tempBeeper;
					inputWorld >> temp;
					tempBeeper = conversion_to_int(temp);
					beeper.push_back(tempBeeper);
				}
			}
		}
	}
	else cout << "Could not open" << endl;

	cout << "World " << world[0] << " " << world[1] << endl;
	cout << "Robot " << robot[0] << " " << robot[1] << " " << robot[2]
		 << " " << robot[3] << endl;

	walls = wall.begin();
	
	while (walls<wall.end())
	{
		cout << "Wall ";
		cout << *walls << " ";
		walls ++;
		cout << *walls << endl;
		walls ++;
	}
	
	beepers = beeper.begin();

	while (beepers<beeper.end())
	{
		cout << "Beepers ";
		cout << *beepers << " ";
		beepers++;
		cout << *beepers << " ";
		beepers++;
		cout << *beepers << endl;
		beepers++;
	}
	
	system("PAUSE");







	return 0;
}