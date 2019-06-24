#ifndef CHILD_H
#define CHILD_H
#include <iostream>
#include <string>

using namespace std;

class Child
{	friend ostream& operator<<(ostream &outStream, const Child &ch);	
	friend istream& operator>>(istream &inStream,  Child &ch);
	public:
		
		//constructors
		Child();
		Child(string firstname, string lastname, int aging);
		Child (const Child &ch);
		~Child();

		//setter and getters
		string getFirstName()const;
		string getLastName()const;
		int getAge()const;
		void setFirstName(string st);
		void setLastName(string st);
		void setAge(int ages);
		
		//oprator oveloads
		bool operator>(const Child &ch) const;
		bool operator>=(const Child &ch) const;
		bool operator<(const Child &ch) const;
		bool operator<=(const Child &ch) const;
		bool operator!=(const Child &ch) const;
		bool operator==(const Child &ch) const;
		Child& operator=(const Child &ch);



	private:
		string firstName;
		string lastName;
		int age;
};

#endif // CHILD_H

