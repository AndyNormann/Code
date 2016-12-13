require 'gosu'
require 'hasu'
load 'Player.rb'
load 'Enemy.rb'

class GameWindow < Gosu::Window
    prepend Hasu::Guard
    def initialize
        super 640, 480
        self.caption = "Halla"
        @background_image = Gosu::Image.new("media/space.png", :tileable => true)

        @player = Player.new
        @player.warp(320, 340)

        @enemies = Array.new
        @enemies[0] = Enemy.new

    end

    def update
        if Gosu::button_down? Gosu::KbLeft or Gosu::button_down? Gosu::GpLeft then
            @player.turn_left
        end
        if Gosu::button_down? Gosu::KbRight or Gosu::button_down? Gosu::GpRight then
            @player.turn_right
        end
        if Gosu::button_down? Gosu::KbUp or Gosu::button_down? Gosu::GpButton0 then
            @player.accelerate
        end
        @player.move
    end

    def draw
        @player.draw
        @background_image.draw(0, 0, 0)
    end
end


window = GameWindow.new
window.show
