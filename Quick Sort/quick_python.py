def QuickSort(vec):
    # base case
    if(len(vec) < 2):
        return vec

    else:
        pivote = vec[0]
        less = [i for i in vec[1:] if i<=pivote]
        greater = [i for i in vec[1:] if i> pivote]

        return QuickSort(less) + [pivote] + QuickSort(greater)

print(QuickSort([10, 7, 8, 9, 1, 5, 1, 34, 34, 54]))
        

