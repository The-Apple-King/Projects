let t1 : int rose_tree =
  Rose (2, [ Rose (1, [ Rose (5, []); Rose (7, []) ] );
               Rose (3, []);
               Rose (4, []);
             ]   )

let t2 : string rose_tree = 
  Rose ("r", [ Rose ("abc", [ Rose ("xy", []); Rose ("z", []) ] );
               Rose ("hello", []);
               Rose ("goodbye", [])
             ]
    )

let t3 : char rose_tree = 
  Rose ('r', [ Rose ('a', [ Rose ('m', []); Rose ('n', []) ] );
               Rose ('b', [ Rose ('o', []); Rose ('p', []) ] );
               Rose ('c', [ Rose ('x', []); Rose ('y', []) ] )
             ]
    )