Summer 2022: CS 433/533-OV Operating Systems
				HW 1

A cli tool is created to get the count of words supplied
as command line arguments during the time of execution,
which then uses these words and creates a table for
further usage. As the input text is given through the
standard input, the tool parses the supplies text and
tokenizes it using string function of C standard library.
Then the tokenized words of a line with space as delimiter,
will be compared with the words supplied as command line
arguments.

Then, if an input word match with the word list in our
table, the count gets incremented and the loop goes on
until it reaches the EOF.

3 functions deals with the table.
- init_table
- update_table
- display_table

init_table
---
	It deals with initalizing of a table, which is
basically and array of entries, where each entry
consists of two fields:
	- keyword (string)
	- count (int)
After initzlizing the table, this function returns
the table to its calling segment.

update_table
---
	This method updates the table by taking the keyword
and word_count of the table and updates the count field
of a keyword on its appearance in a given input line.

display_table
---
	This method basically displays the table on its call.

# How to run the code?
===

To run the code after unzipping the compressed file.
1. Compile the code
2. Run the code with proper keywords and input stream

# Compilation of code
===
$ gcc -g -O0 -Wall main.c

> Then you will get an `a.out` file

# Running the code
===

+ Case 1
---
$ ./a.out [keywords to search]
{- Then give input and press Control-D in the END -}
Example:
	$ ./a.out an and or to
	This is some sample text. You have to find out how many times certain keyword
	s appear.
	It is possible that some words may not appear at all while some words might a
	ppear multiple times.
	There could be newlines and white spaces and long lines. You should keep acce
	pting the text until the end of file character is found. You can use the exam
	ple program getline.c to figure out how to read line by line until there are
	no more characters in the input stream.
	^D
	Here is the number of times each keyword appears:
	an: 0
	and: 2
	or: 0
	to: 3

+ Case 2
---
$ ./a.out [keywords to search] < [input file]

Example:
	$ ./a.out it was < tale.txt 
	Here is the number of times each keyword appears:
	it: 2003
	was: 1763
