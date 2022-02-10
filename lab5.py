import numpy as np

class Node:
    def __init__(self, name):
        self.name = name
        self.connections = []
        self.visited = False

def connect(node1, node2, weight):
    node1.connections.append({"node": node2, "weight": weight})
    node2.connections.append({"node": node1, "weight": weight})

def BFS(node):
    q = [node]
    node.visited = True
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                q.append(con["node"])
                con["node"].visited = True


def get_all_nodes(node):
    #Return a list of the nodes in the graph of nodes connected to node
    #(N.B., the nodes can be indirectly connected as well)
    lis = [node]
    n_visited = 0
    node.visited = True

    #if all visited, move to next node
    while n_visited < len(node.connections):

        #find unvisited nodes from fixed node and add in lis
        for i in range(len(node.connections)):
            connected_n = node.connections[i]
            if connected_n["node"].visited == False:
                #print("node:", connected_n["node"].name, connected_n["weight"])
                lis.append(connected_n["node"])
                connected_n["node"].visited = True
            else:
                n_visited += 1
            #print("lis:", lis)

        if n_visited == len(node.connections):
            node = node.connections[0]["node"]
            n_visited = 0


    return lis

def unvisit_all(node):
    '''Change all n.visited to False in all the nodes in the graph of nodes
    connected to node. Use BFS to find all the nodes'''
    q = [node]
    node.visited = False
    while len(q) > 0:
        cur = q.pop(0) # remove q[0] from q and put it in cur
        print("unvisited:", cur.name)
        for con in cur.connections:
            if con["node"].visited:
                q.append(con["node"])
                con["node"].visited = False


def DFS_rec(node):
    '''Print out the names of all nodes connected to node using a
    recursive version of DFS'''
    if node.visited == False:
        print("DFS_rec:", node.name)
        node.visited = True
        for connected_n in node.connections:
            DFS_rec(connected_n["node"])


def DFS_nonrec(node):
    #Print out the names of all nodes connected to node using a non-recursive
    #version of DFS. Make it so that the nodes are printed in the same order as DFS rec

    node1 = node
    n_connected = 0
    res = []
    track = []
    a_n = get_all_nodes(node)



    while len(res) < len(a_n):
        if node1.visited == True:
            res.append(node1) # add node1 to res
            #print("res.append:", node1.name)
            node1.visited = False
        if node1 not in track:
            track.append(node1) # add to track if going downward
            #print("track:", track)

        #if there is a free connection, go
        for connected in node1.connections:
            #identify the free connections
            if connected["node"].visited == True: #true is free
                node1 = connected["node"]
                break #out of the for loop so that it works with new node1
            else:
                n_connected += 1 #count the number connected to node1
            if n_connected > len(node1.connections):
                if len(track) > 1:
                    popped = track.pop() # if going upwards, get rid of self in track
                    node1 = track[-1] # new node1 is the previous
                    #print("popped:", popped.name)
                    break #out of the for loop so that it works with new node1


    for j in range(len(res)):
        print("DFS_nonrec:", res[j].name)

def DFS_stolen(node):
    s = [node]
    node.visited = True
    while len(s) > 0:
        cur = s.pop() # remove s[-1] from s and put it in cur
        print(cur.name)
        for con in cur.connections:
            if not con["node"].visited:
                s.append(con["node"])
                con["node"].visited = True


if __name__ == '__main__':
    TO = Node("TO")
    NYC = Node("NYC")
    DC = Node("DC")
    CDMX = Node("CDMX")
    SF = Node("SF")

    connect(TO, NYC, 3)
    connect(TO, SF, 6)
    connect(TO, CDMX, 7)
    connect(NYC, DC, 2)
    connect(SF, DC, 5)

    L = get_all_nodes(TO)
    for node0 in L:
        print("get all nodes:", node0.name)
    print()
    #DFS(TO)
    unvisit_all(TO)
    print()
    DFS_rec(TO)
    print()
    unvisit_all(TO)
    print()
    DFS_nonrec(TO)
    print()
    unvisit_all(TO)
    print()
    DFS_stolen(TO)
    #print(dijsktra_slowish(TO))


