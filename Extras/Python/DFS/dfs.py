#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  5 10:03:56 2021

@author: nehal
"""

graph1 = {'A': ['B', 'D', 'G', 'I'], 'B': ['D', 'C'], 'C' : ['A', 'E'], 'D' : ['F','C'],
          'E' : ['F', 'J'], 'F' : ['H','C'], 'G':['F','K'], 'H':['E', 'K', 'L'], 'I':['S'],
          'J':['S'], 'K':[], 'L':['J','F'], 'S':['K'] }
 
def dfs(graph, node, visited):
    if node not in visited:
        visited.append(node)
        for k in graph[node]:
            dfs(graph,k, visited)
    return visited
 
visited = dfs(graph1,'A', [])
print(visited)