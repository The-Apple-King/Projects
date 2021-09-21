let rec sum (xs:int list): int=
match xs with 
| [] -> 0
| x :: rest -> x + sum rest

let rec sumf (xs: float list): float =
match xs with
| [] -> 0.0
| x :: rest -> x +. sumf rest

let rec product (xs:int list): int=
match xs with 
| [] -> 0
| x :: rest -> x * product rest

let rec productf (xs: float list): float =
match xs with
| [] -> 0.0
| x :: rest -> x *. productf rest

let rec minimum xs =
match xs with 
| [] -> []