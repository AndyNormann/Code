import Html exposing (Html, button, div, text)
import Html.App as Html
import Html.Events exposing (onClick)

main =
    Html.beginnerProgram { model = model, view = view, update = update }

-- Model

type alias Model = Int

-- View

view model =
    div []
        [ button [ onClick Increment ] [ text "+"]
        , div [] [ text  (toString model) ]
        , button [ onClick Decrement ] [ text "-"]
        , div [] [ text  "" ]
        , button [ onClick Reset ] [ text "reset"]
        ]

-- Update

type Msg = Increment | Decrement | Reset

update msg model =
    case msg of
        Increment ->
            model + 1
        Decrement ->
            model - 1
        Reset ->
            0
            


