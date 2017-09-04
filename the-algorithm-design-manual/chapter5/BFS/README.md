1.  gcc adjacency_lists.c bfs.c main.c queue.c

2.  ./a.out

        enter nvertices and nedges: 6 7      
        enter vertex x and y: 1 6
        enter vertex x and y: 1 5
        enter vertex x and y: 1 2
        enter vertex x and y: 2 3
        enter vertex x and y: 2 5
        enter vertex x and y: 3 4
        enter vertex x and y: 4 5
        enter started vertex: 1
        enqueue:  1
        dequeue:  1
        processed edge (1,2)
        enqueue:  2
        processed edge (1,5)
        enqueue:  5
        processed edge (1,6)
        enqueue:  6
        dequeue:  2
        processed edge (2,5)
        processed edge (2,3)
        enqueue:  3
        dequeue:  5
        processed edge (5,4)
        enqueue:  4
        dequeue:  6
        dequeue:  3
        processed edge (3,4)
        dequeue:  4





