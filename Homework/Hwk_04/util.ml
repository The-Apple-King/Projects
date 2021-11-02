
module type UtilS = sig
  val implode: char list -> string

  val explode: string -> char list

  val read_file: string -> char list

  val split_by: ('a -> bool) -> 'a list -> 'a list list

  val read_words: string -> string list
end

module UtilM : UtilS = struct

  let implode (cs: char list) : string =
    String.concat "" (List.map  (String.make 1) cs)

  let explode (s: string) : char list =
    let l = String.length s
    in
    let rec f i = 
      if i = l then [] else s.[i] :: f (i+1)
    in f 0

  let read_file (file_name: string) : char list =
    let ic = open_in file_name 
    in 
    let rec read_chars ic =
      try 
        let next_char = input_char ic
        in next_char :: read_chars ic
      with 
        _ -> [] 
    in read_chars ic



  let rec splitletter (output:'a list) (word: string)  (func) (start:int) (i:int): string list =
  if i< String.length word then 
  if func String.get word i then splitletter (output :: String.sub word start (i-start)) word func (i+0) (i+1)
  else splitletter output word func start (i+1)
  else output :: String.sub word start (i-start)

(*breaks list into list of lists based on input*)
  let rec split_by (func) (wordlst: string list): 'a list list = 
  match wordlst with
  | [] -> []
  | x::xs -> splitletter [] x func 0 0 :: split_by func xs
  
     

  let read_words (file_name: string) : string list =
    let is_whitespace c = match c with
      | ' ' | '\t' | '\n' | '\r' -> true
      | _ -> false
    in
    List.map implode (split_by is_whitespace (read_file file_name))
end
