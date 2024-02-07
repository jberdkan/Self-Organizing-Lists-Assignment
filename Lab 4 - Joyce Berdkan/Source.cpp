#include <iostream>
#include <string>
#include <fstream>
#include "CountList.h"
#include "MTFList.h"
#include "TransposeList.h"

using namespace std;
int main()
{
	cout << "Test 1: Character Types: " << endl << endl;
	CountList<char> c;
	c.add('A');
	c.add('B');
	c.add('C');
	c.add('D');
	c.add('E');
	c.add('F');
	c.add('G');
	c.add('H');

	c.find('F');
	c.find('D');
	c.find('F');
	c.find('G');
	c.find('E');
	c.find('G');
	c.find('F');
	c.find('A');
	c.find('D');
	c.find('F');
	c.find('G');
	c.find('E');
	c.find('H');
	c.find('I');

	//cout << "CountSelfOrderedList compares: " << endl << c.getCompares() << endl;
	c.printlist();

	MTFList<char> mtf;
	mtf.add('A');
	mtf.add('B');
	mtf.add('C');
	mtf.add('D');
	mtf.add('E');
	mtf.add('F');
	mtf.add('G');
	mtf.add('H');


	mtf.find('F');
	mtf.find('D');
	mtf.find('F');
	mtf.find('G');
	mtf.find('E');
	mtf.find('G');
	mtf.find('F');
	mtf.find('A');
	mtf.find('D');
	mtf.find('F');
	mtf.find('G');
	mtf.find('E');
	mtf.find('H');
	mtf.find('I');

	//cout << "Move-to-front compares: " << endl  << mtf.getCompares() << endl;
	mtf.printlist();

	TransposeList<char> t;
	t.add('A');
	t.add('B');
	t.add('C');
	t.add('D');
	t.add('E');
	t.add('F');
	t.add('G');
	t.add('H');


	t.find('F');
	t.find('D');
	t.find('F');
	t.find('G');
	t.find('E');
	t.find('G');
	t.find('F');
	t.find('A');
	t.find('D');
	t.find('F');
	t.find('G');
	t.find('E');
	t.find('H');
	t.find('I');

	//cout << "TransposeSelfOrderedList compares: "<< endl  << t.getCompares() << endl;
	t.printlist();


	cout << endl;
	cout << "Test 2: String Types:" << endl << endl;
	fstream input;
	input.open("test.txt");

	CountList<string>countstring;
	MTFList<string>mtfstring;
	TransposeList<string>transposestring;

	string word;

	while (input >> word)
	{
		countstring.find(word);
		mtfstring.find(word);
		transposestring.find(word);
	}

	countstring.printlist(10);
	cout << endl;

	mtfstring.printlist(10);
	cout << endl;

	transposestring.printlist(10);
	cout << endl;
	
	input.close();
	system("pause");

	return 0;
}