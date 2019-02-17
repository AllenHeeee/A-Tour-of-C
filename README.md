# A-Tour-of-C
Rutgers-CS214-Assignment0
The main data studcture in this program is Linked List,
Each node includes a single word, the length of the word and next node.
Part 1: I extract letters from the input string. 
I use a pointer to go through the input string.
When the pointer meets the letter characters, I record the letter into a extra char array.
when the pointer meets the non-letter characters, I put the char array into the linked lisk as an single word.
When the input string starts with the non-letter characters, the pointer will go to next character.
When the input string does not end with the non-letter characters, the char array will be put into the linked list, if there is letters in the single word.
Part 2: I sort the node when I insert them into the main linked list.
I write two methods named comTo and search to get the correct location of the new node in the Linked List, and insert the node.
Finally, print out the whole linked list.
