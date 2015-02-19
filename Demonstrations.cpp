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

int main(){
	RangeArray<int> ob(-5, 5 ,0);
	RangeArray<int>::iterator p;

	p = ob.insert(&ob[5] ,1);

	cout << ob.size() << endl;

	ob.erase(p);

	cout << ob.size() << endl;

	system("pause");
	return 0;
}