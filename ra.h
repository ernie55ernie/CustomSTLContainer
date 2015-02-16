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


};

// ***** Implementations of non-inline functions *****

// Contruct an array of te specified range
// with each element having the specified initial value.
template <class T, class A>
RangeArray<T, A>::RangeArray(int low, int high, const T &t){
}

// Construct zero-based array num elements
// with the value t. This constructor is required
// for STL compatiblilty.
template <class T, class A>
RangeArray<T, A>::RangeArray(int num, const T &t){
}

// Construct zero-based array from range of iterators.
// This constructor is required for STF compatibility.
template <class T, class A>
RangeArray<T, A>::RangeArray(iterator start, iterator stop){
}

// Copy constructor.
template <class T, class A>
RangeArray<T, A>::RangeArray(const RangeArray<T, A> &o){
}

// Destructor.
template <class T, class A>
RangeArray<T, A>::~RangeArray(){
}