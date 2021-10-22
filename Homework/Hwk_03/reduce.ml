(* Part 2 *)

type 'a tree 
  = Leaf 
  | Fork of 'a tree * 'a * 'a tree

let t1 : int tree = 
  Fork (Fork (Leaf, 2, Leaf),
        3,
        Fork (Leaf,
              4, 
              Fork (Leaf, 5, Leaf)
          )
    )

let t2 : string tree = 
  Fork (Fork (Leaf, "12", Leaf),
        "34",
        Fork (Leaf,
              "5", 
              Fork (Leaf, "678", Leaf)
          )
    )

let t3 : int tree =
  Fork (Fork (Fork (Leaf, 1, Leaf),
              2, 
              Fork (Leaf, 3, Leaf) ),
        4,
        Fork (Fork (Leaf, 5, Leaf),
              6, 
              Fork (Leaf, 7, Leaf) )
    )

let t4 : 'a tree = Leaf

let max l r = if l > r then l else r

let rec reduce t (func) (x) = 
match t with 
| Leaf -> x
| Fork (l,n,r) -> func n (reduce l func x) (reduce r func x)

let rec reduces t (func) (x: bool) = 
match t with 
| Leaf -> x
| Fork (l,n,r) -> func l r (reduces l func x) (reduces r func x)


let size t = reduce t (fun _ l r-> 1 + l + r) 0

let sum t = reduce t ( fun n l r->  n + l + r) 0

let product t = reduce t ( fun n l r->  n * l * r) 1

let char_count t = reduce t ( fun n left right->  String.length n +  left +  right) 0

let height t = 1 + reduce t ( fun _ l r -> 1 + max l r) 0 

let perfect_balance t = reduces t (fun l r la ra -> height l = height r && la && ra) true

let maximum t = match t with 
| Fork (l,n,r)-> Some (max (reduce l ( fun n l r -> max n (max l r)) n) (reduce r ( fun n l r -> max n (max l r)) n))
| Leaf -> None