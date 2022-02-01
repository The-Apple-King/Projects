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
let cube (n: int): int = n*n*n

<<<<<<< HEAD
let rec cubes_from n = 
  Cons ( cube (n), delay ( fun () -> cubes_from (n+1) ) )
=======
let rec cubes_from (n: int): 'a stream  = 
  Cons ( (cube n), delay ( fun () -> cubes_from (n+1) ) )
>>>>>>> 3a129bada35b9d0b1f0c008faf93891389d34c5e

let cubes_from_zip (n: int): 'a stream  =
  zip (fun x1 x2 -> x1*x2*x1) (from n) (from n)

let cubes_from_map (n: int): 'a stream  = 
  map (cube) (from n)

<<<<<<< HEAD


  let rec drop n stream =
    match n with 
    | 0 -> stream
    | _ -> match stream with 
    | Cons (h,t) -> drop (n-1) (demand t)

=======

  let rec drop (n: int) (stream: 'a stream): 'a stream =
    match n with
    | 0 -> stream
    | _ -> match stream with 
        | Cons (h,t) -> drop (n-1) (demand t)
>>>>>>> 3a129bada35b9d0b1f0c008faf93891389d34c5e


let rec drop_until func stream =
  match stream with 
  | Cons (h,t) -> if func h = false then drop_until func (demand t) else stream

<<<<<<< HEAD


let rec arith_help n incr runs = 
  Cons ( (n + (incr * runs)), delay ( fun () -> arith_help n incr (runs+1) ) )
let arith_seq n incr = arith_help n incr 0
=======
let rec drop_until (func) (stream: 'a stream): 'a stream =
  match stream with 
  | Cons(h,t) -> if func h = false 
  then drop_until func (demand t)
  else stream


>>>>>>> 3a129bada35b9d0b1f0c008faf93891389d34c5e


let rec arith_seq (n:int) (incr:int): 'a stream = 
Cons (n, delay ( fun () -> arith_seq (n+incr) (incr) ))

<<<<<<< HEAD
let rec sieve stream = 
match stream with 
| Cons (h,t) -> Cons (h,(delay (fun () ->  sieve (filter (fun x -> if h mod x = 0 && h<> x then true else false) (demand t)))))
=======

let rec sieve (stream: 'a stream): 'a stream  = 
  match stream with 
  | Cons(h,t) -> Cons(h, delay (fun () -> sieve (demand (delay (fun () -> filter ( fun (x) -> x mod h <> 0 ) (demand t))))))
>>>>>>> 3a129bada35b9d0b1f0c008faf93891389d34c5e

let primes = sieve (from 2)

