#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>


#ifndef TRANSPOSELIST_H
#define TRANSPOSELIST_H

using namespace std;

template <typename E>
class TransposeList : public SelfOrderedListADT<E>
{
private:
	TransposeList(const TransposeList&) {}
	LList<E> list;
	int numofcompares;
	map<E, int> frequency;


public:
	//Transpose constructor, set the number of compares to zero
	TransposeList() { numofcompares = 0; }
	~TransposeList() {}

	//function to find a specified element in the list
	bool find(const E& it)
	{
		int found = 0;
		list.moveToStart();
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
		//if there is a duplicate increment the number of times accessed
	//for that element and call the reorder function
		if (found == 1)
		{
			//int temp;
			frequency[it]++;
			reorder(it);
			return true;
		}
		else
		{
			/*list.moveToEnd();
			list.insert(it);*/
			add(it);
			//reorder();
			return false;
		}
	}

	//function to call the list append function
	void add(const E& it) 
	{
		list.append(it);
		frequency.insert(pair<E, int>(it, 0));

	}

	//function to return the number of compares
	int getCompares()const {
		return numofcompares;
	}

	//function to return the size of the list
	int size() const {
		return list.length();
	}

	//function to call the list 
	void printlist()  {
		cout << "Transpose Heuristic: ";
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
		cout << "My list size is: " << size() << endl << endl;

	}

	//function to print a specified number of items from the list
	void printlist(int n)  {
		cout << "Transpose Heuristic: " << endl;
		cout << "Number of Compares: " << getCompares() << endl;
		/*list.print(n)*/;
		cout << "My final list structure with frequencies is: " << endl;
		list.moveToStart();
		for (int i = 0; i < n; i++)
		{
			cout << list.getValue() << "-" << frequency.at(list.getValue()) << " ";
			list.next();
		}
		cout << endl;
		cout << "My list size is " << size() << endl << endl;
	}

	//function to reorder the elements by swapping them with the
	//previous element
	void reorder( const E& it)
	{
		
		if(list.frontValue() != it)
		{
			list.prev();
			list.insert(it);
			list.next();
			list.next();
			list.remove();
		}

	}
};
#endif