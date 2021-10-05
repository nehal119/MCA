"""Breath First Search (BFS) can be used when finding the shortest path
from a given source node to a target node in an unweighted graph.
"""
from typing import Dict

# This is a unweighted (edges don't have any weight) directed Graph
graph = {
  'A' : ['B', 'D', 'G', 'I'],  'B' : ['D', 'C'],  'C' : ['A', 'E'], 'D' : ['F','C'],  'E' : ['F', 'J'],
  'F' : ['H','C'],  'G':['F', 'K'], 'H':['E', 'K', 'L'],  'I':['S'],  'J':['S'],  'K':[], 'L':['J','F'],  'S':['K']
}

class Graph:
    def __init__(self, graph: Dict[str, str], source_vertex: str):      #
        self.graph = graph
        # mapping node to its parent in resulting breadth first tree
        self.parent = {}
        self.source_vertex = source_vertex

    def bfs(self):
        visited = {self.source_vertex}          # Setting the source node to the visted
        self.parent[self.source_vertex] = None  #Setting the parent node of the source to NONE
        queue = [self.source_vertex]            # first in first out queue

        while queue:                            #till queue is not empty
            vertex = queue.pop(0)
            print("Visited:",vertex)
            for adjacent_vertex in self.graph[vertex]:
                if adjacent_vertex not in visited:
                    visited.add(adjacent_vertex)

                    self.parent[adjacent_vertex] = vertex # Marking the parent of child node
                    print("Graph parent nodes:",self.parent)

                    queue.append(adjacent_vertex)
                    print("queue elements:",queue)

    def shortest_path(self, target_vertex: str):
        
        if target_vertex == self.source_vertex:
            return f"{self.source_vertex}"
        elif not self.parent.get(target_vertex):
            return f"No path from vertex:{self.source_vertex} to vertex:{target_vertex}"
        else:
            return self.shortest_path(self.parent[target_vertex]) + f"->{target_vertex}"


if __name__ == "__main__":
    g = Graph(graph, "H")
    g.bfs()
    print("\nShortest path is:", g.shortest_path("I"))