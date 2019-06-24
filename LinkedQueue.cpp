#pragma once
#include "LinkedQueue.h"
#include "LinkedStack.h"//this is the stack class I defined in this project

//constr
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(): top(nullptr), tail(nullptr), size(0)//const
{	
}

//destructor
template<class ItemType>
LinkedQueue<ItemType>:: ~LinkedQueue()
{
	DeleteQueue();
}

//copy constructor
template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType> &que)//copy const
{	
	
	Node* curr = que.top;
	if(curr == nullptr)
	{
		top = nullptr;
		tail = nullptr;
		size = 0;
	}
	else
	{	
		ItemType item;
		while(curr != nullptr)	
		{		
			item = *(curr->data);//get the data vakue of the argument queue
			this->Enqueue(&item);//push the data to the left side of the queue
			curr = curr->next;
		}
	}
	curr = nullptr;
}

//build queue from a file
template<class ItemType>
bool LinkedQueue<ItemType>::BuildQueue(string fileName)
{
	ifstream file(fileName);
	if(file.is_open())
	{
		ItemType item;
		while(file>>item)
		{
			this->Enqueue(&item);
		}
		file.close();
		return true;
	
	}
	cerr<<"could't open file"<<endl;
	return false;
}

//this member function builds the Queue given the address of the item to b
//equeued
template<class ItemType>
void LinkedQueue<ItemType>::Enqueue( ItemType *obj )
{	
	Node* newNode = new Node;
	ItemType* item = new ItemType;
	*item = *obj;
	newNode->data = item;
	
	if(top == nullptr)// empty queue
	{	//top = new Node;
		top =  newNode;
		tail = newNode;
		size++;
	}
	
	else //if the queue is not empty
	{
		tail->next = newNode;
		tail = newNode;
		size++;
	}
}

//this member function deletes the first element of the queue
template<class ItemType>
bool LinkedQueue<ItemType>::Dequeue(ItemType &result)
{
	if(top == nullptr)//no element to be deleted
	{
		return false;
	}
	
	Node* curr = top;
	
	top = top->next;//top points to the next element in the list(the second element is now the first)
	curr->next = nullptr;
	result = *(curr->data);//return the first element
	size--;//update size
	delete curr->data;//delete the data member
	delete curr;//reclaiming memory
	curr = nullptr;
	return true;
}

//peek the top element
template<class ItemType>
bool LinkedQueue<ItemType>::Peek(ItemType &result) const
{
	if(top == nullptr)
	{
		return false;
	}
	//the queue is not empty
	result = *(top->data);
	return true;
}

//check if the queue is empty
template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{

	bool isEmpty = (size == 0);
	return isEmpty;
}

//size of the queue
template<class ItemType>
int LinkedQueue<ItemType>::Size() const
{
	return size;
}

//delete the entire list(queue)
template<class ItemType>
void LinkedQueue<ItemType>::DeleteQueue()
{	
	size = 0;//set size to zero
	Node* curr = top;
	while(top != nullptr)
	{
		top = top->next;
		delete curr->data;//delete the data pointer
		delete curr;//reclaiming memory
		curr = top;//advance curr
	}
	top = nullptr;
	tail = nullptr;
	curr = nullptr;
}

//reverse the order of elements in the queue
template<class ItemType>
void LinkedQueue<ItemType>::Reverse()
{
	 Node* current = top; 
   	 Node* next = nullptr;
	 tail = top; //bring the tail to the other end
    	while (current->next != NULL) 
	{ 
        	next = current->next; 
        	current->next = next->next; 
        	next->next = top; 
        	top = next; 
    	} 
	current = nullptr;
	next = nullptr;
}

//== operator overloads
template<class ItemType>
bool LinkedQueue<ItemType>::operator==(const LinkedQueue<ItemType> &que)const
{
	if(size != que.size)//if unequal size, they are not equal
	{
		return false;
	}
	
	//if they have equal size, compare their contents
	Node* curr = top;
	Node* guest = que.top;
	while(curr != nullptr)
	{
		if(*curr->data != *(guest->data))
		{
			return false;
		} 
		guest = guest->next;
		curr = curr->next;
	}
	return true;
}

//!= operator overload
template<class ItemType>
bool LinkedQueue<ItemType>::operator!=(const LinkedQueue<ItemType> & que)const
{
	if(size != que.size) //if they are of differen size, they are unequal
	{
		return true;	
	}
	
	Node* curr = top;
	Node* guest = que.top;
	
	while(curr != nullptr)
	{
		if(*(curr->data) != *(guest->data))
		{
			return true;
		}
		guest = guest->next;
		curr = curr->next;
	}
	return false;
}

//asignment operator
template<class ItemType>
LinkedQueue<ItemType>& LinkedQueue<ItemType>::operator=(const LinkedQueue<ItemType>& que)
{
	if(this != &que)//check self assignment
	{
		this->DeleteQueue();//clear original content of left side
	
		Node* curr = que.top;
		ItemType item;
		while(curr != nullptr)
		{
			item = *(curr->data);//get the data item 
			this->Enqueue(&item);//call the Enqueue() member function to populate the list
			curr = curr->next;
		}
		curr = nullptr;
	}	
	return *this;
}

