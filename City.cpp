//I affirm that all code given below was written solely by me, Ryan Teo, and that any help I received
//adhered to the rules stated for this exam.

#include <iostream>
#include "City.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Creates a new city with the given name
//When the city is created you need to restore
//it's population from a file.
//Hint: You will want to make the file name
//be based on the name of the city.
City::City(string cityName)
{
	this->cityName = cityName;
	string file = cityName + ".txt"; //file with city name
	ifstream fin(file, ios::out); //open the file 
	

	fin >> population; //input the population
	fin.close();
}

//This is the destructor for the city. When
//this city is destroyed, save the population of
//the city to a file so that you can restore
//it in the constructor the next time that
//a city with this name is created.
City::~City()
{
	string file = cityName + ".txt"; //file with city name
	ofstream fout(file, ios::in); //open the file
	for (int i = 0; i < population; i++)
	{
		fout << citizens[i]; //output the population
	}
	fout.close(); //close the file
}

//Returns the city name
string City::getCityName()
{
	return cityName;
}

//Returns the number of citizens in this city
int City::populationSize()
{
	return citizens.size();
}

//Returns the citizen at the given index.
Citizen* City::getCitizenAtIndex(int index)
{
	return citizens[index];
}

//Adds a citizen to this city. You will need to
//make a copy of this citizen so that you make
//sure to keep it around for the life of the city.
void City::addCitizen(Citizen* citizen)
{
	citizens.push_back(citizen);
}

//Returns the citizen with the given id.
Citizen* City::getCitizenWithId(int id)
{
	for (int i = 0; i < population; i++) //checks every citizen
	{
		if (citizens[i]->getId() == id) //checks citizens id with the specified id
		{
			return citizens[i]; //returns the citezens with the same id
		}
	}
}

//Returns a vector of citizens that all have
//the given color as their favorite color.
//For example, if color is “Blue” this will return all citizens
//for this city who’s favorite color is Blue.

//I used the same checks as I did for the id above but couldn't fix the errors, don't know why.
//Also I'm not sure if I'm supposed to get a different ouput the second and third times or 
//if that's only supposed to happen if I have no errors the first time
vector<Citizen*> City::getCitizensForFavoriteColor(string color) 
{
	for (int i = 0; i < population; i++)
	{
		if (citizens[i]->getFavoriteColor() == color)
		{
			favColor.push_back(citizens[i]);
		}
	}
	return favColor;
}