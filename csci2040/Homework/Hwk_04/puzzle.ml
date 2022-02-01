
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
    | (pre , []) -> ans
    | (pre , suf) -> match suf with
        (*call test until suf is empty making ans a list of tuples containing the word and changed word *)
        | [] -> []
        | char::xs -> test (pre@[char] , xs) dict (ans @ (check_dict (UtilM.implode (pre@suf)) (UtilM.implode (pre@['j']@xs)) dict)@
        (check_dict (UtilM.implode (pre@suf)) (UtilM.implode (pre@['q']@xs)) dict)@(check_dict (UtilM.implode (pre@suf)) (UtilM.implode (pre@['x']@xs)) dict)@
        (check_dict (UtilM.implode (pre@suf)) (UtilM.implode (pre@['z']@xs)) dict))


  (*creates set dictionary*)
  let rec create_dict (word_list: 'a list) (dict) =
    match word_list with
      | [] -> dict
      |x::xs -> create_dict xs (S.insert x dict)


  (*call for answers but keeps dictionary the same*)
  let rec aws (word_list: string list) (answer:(string * string list) list) (dict): ( string * string list) list = 
    match word_list with 
        | [] -> answer                                                                      (*\/return list of changed words that work over 5 letters *)
        | word::xs -> if String.length word < 5 && test ([],UtilM.explode word) dict [] = [] then aws xs answer dict else aws xs (answer@[(word , (test ([],UtilM.explode word) dict []))])  dict


    (*calls aws because it needs more data types sent in *)
  let answers (word_list: string list) : (string * string list) list =
     aws word_list [] (create_dict word_list S.empty)
      
    (*rename variables condense a couple of functions
    Daniel Kong
    there was one other kid but i didn't get his name*)
end
(*simplify funcions and collapse them down*)
