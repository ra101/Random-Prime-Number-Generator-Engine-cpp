This is a functor, which takes a random engine (like std::default_random_engine) as template input.<br>
it has a non-parameterized as well as parameterized (which take seed as input) consturctor.<br>
furture it can also return its state to be sotred or intitalise with state from std::stringstream<br><br>
<br>
working -<br>
primeDB named file as 9999 prime no., this functor chooses value from those no. using eng()%primeDBsize, where eng is template input random engine functor
