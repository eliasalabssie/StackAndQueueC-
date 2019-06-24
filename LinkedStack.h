#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include<iostream>
#include<string>
#include "Child.h"
using namespace std;


template < class ItemType>
class LinkedStack
{
	//friend ostream object
	friend ostream& operator<<(ostream& outStream, const LinkedStack <ItemType> &stack )
	{
		LinkedStack<ItemType>::Node* orig = stack.top;
		while(orig != nullptr)
		{
			outStream<<*(orig->data);
			orig = orig->next;
		}
		return outStream;
	}

public:
	LinkedStack();//const
	~LinkedStack();//dest
	LinkedStack<ItemType>(const LinkedStack<ItemType> &stack);//copy const

	//memeber functions
	bool BuildStack(string fileName);
	void Push( ItemType *obj );
	bool Pop(ItemType &result);
	bool Peek(ItemType &result) const;
	bool isEmpty() const;
	int Size() const;
	void DeleteStack();
	bool isPalindrome() const;

	//operator overloads
	bool operator==(const LinkedStack<ItemType> &stack)const;
	bool operator!=(const LinkedStack<ItemType> & stack);
	LinkedStack<ItemType>& operator=(const LinkedStack<ItemType>& stack);


private:

	int size;

	struct Node
	{	
	
		ItemType* data = nullptr;
		Node* next = nullptr;
	}; Node* top;


};//end LinkedStack

#include "LinkedStack.cpp"
#endif 
