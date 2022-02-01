
open Streams
open Tests

let show_list (show_elem: 'a -> string) (lst: 'a list) : string =
  "[" ^ (String.concat "; " (List.map show_elem lst)) ^ "]"

let some_tests =
  [ 
    eval_test (fun () ->
        take 3 (cubes_from 1), [1; 8; 27] )
       "take 3 (cubes_from 1)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (cubes_from_zip 1), [1; 8; 27] )
       "take 3 (cubes_from_zip 1)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (cubes_from_map 1), [1; 8; 27] )
       "take 3 (cubes_from_map 1)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (cubes_from 10), [1000; 1331; 1728] )
       "take 3 (cubes_from 10)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (cubes_from_zip 10), [1000; 1331; 1728] )
       "take 3 (cubes_from_zip 10)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (cubes_from_map 10), [1000; 1331; 1728] )
       "take 3 (cubes_from_map 10)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (drop 4 (cubes_from 1)), [125; 216; 343] )
       "take 3 (drop 4 (cubes_from 1))"
        (show_list string_of_int);

    eval_test (fun () ->
        take 1 (drop_until (fun _ -> true) (cubes_from 1)), [1] )
       "take 1 (drop_until (fun _ -> true) (cubes_from 1))"
        (show_list string_of_int);
    
    eval_test (fun () ->
        take 1 (drop_until (fun c -> c > 100) (cubes_from 1)), [125] )
       "take 1 (drop_until (fun c -> c > 100) (cubes_from 1))"
        (show_list string_of_int);

    eval_test (fun () ->
        take 1 (arith_seq 3 5), [3] )
       "take 1 (arith_seq 3 5)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (arith_seq 1 1), [1; 2; 3] )
       "take 3 (arith_seq 1 1)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 3 (arith_seq 3 5), [3; 8; 13] )
       "take 3 (arith_seq 3 5)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 10 (arith_seq 10 10), [10; 20; 30; 40; 50; 60; 70; 80; 90; 100] )
       "take 10 (arith_seq 10 10)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 5 primes, [ 2; 3; 5; 7; 11 ] )
       "take 5 primes"
        (show_list string_of_int);

    eval_test (fun () ->
        take 1 (drop 100 primes), [ 547 ] )
       "take 1 (drop 100 primes)"
        (show_list string_of_int);

    eval_test (fun () ->
        take 5 (sieve (from 2)), [ 2; 3; 5; 7; 11 ] )
       "take 5 (sieve (from 2))"
        (show_list string_of_int);

  ]

let run_tests tests = List.iter (fun f -> f ()) tests

let _ = run_tests some_tests

