# 3.2 Using algorithms from the standard library (4-pt)
You're given a 1000-line text file, phoneno.txt, where each line consists of a 5-digit ID# and a phone# in the format of ###-###-####. The data were generated randomly so there might be duplicates in the IDs. You're asked to do the following by using standard library algorithms as much as possible:
read the file into a map which has an integer for key (ID#) and a string for value (phone#), this allows the duplicates to be removed. Print the map's size.
print the count of phone numbers with the area code of 347.
print someone's ID, given the person's phone #: 212-536-6331. Note that there might be more than one ID with this phone# (like siblings sharing a home number), and you need to list them all.
create a vector that stores all phone numbers with area code 212, from the map. Print the size of the vector.
create another vector from step 4's result, with all duplicates of 212 numbers removed. Print the size of this vector.
Please produce your program output in the following format:

Size of the map: ???
Count of phone# with area code 347: ???
The ID(s) with the given phone#: ???
Size of the vector with all (212) numbers: ???
Size of the vector with unique (212) numbers: ???