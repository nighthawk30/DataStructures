Nathan Taylor

Understanding the task was the first challenge. Once I got that, the character model was pretty straightforward.
For the word model, I didn't understand at first that we were supposed to be able to use k letters of words as our map
key. I was trying to break the text down into individual words and remove all the punctuation and capitalization. I
asked about it on piazza and then when I found out that we were supposed to a word version of part 1, it made a lot more
sense. I used a stringstream to get all of the words from the text into a vector and then used the exact same algorithm
for words that I had used for characters, but instead I was managing vectors instead of strings. I had to write my own
subvector function to parallel the substr that I used for the first part. It worked, but it took over an hour to init
the gibbon.txt. The first thing I did was convert the stringstream part into a manual for loop. That didn't make it
faster. I found that the reading into the vector was not taking the most time though. It was the subvector function.
I eventually realized that I was passing the text vector in by value and so it was copying the whole 265000 long
vector every time. Switching it to pass by reference fixed the problem.

This was a cool project. I had heard about markov chains in linear algebra but didn't get to cover them. I really liked
how the project gave examples at the bottom of the kind of shenanigans that it had been used for.

Time: 8 hours