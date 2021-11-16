module type SetS = sig

  type 'a t

  val empty : 'a t

  val insert : 'a -> 'a t -> 'a t

  val elem : 'a -> 'a t -> bool

end


module type  TreeS = sig
  type 'a tree = Leaf
               | Fork of 'a tree * 'a * 'a tree

  type 'a t = 'a tree

  val empty : 'a t

  val insert : 'a -> 'a t -> 'a t

  val elem : 'a -> 'a t -> bool

  val height: 'a t -> int

  val size: 'a t -> int

end 
module TreeM : TreeS = struct

  type 'a tree = Leaf
               | Fork of 'a tree * 'a * 'a tree

  type 'a t = 'a tree

  let empty = Leaf

  let rec insert (x: 'a) (t: 'a tree): 'a tree = 
    match t with
      | Leaf -> Fork (Leaf, x, Leaf)
      | Fork(l,n,r) -> if x = n then t
         else if x < n then Fork (insert x l, n,  r)
                        else Fork (l, n, insert x r)

  let rec elem (ele: 'a) (t: 'a tree): bool = match t with 
    | Leaf -> false
    | Fork(l,n,r) -> ele = n || if ele < n then elem ele l else elem ele r


 let rec h t counter =
   match t with
     | Fork (left, n, right) -> max (h left (counter +1)) (h right ( counter +1))
     | Leaf -> counter+1

 let rec height t = 
  h t 0

let rec size t = 
  match t with 
    | Fork (left, n, right) -> 1 + size left + size right
    | Leaf -> 0


end

module TreeSet : SetS = TreeM


let implode (cs: char list) : string =
    String.concat "" (List.map  (String.make 1) cs)

  let explode (s: string) : char list =
    let l = String.length s
    in
    let rec f i = 
      if i = l then [] else s.[i] :: f (i+1)
    in f 0


(*check if the word is in the dictionary and returns it in a list*)
    let rec check_dict originalword (word: string)(dict) : string list=
      if  TreeM.elem word dict && originalword <> word then [word] else []


      (*tests the word with different letters, uses a tuple to hold begining and end of a list
      returns a list of new words made from word that are in the dictionary *)
    let rec test (word: (char list * char list)) (dict) (ans: string list): string list=
    match word with
      | (x1 , []) -> ans
      | (x1 , x2) -> match x2 with
          (*call test until x2 is empty making ans a list of tuples containing the word and changed word *)
          | [] -> []
          | x::xs -> test (x1@[x] , xs) dict (ans @ (check_dict (implode (x1@x2)) (implode (x1@[String.get "j" 0]@xs)) dict)@
          (check_dict (implode (x1@x2)) (implode (x1@[String.get "q" 0]@xs)) dict)@(check_dict (implode (x1@x2)) (implode (x1@[String.get "x" 0]@xs)) dict)@
          (check_dict (implode (x1@x2)) (implode (x1@[String.get "z" 0]@xs)) dict))


    (*quick check to see if the word is long enough *)
  let rec try_word (word: string) (dict) =
    if String.length word < 5 then [] else test ([],explode word) dict []
    


  (*creates set dictionary*)
  let rec create_dict (word_list: 'a list) (dict) =
    match word_list with
      | [] -> dict
      |x::xs -> create_dict xs (TreeM.insert x dict)


  (*call for answers but keeps dictionary the same*)
  let rec aws (word_list: string list) (answer:(string * string list) list) (dict): ( string * string list) list = 
    match word_list with 
        | [] -> answer                                                                      (*\/return list of changed words that work over 5 letters *)
        | x::xs -> if try_word x dict = [] then aws xs answer dict else aws xs (answer@[(x , (try_word x dict))])  dict


    (*calls aws because it needs more data types sent in *)
  let answers (word_list: string list) : (string * string list) list =
     aws word_list [] (create_dict word_list TreeM.empty)