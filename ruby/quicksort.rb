def quick_sort(array)
    qsort(array, 0, array.length-1)
end

def qsort(array, low, high)
    if low < high
        pivot = partition(array, low, high)
        qsort(array, low, pivot-1)
        qsort(array, pivot+1, high)
    end
end

def partition(array, low, high)
    pivot = array[low]
    leftwall = low
    for e in low+1..high
        if pivot > array[e]
            leftwall = leftwall+1
            swap(array, e, leftwall)
        end
    end
    swap(array, low, leftwall)
    return leftwall
end

def swap(array, i, j)
    temp = array[i]
    array[i] = array[j]
    array[j] = temp
end

bla = []

while num = gets
    bla[bla.length] = Integer(num)
end

quick_sort(bla)

puts(bla)
