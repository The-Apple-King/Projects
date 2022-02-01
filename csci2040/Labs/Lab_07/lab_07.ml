

let rec all_suffixes (w: 'a list) : 'a list list =
match w with 
| [] ->[[]]
| x::[] -> [x] :: [] :: []
| x::xs -> w ::  all_suffixes xs




let rec pre (w: 'a list list) =
match w with 
| [] -> []
| x::xs -> (List.rev x) :: pre xs

let rec all_prefixes (w: 'a list) : 'a list list =
pre (all_suffixes (List.rev w))

let red w =
match w with
| [] -> []
|x::xs -> xs

let rec all lst1 lst2 = 
match lst1 with
| []-> []
| x::xs -> (x, (match lst2 with 
|[] -> []
|p::ps -> p)) :: all xs (red lst2)



let rec all_parts (w: 'a list) : ('a list * 'a list) list =
all (all_prefixes w) (List.rev (all_suffixes w))