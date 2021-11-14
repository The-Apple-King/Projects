# Homework 5: Reasoning about Correctness.

by, Owen Swearingen

# Problem 1

## given
    let rec prod (lst: int list) : int = match lst with  
    | [] -> 1  
    | y::ys -> y * prod ys

## prove
### base case
    - prod (l1 @ l2) = prod l1 * prod l2

    - base case l1 = []
    - prod [] @ l2 = prod l2 
      - by properties of list and append  
       
    - show prod []@l2 = prod [] * prod l2
    - prod l2 = 1 * prod l2  
      -by identity  

    - prod [] * prod l2 = prod l2  
      -by definition of prod

### inductive case l1 = x::xs
    - prod (x::xs)@l2 = prod x @ xs @ l2  
      -by properties of lists  

    - x* prod xs@l2  
      -by definition of prod  

    - x* prod xs * prod l2  
      -by inductive hypothesis  

    - = prod (x::xs) * prod l2  
      -by definition of prod


<!-- Barrier which makes it easier for me to read and edit -->

# Problem 2
## given

    let rec foldr (f: 'a -> 'b -> 'b) (lst: 'a list) (base: 'b) : 'b =  
    match lst with  
    | [] -> base  
    | x::xs -> f x (foldr f xs base)  

    let prod_fold (lst: int list) : int = foldr ( * ) lst 1  

    let rec prod (lst: int list) : int = match lst with  
    | [] -> 1  
    | y::ys -> y * prod ys  

## prove
### base case
    - prod lst = prod_fold lst   
    - prod [] = prod_fold []
    - prod [] = 1  
      by properties of prod
    - prod_fold [] = 1 
    - by properties of prod_fold
    - prod [] = prod_fold []
    - 1 = 1

### inductive case 
    - lst = x::xs
    - prod [x::xs] = x * prod [xs] 
    - by inductive hypothesis  
   
    - prod_fold [x::xs] = foldr ( * ) [x::xs] 1  
      -by properties of prod_fold  

    - foldr ( * ) [x::xs] 1 = x * foldr ( * ) xs 1  
      -by inductive hypothesis  

    - x * prod [xs] = x * foldr ( * ) xs 1  
      -by definitions of prod and foldr



<!-- Barrier which makes it easier for me to read and edit -->



# Problem 3
## given
    type nat = Zero | Succ of nat  
    
    let rec maximum (lst: nat list) : nat = match lst with  
    | [] -> Zero  
    | n::ns -> maxnat n (maximum ns)  

    maxnat Zero n = n  

    maxnat a (maxnat b c) = maxnat (maxnat a b) c  

## prove
 ### base case 
    - maximum (l1 @ l2) = maxnat (maximum l1) (maximum l2)
    
    - l1 = []
    - maximum [] @ l2 = maximum l2
    - by properties of list and append
    - show maximum []@l2 = maximum zero::l2
    - by identity
    - maximum zero::l2 = maxnat zero maximum l2
    - by definition of maximum

 ### inductive case  
    - l1 = [x]
    - maximum [x]@l2 = maximum x @ l2
    - by properties of lists 
    - maximum [x]@l2 = maxnat x (maximum (l2))
    - by definition of maximum
    - maxnat ([x]) (maximum l2) 
    - by inductive hypothesis
    - maximum ([x]@l2) = maxnat x maximum l2
    - by definition of maximum



<!-- Barrier which makes it easier for me to read and edit -->


# Problem 4
## part 1
    type 'a tree   
      = Leaf  
      | Fork of 'a tree * 'a * 'a tree  
    
      the principle of induction for this type is: for all t : 'a tree, P(t) holds if  
      P(Leaf), and  
    P(t1), and P(t2) implies P(Node(t1, v, t2) (for any value v of type 'a).  

## part 2
    type 'a rose_tree = Rose of 'a * 'a rose_tree list  
    
    the principle of induction for this type is: for all Rose: rose_tree, P(t) holds if  
    P(rose) implies P(Rose(v, rose_tree list)) for any value v of type 'a  

## part 3
    type 'a elf_tree = Empty  
    | Leaf of 'a  
    | Fork of 'a * 'a elf_tree * 'a elf_tree  

    the principle of induction for this type is: for all t : 'a tree, P(t) holds if  
    P(Leaf), and  
    P(t1), and P(t2) implies P(Node(v, t1, t2) (for any value v of type 'a).  


<!-- Barrier which makes it easier for me to read and edit -->


# Problem 5
## given
    let rec height_rec (t: 'a elf_tree) : int = match t with
    | Empty -> 0
    | Leaf _ -> 1
    | Fork (_, l, r) -> 1 + max (height_rec l) (height_rec r)

    let rec reduce t (func) (x) = 
    match t with 
    | Empty -> x
    | Leaf p -> func p (reduce Empty (func) x) (reduce Empty (func) x)
    | Fork (n,l,r) -> func n (reduce l func x) (reduce r func x)


    let height t = reduce t ( fun _ l r -> 1 + max l r) 0 
    prove
    height t = height rect t

## base case 
    - t = leaf v
    - height (leaf v) = reduce leaf v ( fun _ l r -> 1 + max l r) 0 
    - by induction
    - reduce leaf v ( fun _ l r -> 1 + max l r) 0 = func p (reduce Empty (func) x) (reduce Empty (func) x)
    - by induction
    - func p (reduce Empty (func) x) (reduce Empty (func) x) = func p 0 0
    - by induction
    - fun p 0 0 = 1 + max 0 0= 1 + 0 = 1
    - by properties of fun
    - height leaf v = 1
 
    - height_rec leaf v = 1
    -  by definition of height rec
    -  height leaf v = height rec leaf v

## inductive case 
    - t = Fork(v, leaf1, leaf2)
    - height Fork(v, leaf1 leaf2) = reduce Fork(v, leaf1 leaf2) ( fun _ l r -> 1 + max l r) 0  
      -by induction
    - reduce Fork(v, leaf1 leaf2) ( fun _ l r -> 1 + max l r) 0 = 1 + max (reduce Leaf1 fun 0) (reduce    - Leaf2 fun 0)
    - (reduce Leaf1 fun 0)  = 1 as shown in base case so
    - 1 + max (reduce Leaf1 fun 0) (reduce Leaf2 fun 0) = 1 + max 1 1 = 1 + 1
    - height Fork(v,leaf1,leaf2) = 2
     
    - height_rec Fork(v, leaf1, leaf2) = 1 + max height_rec leaf1 height rec leaf2
    - height_rec leaf = 1 as shown in base case
    - 1+max height_rec leaf1 height rec leaf2 = 1+ max 1 1
      -by induction
    - 1+ max 1 1 = 1 + 1 = 2
      -by properties of max
    - height Fork(v, leaf1, leaf2) = height_rec Fork(v, leaf1, leaf2)