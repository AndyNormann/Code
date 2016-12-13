module Main exposing (..)

import Html exposing (text, Html)


add x y =
    x + y


add3 =
    add 3


main : Html msg
main =
    add3 4
        |> toString
        |> text
