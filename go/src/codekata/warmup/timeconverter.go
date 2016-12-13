package main

import(
    "fmt"
    "os"
    "strings"
    "strconv"
    "errors"
)


type time struct {
    hour int
	minute int
    second int
    am_pm string
}



func main() {

    if len(os.Args) != 2 {
        fmt.Printf("Usage: %s <time>\n", os.Args[0])
        os.Exit(-1)
    }

    ballefitt, err := time_convert(os.Args[1])
    if err != nil {
        panic(err)
    }

    ballefitt.print()
}


func (t *time) print() {
    fmt.Printf("%d:%d:%d\n", t.hour, t.minute, t.second)
}


func time_convert(line string) (time, error) {

    ret_val := time{}
    var err error = nil

    line_split := strings.Split(line, ":")
    
    // Parse minute
    ret_val.minute, err = strconv.Atoi(line_split[1])
    if err != nil {
        return ret_val, err
    }


    // Parse second + am/pm
    second_am_pm := []byte(line_split[2])

    // Extract second 
    ret_val.second, err = strconv.Atoi(string(second_am_pm[0:2]))
    if err != nil {
        return ret_val, err
    }
    // Extract am/pm
    am_pm_bytes := second_am_pm[2:len(second_am_pm)]
    ret_val.am_pm = string(am_pm_bytes)

    if ret_val.am_pm != "AM" && ret_val.am_pm != "PM" {
        return ret_val, errors.New("invalid time format")
    }

    // Parse hour
    var hour_int int
    hour_int, err = strconv.Atoi(line_split[0])
    if err != nil {
        return ret_val, err
    }


    // Handle am/pm conversion
    if ret_val.am_pm == "PM" {
        hour_int += 12
    }
    if hour_int == 24 {
        hour_int = 0
    }

    ret_val.hour = hour_int


    return ret_val, nil
}
