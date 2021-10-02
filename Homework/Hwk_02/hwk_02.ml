open Char
open String

let sum xs =
List.fold_right (+) xs 0

let sumf xs =
List.fold_right (+.) xs 0.0

let product xs =
List.fold_right ( * ) xs 1

let productf xs =
List.fold_right ( *. ) xs 1.0


let mins x z = 
if x < z then x else z

let minimum xs =
match xs with
| [] -> raise (Invalid_argument "minimum: requires list of values")
| x :: rest -> List.fold_right mins rest x


let long x z = 
if String.length x > String.length z then x else z


let longest xs =
match xs with
| [] -> raise (Invalid_argument "longest: requires list of values")
| x :: rest -> List.fold_right long rest x
 

let append list1 list2 =
List.fold_right (fun x xs -> x :: xs) list1 list2


let elem x xs = 
List.fold_right (fun p b -> if p = x then true else b) xs false



let ex x =
x ^ "!"
let excited (xs: string list): string list =
List.map ex xs

let suffix x (ps: string list): string list =
 List.map (fun z -> z ^ x) ps

let excited' (ps: string list): string list =
suffix "!" ps


let lgs x =
(String.length x)
let lengths xs = 
List.map lgs xs



let lg x =
(x, (String.length x))
let length_pairs xs = 
List.map lg xs


let cap x =
(String.capitalize_ascii x)
let capitalize xs = 
List.map cap xs

let bs x =
if (x mod 2 = 1) then true else false
let all_odds (xs: int list) =
List.filter bs xs

let ps x =match x with
| "" ->  raise (Invalid_argument "all_capitalized: requires strings")
|_ ->  (sub x 0 1) >= "A" && (sub x 0 1) <= "Z"
let all_capitalized (xs: string list) =
List.filter ps xs

let rec sqr x xs = 
if x < xs || xs = 1 then (if (x*x) = xs then true else sqr (x+1) xs) else  false

let s xs = sqr 0 xs
let all_squares xs =
List.filter s xs


let grp xs x =
match xs with
| (lst, prev, add) -> if add then ((prev, x) :: lst, x, false) else (lst, x, true)

let group (lst: 'a list): ('a * 'a) list =
match lst with
| x :: rest -> 
    (match List.fold_left (grp) ([], x, true) rest with
    | (_, _, true) -> raise (Invalid_argument "group: requires an even amount of variables in the list")
    | (a, _, _) -> List.rev a)
| [] -> raise (Invalid_argument "group: requires an even amount of variables in the list")


let unzip lst =
List.fold_right (fun x xs -> match (x, xs) with | ((l, r), (ls, rs)) -> (l::ls, r::rs)) lst ([], [])