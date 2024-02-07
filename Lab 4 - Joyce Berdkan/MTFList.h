#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>
#include <map>

#ifndef MTFLIST_H
#define MTFLIST_H

using namespace std;

template <typename E>
class MTFList : public SelfOrderedListADT<E>
{
private:
	MTFList(const MTFList&) {}
	LList<E> list;
	int numofcompares;
	map<E, int> frequency;

public:
	//Move to first constructor, setthe number of compares to zero
	MTFList() { numofcompares = 0; }
	~MTFList() {};

	//function to find a value in the list
	bool find(const E& it)
	{
		//variable to determine whether code proceeds or not
		int found = 0;
		//move the list to the start
		list.moveToStart();
		//loop to determine if there are duplicate values in the list or not
		for (int i = 0; i < list.length(); i++)
		{
			numofcompares++;
			if (list.getValue() == it)
			{
				found = 1;
				break;
			}
			list.next();
		}
		//if found equals one then increment the number of accesses for
		//the current item
		if (found == 1)
		{
			frequency[it]++;
			//int temp;
			reorder();
			return true;
		}
		else
		{
			/*list.moveToEnd();
			list.insert(it);*/
			add(it);
			reorder();
			return false;
		}
	}

	//function to call the list append function and pass it the element
	void add(const E& it)
	{
		list.append(it);
		frequency.insert(pair<E, int>(it, 0));
	}

	//function to reoreder the elements by moving them to the front
	//when they are accessed
	void reorder()
	{
		//get the number of accesses for the item to be swapped
		int toSwap;
		list.next();
		int next;
		list.prev();
		E temp = list.remove();
		list.moveToStart();
		int front;
		list.insert(temp);
		list.next();
	}

	//function to print the list
	void printlist() 
	{
		cout << "Move-To-Front Heuristic: " ;
		cout << endl;
		cout << "Number of Compares: " << getCompares();
		cout << endl;
		//list.print();
		cout << "My final list structure with frequencies is: " << endl;
		list.moveToStart();
		for (int i = 0; i < list.length(); i++)
		{
			cout << list.getValue() << "-" << frequency.at(list.getValue()) << " ";
			list.next();
		}
		cout << endl;
		cout << "My list size is: " << size() << endl<<endl ;

	}

	//function to print a specified numberof items in the list
	void printlist(int n) 
	{
		cout << "Move-To-Front Heuristic: " << endl;
		cout << "Number of Compares: " << getCompares() <<endl;
		/*list.print(n)*/;
		cout << "My final list structure with frequencies is: " << endl;
		list.moveToStart();
		for (int i = 0; i < n; i++)
		{
			cout << list.getValue() << "-" << frequency.at(list.getValue()) << " ";
			list.next();
		}
		cout << endl;
		cout << "My list size is " << size() << endl <<endl;
	}

	//function to return the number of compares
	int getCompares() const
	{
		return numofcompares;
	}

	//function to return the list size
	int size() const
	{
		return list.length();
	}
};
#endif