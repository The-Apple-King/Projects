
(* Part 3. Rose trees *)

type 'a rose_tree = Rose of 'a * 'a rose_tree list

let t1 : int rose_tree =
  Rose (2, [ Rose (1, [ Rose (5, []); Rose (7, []) ] );
               Rose (3, []);
               Rose (4, []);
             ]   )

let t2 : string rose_tree = 
  Rose ("r", [ Rose ("abc", [ Rose ("xy", []); Rose ("z", []) ] );
               Rose ("hello", []);
               Rose ("goodbye", [])
             ]
    )

let t3 : char rose_tree = 
  Rose ('r', [ Rose ('a', [ Rose ('m', []); Rose ('n', []) ] );
               Rose ('b', [ Rose ('o', []); Rose ('p', []) ] );
               Rose ('c', [ Rose ('x', []); Rose ('y', []) ] )
             ]
    )

let t4 : int rose_tree = Rose (4, [])

let rec reduce t (func) (x) = 
match t with 
| Rose (n , [r]  ) -> func n (reduce r func x) 
|_ -> x

let size t = reduce t (fun _ r-> 1 + r) 0

let sum _ = raise (Failure "complete this") 

let product _ = raise (Failure "complete this") 

let char_count _ = raise (Failure "complete this") 

let height _ = raise (Failure "complete this") 

let perfect_balance _ = raise (Failure "complete this") 

let maximum _ = raise (Failure "complete this") 
