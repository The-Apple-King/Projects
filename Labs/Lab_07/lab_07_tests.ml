(* You are welcome to read this file, but you do not need
   to understand (yet) its contents.  We will discuss 
   several aspects of this later in the semester. For now
   you only need to use it, not understand it.
 *)

open Lab_07

type test = unit -> unit

let check_test (f: unit -> bool) (f_str: string) : test =
  fun () ->
  (try
     (if f () then
        print_endline ("PASSED: " ^ f_str)
      else
        print_endline ("FAILED: " ^ f_str)
     )
   with
   | _ -> print_endline ("FAILED, exception raised: " ^ f_str)
  )

let some_tests = [
    check_test (fun () -> 
        all_suffixes ['c'; 'a'; 'r'] = [['c'; 'a'; 'r']; ['a'; 'r']; ['r']; []])
       "all_suffixes ['c'; 'a'; 'r'] =\n    [['c'; 'a'; 'r']; ['a'; 'r']; ['r']; []]";
    check_test (fun () -> 
        all_suffixes [5; 6; 7] = [[5; 6; 7]; [6; 7]; [7]; []])
       "all_suffixes [5; 6; 7] = [[5; 6; 7]; [6; 7]; [7]; []]";
    check_test (fun () -> 
        all_suffixes [] = [ [] ])
       "all_suffixes [] = [ [] ])";

    check_test (fun () ->
        all_prefixes ['c'; 'a'; 'r'] = [['c'; 'a'; 'r']; ['c'; 'a']; ['c']; []])
       "all_prefixes ['c'; 'a'; 'r'] =\n   [['c'; 'a'; 'r']; ['c'; 'a']; ['c']; []])";
    check_test (fun () ->
        all_prefixes [5; 6; 7] = [[5; 6; 7]; [5; 6]; [5]; []])
       "all_prefixes [5; 6; 7] = [[5; 6; 7]; [5; 6]; [5]; []]";
    check_test (fun () -> 
        all_prefixes [] = [ [] ])
       "all_prefixes [] = [ [] ])";

    check_test (fun () ->
        all_parts ['c'; 'a'; 'r'] = [(['c'; 'a'; 'r'], []); (['c'; 'a'], ['r']); (['c'], ['a'; 'r']); ([], ['c'; 'a'; 'r'])])
       "all_parts ['c'; 'a'; 'r'] =\n  [ (['c'; 'a'; 'r'], []);\n    (['c'; 'a'], ['r']);\n    (['c'], ['a'; 'r']);\n    ([], ['c'; 'a'; 'r']) ]";

    check_test (fun () ->
        all_parts [5; 6; 7] = [([5; 6; 7], []); ([5; 6], [7]); ([5], [6; 7]); ([], [5; 6; 7])]) 
       "all_parts [5; 6; 7] =\n  [([5; 6; 7], []);\n   ([5; 6], [7]);\n   ([5], [6; 7]);\n   ([], [5; 6; 7]) ]";

    check_test (fun () -> 
        all_parts [] = [ ([], []) ])
       "all_parts [] = [ ([], []) ]";

  ]


let run_tests tests = List.iter (fun f -> f ()) tests

let _ = run_tests some_tests



