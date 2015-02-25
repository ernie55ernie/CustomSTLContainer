# CustomSTLContainer
<ol>
  <li>Try to enhance and experiment with RangeArray class. For example, add reverse iterators, rbegin(), and rend() functions.</li>
  <li>Try to optimize the container. For example, try allocating a little more memory than needed when constructing objects so that no all insert operations force a re-allocation.</li>
  <li>Try adding a constructor that takes a standard array and an index as the location of zero.</li>
  <li>Try using a vector, rather than a standard array, to hold the elements of the RangeArray.</li>
</ol>
#Custom Container Requirements
<h1>General Requirements</h1>
<ol>
	<li>The container must use the allocator's member functions to allocate and release memory. The allocator is specified as a parameter when a container is created.</li>
	<li>Every container must provide these type:	iterator 	const_iterator	reference	 const_reference	value_type	size_type	difference_tyoe</li>
	<li>A reversible container (one that supports bidirectional iterators) must also apply these types:	reverse_iterator	const_reverse_iterator</li>
	<li>All containers must provide a default constructor, which creates a zero-length container, and a copy constructor. Various parameterized constructors are also needed, the precise form of which differs between sequence and associative containers. A destructor is also required.</li>
	<li>The following operators must be supported by all containers:	=	==	!=	&lt;	&lt;=	&gt;	&gt;=</li>
	<li>The following member functions must be supported:	begin()	clear()	empty()	end()	erase()	insert()	max_size()	rbegin()	rend()	swap()	size()</li>
</ol>
<h1>Additional Sequence Container Requirements</h1>
<ol>
	<li>In additional to a default constructor and a copy constructor, a sequence container must supply a constructor that creates and initializes a specified number of elements. It must also provide a constructor that creates and initialized an object given a range of elements:
		<p>Cnt()</p>
		<p>Cnt(c)</p>
		<p>Cnt(num, val)</p>
		<p>Cnt(start, end)</p>
	</li>
	<li>Standard C++ defines the following optional member functions for sequence containers:	at()	back()	front()	pop_back()	pop_front()	push_back()	push_front()<p>The subscript operator [] is also optional.</p></li>
</ol>
<h1>Associative Container Requirements</h1>
<ol>
	<li>All associative containers must define these additional types:	key_compare	key_type	value_compare</li>
	<li>Along with a default constructor and a copy constructor, an associative container must supply constructors that allow you to specified a comparsion function. You must also define a constructor that creates and initialized an objects given a range of elements/ One version of this constructor must use the default comparsion function. Another must allow the user to specify the comparsion function:	Cnt()	Cnt(c)	Cnt(comp)	Cnt(start, end)	Cnt(start, end, comp)</li>
	<li>Associative containers must provide these additional member function:	count()	equal_range()	find()	key_comp()	lower_bound()	upper_bound()	value_bound()</li>
	<li></li>
</ol>