
open Streams
open Tests

let show_list (show_elem: 'a -> string) (lst: 'a list) : string =
  "[" ^ (String.concat "; " (List.map show_elem lst)) ^ "]"

let some_tests =
  [ 
    eval_test (fun () ->
        take 3 (from_by_2 1), [1; 3; 5] )
       "take 3 (from_by_2 1)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (from_by_2 2), [2; 4; 6] )
       "take 3 (from_by_2 2)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (from_by_2 3), [3; 5; 7] )
       "take 3 (from_by_2 3)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 evens, [2; 4; 6] )
       "take 3 evens"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 evens_filter, [2; 4; 6] )
       "take 3 evens_filter"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 evens_map, [2; 4; 6] )
       "take 3 evens_map"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 evens_zip, [2; 4; 6] )
       "take 3 evens_zip"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 evens_pick, [2; 4; 6] )
       "take 3 evens_pick"
        (show_list string_of_int);

  ]

let run_tests tests = List.iter (fun f -> f ()) tests

let _ = run_tests some_tests

