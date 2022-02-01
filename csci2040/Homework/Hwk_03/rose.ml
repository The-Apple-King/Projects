
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

let rec reduce func t =
  match t with
  | Rose (n, lst) -> func n (List.map (reduce func) lst)

  let red t =
  match t with 
  | Rose (n, lst) -> lst

let size t = reduce (fun n ss-> 1 + (List.fold_right (fun init n -> init + n) ss 0) )t

let sum t = reduce (fun n ss-> n + (List.fold_right (fun init n -> init + n) ss 0) )t

let product t =  reduce (fun n ss-> n * (List.fold_right (fun init n -> init * n) ss 1) )t

let char_count t = String.length( reduce (fun c ss ->  c ^ (String.concat "" ss)) t)

let height t = 1 + reduce (fun _ ss-> (List.fold_right (fun init _ -> init + 1) ss 0) )t

let equal lst =
match lst with
|[] -> true
|x::xs -> List.memq x xs

let rec perfect_balance t =  equal (List.map height (red t)) 

let max l r = if l>r then l else r

let maximum t =  Some(reduce (fun n ss-> max (List.fold_right (max) ss n) n )t)
