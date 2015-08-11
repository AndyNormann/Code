class DemoController < ApplicationController
    layout false

    def index
        @stuff = ['halla', 'skjera', 'ikkemyeda', 'keyda']
    end
end
