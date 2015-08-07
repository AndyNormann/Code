def mergesort(a)
    n = a.length
    if n == 1
        return a
    end

    left = a[0..n/2]
    right = a[n/2+1..n-1]

    mergesort(left)
    mergesort(right)

    return merge(left, right)
end

def merge(left, right)
    merged = []
    merged[merged.length]

    while 
    end
end

puts mergesort([1, 55, 8, 2, 3, 5, 7, 8])

