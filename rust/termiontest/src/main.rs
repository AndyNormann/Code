extern crate termion;

use termion::raw::IntoRawMode;
use termion::event::Key;
use termion::input::TermRead;
use std::io::{Write, stdout, stdin};

fn main() {

    let stdin = stdin();
    let mut stdout = stdout().into_raw_mode().unwrap();

    write!(stdout, "{}{}q to exit, Type stuff plz{}",
           termion::clear::All,
           termion::cursor::Goto(1, 1),
           termion::cursor::Hide).unwrap();

    stdout.flush().unwrap();

    for c in stdin.keys() {
        write!(stdout, "{}{}", termion::cursor::Goto(1, 1), termion::clear::CurrentLine).unwrap();

        match c.unwrap() {
            Key::Char('q') => break,
            Key::Char(c) => println!("{}", c),
            Key::Alt(c) => println!("M-{}", c),
            Key::Ctrl(c) => println!("C-{}", c),
            Key::Left => println!("->"), 
            Key::Right => println!("<-"), 
            Key::Up => println!("^"), 
            Key::Down => println!("v"), 
            Key::Backspace => println!("backspace"),
            _ => (),
        }

        stdout.flush().unwrap();
    }

    write!(stdout, "{}", termion::cursor::Show).unwrap();
}
