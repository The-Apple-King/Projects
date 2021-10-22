(* You are welcome to read this file, but you do not need
   to understand (yet) its contents.  We will discuss 
   several aspects of this later in the semester. For now
   you only need to use it, not understand it.
 *)

open Tree

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

let some_tests =
  [ check_test (fun () -> size t2 = 4)
                         "size t2 = 4";
    check_test (fun () -> sum t1 = 14)
                         "sum t1 = 14";
    check_test (fun () -> product t1 = 120)
                         "product t1 = 120";
    check_test (fun () -> char_count t2 = 8)
                         "char_count t2 = 8";
    check_test (fun () -> height t1 = 4)
                         "height t1 = 4";
    check_test (fun () -> perfect_balance t1 = false)
                         "perfect_balance t1 = false";
    check_test (fun () -> perfect_balance t3 = true)
                         "perfect_balance t3 = true";
    check_test (fun () -> maximum t1 = Some 5)
                         "maximum t1 = Some 5";
    check_test (fun () -> maximum t4 = None)
                         "maximum t4 = None"
  ]


let run_tests tests = List.iter (fun f -> f ()) tests

let _ = run_tests some_tests


