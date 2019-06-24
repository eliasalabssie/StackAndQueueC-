#pragma once
#include "LinkedStack.h"
#include <fstream>


template<class ItemType>
LinkedStack<ItemType>::LinkedStack():top(nullptr), size(0)
{
	//onstruct
}


//detor 
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	DeleteStack();

}


//copy constructor
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType> &stack)
{		
	Node* orig = stack.top;
	if(orig == nullptr)
	{
		top = nullptr;
		size = 0;
	}

	else
	{
		LinkedStack <ItemType> st;//auxiliary stack
		
		while(orig != nullptr)
		{
			st.Push(*(orig->data));//pushing the data into the auxiliary stack
			orig = orig->next;

		}
		orig = nullptr;//set the Node pointer to nullptr
		ItemType item;
		while(!st.isEmpty())
		{	
			 st.Pop(item);//delete the auxiliary stack 
			this->Push(&item);//populate the "this" class

		}
	}

}


//this BuildStack memeber functions buildds the stack from the file
template <class ItemType>
bool LinkedStack<ItemType>::BuildStack(string fileName)
{	
	ifstream file(fileName);
	//file.open(fileName);
	if(!file.is_open())
	{
		cerr<<"unable to open file " <<fileName;//file not available or not readable.
		return false;
	}

	//if file is in good condition to be opened
	 ItemType data;
	 
	while(file >> data)
	{
		this->Push(&data);
	}
	file.close();
	return true;
}

//populate the stack 
template <class ItemType>
void LinkedStack<ItemType>::Push( ItemType *obj )
{		

		Node* newNode = new Node;
		ItemType *item = new ItemType;
		*(item) = *(obj);
		newNode->data = item;
		newNode->next = top;
		top = newNode;
		size++;//update size private data member		
}//end Push


//pop deletes the first element of the stack
template <class ItemType>
bool LinkedStack<ItemType>::Pop(ItemType &result)
{
	if(top != nullptr)
	{
		result = *(top->data);
		Node* curr = top;
		top = top->next;
		delete curr->data;// delete the front Node
		delete curr;
		curr = nullptr;
		size--; //rduced size by one	
		return true;

	}
	return false;//if the Stack is empty, return false.
}//endl of Pop


//Peek and return the first element via the argument
template <class ItemType>
bool LinkedStack<ItemType>::Peek(ItemType &result) const
{
	if(top != nullptr)
	{
		result = *(top->data);
		return true;
	}
	return false;
}//end Peek


//this method checks if the Stack is empty: return true if it is, false otherwise
template <class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	bool result = (top == nullptr);
	return result;
}


template <class ItemType>
int LinkedStack<ItemType>::Size() const
{
	return size;
}


//delete the entire stack and de-allocate memory
template <class ItemType>
void LinkedStack<ItemType>::DeleteStack()
{	
	size = 0;//the size of the stack to zero
	Node* curr = top;
	while(top != nullptr)
	{
		top = top->next;
		delete curr->data;//delete the data member pointer
		delete curr;
		 curr = top;
	}
	curr = nullptr;
	top = nullptr;
}


//Palindrome function
template <class ItemType>
bool LinkedStack<ItemType>::isPalindrome() const
{	
	if(top == nullptr)
	{
		return true; //empty list is palindrome
	}
	
	//make  empty auxiliary LinkedStack to hold the "this" values in reverse order.
	LinkedStack<ItemType> pal;

	ItemType hold;//holds data values during traversing 
	Node* curr = top;
	
	//populate the empty LinkedStack
	while(curr != nullptr)
	{	
		hold = *(curr->data);//get the data value of the "this" object	
		pal.Push(&hold);//push to the stack
		curr = curr->next;//advance the Node pointer
	}	
	curr = nullptr;//set to null to avoid dangling	

	//now I have one more populated linkedStack other than the "this" object in reverse order.
	//so compare thier values for palindrome	
	Node* temp = top;	
	while(temp != nullptr)
	{
		  pal.Pop(hold);
		
		if(*(temp->data) != hold)//compare the top data values of the two stacks
		{
			pal.DeleteStack();//delete the stack
			return false;// if one of the data values differ, return false. 
		}
		
		temp = temp->next;
	}
	return true;//return true( the reversed stack and the original stack match one-t0-one from top to bottom)
	
}


// equality operator overload
template <class ItemType>
bool LinkedStack<ItemType>::operator==(const LinkedStack<ItemType> &stack)const
{
	if(size != stack.size)//if different size, they are not  equal	
	{
		return false;
	}
	
	//if equal size	
	Node* home = top;
	Node* guest = stack.top;

	while(guest != nullptr)
	{	 
		if(*(home->data) != *(guest->data))//compare each data values
		{
			return false;
		}
		guest = guest->next;
		home = home->next;
	}
	home = nullptr;
	guest = nullptr;
	return true;
}

//!= operator overload
template <class ItemType>
bool LinkedStack<ItemType>::operator!=(const LinkedStack<ItemType> & stack)
{
	if(size != stack.size)//if different size, they are not equal
	{
		return true;
	}
	
	Node* home = top;
	Node* guest = stack.top;
	while(guest != nullptr)
	{
		if(*(guest->data) != *(home->data))//compare data values
		{
			return true;
		}
		guest = guest->next;
		home = home->next;
	}
	return false;

}

//assignment operator
template <class ItemType>
LinkedStack<ItemType>& LinkedStack<ItemType>::operator=(const LinkedStack<ItemType> &stack)
{	
	
	if(this != &stack) //check self assignment
	{	
		this->DeleteStack();//clear left Stack
		Node* temp = stack.top;
		LinkedStack<ItemType> mys;// a new linked stack object
		ItemType resul;
		while(temp != nullptr)
		{
		 	resul = *(temp->data);
			mys.Push(&resul);
			temp = temp->next;
		}
		
		//copy the elements to "this" in the same order as the original stack
		//and delete the auxilary stack to free up memmory
		while(!mys.isEmpty())
		{	 mys.Pop(resul);
			this->Push(&resul);
				

		}
	} 
	return  *this;
}







