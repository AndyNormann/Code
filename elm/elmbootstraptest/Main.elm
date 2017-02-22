module Main exposing (..)

import Bootstrap.Grid exposing (..)
import Bootstrap.Wells exposing (..)
import Bootstrap.Buttons exposing (..)
import Html exposing (..)


-- Program


main =
    beginnerProgram
        { model = model
        , view = view
        , update = update
        }



-- Model


model =
    0



-- View


view model =
    containerFluid
        [ row
            [ column [ ExtraSmall Two ]
                [ h1 []
                    [ text "halal"
                    , btn BtnPrimary [ BtnBlock, BtnLarge ] [ BtnCollapse "#myId, .myClass" ] [] [ text "halla" ]
                    ]
                ]
            ]
        ]



-- Update


type Msg
    = Increment
    | Decrement


update msg model =
    case msg of
        Increment ->
            model + 1

        Decrement ->
            model - 1
