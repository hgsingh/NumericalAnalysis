a = [1,5,7,7,9,9,9,10]
b = [0,1,2,21,33,44,55,66]
_lenOf = len(a) + len(b)
arr = [0]*_lenOf
i = 0
j = 0
k = 0
while(k <_lenOf and j<len(b) and i<len(a)):
    if(a[i] <= b[j]):
        arr[k] = a[i]
        i = i + 1
        k = k + 1
    else:
        arr[k] = b[j]
        j = j + 1
        k = k + 1
if(j == len(b) and i<len(a)):
    while(k < _lenOf and i < len(a)):
            arr[k] = a[i]
            i = i + 1
            k = k + 1
if(i == len(a) and j<len(b)):
    while( k< _lenOf and j < len(b)):
        arr[k] = b[j]
        j = j + 1
        k = k + 1

print arr
    
