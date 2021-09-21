let rec sumf (xs: float list): float =
match xs with
| [] -> 0.0
| x :: rest -> x +. sumf rest

let rec square (xs: float list): float =
match xs with
| [] -> 0.0
| x :: rest -> (x *. x) + square rest
