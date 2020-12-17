PART 1/2:
Nathan Taylor 8/29/2020
Challenges:
I would say that the project is broken into 4 parts. The first part was parsing the data. I used a lot of the things from
lab to do it. It mentioned that you could either dynamically alot space in the 2d vector or do it all at once with the file size upfront.
I read in the first 2 lines, but then realized it was useless information and used the getline to skip it. Then I would read in each line
and break it into data points using the string stream. Once the string stream ended, I would go to the next line in the file. Worked like
a charm. Though I definitely encountered bugs, it was mostly just forgetting things.

The second part was drawing the vector into an image. It was actually pretty simple from following the directions. I just had to change
the initial values and work with floats to get the proper outcome.

The third part took a while. At first, it was a little hard to understand the goal. I have written my fair share of recursive
functions before, I just wasn't sure where to start. Once I realized you were trying to get from somewhere on the left edge to
somewhere on the right edge, it made a bit more sense. I made a 2d vector after the table in the directions. I knew then that I
needed a recursive algorithm to apply at each point on the left edge of the image. Setting up the function was pretty simple, but I
confused myself a bunch of times with rows and columns, versus x and y. It took a while before I realized that each row down was a positive
y and each column right was a positive x, not the other way around.

And then I thought I was done. Yay!. My program successfully made cool images and found paths through smaller images, the runtime was too
long for any of the real images. Then I looked through the directions and it said to test every example for edge cases. When I first saw
the image my program made for the hd Mt. Kilimanjaro (which I have now spelled many many many times in testing), it was a 1 pixel high line.
I was very confused. Then I looked at the text file, and it took me a while to realize that those arrows on the left and right meant that
the file was literally 1 line of text. Theres over 10000 numbers in 1 line of text, wtf. I had to rewrite my entire read in code like 5 times.
First I had to actually use the rows and columns given at the top of the file. Then I had to reformat my sytem so it could write the array
itself without needing to go to the top of the loop for a new getline. It ended up being a bit simpler than the original one, but it took
as long as the rest of the project.

Like/Dislike: I really like how the lab tied into the project. I would not have been able to do the project with out it. Also,
the images were awesome. Totally did not expect the fractal patterns.

Time: 7 hours

PART 2/2:
Nathan Taylor 9/12/2020
Collaborations:
I needed a way for the method that finds the lowest cost path to output both the cost of the path chosen and the direction
it used. I eventually decided to pass an array, but I couldn't remember how to pass it in by reference. I used some of the ideas from
this thread: http://www.cplusplus.com/forum/beginner/30698/ in order to understand how it worked.

Challenges:
I would say that one of the main challenges was figuring out where to start. I read through the description of dynamic programming
and I sort of understood what was going on, but I hadn't read to deeply into the implementation. I actually ended up just using the
description of the algorithm with the diagrams, it was a lot easier to understand than the directions at the time. The first thing
I implemented was setting the right side of the cost table to 0. Then I literally just added a second for loop to set the column just
to the right of the last column, very similar to what is shown in the algorithm. In order to choose the lowest cost option, I ended up
hijacking the code from the initial recursion part and modifying it to find the cost. It was giving me a lot of seg faults
and I actually used the debugger in order to find that I had forgotten that to go "up" in the table, you have to subtract.
It was still giving weird values, before I realized that it was just finding the elevation change between the points. I had forgotten
to add on the cost from the location it chose.

Another tricky part was figuring out how to do the direction table. I realized it would be super easy to just combine it with my cost
method because that already had to find the lowest cost path, and therefore the direction it came from. The way I decided to implement it
was to put the three potential paths into an array. When I found the lowest cost path, I also subtracted 1 from the index that I found it
to get the direction. 1: northeast, 0:east, -1:southeast. In order to get the information out, because I now needed to get 2 numbers
from the function, I had to do some research on passing in arrays.

Coloring the most optimal paths was easy. I just made a recursive function to take the current position, add to the x
and add the corresponding value from the direction table to the y. Each time it stepped, it changed the color of the
pixel it was on.

Okay, now that I have finished, I ran the program for all the data sets. It took a while for colorado.dat, but eventually
got there. The largest data set, grand canyon hires, ran for 2 hours before clion crashed. I decided to try and make it
more efficient. First I added print out statements to show what completion percent each process was at. The path drawing
was taking the longest of the two. First I tried to create a table to keep track of the spaces that had been colored
and stop the recursion if it had already painted that square. That did not make a significant change. Then I decided to
actually follow the directions for implementation and it said to use a for loop. Tried it, and the drawing part was
wayyyyy faster. That surprised me because I would have though that since they were completing the same task, and keeping
track of the same information, they would take a similar amount of time. This part alone warranted about 3 hours of work.
To be fair, it worked before hand, and I could have stopped, but I decided not too.

Like/Dislike: I would say that this is a pretty good assignment. I like that it has an actual visual output and it gave
a lot of practice with loops and recursion.

Time Spent: 4 hours + 3 to make it run faster because I didn't follow directions