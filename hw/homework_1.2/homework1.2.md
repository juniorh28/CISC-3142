1.2 Finding non-trivial divisors for a sequence of integers from a file, writing results to another file (4-pt)
Write a C++ program to do the following:

    Read from a text file "input.txt", which has one integer on each line and should assume the values as given in the example below
    For each integer, produce all of its divisors other than 1 and itself (they are called non-trivial divisors), separated by a comma.
        If it's prime number, produce the word "None"
        In the example code on lecture notes, we enumerated all possible values less than the number itself
        But you only need to reach sqrt(num) to find all factors and you should take this approach in this assignment
        Save the other factors (>sqrt(num)) in an array
        Write a reverseArray() function to reverse the array so factors are in ascending order
            Write a swapInt(int& i1, int& i2) function, which is called by reverseArray()
    Output all factors into a separate file, "output.txt", in a format as shown in the example below

Example
Given the file input.txt

36
48
13
49
27

The output.txt file should look like the following:

36 : 2, 3, 4, 6, 9, 12, 18
48 : 2, 3, 4, 6, 8, 12, 16, 24
13 : None
49 : 7
27 : 3, 9