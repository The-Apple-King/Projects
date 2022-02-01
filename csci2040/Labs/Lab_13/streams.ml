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

let rec from_by_2 n =
  Cons ( n, delay ( fun () -> from_by_2 (n+2) ) )

let evens = 
  from_by_2 2

let evens_filter =
  filter (fun n -> (n mod 2 = 0))  nats
 
let rec evens_map =
  map (fun n -> n*2) nats

let evens_zip =
  zip (fun x1 x2 -> x1+x2) nats nats

  let rec pp nats = match nats with 
  |Cons(h,t) -> match demand t with 
      |Cons(h2,t2) -> Cons(h2, delay (fun () -> pp (demand t2)) )

let evens_pick =
  pp nats
