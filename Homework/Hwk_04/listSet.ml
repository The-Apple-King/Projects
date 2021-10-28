open Set

module ListM : SetS = struct

  type 'a t = 'a list

  let empty = []

  let insert _ = raise (Failure "complete this")

  let elem _ = raise (Failure "complete this")

end
