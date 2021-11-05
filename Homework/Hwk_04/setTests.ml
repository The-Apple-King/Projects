(* Some tests for set implementations. *)

open Tests

module SetTests (S: Set.SetS) = struct
  open S

  let evens_set = List.fold_right insert [2;4;6;8;10] empty

  let test x = insert 4 (insert 8 x) 

  let some_tests = [
      check_test (fun () -> 
          elem 4 empty = false)
         "elem 4 empty = false";

      (* for all v, s : elem v (insert v s)   *)
      check_test (fun () ->
          elem 4 (insert 4 empty))
         "elem 4 (insert 4 empty)";

      check_test (fun () ->
          elem 8 (List.fold_right insert [2;4;6;8;10] empty))
         "elem 8 (copied evens set code into the call)";

         check_test (fun () ->
          elem 8 (test empty))
         "elem 8 (calls another function using insert but not a list)";

      check_test (fun () ->
          elem 8 evens_set)
         "elem 8 evens_set";
  
      check_test (fun () ->
          elem 12 (insert 12 evens_set))
         "elem 12 (insert 12 evens_set)";
    ]
                 
  let run () = run_tests some_tests

end

module ListSetTests = SetTests (ListSet.ListM)
module TreeSetTests = SetTests (Tree.TreeSet)
module TreeMTests = SetTests (Tree.TreeM)

let _ =
  print_endline ("Set Tests.\n");

  print_endline ("AltList Tests:");
  ListSetTests.run ();

  print_endline ("Tree Set Tests:");
  TreeSetTests.run ();

  (* This is really not needed since here we are
     testing the very same functions as in TreeSetTests.
   *)
  print_endline ("Tree Tests:");
  TreeMTests.run ();

