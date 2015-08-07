sum = 0

for e in 1..10000
    if e % 3 == 0 || e % 5 == 0
        sum += e
    end
end

puts sum

