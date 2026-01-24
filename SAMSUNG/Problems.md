# Problem 1: Bipartite Graph Coloring

**Description:**
Given an undirected graph, determine if it is bipartite. If it is bipartite, print one of the two sets of vertices that form the bipartition. If the graph is not bipartite, print "-1". The graph may be disconnected. If the graph is bipartite, there are two valid sets of vertices (color classes); printing either one is acceptable.

**Input Format:**

- The first line contains an integer $T$, the number of test cases.
- For each test case:
  - The first line contains two integers $V$ and $E$, representing the number of vertices and edges, respectively. Vertices are numbered from $1$ to $V$.
  - The next $E$ lines each contain two integers $u$ and $v$, representing an edge between vertex $u$ and vertex $v$.

**Output Format:**

- For each test case, if the graph is not bipartite, print "-1".
- If the graph is bipartite, print the vertices of one of the color sets in increasing order, separated by spaces.

**Constraints:**

- $1 \le T \le 10$
- $1 \le V \le 1000$
- $0 \le E \le V(V-1)/2$
- The graph contains no self-loops or multiple edges between the same pair of vertices.

**Test Cases:**

**Input:**

```
5
4 4
1 2
2 3
3 4
4 1
3 3
1 2
2 3
3 1
5 3
1 2
3 4
4 5
6 5
1 2
3 4
4 5
5 3
3 6
5 4
1 2
1 3
1 4
1 5
```

**Output:**

```
1 3
-1
1 3 5
-1
2 3 4 5
```

**Explanation:**

1. **Case 1 (Cycle C4):** Edges are (1,2), (2,3), (3,4), (4,1). This is a bipartite graph (even cycle). The color sets are {1, 3} and {2, 4}. Printing "1 3" is correct.
2. **Case 2 (Cycle C3):** Edges are (1,2), (2,3), (3,1). This is a triangle (odd cycle). Not bipartite. Output: -1.
3. **Case 3 (Disconnected Forest):**
   - Component 1: Edge (1,2). Colors: {1}, {2}.
   - Component 2: Path 3-4-5. Colors: {3, 5}, {4}.
   - Combined Set 1: {1, 3, 5}. Combined Set 2: {2, 4}. Output "1 3 5" is valid.
4. **Case 4 (Disconnected with Odd Cycle):**
   - Component 1: Edge (1,2). Bipartite.
   - Component 2: Triangle 3-4-5 plus edge (3,6). Edges: (3,4), (4,5), (5,3), (3,6). The cycle 3-4-5-3 is odd. The component is not bipartite.
   - Thus, the entire graph is not bipartite. Output: -1.
5. **Case 5 (Star Graph):** Center 1 connected to leaves 2, 3, 4, 5. Bipartite. Sets are {1} and {2, 3, 4, 5}. Output "2 3 4 5" is valid.

# Problem 2: Balloon Bursting

**Description:**

There are $n$ balloons and $n$ bullets. Each balloon is assigned a particular number of points.
Whenever a particular balloon is shot, the number of points obtained increases by detailed rules:

1. The multiplication of the point assigned to the balloon on the left and that of the right side ($Left \times Right$).
2. The point assigned to the left if no right balloon exists ($Left$).
3. The point assigned to the right if no left balloon exists ($Right$).
4. The point assigned to itself if no other balloon exists ($Self$).

You have to find the sequence of bursting balloons that maximizes the total points obtained. Output this maximum possible score.

**Input Format:**

- The first line contains an integer $T$, the number of test cases.
- Case Format:
  - First line: $N$, number of balloons.
  - Second line: $N$ integers, the points on the balloons.

**Output Format:**

- A single integer representing the maximum points.

**Constraints:**

- $1 \le N \le 500$
- $0 \le Points \le 100$

**Test Cases:**

**Input:**

```
4
1 2 3 4
6
1 0 2 3 0 4
1
5
2
1 5
3
2 3 5
```

**Output:**

```
20
34
5
10
20
```

**Explanation:**

1. **Case 1 (`1 2 3 4`):** Optimal 20.
2. **Case 2 (`1 0 2 3 0 4`):** Optimal 34.
3. **Case 3 (`5`):** Single balloon. Points 5.
4. **Case 4 (`1 5`):** Max 10.
5. **Case 5 (`2 3 5`):** Max 20.

# Problem 3: Catch the Stationary Piece (Knight's Move)

**Description:**
There is a mobile piece and a stationary piece on an $N \times M$ chessboard. You need to capture the stationary piece by moving the mobile piece with the minimum number of moves.
The available moves of the mobile piece are those of a standard Chess Knight: it moves 2 squares in one cardinal direction (horizontal or vertical) and then 1 square perpendicular to that direction.
Formally, from $(r, c)$, valid moves are $(r \pm 2, c \pm 1)$ and $(r \pm 1, c \pm 2)$, provided they are within the board boundaries.
The top-left coordinate is $(1, 1)$.

**Input Format:**

- The first line contains $T$, the number of test cases ($T \le 20$).
- For each test case:
  - First line: Two integers $N$ (rows) and $M$ (columns).
  - Second line: Four integers $R_1, C_1, R_2, C_2$.
    - $(R_1, C_1)$ is the starting location of the mobile piece.
    - $(R_2, C_2)$ is the location of the stationary piece (target).

**Output Format:**

- For each test case, print "Case #T" on the first line.
- On the next line, print the minimum number of moves to catch the piece.
- If it is impossible to reach the target, print "-1".

**Test Cases:**

**Input:**

```
5
9 9
3 5 2 8
20 20
2 3 7 9
5 5
3 3 3 3
3 3
1 1 3 3
2 2
1 1 2 2
```

**Output:**

```
Case #1
2
Case #2
5
Case #3
0
Case #4
4
Case #5
-1
```

**Explanation:**

1. **Case 1:** (3,5) -> (2,8). Path: (3,5) -> (1,6) -> (2,8) is 2 moves.
2. **Case 2:** (2,3) -> (7,9). Distance is 5.
3. **Case 3:** Start equals End. 0 moves.
4. **Case 4:** 3x3 board, (1,1) to (3,3). Path: (1,1) -> (2,3) -> (3,1) -> (1,2) -> (3,3). 4 moves.
5. **Case 5:** 2x2 board, (1,1) to (2,2). No valid moves exist. Result is -1.

# Problem 4: Convex Hull

**Description:**
Given a set of random points in a 2-D plane, construct a convex polygon with the minimum area of covering that encompasses all the given points (Convex Hull). Output the vertices of this polygon.

**Input Format:**

- The first line contains an integer $T$, the number of test cases.
- For each test case:
  - The first line contains an integer $N$, the number of points.
  - The next $N$ lines each contain two integers $X$ and $Y$, the coordinates of the points.

**Output Format:**

- For each test case, print the number of vertices on the convex hull like "Count: K".
- On the next line, print the vertices of the convex hull in counter-clockwise order, starting from the bottom-most-left-most point. Format each vertex as "x y", separated by a space or a comma.
- Do not include collinear points that are not vertices (corners) of the hull.
- If $N < 3$, print "-1".

**Constraints:**

- $1 \le T \le 10$
- $1 \le N \le 100$
- $-1000 \le X, Y \le 1000$

**Test Cases:**

**Input:**

```
3
5
1 1
3 1
3 3
1 3
2 2
3
0 0
2 0
1 1
3
0 0
1 1
2 2
```

**Output:**

```
4
1 1, 3 1, 3 3, 1 3
3
0 0, 2 0, 1 1
2
0 0, 2 2
```

**Explanation:**

1. **Case 1:** Square with center point. 4 vertices.
2. **Case 2:** Triangle. 3 vertices.
3. **Case 3:** Collinear points. 2 vertices (endpoints).

# Problem 5: Crow and Overflowing Pots

**Description:**
There are $N$ pots. Every pot has some water in it and is associated with an overflow number $O_i$, which indicates the minimum number of stones required for that pot to overflow. The crow knows all the overflow numbers $O_1, \dots, O_N$, but does not know which pot corresponds to which number until it overflows. The crow wants to overflow at least $K$ pots.
You need to find the minimum number of stones the crow needs to use to guarantee that $K$ pots overflow in the worst-case scenario.

**Input Format:**

- The first line contains an integer $T$, the number of test cases.
- For each test case:
  - The first line contains $N$ (number of pots).
  - The second line contains $N$ integers representing the overflow numbers of the pots.
  - The third line contains $K$ (number of pots to overflow).

**Output Format:**

- For each test case, print the minimum number of stones required in the worst case.

**Constraints:**

- $1 \le T \le 10$
- $1 \le K \le N \le 1000$
- $1 \le O_i \le 1000$

**Test Cases:**

**Input:**

```
6
2
5 58
1
3
1 2 3
2
3
1 2 3
3
3
5 8 2
2
1
100
1
8
3 3 3 5 12 13 34 42
6
```

**Output:**

```
10
5
6
12
100
65
```

**Explanation:**

1. **Case 1 ($N=2, O=\{5, 58\}, K=1$):** Crow puts 5 stones in first pot. If it overflows (was 5), done (5 stones). If not (was 58), he puts 5 stones in second pot (must be 5). It overflows. Total 10 stones.
2. **Case 2 ($N=3, O=\{1, 2, 3\}, K=2$):** Sorted $O$: 1, 2, 3. Formula: $O_1 + (3-2+1) \times O_2 = 1 + 2 \times 2 = 5$.
3. **Case 3 ($N=3, O=\{1, 2, 3\}, K=3$):** Sorted $O$: 1, 2, 3. Formula: $1 + 2 + (3-3+1) \times 3 = 1 + 2 + 3 = 6$.
4. **Case 4 ($N=3, O=\{5, 8, 2\}, K=2$):** Sorted $O$: 2, 5, 8. Formula: $2 + (3-2+1) \times 5 = 2 + 10 = 12$.
5. **Case 5 ($N=1, O=\{100\}, K=1$):** Just 1 pot. Needs 100 stones.
6. **Case 6 ($N=8, O=\{3, 3, 3, 5, 12, 13, 34, 42, K=6$):** Sorted $O$: 3, 3, 3, 5, 12, 13, 34, 42. Formula: $3 + 3 + 3 + 5 + 12 + (8-6+1) \times 13 = 26 + 3 \times 13 = 26 + 39 = 65$.

# Problem 6: Doctor Probability

**Description:**
A Doctor travels from a division to another division where divisions are connected like a directed graph. The edge weights are the probabilities of the doctor going from that division to the other connected division. The doctor stays 10 mins at each division. Given a time $T$, find the division in which he will be staying by that time. This is determined by finding the division which has the highest probability.
Note: If he reaches a point where there are no further nodes, he leaves the lab after 10 mins.

**Input Format:**

- The first line contains an integer $T_{cases}$, the number of test cases.
- For each test case:
  - The first line contains three integers: $N$ (nodes), $E$ (edges), and $Time$.
  - The next line contains $E$ triples: start node, end node, probability.

**Output Format:**

- For each test case, print the node with the highest probability and the probability value (up to 6 decimal places).

**Test Cases:**

**Input:**

```
2
6 10 40
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
```

**Output:**

```
6 0.774000
3 0.700000
```
