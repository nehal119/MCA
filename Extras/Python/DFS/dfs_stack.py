#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct  3 12:14:04 2021

@author: nehal
"""

graph = {'A': ['B', 'D', 'G', 'I'], 'B': ['D', 'C'], 'C' : ['A', 'E'], 'D' : ['F','C'],
      'E' : ['F', 'J'], 'F' : ['H','C'], 'G':['F','K'], 'H':['E', 'K', 'L'], 'I':['S'],
      'J':['S'], 'K':[], 'L':['J','F'], 'S':['K'] }

class Stack:
    def __init__(self):
        self.list = []

    def push(self, item):
        self.list.append(item)

    def pop(self):
        return self.list.pop()

    def top(self):
        return self.list[-1]

    def is_empty(self):
        return len(self.list) == 0
    
    def display(self):
        for item in self.list[::-1]:
            print(item)

def dfSearch(graph, start):
    stack = Stack()
    stack.push(start)
    path = []

    while not stack.is_empty():
        print("Current stack is: ")
        stack.display()
        vertex = stack.pop()
        print("Pop", vertex, "from Stack")
        print("Current path is: ", path)
        if vertex in path:
            print(vertex, "Alredy visited")
            continue
        print("Visiting vertex", vertex)
        path.append(vertex)
        for neighbor in graph[vertex]:
            print("Push", neighbor, "into Stack")
            stack.push(neighbor)

    return path


if __name__ == '__main__':
    dfs_path = dfSearch(graph, 'A')
    print("DFS path is: ", dfs_path)