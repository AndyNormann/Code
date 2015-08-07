class Node
    def initialize(data)
        @data = data
        @next = nil
    end

    attr_accessor :data, :next

    def add(new)
        if @next == nil
            @next = new
        elsif new.data < @next.data
            new.next = @next
            @next = new
        else
            @next.add(new)
        end
    end

    def to_s
        retVal = @data.to_s
        if @next != nil
            return retVal + ' ' +  @next.to_s
        end
        return retVal
    end
end

class SortedLinkedList
    def initialize
        @root = Node.new(0)
    end

    def add(input)
        @root.add(Node.new(input))
    end

    def to_s
        @root.next.to_s
    end
end

list = SortedLinkedList.new

list.add(5)
list.add(1)
list.add(3)
list.add(6)
list.add(8)
list.add(9)

print list
