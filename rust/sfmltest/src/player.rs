use math::*;

pub struct Player {
    pub x: f32,
    pub y: f32,
    pub vel_x: f32,
    pub vel_y: f32,
    pub angle: f32,
}

impl Player {
    pub fn turn_left(&mut self) {
        self.angle += 4.5;
    }
    pub fn turn_right(&mut self) {
        self.angle -= 4.5;
    }
    pub fn update(&mut self, window_width: f32, window_height: f32) {
        self.x += self.vel_x;
        self.y += self.vel_y;

        if self.x > window_width {
            self.x = 0.;
        } else if self.x < 0. {
            self.x = window_width;
        }
        if self.y > window_height {
            self.y = 0.;
        } else if self.y < 0. {
            self.y = window_height;
        }

        self.vel_x *= 0.95;
        self.vel_y *= 0.95;
    }
    pub fn accelerate(&mut self) {
        self.vel_x += offset_x(self.angle, 0.5);
        self.vel_y += offset_y(self.angle, 0.5);
    }
    pub fn reverse(&mut self) {
        self.vel_x -= offset_x(self.angle, 0.5);
        self.vel_y -= offset_y(self.angle, 0.5);
    }
}
