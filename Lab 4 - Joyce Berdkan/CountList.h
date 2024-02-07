#include "SelfOrderedListADT.h"
#include"llist.h"
#include <map>


#ifndef COUNTLIST_H
#define COUNTLIST_H

using namespace std;
template <typename E>

class CountList : public SelfOrderedListADT<E> {
private:
	CountList(const CountList&) {}
	LList <E> list;
	int numofcompares;
	map<E, int> frequency;

public:
	CountList() { numofcompares = 0; }
	~CountList() {}

	//function for finding a user given value
	bool find(const E& it)
	{
		//varible for triggering parts of code
		int found = 0;
		//move the list to the start
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
		//increment the number of times accessed if a dupliacte value is found
		if (found == 1)
		{
			/*int temp;*/
			reorder(it);
			return true;
		}
		else {
			/*list.moveToEnd();
			list.insert(it);*/
			add(it);
			return false;
		}
	}

	//function to  add a value to the end of the list 
	void add(const E& it) 
	{
		list.append(it);
		frequency.insert(pair<E, int>(it, 0));

	}

	//function to reorder th eitems based on their number of accesses
	void reorder(const E& it)
	{
		
		int itFreq = ++frequency[it];
		int currFreq;

		while (list.getValue() != list.frontValue())
		{
			if (list.getValue() != list.frontValue())
			{
				list.prev();
				currFreq = frequency.at(list.getValue());
			}
			else {
				break;
			}
			if (itFreq > currFreq)
			{
				list.next();
				list.remove();
				list.prev();
				list.insert(it);
			}
		}
	}

	//function to return the number of compares
	int getCompares()const 
	{
		return numofcompares;
	}

	//function to return the size of the list
	int size() const {
		return list.length();
	}

	//function to print the list
	void printlist()
	{
		cout << "Count Heuristic: ";
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
		cout << "My list size is: " << size() << endl <<endl;

	}

	//same as above, but will only print a given number of values
	void printlist(int n)
	{
		cout << "Count Heuristic: " << endl;
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
		cout << "My list size is " << size() << endl <<endl;
	}
};
#endif