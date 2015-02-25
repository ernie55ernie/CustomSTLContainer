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
	<li></li>
</ol>
<h1>Additional Sequence Container Requirements</h1>
<ol>
	<li></li>
</ol>
<h1>Associative Container Requirements</h1>
<ol>
	<li></li>
</ol>