
open Set
open Util

module type PuzzleS = sig

  val answers : string list -> (string * string list) list

end

module PuzzleF (S: SetS) : PuzzleS = struct

    (*check if the word is in the dictionary and returns it in a list*)
    let rec check_dict originalword (word: string)(dict) : string list=
      if  S.elem word dict && originalword <> word then [word] else []


      (*tests the word with different letters, uses a tuple to hold begining and end of a list
      returns a list of new words made from word that are in the dictionary *)
    let rec test (word: (char list * char list)) (dict) (ans: string list): string list=
    match word with
      | (x1 , []) -> ans
      | (x1 , x2) -> match x2 with
          (*call test until x2 is empty making ans a list of tuples containing the word and changed word *)
          | [] -> []
          | x::xs -> test (x1@[x] , xs) dict (ans @ (check_dict (UtilM.implode (x1@x2)) (UtilM.implode (x1@[String.get "j" 0]@xs)) dict)@
          (check_dict (UtilM.implode (x1@x2)) (UtilM.implode (x1@[String.get "q" 0]@xs)) dict)@(check_dict (UtilM.implode (x1@x2)) (UtilM.implode (x1@[String.get "x" 0]@xs)) dict)@
          (check_dict (UtilM.implode (x1@x2)) (UtilM.implode (x1@[String.get "z" 0]@xs)) dict))


    (*quick check to see if the word is long enough *)
  let rec try_word (word: string) (dict) =
    if String.length word < 5 then [] else test ([],UtilM.explode word) dict []
    


  (*creates set dictionary*)
  let create_dict (word_list: 'a list) (dict) =
    match word_list with
      | [] -> dict
      |x::xs -> S.insert x dict


  (*call for answers but keeps dictionary the same*)
  let rec aws (word_list: string list) (answer:(string * string list) list) (dict): ( string * string list) list = 
    match word_list with 
        | [] -> answer                                                                      (*\/return list of changed words that work over 5 letters *)
        | x::xs -> if try_word x dict = [] then aws xs answer dict else aws xs (answer@[(x , (try_word x dict))])  dict


    (*calls aws because it needs more data types sent in *)
  let answers (word_list: string list) : (string * string list) list =
     aws word_list [] (create_dict word_list S.empty)
      

end
(*simplify funcions and collapse them down*)
