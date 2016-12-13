module Main exposing (..)

import Html exposing (..)
import Html.Attributes exposing (..)


main : Html msg
main =
    body [ text_style ]
        [ h1 [] [ text "Lorem Ipsum" ]
        , p []
            [ text "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
            ]
        ]


text_style =
    style
        [ ( "color", "#050505" )
        , ( "backgroundColor", "#f9fafc" )
        , ( "textAlign", "center" )
        , ( "fontFamily", "PragmataPro" )
        , ( "fontSize", "18px" )
        , ( "padding", "1cm" )
        ]
