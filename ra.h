// A custom container that implements a 
// range-selectable array.
//
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

using namespace std;

// An exception class for RangeArray.
class RAExc{
	string err;
public:

	RAExc(string e){
		err = e;
	}

	string geterr(){return err;}
};

// A range-selectable array container.
template<class T, class Allocator = allocator<T> >
class RangeArray{
	T *arrayptr;	// pointer to array that underlies the conatiner

	unsigned len;	// holds length of the container
	int upperbound;	// lower bound
	int lowerbound;	// upper bound

	Allocator a;	// allocator
public:
	// Required typedefs for container.
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::size_type size_type;
	typedef typename Allocator::difference_type difference_type;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;

	// Forward iterators.
	typedef T * iterator;
	typedef const T * const_iterator;

	// Note: This container does not support reverse
	// iterators, but you can add them if you like.

	// ***** Constructors and Destructor /////

	// Default constructor.
	RangeArray(){
		upperbound = lowerbound = 0;
		len = 0;
		arrayptr = a.allocate(0);
	}

	// Construct an array of the specified range
	// with each element having the specified initial value.
	RangeArray(int low, int high, const T &t);

	// Construct zero-based array of num elements
	// with the value t. This constructor is required
	// for STL compatibility.
	RangeArray(int num, const T &t = T());

	// Construct from range of iterators.
	RangeArray(iterator start, iterator stop);

	// Copy constructor.
	RangeArray(const RangeArray &o);

	// Destructor.
	~RangeArray();

	// ***** Operator Functions *****

	// Return trference to specified element.
	T &operator[](int i){
		return arrayptr[i - lowerbound];
	}

	// Return const reference to specified element.
	const T &operator[](int i)const{
		return arrayptr[i - lowerbound];
	}

	// Assign one container to another.
	RangeArray &operator=(const RangeArray &o);

	// ***** Insert Functions *****

	// Insert val at p.
	iterator insert(iterator p, const T &val);

	// Insert num copies of val at p.
	void insert(iterator p, int num, const T &val){
		for(;num > 0; num--)p = insert(p, val) + 1;
	}

	// Insert range specified by start and stop p.
	void insert(iterator p, iterator start, iterator end){
		while(start != stop){
			p = insert(p, *start) + 1;
			start++;
		}
	}

	// ***** Erase Functions *****

	// Return const iterator to first element.
	const_iterator begin() const{
		return &arrayptr[0];
	}

	// Return const iterator to last element.
	const_iterator end() const{
		return &arrayptr[upperbound - lowerbound];
	}

	//Return the size of the container.
	size_type size() const{
		return end() - begin();
	}
};

// ***** Implementations of non-inline functions *****

// Contruct an array of te specified range
// with each element having the specified initial value.
template <class T, class A>
RangeArray<T, A>::RangeArray(int low, int high, const T &t){
	if(high <= low) throw RAExc("Invalid Range");

	high++;

	// Save endpoint.
	upperbound = high;
	lowerbound = low;

	// Allocate memory for the container.
	arrayptr = a.allocate(high - low);

	// Save the length of the container.
	len = high - low;

	// Construct the elements.
	for(size_type i = 0; i < size(); i++)
		a.construct(&arrayptr[i], t);
}

// Construct zero-based array num elements
// with the value t. This constructor is required
// for STL compatiblilty.
template <class T, class A>
RangeArray<T, A>::RangeArray(int num, const T &t){

	// Save endpoints.
	upperbound = num;
	lowerbound = 0;

	// Allocate memory for the container.
	arrayptr = a.allocate(num);

	// Save the length of the container.
	len = num;

	// Construct the elements.
	for(size_type i = 0; i < size(); i++)
		a.construct(&arrayptr[i], t);
}

// Construct zero-based array from range of iterators.
// This constructor is required for STF compatibility.
template <class T, class A>
RangeArray<T, A>::RangeArray(iterator start, iterator stop){
	// Allocate sufficient memory.
	arrayptr = a.allocate(stop - start);

	upperbound = stop - start;
	lowerbound = 0;

	len = stop - start;

	// Construct the elements using those
	// specified by the range of iterators.
	for(size_type i = 0; i < size(); i++)
		a.construct(&arrayptr[i], *start++);
}

// Copy constructor.
template <class T, class A>
RangeArray<T, A>::RangeArray(const RangeArray<T, A> &o){
	// Allocate memory for the copy.
	arrayptr = a.allocate(o.size());

	upperbound = o.upperbound;
	lowerbound = o.lowerbound;
	len = o.len;

	// Make the copy.
	for(size_type i = 0; i < size(); i++)
		a.construct(&arrayptr[i], o.arrayptr[i]);
}

// Destructor.
template <class T, class A>
RangeArray<T, A>::~RangeArray(){
	// Call destructors for elements in the container.
	for(size_type i = 0; i < size(); i++)
		a.destroy(&arrayptr[i]);

	// Release memory.
	a.deallocate(arrayptr, size());
}

// Assign one container to another.
template <class T, class A> RangeArray<T, A>&
	RangeArray<T, A>::operator=(const RangeArray<T, A> &o){
	// Call destructor for elements in target container.
	for(size_type i = 0; i < size(); i++)
		a.destroy(&arrayptr[i]);

	// Release original memory.
	a.deallocate(arrayptr, size());

	// Allocate memory for new size.
	arrayptr = a.allocate(o.size());

	upperbound = o.upperbound;
	lowerbound = o.lowerbound;
	len = o.len;

	// Make copy.
	for(size_type i = 0; i < size(); i++)
		arrayptr[i] = o.arrayptr[i];

	return *this;
}

// Insert val at p.
template<class T, class A>
typename RangeArray<T, A>::iterator
	RangeArray<T, A>::insert(iterator p, const T &val){
	iterator q;
	size_type i, j;

	// Get sufficient memory.
	T* tmp = a.allocate(size() + 1);

	// Copy existing elements to new array,
	// inserting new element if possible.
	for(i = j = 0; i < size(); i++, j++){
		if(&arrayptr[i] == p){
			tmp[i] = val;
			q = &tmp[j];
			j++;
		}
		tmp[j] = arrayptr[i];
	}

	// Otherwise, the new element goes on end.
	if(p == end()){
		tmp[j] = val;
		q = &tmp[j];
	}

	// Adjust len and bounds.
	len++;
	if(p < &arrayptr[abs(lowerbound)])
		lowerbound--;
	else
		upperbound++;
	
	// Call destructors for elements in old container.
	for(size_type i = 0; i < size() - 1; i++)
		a.destroy(&arrayptr[i]);

	// Release memory for old container.
	a.deallocate(arrayptr, size() - 1);

	arrayptr = tmp;

	return q;
}