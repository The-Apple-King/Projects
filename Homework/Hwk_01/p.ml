let rec long x xs = 
match xs with
| [] -> x
| z :: rest -> if String.length x < String.length z then long z rest else long x rest

let rec longest xs =
match xs with
| [] -> raise (Invalid_argument "longest: requires list of strings")
| x :: pp -> long x pp