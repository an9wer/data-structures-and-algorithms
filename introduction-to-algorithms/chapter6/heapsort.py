class MyList:
    """
    a proxy class for built-in list
    so that we can add the attribute `heap_size` to list
    """
    def __init__(self, l):
        self.wrapped = l
    def __getattr__(self, name):
        return getattr(self.wrapped, name)
    def __setattr__(self, name, value):
        self.__dict__[name] = value

def max_heapify(A, i):
    """
    :param A: the heap list.
    :param i: the ith index of heap tree node, and the (i-1)th index of A.
              remember that the heap tree starts with index 1, and the list A 
              starts with index 0.

              the blow picture is the heap tree.
                        1
                     /     \
                   2         3
                 /   \     /   \
                4     5   6     7
               / \   /
              8  9  10

    :param A.heap_size: the length of A 
    """
    l = (i << 1)
    r = (i << 1) + 1
    if l <= A.heap_size and A[l-1] > A[i-1]:
        largest = l
    else:
        largest = i
    if r <= A.heap_size and A[r-1] > A[largest-1]:
        largest = r
    if largest != i:
        A[i-1], A[largest-1] = A[largest-1], A[i-1]
        max_heapify(A, largest)

def build_max_heap(A):
    A.heap_size = len(A)
    for i in range(len(A)/2, 0, -1):
        max_heapify(A, i)

def heapsort(A):
    build_max_heap(A)
    for i in range(len(A), 1, -1):
        A[i-1], A[0] = A[0], A[i-1]
        A.heap_size -= 1
        max_heapify(A, 1)
    #print A
    return A


if __name__ == '__main__':
    test = MyList([0, 1, 2, 3, 4, 4, 3, 6, -1])
    heapsort(test)

