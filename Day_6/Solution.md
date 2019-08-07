# 题解

## 直角三角形

We need to find an algorithm of complexity better than O(N3). Here we will describe three such algorithms.

The basic idea of the first one is: choose the point in which the angle will be right, fix one other point in the triangle and quickly calculate how many of the remaining points form a right triangle with the first two points. The algorithm is based on the so-called canonical representation of a line. Each line can be, regardless of which two points it is generated from, transformed into a unique form. For a pair of points we use the usual formulas to calculate three integers A, B and C such that Ax + By + C = 0.The equation can be multiplied by a constant, because this doesn't change the line it represents. Now divide A, B and C by their greatest common divisor so that they become relatively prime, and also negate the entire equation if the first non-zero number is negative. With this we can build a function/map f(line), which tells us how many points are on a line. Now it is easy to implement the idea from the start of this paragraph, and using appropriate data structures, the complexity will be good.

The second algorithm, after choosing the first point (where the right angle will be), sorts the remaining points around it by angle. Now we can use two variables (the so-called "sweep" method) to count all right triangles. We move the first variable point by point, and have the second one 90 degrees ahead of it, moving forward, trying to form right triangles with the first variable.

The third algorithm is different from the first two, but also easier to implement. Choose a point P and translate the coordinate plane so that the point P is the origin (more precisely, subtract the coordinates
of point P from every point). Now, for each point, first determine which quadrant it is in, and then rotate it by 90 degrees until it is in the first quadrant. After that, sort all points by angle (y divided by x).Two points form a right triangle with point P if they have the same angle and if they were in neighbouring quadrants before rotating. After sorting, for each set of points with the same angle, count how many of them were in each of the four quadrants and multiply the numbers for neighbouring quadrants.

The complexity of all three algorithms is O(N2·logN). The official source code features the lastalgorithm.

## 排序
When the number of elements N is small, it's possible to simulate the algorithm swap by swap. The complexity of this algorithm is O(N2), and it will surely work for N up to 5000, and the problem statement guarantees that in most of the test cases it will be at most 100.

For longer arrays we need an algorithm more efficient than simulation. Suppose in some phase the number X is to be moved to its final position. The number of swaps in that phase is the difference
between the current and final positions of X. The final position is known, it is exactly X, but the current position isn't.

The current position of X can be calculated from its starting position, provided sufficient information about numbers moved in previous phases. More precisely, each number moved in an odd phase (when
numbers are moved to the left) that was initially to the right of X "jumped over" X during its phase and because of this X moved one place to the right. Similarly, each number moved in an even phase that
was initially to the left of X will move X one place to the left.

These two numbers (how much X has moved left and right) can be efficiently calculated (in logarithmic complexity) using two Fenwick trees; one for odd phases and one for even phases. There is also a
similar solution which uses only one Fenwick tree. Such a solution is implemented in the official source code.

Whenever a task includes smaller and larger constraints with algorithms of vastly different implementation complexity to solve them, it is a good idea to include both algorithms in the source code, and determine which one to use at runtime, depending on N. That way, if there is an error in the more complex algorithm, we don't lose points on the smaller test cases.

## 自行车赛
First we observe that any path ending in city 1 has a corresponding path starting in city 1. It is sufficient to reverse the sequence of roads forming the path. To simplify things, we will be trying to find the longest path starting in city 1.

If we observe the given network we can see that, speaking in graph teory terms, each road is either a part of a single ring, or a bridge.

In order to solve the problem, we must first identify rings and bridges. One of the ways of doing this is by constructing a DFS tree from node 1 and calculating all standard values( discovery time, finish time, lowlink value). Details can be found in the source code.

For a given ring we say that it "hangs" from node X if node X is the highest node in the DFS tree in that ring. For a given bridge we say that it "hangs" from node X if node X is the higher node in the DFS tree.

For each node X we define a subgraph of node X as the union of node X and all subgraphs of all nodes lying in rings "hanging" from X and all subgraphs of all nodes on other side of bridges "hanging" from X.

For each node X we need to find two numbers, circle(X) - path inside subgraph of node X starting and ending in X, and path(x) - path inside subgraph of X starting in X and ending in any node.

circle(X) can be calculated by simple recursion as sum of lengths of all rings "hanging" from X and sum of all circle(Y) for each node Y lying on those rings (because we can take the circle on any node Y and end up back at Y).

When calculating path(X) we need to take into account the following possible scenarios, selecting the one that yields the longest path::

* The path from X ends in X. This leads to path(X) = circle(X).
* We can first make a circle in subgraph of X, and than take one bridge "hanging" from X into a new subgraph giving: path(X) = circle(X) + path(Y) where Y is the node on the other side of the bridge.
* We can make a circle in all rings "hanging" from X except one and than select one city in that ring as the ending. In that case there are two possible ways to arrive to the selected city so we need to find the longer.

The solution is then path(1). Details on how to implement this can be found in the source code.
