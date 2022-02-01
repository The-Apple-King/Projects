(* Hwk 06.  Extend the construts below as specified.

   This a first version of the solution to Hwk 6.

   Any furter changes happened in repo-solutions.
 *)

 type value  
 = Int of int
 | Ref of value ref
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

 | LetRec of string * expr * expr
 | If of expr * expr * expr


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
 | LetRec (str, e1, e2) -> "LetRec (" ^ "\"" ^ str ^ "\", " ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ")"
 | If (e1, e2, e3) -> "If (" ^ serialize_expr e1 ^ ", " ^ serialize_expr e2 ^ ", " ^ serialize_expr e3 ^ ")"

(* Part 2: Free Variables
  ----------------------
*)




let rec freevars (e: expr) : string list =
 match e with
 | Val _ -> []

 | Let (str, e1, e2) -> freevars e1 @ List.filter (fun v -> v <> str) (freevars e2)
   | Lam (str, e1) -> List.filter (fun v -> v <> str) (freevars e1)
 | LetRec (str, e1, e2) -> List.filter (fun v -> v <> str) (freevars e1) @ List.filter (fun v -> v <> str) (freevars e2)

 | Add (e1, e2) -> (freevars e1)@(freevars e2)
 | Sub (e1, e2) -> (freevars e1)@(freevars e2)
 | Mul (e1, e2) -> (freevars e1)@(freevars e2)
 | Div (e1, e2) -> (freevars e1)@(freevars e2)
 | Not (e1) -> (freevars e1)
 | Lt (e1, e2) -> (freevars e1)@(freevars e2)
 | Eq (e1, e2) -> (freevars e1)@(freevars e2)
 | And (e1, e2) -> (freevars e1)@(freevars e2)
 | App (e1, e2) -> (freevars e1)@(freevars e2)

 | Id (e1) -> [e1] 
 
 | If (e1, e2, e3) ->(freevars e1)@(freevars e2)@(freevars e3)

  | Let (str, e1, e2) -> freevars e1 @ List.filter (fun v -> v <> str) (freevars e2)
    | Lam (str, e1) -> List.filter (fun v -> v <> str) (freevars e1)
  | LetRec (str, e1, e2) -> List.filter (fun v -> v <> str) (freevars e1) @ List.filter (fun v -> v <> str) (freevars e2)

  | Add (e1, e2) -> (freevars e1)@(freevars e2)
  | Sub (e1, e2) -> (freevars e1)@(freevars e2)
  | Mul (e1, e2) -> (freevars e1)@(freevars e2)
  | Div (e1, e2) -> (freevars e1)@(freevars e2)
  | Not (e1) -> (freevars e1)
  | Lt (e1, e2) -> (freevars e1)@(freevars e2)
  | Eq (e1, e2) -> (freevars e1)@(freevars e2)
  | And (e1, e2) -> (freevars e1)@(freevars e2)
  | App (e1, e2) -> (freevars e1)@(freevars e2)

  | Id (e1) -> [e1] 
  
  | If (e1, e2, e3) ->(freevars e1)@(freevars e2)@(freevars e3)




(* Part 3: Evaluation 
  ------------------
*)




 



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

   let rec lookup name env = 
     match env with
     | [] -> raise(UnboundVariable (Id(name)))
     | (str, x)::rest -> if name = str then x else lookup name rest

     let rec createvars vars env accum =
      match vars with
      | [] -> accum
      | x::xs -> createvars xs env accum@[(x, (lookup x env))] 

   let rec valuevars name v env accum =
    match env with
    | [] -> accum
    |(str, x)::xs -> if str = name then accum@[(name, v)]@xs else valuevars name v xs accum@[(str, x)]
     

 let rec eval (env: value_environment) (e:expr) : value =
   match e with
   | Val v -> v
   
   | Add (e1, e2) ->
      ( match eval env e1, eval env e2 with
        | Int v1, Int v2 -> Int (v1 + v2)
        | _ -> raise (IncorrectType e)
      )
 
   | Sub (e1, e2) ->
     ( match eval env e1, eval env e2 with
       | Int v1, Int v2 -> Int (v1 - v2)
       | _ -> raise (IncorrectType e)
     )
 
   | Mul (e1, e2) ->
     ( match eval env e1, eval env e2 with
       | Int v1, Int v2 -> Int (v1 * v2)
       | _ -> raise (IncorrectType e)
     )
 
  | Div (e1, e2) ->
    ( match eval env e1, eval env e2 with
      | Int v1, Int v2 -> if v2 <> 0 then Int (v1 / v2) else raise (DivisionByZero e)
      | _ -> raise (IncorrectType e)
    )
  | And (e1, e2) ->
    ( match eval env e1, eval env e2 with
      | Bool v1, Bool v2 -> Bool (v1 && v2)
      | _ -> raise (IncorrectType e)
    )

  | Eq (e1, e2) ->
    ( match eval env e1, eval env e2 with
      | Bool v1, Bool v2 -> Bool (v1 = v2)
      | Int v1, Int v2 -> Bool (v1 = v2)
      | _ -> raise (IncorrectType e)
    )

  | Lt (e1, e2) -> 
      ( match eval env e1, eval env e2 with
        | Int v1, Int v2 -> Bool(v1 < v2) 
        | _ -> raise (IncorrectType e)
      )

  | Let (str, e1, e2) ->
     ( match str, eval env e1, e2 with
     | (s, e1, e2) -> eval ((s, e1)::env) e2
     )
         
  | Id (str) ->
     lookup str env 
    
  | Lam (str, e1) -> Closure (str, e1, (createvars (freevars (Lam(str, e1))) env []))


   | App (e1, e2) ->
   ( match eval env e1, e2 with
   | Closure(str, ex1, env2), v -> eval (env2@[(str, eval env v)]) ex1
   | Ref(x), v -> (match !x with
        | Closure(str, ex1, env2) ->  eval ((str, eval env v)::env2) ex1 
        |_ -> raise(IncorrectType e))

   | _ -> raise(IncorrectType e)
   )
   (*
   let c1 = match eval env e1 with Ref f -> !f | Closure(s,e1,envc) -> Closure(s,e1,envc)
   in match c1, eval env e2 with
      | Closure(str, ex1, env2), v2 -> eval ((str,v2)::env2) ex1
      | _ -> raise(IncorrectType e1)
      *)


  | LetRec (str, e1, e2) -> 
      let recRef = ref(Int 999) in
        let c = eval ((str, Ref(recRef))::env) e1 in
        let () = recRef := c in eval ((str, Ref(recRef))::env) e2
  
  

  | If (e1, e2, e3) -> 
  ( match eval env e1, eval env e2, eval env e3 with
  |  Bool s1, s2, s3 -> if s1 then s2 else s3
  | _ -> raise(IncorrectType e)
  )
  
