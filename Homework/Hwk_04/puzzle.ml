
open Set
open Util

module type PuzzleS = sig

  val answers : string list -> (string * string list) list

end

module PuzzleF (S: SetS) : PuzzleS = struct

  let answers (word_list: string list) : (string * string list) list = 
    raise (Failure "Finish implementation of answers")

end
