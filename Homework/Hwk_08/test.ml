(*the outcomes of each option *)
let runsolutions (x,state) =
match x with
| Fill4GallonJugFromTap ->
  match state with
  | (x,y) -> (4,y)

| Fill3GallonJugFromTap ->
  match state with
  | (x,y) -> (x,3)

| Empty4GallonJugOnGround ->
  match state with
  | (x,y) -> (0,y)

| Empty3GallonJugOnGround -> 
  match state with
  | (x,y) -> (x,0)

| Empty3GallonJugInto4GallonJug ->
  match state with
  | (x,y) -> ((x+y), 0)

| Fill4GallonJugFrom3GallonJug ->
  match state with
  | (x,y) -> ((x+(4-x)), (y-(4-x)))

| Empty3GallonJugInto4GallonJug ->
  match state with
  | (x,y) -> (0, (y+x))

| Fill3GallonJugFrom4GallonJug ->
  match state with
  | (x,y) -> ((x-(3-y)),(y+(3-y)))
