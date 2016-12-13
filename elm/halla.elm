module Main exposing (..)

import Html exposing (text, Html, div, button, beginnerProgram, h3, input)
import Html.Events exposing (..)
import Html.Attributes exposing (..)
import String exposing (toInt)


-- Model


type alias Model =
    { cals : Int
    , amount : Int
    }


initModel : Model
initModel =
    Model 0 1



-- Update


type Msg
    = AddCalorie
    | Clear
    | Input String


update : Msg -> Model -> Model
update msg model =
    case msg of
        AddCalorie ->
            { model
                | cals = model.cals + model.amount
            }

        Clear ->
            initModel

        Input x ->
            case String.toInt x of
                Ok num ->
                    { model
                        | amount = num
                    }

                Err e ->
                    model



-- View


view : Model -> Html Msg
view model =
    div []
        [ h3 [] [ text ("current calories: " ++ (toString model.cals)) ]
        , button
            [ type_ "button"
            , onClick AddCalorie
            ]
            [ text "Add" ]
        , button
            [ type_ "button"
            , onClick Clear
            ]
            [ text "Clear" ]
        , input
            [ onInput Input ]
            []
        ]


main =
    beginnerProgram { model = initModel, view = view, update = update }
