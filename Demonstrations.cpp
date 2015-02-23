// Demonstrate custom STL
#include <iostream>
#include <algorithm>
#include <functional>
#include "ra.h"
using namespace std;

// Display integers -- for use by for_each.
void display(int v){
	cout << v << " ";
}

// Demonstrate basic RangeArray operations.
void basicOperation();

// Demonstrate the relational operators.
void relationalOperator();

int main(){

	//basicOperation();

	relationalOperator();

	system("pause");
	return 0;
}

void basicOperation(){
	RangeArray<int> ob(-5, 5 ,0);
	RangeArray<int>::iterator p;
	int i, sum;

	cout << "Size of ob is: " << ob.size() << endl;

	cout << "Initial contents of ob:\n";
	for(i = -5; i <= 5; i++)cout << ob[i] << " ";
	cout << endl;

	// Give ob some values.
	for(i = -5; i <= 5; i++)ob[i] = i;

	cout << "New values for ob: \n";
	p = ob.begin();
	do{
		cout << *p++ << " ";
	}while(p != ob.end());
	cout << endl;

	// Display sum of negative indexes.
	sum = 0;
	for(i = ob.getlowerbound(); i < 0; i++)
		sum+= ob[i];
	cout << "Sum of values with negative subscripts is: ";
	cout << sum << "\n\n";

	// Use copy() algorithm to copy one object to another.
	cout << "Copy ob to ob2 using copy() algorithm.\n";

	RangeArray<int> ob2(-5, 5, 0);
	copy(ob.begin(), ob.end(), ob2.begin());

	// Use for_each() algorithm to display ob2.
	cout << "Contents of ob2: \n";
	for_each(ob2.begin(), ob2.end(), display);
	cout << "\n\n";

	// Use replace_copy_if() algorithm to remove values less than zero.
	cout << "Replace values less than zero with zero,\n";
	cout << "Put the result into ob3.\n";
	RangeArray<int> ob3(ob.begin(), ob.end());

	// The next line uses the function object less() amd
	// the binder bind2nd().
	replace_copy_if(ob.begin(), ob.end(), ob3.begin(),
		bind2nd(less<int>(), 0), 0);
	cout << "Contents of ob3: \n";
	for_each(ob3.begin(), ob3.end(), display);
	cout << "\n\n";

	cout << "Swap ob and ob3.\n";
	ob.swap(ob3);	// swap ob and ob3
	cout << "Here is ob3:\n";
	for_each(ob3.begin(), ob3.end(), display);
	cout << endl;
	cout << "Swap again to restore.\n";
	ob.swap(ob3);	// restore
	cout << " Here is ob3 after second swap:\n";
	for_each(ob3.begin(), ob3.end(), display);
	cout << "\n\n";

	// Use insert() member function.
	cout << " Element at ob[0] is " << ob[0] << endl;
	cout << "Insert values into ob.\n";
	ob.insert(ob.end(), -9999);
	ob.insert(&ob[1], 99);
	ob.insert(&ob[-3], -99);
	for_each(ob.begin(), ob.end(), display);
	cout << endl;
	cout << "Element at ob[0] is " << ob[0] << "\n\n";

	cout << "Insert -7 three times to front of ob.\n";
	ob.insert(ob.begin(), 3, -7);
	for_each(ob.begin(), ob.end(), display);
	cout << endl;
	cout << "Element at ob[0] is " << ob[0] << "\n\n";

	// Use push_back() and pop_back().
	cout << "Push back the value 40 onto ob.\n";
	ob.push_back(40);
	for_each(ob.begin(), ob.end(), display);
	cout << endl;
	cout << "Pop back two values from ob.\n";
	ob.pop_back();	ob.pop_back();
	for_each(ob.begin(), ob.end(), display);
	cout << "\n\n";

	// Use push_front() and pop_frint()
	cout << "Push front the value 19 onto ob.\n";
	ob.push_front(19);
	for_each(ob.begin(), ob.end(), display);
	cout << endl;
	cout << "Pop front two values from ob.\n";
	ob.pop_front();	ob.pop_front();
	for_each(ob.begin(), ob.end(), display);

	// Use front() and back()
	cout << "ob.front(): " << ob.front() << endl;
	cout << "ob.back(): " << ob.back() << "\n\n";

	// Use erase().
	cout << "Erase element at 0.\n";
	p = ob.erase(&ob[0]);
	for_each(ob.begin(), ob.end(), display);
	cout << endl;
	cout << "Element at ob[0] is " << ob[0] << endl;
	cout << endl;

	cout << "Erase many elements in ob.\n";
	p = ob.erase(&ob[-2], &ob[3]);
	for_each(ob.begin(), ob.end(), display);
	cout << endl;
	cout << "Element at ob[0] is " << ob[0] << endl;
	cout << endl;

	cout << "Insert ob4 into ob.\n";
	RangeArray<int> ob4(0, 2, 0);
	for(i = 0; i < 3; i++)ob4[i] = i + 100;
	ob.insert(&ob[0], ob4.begin(), ob4.end());
	for_each(ob.begin(), ob.end(), display);
	cout << endl;
	cout << "[" << i << "]: " << ob[i] << endl;

	// Use the at() function.
	cout << "Use the at() function.\n";
	for(i = ob.getlowerbound(); i < ob.getupperbound(); i++)
		ob.at(i) = i * 11;

	for(i = ob.getlowerbound(); i < ob.getupperbound(); i++)
		cout << ob.at(i) << " ";
	cout << "\n\n";

	// Use the clear() function.
	cout << "Clear ob.\n";
	ob.clear();
	for_each(ob.begin(), ob.end(),display);	// no effect!
	cout << "Size of ob after clear" << ob.size()
		<< "\nBounds: " << ob.getlowerbound()
		<< " to " << ob.getupperbound() << "\n\n";

	// Create a copy of an object.
	cout << "Make a copy of ob2.\n";
	RangeArray<int> ob5(ob2);
	for_each(ob5.begin(), ob5.end(), display);

	// Construct a new object from a range.
	cout << "Construct object from a range.\n";
	RangeArray<int> ob6(&ob2[-2], ob2.end());
	cout << "Size of ob6: " << ob6.size() << endl;
	for_each(ob6.begin(), ob6.end(), display);
	cout << endl;
}

void relationalOperator(){
	
}