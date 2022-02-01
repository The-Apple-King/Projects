open Char
open String 
let sum_of_floats xs =
List.fold_right (+.) xs 0.0

let sqr x =
x*.x
let square_floats xs=
List.map sqr xs


let ex x =
x ^ "!"
let exclaimify (xs: string list): string list =
List.map ex xs

let bs x =
if (x mod 2 = 0) then true else false
let remove_odds (xs: int list) =
List.filter bs xs

let ps x =
if (sub x 0 1) >= "A" && (sub x 0 1) <= "Z"  then false else true
let remove_caps (xs: string list) =
List.filter ps xs