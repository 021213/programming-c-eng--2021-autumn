/*
1). Create four classes:
	a). Abstract List class;
	b). Inherited ArrayList class;
	c). Inherited LinkedList class;
	d1*). Deck class
	d2*). Queue class
	d3*). Stack class

2). Create a program:
	a). Read an integer array from a *.txt file into an LinkedList.
		(the path of the file is passed as a parameter of the
		main function, the default name is "in.txt").
		main(int argc, char* argv[]);
	b). Convert the LinkedList into an ArrayList using proper friend function.
		(the function shouldn't use any public methods of the classes)
	c). Sort the ArrayList using some n*log(n) algorithm. (not the sort() from the algorithm library).
	d). Save the list into 2 files:
		(the path of the folder to witch your files should be saved is
		passed as a parameter of the main function as well,
		the default folder is the same where *.exe is located):
		a). sorted.txt
		b). sorted.bin
		
3). Your code should contain exceptions, the words public, private, protected*, static*.
	The program itself should contain not only main function. There should be several function.

	myprogram.exe D:\in.txt D:\SortedFile\ ->
	read from D:\in.txt, write to D:\SortedFile\sorted.txt and D:\SortedFile\sorted.bin
	myprogram.exe ->
	read from in.txt, write to sorted.txt and sorted.bin
*/