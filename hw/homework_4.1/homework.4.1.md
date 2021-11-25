4.1 Caesar's Cipher (3-pt)

Caesar's cipher is a very simple encrypting scheme where each letter is shifted down by a fixed number from its position in the alphabet. For example, if the given character set is the English alphabet in upper case and the shift number is 3, then each letter in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" from the plain text will be replaced by "DEFGHIJKLMNOPQRSTUVWXYZABC", respectively, in the cipher text.

Now in this exercise, your character set (alphabet) is the concatenation of all uppercase and lowercase letters:
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

You're given two cipher text strings as the following. 

    "uIFzBOLTbSFbMTPlOPXObTuIFcSPOYcPNCFST"
    "dBFTBSdJQIFSfYFSDJTFxJUIdqMVTqMVT"

You're also given the condition that the corresponding plain text of the first cipher text of the above contains the string "Yanks". Write a C++ program to figure out the shift number then decipher and print out the plain text for both, from your program.