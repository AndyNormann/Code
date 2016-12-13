#![feature(plugin)]
#![plugin(maud_macros)]

extern crate maud;
extern crate iron;

use iron::prelude::*;
use iron::status;


fn main() {

    Iron::new(|r: &mut Request| {
        let name = "tull";
        let name2 = "spull";
        let name3 = "knull";

        let markup = html! {
            div {
                p {"Brille bralle brull, her lukter jeg kristenmans" (name)}
                p {"Brille bralle brull, her lukter jeg kristenmans" (name2)}
                p {"Brille bralle brull, her lukter jeg kristenmans" (name3)}
                p {"Suh dude " (r.url)}
            }
        };
        println!("Connection recieved");
        Ok(Response::with((status::Ok, markup)))
    }).http("localhost:3000").unwrap();
}
