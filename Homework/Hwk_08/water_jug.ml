(*The state is the current amount of water in each jug at each step *)
type operation = Fill4GallonJugFromTap
          | Fill3GallonJugFromTap
          | Empty4GallonJugOnGround
          | Empty3GallonJugOnGround
          | Fill4GallonJugFrom3GallonJug
          | Fill3GallonJugFrom4GallonJug
          | Empty4GallonJugInto3GallonJug
          | Empty3GallonJugInto4GallonJug

type state = int * int


let describe (four:int) (three:int) : string = 
  let describe' jug amount =
    "The " ^ string_of_int jug ^ " gallon jug " ^
    match amount with
    | 0 -> " is empty"
    | 1 -> " contains 1 gallon"
    | x -> " contains " ^ string_of_int x ^ " gallons"
  in
  describe' 4 four ^ ", " ^ describe' 3 three ^ "."

(* some functions that you may find helpful *)
let initial_state : state = (0, 0)

let final_state ((x,y): state) : bool = x = 2

let valid_state ((x,y): state) : bool 
  = x >= 0 && x <= 4 && y >= 0 && y <= 3


(*the outcomes of each option *)
let runsolutions (op,state) =
match op with
| Fill4GallonJugFromTap ->
  (match state with
  | (x,y) -> (4, y))

| Fill3GallonJugFromTap ->
  (match state with
  | (x,y) -> (x, 3))

| Empty4GallonJugOnGround ->
  (match state with
  | (x,y) -> (0, y))

| Empty3GallonJugOnGround -> 
  (match state with
  | (x,y) -> (x, 0))

| Empty3GallonJugInto4GallonJug ->
  (match state with
  | (x,y) -> ((x+y), 0))

| Fill4GallonJugFrom3GallonJug ->
  (match state with
  | (x,y) -> ((x+(4-x)), (y-(4-x))))

| Empty4GallonJugInto3GallonJug ->
  (match state with
  | (x,y) -> (0, (y+x)))

| Fill3GallonJugFrom4GallonJug ->
  (match state with
  | (x,y) -> ((x-(3-y)), (y+(3-y))))


(*uses the output of if statements to create a list of steps based on the current state *)
let accumulate state accum = 
  match state with
  | (x, y) -> if x = 0 then accum := !accum@[(Fill4GallonJugFromTap, runsolutions (Fill4GallonJugFromTap, state))];
  if y = 0 then accum := !accum@[(Fill3GallonJugFromTap, runsolutions (Fill3GallonJugFromTap, state))];
  if x < 4 && x > 0 then accum := !accum@[(Fill4GallonJugFromTap, runsolutions (Fill4GallonJugFromTap, state))]@[(Empty4GallonJugOnGround, runsolutions (Empty4GallonJugOnGround, state))];
  if y < 3 && y > 0 then accum := !accum@[(Fill3GallonJugFromTap, runsolutions (Fill3GallonJugFromTap, state))]@[(Empty3GallonJugOnGround, runsolutions (Empty3GallonJugOnGround, state))];
  if x = 4 then accum := !accum@[(Empty4GallonJugOnGround, runsolutions (Empty4GallonJugOnGround, state))];
  if y = 3 then accum := !accum@[(Empty3GallonJugOnGround, runsolutions (Empty3GallonJugOnGround, state))];
  if (4-x) >= y then accum := !accum@[(Empty3GallonJugInto4GallonJug, runsolutions (Empty3GallonJugInto4GallonJug, state))];
  if (4-x) < y then accum := !accum@[(Fill4GallonJugFrom3GallonJug, runsolutions (Fill4GallonJugFrom3GallonJug, state))];
  if (3-y) >= x then accum := !accum@[(Empty4GallonJugInto3GallonJug, runsolutions (Empty4GallonJugInto3GallonJug, state))];
  if (3-y) < x then accum := !accum@[(Fill3GallonJugFrom4GallonJug, runsolutions (Fill3GallonJugFrom4GallonJug, state))];
  !accum

let possible_steps state =
accumulate state (ref([]))

(*playhelp increments max in order to search for the smallest number of steps*)
let rec playhelp max initial_state = 
  (*go_from searches each possible step increments path and tests each possible outcome to find a solution
  toolong tests the current location in the loop
  max is the maximum amount of loops allowed which will increase each time it fails *)
  let rec go_from max toolong (state: state) (path)=
      if final_state state
      then Some path
      else if state = initial_state && toolong > 2 || toolong = max then None else 
  match possible_steps state with 
  | [(a, state);(b, state1)] -> (match go_from max (toolong+1) state (path @ [(a, state)]) with
                 | None -> go_from max (toolong+1) state1 (path @ [(b,  state1)])
                 | Some path' -> Some path'
                 )
  | [(a, state);(b, state1);(c, state2)] ->(match go_from max (toolong+1) state (path @ [(a, state)]) with
                 | None -> (match go_from max (toolong+1) state1 (path @ [(b,state1)]) with
                    | None -> go_from max (toolong+1) state2 (path @ [(b, state2)])
                    | Some path' -> Some path')
                 | Some path'' -> Some path''
                 )
  | [(a, state);(b, state1);(c, state2);(d, state3)] ->(match go_from max (toolong+1) state (path @ [(a, state)]) with
                 | None -> (match go_from max (toolong+1) state1 (path @ [(b, state1)]) with
                    | None -> (match go_from max (toolong+1) state2 (path @ [(c, state2)]) with
                      | None -> go_from max (toolong+1) state3 (path @ [(d, state3)])
                      | Some path' -> Some path')
                    | Some path'' -> Some path'')
                 | Some path''' -> Some path'''
                 )
  | [(a, state);(b, state1);(c, state2);(d, state3);(e, state4)] ->(match go_from max (toolong+1) state (path @ [(a, state)]) with
                 | None -> (match go_from max (toolong+1) state1 (path @ [(b, state1)]) with
                    | None -> (match go_from max (toolong+1) state2 (path @ [(c, state2)]) with
                      | None -> (match go_from max (toolong+1) state3 (path @ [(d, state3)]) with
                         | None -> go_from max (toolong+1) state4 (path @ [(e, state4)])
                         | Some path' -> Some path')
                      | Some path'' -> Some path'')
                    | Some path''' -> Some path''')
                 | Some path'''' -> Some path''''
                 )
  | _ -> raise (Failure "deal with 3 moves?")
  in
  if go_from max 0 initial_state [] = None then playhelp (max+1) initial_state else go_from max 0 initial_state []

  let play initial_state =
  playhelp 1 initial_state