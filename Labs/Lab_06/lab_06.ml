(*group members
Vera Yushchenko: yushc005@umn.edu
Arjun Balyan: Balya005@umn.edu
 *)


let append list1 list2 =
List.fold_right (fun x xs -> x :: xs) list1 list2

(*renamed variables in unzip so they make more sense when reading through 
also used the append operator instead of @
names:Vera Yushchenko
      Arjun Balyan*)

let rec unzip lst =
    match lst with
    | [] -> ([], [])
    | (first, second) :: rest -> addtup ([first], [second]) (unzip rest)


and addtup t1 t2 =
    match (t1, t2) with
    | (first, second), (firstlst, secondlst) -> (append first firstlst, append second secondlst)

(*shortened invalid argument makes it easier to read without long lines
:Vera yushchenko*)

let grp xs x =
match xs with
| (lst, prev, add) -> if add then ((prev, x) :: lst, x, false) else (lst, x, true)

let group (lst: 'a list): ('a * 'a) list =
match lst with
| x :: rest -> 
    (match List.fold_left (grp) ([], x, true) rest with
    | (_, _, true) -> raise (Invalid_argument "group: requires an even amount of arguments")
    | (a, _, _) -> List.rev a)
| [] -> raise (Invalid_argument "group: requires an even amount of arguments")
