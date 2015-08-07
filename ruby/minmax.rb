def max(list)
    max = list[0]
    for e in list
        if(e > max)
            max = e
        end
    end
    max
end

def min(list)
    min = list[0]
    for e in list
        if(e < min)
            min = e
        end
    end
    min
end

puts(max([1, 4, 2, 0, -1, 99, 102]))
puts(min([2, 55, 2, 3, 4, 1, 6, 76]))
