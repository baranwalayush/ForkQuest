BFS (Breadth First Search)
Given an undirected graph, perform Breadth First Search (BFS) starting from a given source node and print the order of traversal.

BFS explaination:
- it means to read from the head to all the adjacent nodes and enqueue it. 
- now search for adjacent elements of enqueue them again. 
- it uses queue, so all recent added elements will be read later.


Function BFS(start_node, adjacency_list, total_nodes):
- Time complexity, Space complexity: 
    Create a visited array of size total_nodes, initialized to false
    Create an empty queue

    Mark visited[start_node] = true
    Enqueue start_node into the queue

    While queue is not empty: 
        - Time complexity, Space complexity: 
        current_node = Dequeue from queue
        (all these nodes which are dequeued are the adjacent nodes of the visited node)
        Print current_node

        For each neighbor in adjacency_list[current_node]:
            If neighbor is not visited:
                Mark visited[neighbor] = true
                Enqueue neighbor

DFS(Depth First Search)
Given an undirected graph, perform Depth First Search (DFS) starting from a given source node and print the traversal order.

DFS explaination:
- it means to read from the head to all the adjacent nodes and push it, but only pop 1 at a time.
- now search for the adjacent elements of the popped element and then again add them in the stack.
- it uses stack, so all recent added elements will be read first.

Function DFS(start_node, adjacency_list, total_nodes):
    Create a visited array of size total_nodes, initialized to false
    Create an empty stack

    Mark visited[start_node] = true
    push start_node into the stack

    While stack is not empty:
        current_node = pop from stack
        Print current_node

        For each neighbor in adjacency_list[current_node]:
            If neighbor is not visited:
                Mark visited[neighbor] = true
                push neighbor