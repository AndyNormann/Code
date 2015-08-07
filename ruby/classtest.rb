class Node
    def initialize(data)
        @next = nil
        @data = data
    end
    def get_data
        return @data
    end
    def get_next
        return @next
    end
    def set_next(n)
        @next = n
    end
end

class LinkedList
    def initialize(rootval)
        @root = Node.new(rootval)
        @count = 0
    end

    def add(add_val)
        temp = @root
        while temp.get_next != nil
            temp = temp.get_next
        end
        temp.set_next(Node.new(add_val))
    end

    def to_s
        temp = @root
        while temp != nil
            print temp.get_data, ' '
            temp = temp.get_next
        end
    end
end


list = LinkedList.new(5)
list.add(3)
list.add(4)
list.add(6)
list.add(6)
list.add(1)
list.add(0)

puts list.to_s
