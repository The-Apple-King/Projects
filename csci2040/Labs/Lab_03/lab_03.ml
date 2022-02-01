open Char
open String 
let rec sum_of_floats xs =
match xs with
| [] -> 0.0
| x :: rest -> x +. sum_of_floats rest

let rec square_floats (vs: float list)=
match vs with
| [] -> []
| v :: rest -> (v*.v)::square_floats rest

let rec exclaimify (ps: string list): string list =
match ps with
| [] -> []
| p :: rest -> (p ^ "!") :: exclaimify rest


let rec remove_odds (xs: int list) =
match xs with
|[]->[]
|x:: rest -> if x mod 2 = 0 then x :: remove_odds rest else remove_odds rest



let rec remove_caps (xs: string list) =
match xs with
|[] -> []
|x :: rest -> if (sub x 0 1) >= "A" && (sub x 0 1) <= "Z"  then remove_caps rest else x :: remove_caps rest
