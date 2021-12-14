(*

1. What is the search space that your solution explores? Specifically, explain what decisions are made at each step in exploring this space. 
In the case of the subset-sum problem, we made a decision about including, or not including, an element from the original set in the partial subset we were constructing. 
Explain the decisions being made in your solution, with references to those parts of your solution.



2. In exploring the potential coloring of a graph, your solution must not continue searching along that path if two adjacent nodes are colored with the same color. 
Explain how your solution avoids this potential inefficiency.

I create a list of failure cases, where if this connection exists it failed. I then created a couple functions to cycle through every connection and if they matched the failure cases it would instantly return false and stop cycling.
 *)
type node = N of int
type edge = node * node
type graph = node list * edge list

type color = C of int
type coloring = (node * color) list


let g1 : graph = 
  ( [N 1; N 2; N 3; N 4], 
    [ (N 1,N 2); (N 1,N 3); (N 2,N 3); (N 3,N 4) ] )

let g1_coloring : coloring = 
  [ (N 1,C 0); (N 2,C 1); (N 3,C 2); (N 4,C 1) ]

let bad_g1_coloring : coloring = 
  [ (N 1, C 1); (N 2, C 1); (N 3,C 3); (N 4,C 2) ]

let g2 : graph =
  ( [N 1; N 2; N 3; N 4], 
    [ (N 1, N 2); (N 1, N 3); (N 1, N 4); 
      (N 2, N 3); (N 3, N 4); (N 4, N 2) ] )


exception FoundColoring of coloring


(*creates a list of every possible combination of connections that fail*)
let rec test_failures (colors: coloring) (test_against) (accum): (node * node) list =
  if test_against = (N 0, C 0) then (match colors with 
    | [] -> accum
    | x::xs -> accum@(test_failures xs x accum)@(test_failures xs test_against accum))else
    match colors with 
      | [] -> accum
      | x::xs -> (match x with 
          | (n,c) -> match test_against with
              | (ntest, ctest) -> if n <> ntest && c = ctest then test_failures xs test_against (accum@[(n, ntest)]@[(ntest, n)]) else test_failures xs test_against accum)
      
(*following two are used to cycle through outcomes and return true or false *)
let rec contains test list =
  match list with
  | [] -> true
  | x::xs -> if test <> x then contains test xs else false

let rec cycle l contain =
  match l with 
  | [] -> true
  | x::xs -> if contains x contain then cycle xs contain else false

(*looks through the possible failures and if one exists it returns false*)
let valid_coloring (colors: coloring) (graph: graph) = 
  match graph with 
  | (nodes, connections) -> cycle (test_failures colors (N 0,C 0) []) connections


(*tests every possible color and returns a value if one works*)
let rec color_help (c: coloring) (n: node list) (staticn: node list) (g: graph) : coloring option =

  if (valid_coloring c g) && List.length c = List.length staticn then Some c else
  if (valid_coloring c g) then 
  match n with
  |[] -> None
  |y::ys -> 
    match color_help ((y,C 1)::c) ys staticn g with
    | Some sol -> Some sol
    | None -> 
      match color_help ((y,C 2)::c) ys staticn g with
      | Some sol -> Some sol
      | None -> 
        match color_help ((y,C 3)::c) ys staticn g with
        | Some sol -> Some sol
        | None -> None
        
  else None 

(*returns the outcome of previous function *)
let color_option graph: coloring option = 
  match graph with 
  | (nodes, connections) ->  color_help [] nodes nodes graph

(*does the same as above but returns an exception*)
let color_exception (graph: graph): unit = 
   match graph with 
   | (nodes, connections) -> match color_help [] nodes nodes graph with
      | None -> ()
      | Some(x) -> raise (FoundColoring x)