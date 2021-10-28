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

  let insert _ = raise (Failure "complete this")

  let elem _ = raise (Failure "complete this")

  let height _ = raise (Failure "complete this")

  let size _ = raise (Failure "complete this")

end

module TreeSet : SetS = TreeM
