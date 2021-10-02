let grp xs x =
match xs with
| (lst, prev, add) -> if add then ((prev, x) :: lst, x, false) else (lst, x, true)

let group (lst: 'a list): ('a * 'a) list =
match List.fold_left (grp) ([], None, false) lst with
| (_, _, true) -> raise (Invalid_argument "group: requires an even amount of variables in the list")
| (a, _, _) -> List.rev a