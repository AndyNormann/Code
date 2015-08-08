class Node
    attr_accessor :left, :right, :data
    def initialize(val)
        @left = nil
        @right = nil
        @data = val
        @moredata = nil
    end

    def add(input)
        if input > @data
            if @right == nil
                @right = Node.new(input)
            else
                @right.add(input)
            end
        elsif input < @data
            if @left == nil
                @left = Node.new(input)
            else
                @left.add(input)
            end
        end
    end

    def to_s
        if @left != nil
            print @left.to_s
        end
        puts @data.to_s
        if @right != nil
            print @right.to_s
        end
    end
end

class Tree
    def initialize
        @root = nil
    end
    def add(input)
        if @root == nil
            @root = Node.new(input)
        else
            @root.add(input)
        end
    end
    def to_s
        print @root.to_s
    end
end

tree = Tree.new()

while num = gets
    tree.add(Integer(num))
end

print tree.to_s
