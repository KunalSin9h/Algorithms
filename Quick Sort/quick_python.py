def QuickSort(vec):
    # base case
    if(len(vec) <= 1):
        return vec
    else:
        pivote = vec[0] # first element as pivot
        less = [i for i in vec[1:] if i<=pivote]
        greater = [i for i in vec[1:] if i> pivote]
        
        return QuickSort(less) + [pivote] + QuickSort(greater)

l = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
print(QuickSort(l))