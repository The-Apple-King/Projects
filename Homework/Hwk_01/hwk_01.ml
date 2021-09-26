open Char
open String

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
| [] -> 1
| x :: rest -> x * product rest

let rec productf (xs: float list): float =
match xs with
| [] -> 1.0
| x :: rest -> x *. productf rest

let rec mins x xs =
match xs with
| [] -> x
| z :: rest -> if x>z then mins z rest else mins x rest

let minimum xs = 
match xs with
| [] -> raise (Invalid_argument "minimum: requires list of values")
| x :: pp -> mins x pp


let rec long x xs = 
match xs with
| [] -> x
| z :: rest -> if String.length x < String.length z then long z rest else long x rest

let rec longest xs =
match xs with
| [] -> raise (Invalid_argument "longest: requires list of strings")
| x :: pp -> long x pp
 

let append list1 list2 =
list1 @ list2 


let rec elem x xs = 
match xs with
| [] -> false
| z :: rest -> if x = z then true else elem x rest



let rec excited (ps: string list): string list =
match ps with
| [] -> []
| p :: rest -> (p ^ "!") :: excited rest

let rec suffix x (ps: string list): string list =
match ps with
| [] -> []
| p :: rest -> (p ^ x ) :: suffix x rest

let excited' (ps: string list): string list =
suffix "!" ps


let rec lengths xs = 
match xs with
| [] ->[]
|x:: rest -> (String.length x) :: lengths rest

let rec length_pairs xs = 
match xs with
| [] -> []
| x:: rest -> (x, (String.length x)) :: length_pairs rest

let rec capitalize xs = 
match xs with
| []->[]
| x::rest -> (String.capitalize_ascii x) :: capitalize rest

let rec all_odds (xs: int list) =
match xs with
|[]->[]
|x:: rest -> if x mod 2 = 1 then x :: all_odds rest else all_odds rest

let rec all_capitalized (xs: string list) =
match xs with
|[] -> []
|x :: rest ->if(String.length x != 0) then if (compare (uppercase_ascii (sub x 0 1)) (sub x 0 1)) = 0 then x :: all_capitalized rest else all_capitalized rest else raise (Invalid_argument "all_capitalized: requires that none of the strings are empty")

let rec sqr x xs = 
if x < xs || xs = 1 then (if (x*x) = xs then true else sqr (x+1) xs) else  false

let rec all_squares xs =
 match xs with 
| []->[]
|x::rest -> if sqr 0 x then x :: all_squares rest else all_squares rest


let rec group xs = 
match xs with
| [] -> []
|x::[] -> raise (Invalid_argument "group: requires an even amount of variables in the list")
| x :: z :: rest -> (x, z):: group rest


let rec unzip lst =
    match lst with
    | [] -> ([], [])
    | (k, v) :: rest -> addtup ([k], [v]) (unzip rest)
and addtup t1 t2 =
    match (t1, t2) with
    | (k, v), (xk, xv) -> (k @ xk, v @ xv)