extern crate mustache;
extern crate rustc_serialize;

use std::io;
use mustache::MapBuilder;

#[derive(RustcEncodable)]
struct Planet {
    name: String,
}

fn main() {
    let template = mustache::compile_str("hello {{name}}").unwrap();

    let planet = Planet { name: "Mercury".into() };
    template.render(&mut io::stdout(), &planet).unwrap();
    println!("");

    let data = MapBuilder::new()
                   .insert_str("name", "Venus")
                   .build();

    template.render_data(&mut io::stdout(), &data).unwrap();
    println!("");

    template.render_data(&mut io::stdout(), &data).unwrap();
    println!("");

    template.render_data(&mut io::stdout(), &data).unwrap();
    println!("");
}
