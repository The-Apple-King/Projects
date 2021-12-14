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

(*uses the output of if statements to create a list of steps based on the current state *)
let accumulate state accum = 
  match state with
  | (x, y) -> if x = 0 then accum := !accum@[(Fill4GallonJugFromTap)];
  if y = 0 then accum := !accum@[(Fill3GallonJugFromTap)];
  if x < 4 && x > 0 then accum := !accum@[(Fill4GallonJugFromTap)]@[(Empty4GallonJugOnGround)];
  if y < 3 && y > 0 then accum := !accum@[(Fill3GallonJugFromTap)]@[(Empty3GallonJugOnGround)];
  if x = 4 then accum := !accum@[(Empty4GallonJugOnGround)];
  if y = 3 then accum := !accum@[(Empty3GallonJugOnGround)];
  if (4-x) >= y then accum := !accum@[(Empty3GallonJugInto4GallonJug)];
  if (4-x) < y then accum := !accum@[(Fill4GallonJugFrom3GallonJug)];
  if (3-y) >= x then accum := !accum@[(Empty4GallonJugInto3GallonJug)];
  if (3-y) < x then accum := !accum@[(Fill3GallonJugFrom4GallonJug)];
  !accum

let possible_steps state =
accumulate state (ref([]))

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


let rec playhelp max initial_state = 
  let rec go_from max toolong (state: state) (path)=
      if final_state state
      then Some path
      else if state = initial_state && toolong > 2 || toolong = max then None else 
  match possible_steps state with 
  | [a;b] -> (match go_from max (toolong+1) (runsolutions (a, state)) (path @ [(a, (runsolutions (a, state)))]) with
                 | None -> go_from max (toolong+1) (runsolutions (b, state)) (path @ [(b, (runsolutions (b, state)))])
                 | Some path' -> Some path'
                 )
  | [a;b;c] ->(match go_from max (toolong+1) (runsolutions (a, state)) (path @ [(a, (runsolutions (a, state)))]) with
                 | None -> (match go_from max (toolong+1) (runsolutions (b, state)) (path @ [(b, (runsolutions (b, state)))]) with
                    | None -> go_from max (toolong+1) (runsolutions (c, state)) (path @ [(c, (runsolutions (c, state)))])
                    | Some path' -> Some path')
                 | Some path'' -> Some path''
                 )
  | [a;b;c;d] ->(match go_from max (toolong+1) (runsolutions (a, state)) (path @ [(a, (runsolutions (a, state)))]) with
                 | None -> (match go_from max (toolong+1) (runsolutions (b, state)) (path @ [(b, (runsolutions (b, state)))]) with
                    | None -> (match go_from max (toolong+1) (runsolutions (c, state)) (path @ [(c, (runsolutions (c, state)))]) with
                      | None -> go_from max (toolong+1) (runsolutions (d, state)) (path @ [(d, (runsolutions (d, state)))])
                      | Some path' -> Some path')
                    | Some path'' -> Some path'')
                 | Some path''' -> Some path'''
                 )
  | [a;b;c;d;e] ->(match go_from max (toolong+1) (runsolutions (a, state)) (path @ [(a, (runsolutions (a, state)))]) with
                 | None -> (match go_from max (toolong+1) (runsolutions (b, state)) (path @ [(b, (runsolutions (b, state)))]) with
                    | None -> (match go_from max (toolong+1) (runsolutions (c, state)) (path @ [(c, (runsolutions (c, state)))]) with
                      | None -> (match go_from max (toolong+1) (runsolutions (d, state)) (path @ [(d, (runsolutions (d, state)))]) with
                         | None -> go_from max (toolong+1) (runsolutions (e, state)) (path @ [(e, (runsolutions (e, state)))])
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