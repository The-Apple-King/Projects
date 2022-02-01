(* Part 4 *)

type 'a elf_tree = Empty
                 | Leaf of 'a
                 | Fork of 'a * 'a elf_tree * 'a elf_tree

let t1 : int elf_tree = 
  Fork (3,
        Fork (2, Empty, Leaf 6),
        Fork (4, 
              Leaf 7,
              Fork (5, Empty, Empty)
          )
    )

let t2 : string elf_tree = 
  Fork ("12",
        Fork ("34", Empty, Leaf "567"),
        Fork ("8910", 
              Leaf "1112",
              Fork ("13", Empty, Empty)
          )
    )

let t3 : int elf_tree =
  Fork (1,
        Fork (2, 
              Fork (3, Leaf 0, Leaf 0),
              Fork (4, Leaf 0, Leaf 0) ),
        Fork (5, 
              Fork (6, Leaf 0, Leaf 0),
              Fork (7, Leaf 0, Leaf 0) )
    )

let t4 : 'a elf_tree = Empty

let max l r = if l > r then l else r

let rec reduce t (func) (x) = 
match t with 
| Empty -> x
| Leaf p -> func p (reduce Empty (func) x) (reduce Empty (func) x)
| Fork (n,l,r) -> func n (reduce l func x) (reduce r func x)

let rec reduces t (func) (x: bool) = 
match t with 
| Empty -> x
| Leaf p -> x
| Fork (n,l,r) -> func l r (reduces l func x) (reduces r func x)

let size t = reduce t (fun _ l r-> 1 + l + r) 0

let sum t = reduce t ( fun n l r->  n + l + r) 0

let product t = reduce t ( fun n l r->  n * l * r) 1

let char_count t = reduce t ( fun n left right->  String.length n +  left +  right) 0

let height t = reduce t ( fun _ l r -> 1 + max l r) 0 

let perfect_balance t = reduces t (fun l r la ra -> height l = height r && la && ra) true

let maximum t = match t with 
| Empty -> None
| Fork (n,l,r)-> Some (max (reduce l ( fun n l r -> max n (max l r)) n) (reduce r ( fun n l r -> max n (max l r)) n))
| Leaf p -> Some p
