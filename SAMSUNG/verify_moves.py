from collections import deque

def solve(N, M, Start, End):
    if Start == End: return 0
    q = deque([(Start, 0)])
    vis = set([Start])
    moves = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
    
    while q:
        (r, c), dist = q.popleft()
        if (r, c) == End:
            return dist
        
        for dr, dc in moves:
            nr, nc = r + dr, c + dc
            if 1 <= nr <= N and 1 <= nc <= M and (nr, nc) not in vis:
                vis.add((nr, nc))
                q.append(((nr, nc), dist + 1))
    return -1

# Edge Cases
print(f"Same Pos: {solve(5, 5, (3,3), (3,3))}")
print(f"3x3 Corner: {solve(3, 3, (1,1), (3,3))}")
print(f"One Move: {solve(5, 5, (1,1), (2,3))}")
print(f"Impossible 2x2: {solve(2, 2, (1,1), (2,2))}")
print(f"Impossible 3x3 Center: {solve(3, 3, (2,2), (1,1))}") # Knight at (2,2) in 3x3 has NO valid moves.
