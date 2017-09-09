1.  gcc main.c adjacency_lists.c dfs.c

2.  ./a.out

        enter nvertices and nedges: 6 7
        enter vertex x and y: 1 2
        enter vertex x and y: 2 3
        enter vertex x and y: 3 4
        enter vertex x and y: 4 5
        enter vertex x and y: 5 2
        enter vertex x and y: 5 1
        enter vertex x and y: 1 6
        enter started vertex: 1
        start 1
        processed edge (1,6)
        start 6
        end 6
        processed edge (1,5)
        start 5
        processed edge (5,2)
        start 2
        processed edge (2,3)
        start 3
        processed edge (3,4)
        start 4
        end 4
        end 3
        end 2
        end 5
        end 1
