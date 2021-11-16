open Set

module type  TreeS = sig
  type 'a tree = Leaf
               | Fork of 'a tree * 'a * 'a tree

  type 'a t = 'a tree

  val empty : 'a t

  val insert : 'a -> 'a t -> 'a t

  val elem : 'a -> 'a t -> bool

  val height: 'a t -> int

  val size: 'a t -> int

end

module TreeM : TreeS = struct

  type 'a tree = Leaf
               | Fork of 'a tree * 'a * 'a tree

  type 'a t = 'a tree

  let empty = Leaf

  let rec insert (x: 'a) (t: 'a tree): 'a tree = 
    match t with
      | Leaf -> Fork (Leaf, x, Leaf)
      | Fork(l,n,r) -> if x = n then t
         else if x < n then Fork (insert x l, n,  r)
                        else Fork (l, n, insert x r)

  let rec elem (ele: 'a) (t: 'a tree): bool = match t with 
    | Leaf -> false
    | Fork(l,n,r) -> ele = n || if ele < n then elem ele l else elem ele r


 let rec h t counter =
   match t with
     | Fork (left, n, right) -> max (h left (counter +1)) (h right ( counter +1))
     | Leaf -> counter+1

 let rec height t = 
  h t 0

let rec size t = 
  match t with 
    | Fork (left, n, right) -> 1 + size left + size right
    | Leaf -> 0


end

module TreeSet : SetS = TreeM
