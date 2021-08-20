**Part 1**
An Implementation of a `hash table` that stores words (strings).

Hash Table Dictionary

A hash table class called `HashTable` to store standard strings composed of lower-case letters. 
Collisions are handled using double hashing.



**Part 2**

    Each function in `spellcheck.h` checks to see if its input string is in a given dictionary and, 
    if not, returns an ordered list of words in the dictionary that is similar to its input, as determined by the function's process. 

There are three possible return values for each of the functions.

    success - if word parameter is in dict the result should contain word, and no other strings.

    near-miss - if word is not in dict but dict contains strings similar to word, as determined by the function. the 
                    result should contain these near-misses in order.

    failure - if word is not in dict and dict contains no strings similar to word, as determined by the function, the
                result should be empty.

Functions

    extraLetter - if word is not in dict returns all strings in dict that can be made by deleting a single letter from word

    transposition - if word is not in dict returns all strings in dict that can be made swapping any two adjacent letters in word

    missingSpace - if word is not in dict returns all pairs of strings in dict that can be made by inserting a single space in word; each string in the result should consist of the two strings from dict separated by a space

    missingLetter - if word is not in dict returns all strings in dict that can be made by inserting any single letter of the alphabet at any position in word

    incorrectLetter - if word is not in dict returns all strings in dict  that can be made by changing any single letter of word to a different letter in the alphabet

Examples

`extraLetter` - input: chate, output: {chat, hate} - not hat or cat as they have two fewer letters

`transposition` - input: atr, output: {tar, art} - not rat as that requires swapping more than two adjacent letters

`missingSpace` - input: rateat, output: {rat eat, rate at}

`missingLetter` - input: poe, output: {poet, poke, pole, pope, pose} - not poetry as it has more than one missing 
                    letter

`incorrectLetter` - input: thed, output: {shed, thee, them, they, thud, toed} - not shad or thus as they have two 
                    incorrect letters