#include "Child.h"
#include <fstream>

Child::Child()
{
	firstName = "";
	lastName = ""; 
	age = 0;
}

Child::Child(string firstname, string lastname, int aging)
{
	firstName = firstname;
	lastName = lastname;
	 age = aging;
}

//constructor from Child
Child::Child(const Child &child)
{	
	*this = child;
}


//destructor
Child::~Child()
{
}

//getter and setters
string Child::getFirstName()const
{
	return firstName;
}

string Child::getLastName()const
{
	return lastName;
}

int Child::getAge()const
{
	return age;
}

void Child::setFirstName(string st)
{
	firstName = st;
}

void Child::setLastName(string st)
{
	lastName = st;
}
void Child::setAge(int ages)
{
	age = ages;
}


//.....operator overloads....................
bool Child::operator>(const Child &ch) const
{
	
	if(lastName > ch.lastName) //if they have same last name
	{
		return true;

	}
	else if(lastName < ch.lastName) //this last name is less than the parameter lastname
	{
	
		return false;
	}
	
	else //if same last name
	{
	
		if(firstName > ch.firstName)
		{
		
			return true;
		
		}
		
		if(firstName < ch.firstName)
		{	
			return false;
		
		}
		
		else//if same last and first name,  compare age
		{
		
			return age > ch.age;
		}

	}
}

//>=
bool Child::operator>=(const Child &ch) const
{
	
	bool greater = *this > ch;
	bool equal = *this == ch;
	
	return (greater || equal);
}

//<
bool Child::operator<(const Child &ch) const
{

	if(lastName == ch.lastName)
	{
		if(firstName == ch.firstName)
		{
			if(age == ch.age)
			{
				return false;
			}
			return (age < ch.age);
		}
		return (firstName < ch.firstName);
	}
	return (lastName < ch.lastName);
}


//<=
bool Child::operator<=(const Child &ch) const
{
	bool less = (*this < ch);
	bool equal = *this == ch;


	return (less || equal);


}

// !=
bool Child::operator!=(const Child &ch) const
{
	return ((firstName != ch.firstName) || (lastName != ch.lastName) || (age != ch.age));
}


//==
bool Child::operator==(const Child &ch) const
{
	return ((firstName == ch.firstName) && (lastName == ch.lastName) && (age == ch.age));
}

//assignment op
Child& Child::operator=(const Child &ch) 
{

	if(*this == ch)//if they are already equal, return false.
	{
		return *this;
	}

	else
	{
		firstName = ch.firstName;
		lastName = ch.lastName;
		age = ch.age;
		return *this;
	}
}


//ostream object
ostream& operator<<(ostream &outStream, const Child &ch)
{
	outStream << ch.firstName << ch.lastName << ch.age;
	return outStream;
}


//istream 
istream& operator>>(istream &inStream,Child &ch)	
{	
	inStream >> ch.firstName >> ch.lastName >>ch.age;

	//this->firsstName = ch.firstName;
	//this->lastName = ch.lastName;
	//this->age = ch.age;
	return inStream;
}



