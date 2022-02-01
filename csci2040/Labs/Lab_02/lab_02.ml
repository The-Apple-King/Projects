let circle_circum_v1 r =
  (r+.r)*.3.14




let circle_circum_v2 r pi =
  (r+.r)*.pi

let rec power x y = 
  if y = 1.0 then x 
  else x *. power x (y -. 1.0)

let cube x = 
  power x 3.0
    
