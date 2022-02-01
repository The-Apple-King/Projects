open Int
(* Part 1 *)

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

let rec size t = 
match t with 
| Fork (left, n, right) -> 1 + size left + size right
| Leaf -> 0

let rec sum t : int =
  match t with
  | Fork (left, n, right) -> n + sum left + sum right
  | Leaf -> 0

let rec product t : int =
  match t with
  | Fork (left, n, right) -> n * product left * product right
  | Leaf -> 1

let rec char_count t = 
match t with
  | Fork (left, n, right) -> String.length n + char_count left + char_count right
  | Leaf -> 0

let max l r = if l > r then l else r

 let rec h t counter =
match t with
  | Fork (left, n, right) -> max (h left (counter +1)) (h right ( counter +1))
  | Leaf -> counter+1

 let rec height t = 
 h t 0


let rec perfect_balance t =  
 match t with
  | Fork (left, n, right) -> if (height left = height right) then perfect_balance left && perfect_balance right else false
  | Leaf -> true



let rec maximum t = 
 match t with
  | Fork(Leaf, n, Leaf) -> Some(n)
  | Fork(Leaf, n, right) -> (match maximum right with
    | Some(r) -> Some(max n r)
    | None -> Some(n))
  | Fork(left, n, Leaf) -> (match maximum left with
    | Some(l) -> Some(max l n)
    | None -> Some(n))
  | Fork(left, n, right) -> (match (maximum left, maximum right) with
    | (Some(l), Some(r)) -> Some(max (max l r) n)
    | (Some(l), None) -> Some(max l n)
    | (None, Some(r)) -> Some(max n r)
    | (None, None) -> Some(n))
  | Leaf -> None