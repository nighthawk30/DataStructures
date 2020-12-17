Nathan Taylor 9/4
I am comfortable sharing my images and identity
While not super interesting to look at, this program generates a bunch of rectangles recursively by
randomly splitting rectangles into smaller rectangles. It colors the rectangles based on how close each
rectangle is to being a square. The more square like the rectangle is, the warmer the color is.
The color warmth was the most complicated thing to do.

What I first did was graph the rgb values for each of the 12 main colors. I wanted to fit a function to the
graphs for each of the data sets so that I could plug in values and get out a proper color warmth for 0-11.
First I tried polynomials, but they turned out to be too tedious to work with. Then I tried sinusoidal functions,
but they didn't fit the curve. What I ended up using was a sigmoid function, the kind used in neural networks to
scale values passed between nodes. It takes any number and scales it to a range from 0 to 1. Its curve fit the data
really well. I used desmos to modify the sigmoid so that it fit the range and shift of each data set for rgb color
warmth. What I ended up with was three piecewise functions in 3 repeating phases. I quickly realized that 10 and 11,
magenta and pink, didn't fit what I was trying to do. The rest was just implementation. I also reduced the minimum
rectangle area.
