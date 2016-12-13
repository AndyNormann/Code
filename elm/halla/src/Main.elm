module Main exposing (..)

import Html exposing (text, Html, div, ul, li, button)
import Html.App exposing (beginnerProgram)
import Html.Events exposing (onClick)
import List exposing (head, tail)


main =
    beginnerProgram { model = 0, view = view, update = update}



model_ =
    [ [0, 0, 0, 0, 0]
    , [0, 0, 0, 0, 0]
    , [0, 0, 0, 0, 0]
    , [0, 0, 0, 0, 0]
    , [0, 0, 0, 0, 0]
    , [0, 0, 0, 0, 0]
    ]

view model =
    div []
        [ button [onClick Decrement] [text "-"]
        , div [] [text (toString model)]
        , button [onClick Increment] [text "+"]
        , div [] [text (toString (tail model_))]
        ]

type Msg = Increment | Decrement


update msg model =
    case msg of
        Increment ->
            model + 1
        Decrement ->
            model - 1
