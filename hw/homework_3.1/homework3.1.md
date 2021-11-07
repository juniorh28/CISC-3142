3.1 Evaluating performance of STL containers (4-pt)

Conduct an evaluation of the performance of STL containers (vector, list, set, unordered_set) in inserting and finding elements, with a relatively large data set. What you'll be measuring is the execution time. Obviously it's dependent on the speed of the computer one uses, so what matters is the relative speed (relative to the vector's speed in percentage)

1. create a vector of 100,000 elements of integers, with the values initially set as 1~100,000, in this order.
2. randomize the ordering of these values so they are shuffled
3. measure the time of inserting all elements of this vector into another empty vector, list, set, and unordered_set, at the end of the container
   1. that is, the time of populating 100K numbers in the 4 containers, respectively (4 resultant time durations)
   2. you can write a universal function that does inserting at the iterator position returned by c.end(), where c is the container in question
4. do the same for the 4 containers (also from the empty state), but inserting elements at the beginning of the container (inserting at .begin())
5. with all containers properly populated, measure the time to find each value of (1~10,000, that's 10K) in vector, list, set, and unordered_set
    1. that is, the time of finding all 10K numbers in the 4 containers, respectively (4 resultant time durations)
    2. for vector/list, use the std::find() algorithm;  for set/unordered_set, use the member function .find()
6. when reporting your results, please also output the percentage relative to data for the vector
7. try to explain what you have found out, in a separate document (TXT or PDF)