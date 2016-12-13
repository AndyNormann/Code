require 'hasu'

class Game < Hasu::Window
  def initialize
    super(640, 480, false)
    self.caption = "Halla"
    @background_image = Gosu::Image.new("../media/space.png", :tileable => true)
  end

  def reset
  end

  def update
  end

  def draw
      @background_image.draw(0, 0, 0)
  end
end
