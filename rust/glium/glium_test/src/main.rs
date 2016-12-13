extern crate glium;

fn main() {
    use glium::DisplayBuild;

    let display = glium::glutin::WindowBuilder::new()
                      .build_glium()
                      .expect("Failed to create a window");

    loop {
        let mut target = display.draw();
        target.clear_color(0.0, 0.0, 1.0, 1.0);

        target.finish().unwrap();

        for ev in display.poll_events() {
            match ev {
                glium::glutin::Event::Closed => return,
                _ => (),
            }
        }
    }


}
