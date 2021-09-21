let rec sum (xs: float list) =
match xs with
| [] -> []
| x :: rest -> x +. sumf rest

let rec square (vs: float list)=
match vs with
| [] -> []
| v :: rest -> (v*.v)::square rest

let rec exclamify (ps: string list): string list =
match ps with
| [] -> ["!"]
| p :: rest -> (p ^ "!") :: exclamify rest


let rec remove_odds (xs: int list) =
match xs with
|[]->[]
|x:: rest -> if x mod 2 = 0 then x :: remove_odds rest else remove_odds rest


(*let remove_caps (xs: string list) =
match xs with
|[] -> []
|x :: rest -> if (equal (uppercase_ascii (get x 0)) (get x 0)) then exclamify rest
 *)