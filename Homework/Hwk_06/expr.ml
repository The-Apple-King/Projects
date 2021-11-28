(* Hwk 06.  Extend the construts below as specified.

   This a first version of the solution to Hwk 6.

   Any furter changes happened in repo-solutions.
 *)

type value 
  = Int of int
  | Bool of bool
  | Closure of string * expr * value_environment

and value_environment = (string * value) list
                               
and expr 
  = Val of value

  | Add of expr * expr
  | Sub of expr * expr
  | Mul of expr * expr
  | Div of expr * expr 

  | Lt  of expr * expr
  | Eq  of expr * expr
  | And of expr * expr
  | Not of expr

  | Let of string * expr * expr
  | Id  of string

  | App of expr * expr
  | Lam of string * expr

(* These 2 are for part 3, uncomment them when you start that part *)
(*
  | LetRec of string * expr * expr
  | If of expr * expr * expr
*)

(* These 5 are for part 4, uncomment them when you start that part *)
(*
  | Nil
  | Cons of expr * expr
  | Head of expr
  | Tail of expr
  | IsEmpty of expr
*)


(* Part 1: Serialize 
   -----------------
 *)

let rec serialize_value (v: value) : string =
  match v with
  | Int i -> "Int " ^ string_of_int i
  | Bool i -> if (i = true) then "Bool true" else "Bool false"


let rec serialize_expr (e: expr) : string =
  match e with
  | Val v -> "Val (" ^ (serialize_value v) ^ ")"

  | Add (e1, e2) -> "Add (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | Sub (e1, e2) -> "Sub (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | Mul (e1, e2) -> "Mul (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | Div (e1, e2) -> "Div (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | Not (e1) -> "Not (" ^ serialize_expr e1 ^ ")"
  | Let (str, e1, e2) -> "Let (" ^ "\"" ^ str ^ "\""^ ", " ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | Lt (e1, e2) -> "Lt (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | Lam (str, e1) -> "Lam (" ^ "\"" ^ str ^ "\"" ^ ", " ^ serialize_expr e1 ^ ")"
  | Eq (e1, e2) -> "Eq (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | And (e1, e2) -> "And (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
  | Id (e1) -> "Id " ^ "\"" ^ e1 ^ "\""
  | App (e1, e2) -> "App (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"


(* Part 2: Free Variables
   ----------------------
 *)


let rec freevars (e: expr) : string list =
  match e with
  | Val _ -> []




(* Part 3: Evaluation 
   ------------------
 *)
 
 type environment = (string * int) list

 let rec lookup (name: string) (env: environment) : int =
  (*raise the unbound variable exception here*)
   match env with
   | [] -> raise (Failure ("Identifier " ^ name ^ " not found."))
   | (n,v) :: rest ->
      if n = name then v
      else lookup name rest
 
 let rec eval (e: expr) (env: environment) : int =
   match e with
   | Num n -> n
   | Id x -> lookup x env
   | Add (e1, e2) -> if e1 = e2 (*both type int test*)then  (eval e1 env) + (eval e2 env) else raise IncorrectType
   | Sub (e1, e2) -> if e1 = e2 (*both type int test*)then  (eval e1 env) - (eval e2 env) else raise IncorrectType
   | Mul (e1, e2) -> if e1 = e2 (*both type int test*)then  (eval e1 env) * (eval e2 env) else raise IncorrectType
   | Div (e1, e2) -> if e1 = e2 (*both type int test*)then  (if(eval e2 env <> 0) then (eval e1 env) / (eval e2 env) else raise DivisionByZero) else raise IncorrectType
   | And (e1, e2) -> if (e1 = e2 && e1 = Bool(*both type bool test*)) 
   | Eq (e1, e2) -> (*not sure what this does*)
   | App
   | Lam
   | Let (x, e1, e2) -> 
      let v = eval e1 env in
      let env' = (x, v) :: env in
      eval e2 env'


exception DivisionByZero of expr
exception UnboundVariable of expr
exception IncorrectType of expr

(* The following 2 exceptions are used in part 4 in
   evaluating lists. You can disregard them until then.
 *)
exception HeadOfEmptyList of expr
exception TailOfEmptyList of expr


let serialize_excp (e: exn) : string =
  match e with
  | DivisionByZero e -> "DivisionByZero (" ^ serialize_expr e ^ ")"
  | UnboundVariable e -> "UnboundVariable (" ^ serialize_expr e ^ ")"
  | IncorrectType e -> "IncorrectType (" ^ serialize_expr e ^ ")"
  | Division_by_zero -> "OCaml built-in Division_by_zero exception"

  (* These are not needed until part 4 and can be disregared until then *)
  | HeadOfEmptyList e -> "HeadOfEmptyList (" ^ serialize_expr e ^ ")"
  | TailOfEmptyList e -> "TailOfEmptyList (" ^ serialize_expr e ^ ")"

  | _ -> "Unexpected Exception"


let rec eval (env: value_environment) (e:expr) : value =
  match e with
  | Val v -> v

  | Add (e1, e2) ->
     ( match eval env e1, eval env e2 with
       | Int v1, Int v2 -> Int (v1 + v2)
       | _ -> raise (IncorrectType e)
     )

