#pragma once
#include<iostream>
#include<string>

using namespace std;

template < class ItemType>
class LinkedQueue
{
	
	//ostream friend method
	friend ostream& operator<<(ostream& outStream, const LinkedQueue<ItemType>& que )
	{
		LinkedQueue<ItemType>::Node* orig = que.top;
		while(orig != nullptr)
		{
			outStream<<*(orig->data);
			orig = orig->next;
		}
		delete orig;
		orig = nullptr;
		return outStream;
	}


public:
	LinkedQueue();//const
	~LinkedQueue();
	LinkedQueue(const LinkedQueue<ItemType> &que);//copy const
	
	//memeber functions
	bool BuildQueue(string fileName);
	void Enqueue( ItemType *obj );
	bool Dequeue(ItemType &result);
	bool Peek(ItemType &result) const;
	bool isEmpty() const;
	int Size() const;
	void DeleteQueue();
	void Reverse();
	void rev();
	
	//operator overloads
	bool operator==(const LinkedQueue<ItemType> &que)const;
	bool operator!=(const LinkedQueue<ItemType> & que)const;
	LinkedQueue<ItemType>& operator=(const LinkedQueue<ItemType>& que);

private:
	int size;
	struct Node
	{
		ItemType* data = nullptr;
		Node* next = nullptr ;
	}; Node* top, * tail;
};
#include "LinkedQueue.cpp"

