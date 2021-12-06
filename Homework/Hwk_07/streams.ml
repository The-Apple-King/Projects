(* The code below is from Professor Eric Van Wyk. *)
type 'a hidden = Value of 'a
               | Thunk of (unit -> 'a)

type 'a lazee = 'a hidden ref

let delay (unit_to_x: unit -> 'a) : 'a lazee =
  ref ( Thunk unit_to_x )

let force (l: 'a lazee) : unit = match !l with
  | Value _ -> ()
  | Thunk f -> l := Value (f ())

let demand (l: 'a lazee) : 'a =
  force l;
  match !l with
  | Value v -> v
  | Thunk _ -> failwith "This should not happen."

type 'a stream = Cons of 'a * 'a stream lazee

let rec take (n: int) (s: 'a stream) : 'a list =
  match n with
  | 0 -> []
  | _ -> (match s with
          | Cons (h, t) -> h :: take (n-1) (demand t)
         )

let rec map (f: 'a -> 'b) (s: 'a stream) : 'b stream =
  match s with
  | Cons (h, t) -> Cons (f h, delay (fun () -> map f (demand t) ) )

let rec zip (f: 'a -> 'b ->'c) (s1: 'a stream) (s2: 'b stream) :
          'c stream =
  match s1, s2 with
  | Cons (h1, t1), Cons (h2, t2) ->
     Cons (f h1 h2, delay (fun () -> zip f (demand t1) (demand t2)))

let rec filter (f: 'a -> bool) (s: 'a stream) : 'a stream = 
  match s with
  | Cons (h, t) ->
     let rest = delay (fun () -> filter f (demand t))
     in
     if f h 
     then Cons (h, rest)
     else demand rest

let rec from n =
  Cons ( n, delay ( fun () -> from (n+1) ) )

let nats = from 1




(* The code below is from Owen Swearingen *)

(*using cubes a lot a function to do so makes it easier*)
let cube n = n*n*n

let rec cubes_from n = 
  Cons ( (n), delay ( fun () -> cubes_from (n+1) ) )

let cubes_from_zip n =
  zip (fun x1 x2 -> x1*x2*x1) (from n) (from n)

let cubes_from_map n = 
  map (cube) (from n)

(*
  let rec from n =
    Cons ( n, delay ( fun () -> from (n+1) ) )

  let rec drop n stream =
    if n > 0 then(
      match stream with 
      Cons(h,t) -> drop (n-1) demand t)
    else
      (match stream with
      Cons(h,t) -> drop 0 Cons(h, demand t))



let drop_until func stream =
  if func = false 
  then (match stream with
    Cons(h,t) -> drop_until func demand t)
  else ( match stream with
  Cons(h,t) -> drop_until func Cons(h, demand t))

*)

let rec arith_help n incr runs = 
  Cons ( (n), delay ( fun () -> cubes_from (n+1) ) )
let arith_seq n incr = arith_help n incr 0



let sieve stream = 
sieve (map (fun x n -> if n mod x = 0 then [] else x ) stream)

let primes = sieve (from 2)

