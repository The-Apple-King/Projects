type 'a tree = Tip of 'a
      | Split of 'a tree * 'a tree * 'a tree

      let t3 : 'a tree =
        Split (Tip(5), Split (Tip(3),Tip(10),Tip(15)),Tip(4))
                    

let min tree = 3

let rec repaddmin tree =
      let rec ram tree ogtree =
      match tree with
      | Tip(x) -> Tip(x + min ogtree)
      | Split(a,b,c) -> Split((ram a ogtree), (ram b ogtree), (ram c ogtree)) in
match tree with
| Tip(x) -> Tip(x+ min tree)
| Split(a,b,c) -> Split((ram a tree), (ram b tree), (ram c tree))