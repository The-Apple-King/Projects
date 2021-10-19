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

let rec reduce _ = raise (Failure "complete this") 

let size _ = raise (Failure "complete this") 

let sum _ = raise (Failure "complete this") 

let product _ = raise (Failure "complete this") 

let char_count _ = raise (Failure "complete this") 

let height _ = raise (Failure "complete this") 

let perfect_balance _ = raise (Failure "complete this") 

let maximum _ = raise (Failure "complete this") 
