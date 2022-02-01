open Set

module ListM : SetS = struct

  type 'a t = 'a list

  let empty = []

  let insert (x: 'a) (set: 'a list): 'a list = set @ [x]

  let rec elem (ele: 'a) (set: 'a list): bool = match set with 
  | [] -> false
  | x::xs -> ele = x || elem ele xs

end
