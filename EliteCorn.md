# Elite Corteva Corn Plants

A new research project has started that examines the relative heights of corn plants in a field and then calculates the most **Elite** plant in that field.

The corn has been planted in a grid and a drone was flown over to measure the height of each plant. The height of each corn plant has been recorded as an integer from 0-9 with 0 being the shortest plant and 9 representing the tallest plant.
[Small Example]
41484
36623
76443
44650
46401

Ultimately we want to find the most **Elite** plant which will be defined later. To begin with we need to look at how many plants are visible from outside the field.

You must first figure out which corn plants are visible when looking from the edge of the field, looking directly along a column or row.

A plant is only visible if all the other corn plants from the edge of the field up to that plant are shorter than it is. You need only to worry about plants that are in the same column or row.

By default all plants on the outer edge of the field are visible because there are no other plants to block their view. That gives 16 visible plants to start with.

**Next we'll look at the interior plants:**
First Interior Row, moving from left to right:
- The 6 on the left is visible because you could see it from the top or the left side.
- The next 6 is visible because you could see it from the top or the right side.

Second Interior Row, moving left to right:
- The 6 is visible because you can see it from the right side.
- The last 4 is visible because it can be seen from right.

Third Interior Row, moving from left to right:
- The 6 is visible because it can be seen from the left, right and bottom.
- The 5 is visible because it can be seen from the right and bottom.

All other interior plants are blocked and can't be seen.

In the end we have 6 plants on the interior that can be seen and the 16 plants on the edge of the field which totals to 22 visible plants.

**Write code that reads in the provided input.txt file (containing the grid of plant height values) and outputs the number of corn plants visible from outside the field.**

## Finding the Most Elite Corn Plant 

Now that we know which corn plants can be seen from outside the field, we can turn our attention to finding the most **Elite** plant in the field.

Secret research has revealed that the most **Elite** plant in a given field is the plant that has the most **Field Visibility** which is described below.

Given each plant in the field, first cacluate how far it can **see** in each direction. Calculate a **seeing distance** value by looking right, left, up and down from each plant and stopping when you reach the edge of the field or encountering a plant that is the same height or taller than the plant you are testing for. All the plants on the edge of the field will have at least one of their **seeing distance** values be 0.

Using the same example as before, let's look at the middle 6 in the 2nd row.

41484
36623
76443
44650
46401

- Looking Right from the plant, it can see 2 other plants and then hits the field boundary
- Looking Left from the plant, it can only see 1 other plants because it immediately encounters a plant of equal height
- Looking Up from that plant it can see 1 other plant before hitting the field boundary
- Looking Down from the plant, it can see 2 other plants and is then blocked by a plant of equal height

Finally we take the **seeing distance** for each of the 4 directions and multiply them together to obtain the **Elite Score** for the plant.

**Elite Score** = 2 * 1 * 1 * 2 = 4

Not bad but there should be a better plant in the field. Let's now look at the plant with height 6 in the 4th row:

41484
36623
76443
44650
46401

- Looking Right, it can see 2 plants and then the field boundary
- Looking Left, it can see 2 plants before the edge
- Looking Up, it can see 2 plants before being blocked by a plant of equal height
- Looking Down, it can see 1 plant and then hits the edge of the field

Elite Score = 2 * 2 * 2 * 1  = 8

This turns out to be the plant with the greatest **Elite Score** in the field.

Given the same input.txt file from before, find the largest **Elite Score** for any corn plant in the field.
