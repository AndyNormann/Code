module Main exposing (..)

import Html exposing (..)
import Html.Attributes exposing (..)
import Html.Events exposing (..)
import List exposing (..)
import Bootstrap.Grid exposing (..)
import Bootstrap.Buttons exposing (..)
import Bootstrap.Page exposing (..)
import Bootstrap.ListGroup exposing (..)
import Time exposing (..)


model =
    { types =
        [ init_time "Dobbeltime" 2.0 0
        , init_time "Møte" 0.5 1
        , init_time "Mail" 0.25 2
        , init_time "Random" 0.25 3
        , init_time "Retting" 0.5 4
        ]
    , total = 0
    , id = 5
    }


main =
    beginnerProgram { model = model, update = update, view = view }


view model =
    body []
        [ containerFluid
            [ div [ class "text-center" ] [ pageHeader [] [ h3 [] [ text "Timeliste" ] ] ]
            , div []
                ((List.map buttonize model.types)
                    ++ [ button [ class (button_styling ++ " glyphicon glyphicon-plus"), onClick AddButton ] [ text "" ] ]
                )
            ]
        ]


subscriptions model =
    every hour Tick


type Msg
    = Hold
    | AddButton
    | Click Float Int
    | Tick Time


update msg model =
    case msg of
        Hold ->
            model

        AddButton ->
            { model | types = (append model.types [ init_time "placeholder" 0.0 model.id ]), id = model.id + 1 }

        Click amount id ->
            { model | total = model.total + amount, types = (update_button_total model.types id) }

        Tick t ->
            model


update_button_total buttons id =
    let
        current_button =
            (head buttons)
    in
        case current_button of
            Nothing ->
                []

            Just current ->
                if current.id == id then
                    { current | total = current.total + 1 }
                        :: Maybe.withDefault [] (tail buttons)
                else
                    current
                        :: (update_button_total
                                (Maybe.withDefault [] (tail buttons))
                                id
                           )


buttonize buttonType =
    row
        [ column [ ExtraSmall Ten, Medium Six ]
            [ btn BtnPrimary [ BtnBlock ] [] [ onClick (Click buttonType.hours buttonType.id) ] [ text buttonType.name ] ]
        , column [ ExtraSmall Two, Medium Six ]
            [ btn BtnPrimary
                []
                []
                [ attribute "data-toggle" "dropdown", attribute "ariahaspopup" "true", attribute "aria-expanded" "false" ]
                [ span [ class "caret" ] [] ]
            , ul [ class "dropdown-menu" ]
                [ pullRight []
                    [ listGroup
                        [ listGroupItem [] [ text "walla burr" ]
                        , listGroupItem [] [ input [ placeholder buttonType.name ] [ text "halaman" ] ]
                        ]
                    ]
                ]
            ]
        ]


button_styling : String
button_styling =
    "btn btn-primary btn-md"


type alias Times =
    { name : String
    , hours : Float
    , total : Int
    , id : Int
    }


init_time name hours id =
    Times name hours 0 id
