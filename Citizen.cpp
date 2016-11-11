//I affirm that all code given below was written solely by me, Ryan Teo, and that any help I received
//adhered to the rules stated for this exam.

#include <iostream>
#include <string>
#include "Citizen.h"
using namespace std;

//Creates a new Citizen object with the passed in
//id, name, and favorite color
//Once a citizen is created, you can't change their id or name
//but you can change their favorite color

Citizen::Citizen(int id, string firstName, string lastName, string color)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->color = color;
}

//Creates a new Citizen object by copying data from the
//passed in citizen
Citizen::Citizen(Citizen* citizen)
{
	citizen = new Citizen(id, firstName, lastName, color); //creates new citizen
	delete citizen; //delete for new
}

//Returns the first name of this citizen
string Citizen::getFirstName()
{
	return firstName;
}

//Returns the last name of this citizen
string Citizen::getLastName()
{
	return lastName;
}

//Returns the id for this citizen
int Citizen::getId()
{
	return id;
}

//Returns the favorite color for this citizen
string Citizen::getFavoriteColor()
{
	return color;
}

//Sets the favorite color for this citizen
void Citizen::setFavoriteColor(string color)
{
	this->color = color;
}
