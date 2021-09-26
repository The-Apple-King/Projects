(* You are welcome to read this file, but you do not need
   to understand (yet) its contents.  We will discuss 
   several aspects of this later in the semester. For now
   you only need to use it, not understand it.
 *)

open Hwk_01

type test = unit -> unit

let eqf (f1: float) (f2: float) : bool = 
  (* We will not check floating point values for exact
     equality since rounding errors can derail this method.
     Instead we determine that the values are "close enough"
     together by checking that the absolute value of their 
     difference is within a specified value, `epsilon`.
   *)
  let epsilon = 0.01
  in
  if f1 > f2 then
    ((f1 -. f2) < epsilon) 
  else
    ((f2 -. f1) < epsilon) 

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

let check_excp (f: unit -> bool) (f_str: string) (msg_prefix: string): test =
  let check_msg m mp = 
    let mp_length = String.length mp
    in
    if mp_length > String.length m 
    then false
    else mp = String.sub m 0 mp_length
  in

  fun () ->
  (let result = 
     try f () with
     | Invalid_argument msg -> check_msg msg msg_prefix
     | _ -> false
   in 
   if result then
     print_endline ("PASSED, exception raised: " ^ f_str)
   else
     print_endline ("FAILED, no exception or incorrect exception: " ^ f_str)
  )

let some_tests =
  [ check_test (fun () -> sum [1; 2; 3; 4] = 10)
                         "sum [1; 2; 3; 4] = 10";
    check_test (fun () -> eqf (sumf [1.0; 2.0; 3.0; 4.0]) 10.0)
                         "eqf (sumf [1.0; 2.0; 3.0; 4.0]) 10.0";
    check_test (fun () -> product [2; 3; 4] = 24)
                         "product [2; 3; 4] = 24";
    check_test (fun () -> eqf (productf [2.0; 3.0; 4.0]) 24.0)
                         "eqf (productf [2.0; 3.0; 4.0]) 24.0";
    check_test (fun () -> minimum [2; 3; 4] = 2)
                         "minimum [2; 3; 4] = 4";
    check_excp (fun () -> minimum [])
                         "minimum []"
                         "minimum";

    check_test (fun () -> 
        longest ["a"; "ab"; "abc"; "bc"] = "abc")
       "longest [\"a\"; \"ab\"; \"abc\"; \"bc\"] = \"abc\"";

    check_test (fun () -> 
        let r = longest ["ab"; "d"; "bc"] in r = "ab" || r = "bc")
       "let r = longest [\"ab\"; \"d\"; \"bc\"] in r = \"ab\" || r = \"bc\"";

    check_excp (fun () -> longest [] = "") 
                         "longest []"
                         "longest";

    check_test (fun () -> append [1; 2] [3; 4] = [1; 2; 3; 4])
                         "append [1; 2] [3; 4] = [1; 2; 3; 4]";
    check_test (fun () -> append [1; 2] [] = [1; 2])
                         "append [1; 2] [] = [1; 2]";
    check_test (fun () -> append [] [1; 2] = [1; 2])
                         "append [] [1; 2] = [1; 2]";


    check_test (fun () -> elem 2 [1; 2; 3])
                         "elem 2 [1; 2; 3]";
    check_test (fun () -> not (elem 4 [1; 2; 3]))
                         "not (elem 4 [1; 2; 3])";

    check_test (fun () ->
        excited ["Hello"; "World"] = ["Hello!"; "World!"])
       "excited [\"Hello\"; \"World\"] = [\"Hello!\"; \"World!\"]";
    check_test (fun () ->
        excited ["I"; "luv"; "2041"] = ["I!"; "luv!"; "2041!"])
       "excited [\"I\"; \"luv\"; \"2041\"] = [\"I!\"; \"luv!\"; \"2041!\"]";

    check_test (fun () ->
        suffix "!" ["Hello"; "World"] = ["Hello!"; "World!"])
       "suffix \"!\" [\"Hello\"; \"World\"] = [\"Hello!\"; \"World!\"]";

    check_test (fun () ->
        suffix "?" ["Why"; "oh"; "why"] = ["Why?"; "oh?"; "why?"])
       "suffix \"?\" [\"Why\"; \"oh\"; \"why\"] = [\"Why?\"; \"oh?\"; \"why?\"]";
    check_test (fun () ->
        excited' ["Hello"; "World"] = ["Hello!"; "World!"])
       "excited' [\"Hello\"; \"World\"] = [\"Hello!\"; \"World!\"]";

    check_test (fun () ->
        lengths ["I"; "luv"; "2041"] = [1; 3; 4])
       "lengths [\"I\"; \"luv\"; \"2041\"] = [1; 3; 4]";

    check_test (fun () ->
        length_pairs ["I"; "luv"; "2041"] = [("I", 1); ("luv", 3); ("2041", 4)])
       "length_pairs [\"I\"; \"luv\"; \"2041\"] = [(\"I\", 1); (\"luv\", 3); (\"2041\", 4)]";

    check_test (fun () ->
        capitalize ["The"; "sky"; "is"; "blue"] = ["The"; "Sky"; "Is"; "Blue"])
       "capitalize [\"The\"; \"sky\"; \"is\"; \"blue\"] = [\"The\"; \"Sky\"; \"Is\"; \"Blue\"]";

    check_test (fun () ->
        all_odds [1; 2; 3; 4; 5] = [1; 3; 5])
       "all_odds [1; 2; 3; 4; 5] = [1; 3; 5]";

    check_test (fun () ->
        all_capitalized ["The"; "sky"; "is"; "Blue"] = ["The"; "Blue"])
       "all_capitalized [\"The\"; \"sky\"; \"is\"; \"Blue\"] = [\"The\"; \"Blue\"]";


    check_excp (fun () ->
        all_capitalized ["The"; ""; "is"; "Blue"] = [])
       "all_capitalized [\"The\"; \"\"; \"is\"; \"Blue\"] = []"
       "all_capitalized";

    check_test (fun () ->
        all_squares [1; 2; 3; 4; 5; 6; 7; 8; 9] = [1; 4; 9])
       "all_squares [1; 2; 3; 4; 5; 6; 7; 8; 9] = [1; 4; 9]";

    check_test (fun () ->
        group [1; 2; 3; 4; 5; 6] = [(1, 2); (3, 4); (5, 6)])
       "group [1; 2; 3; 4; 5; 6] = [(1, 2); (3, 4); (5, 6)]";

    check_test (fun () ->
        group ['1'; '2'; '3'; '4'; '5'; '6'] = [('1', '2'); ('3', '4'); ('5', '6')])
       "group ['1'; '2'; '3'; '4'; '5'; '6'] = [('1', '2'); ('3', '4'); ('5', '6'))";

    check_excp (fun () ->
        group [1; 2; 3] = [])
       "group [1; 2; 3] = []"
       "group";


    check_test (fun () ->
        unzip [(1, 2); (3, 4); (5, 6)] = ([1; 3; 5], [2; 4; 6]))
       "unzip [(1, 2); (3, 4); (5, 6)] = ([1; 3; 5], [2; 4; 6])";

    check_test (fun () ->
        let strs = ["The"; "sky"; "is"; "Blue"] in (strs, lengths strs) = unzip (length_pairs strs))
       "let strs = [\"The\"; \"sky\"; \"is\"; \"Blue\"] in (strs, lengths strs) = unzip (length_pairs strs)";
  ]


let run_tests tests = List.iter (fun f -> f ()) tests

let _ = run_tests some_tests