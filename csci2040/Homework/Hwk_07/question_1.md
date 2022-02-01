# Homework 7: Lazy Evaluation

by Owen Swearingen

## definitions
```
sum [] = 0
sum x::xs -> x + sum xs

take 0 lst = [ ]
take n [ ] = [ ]
take n (x::xs) = x::take (n-1) xs

evens_from 0 v = [ ]
evens_from n v = v+v :: (evens_from (n-1) (v+1)
```

## evaluate
```
sum (take 3 (evens_from 5 1))
```
## Call-by-value

### even_from 5 1
- (1+1)::evens_from 4 2
- 2::evens_from 4 2
- 2::(2+2)::evens from 3 3
- 2::4::evens from 3 3
- 2::4::(3+3)::evens from 2 4
- 2::4::6::evens from 2 4
- 2::4::6::(4+4)::evens from 1 5
- 2::4::6::8::evens_from 1 5
- 2::4::6::8::(5+5)::evens_from 0 6
- 2::4::6::8::10::evens_from 0 6
- 2::4::6::8::10::[]
- 2::4::6::8::10
<br><br>
 ### take 3 [2::4::6::8::10]
- 2::take 2 [4::6::8::10]
- 2::4::take 1 [6::8::10]
- 2::4::6::take 0 [6::8::10]
- 2::4::6::[]
- [2::4::6]
  <br><br>
- ## sum [2::4::6]
- 2+sum [4::6]
- 2+4+sum [6]
- 2+4+6+sum []
- 2+4+6+0
- 2+4+6= 12
- Final answer 12

### Call-by-name
- sum (take 3 (evens_from 5 1))
- sum (take 3 (2::evens_from 4 2))
- sum (2::(take 2 (evens_from 4 2))
- 2 + sum (take 2 (4::evens_from 3 3))
- 2 + sum (take 2 (4::evens_from 3 3))
- 2 + sum 4::(take 1 (evens_from 3 3))
- 2 + (4 + sum (take 1 (evens_from 3 3)))
- 2 + (4 + sum (take 1 (6::evens_from 2 4)))
- 2 + (4 + sum 6::take 0)
- 2 + 4 + (6 sum take 0)
- 2 + 4 + (6 sum [])
- 2 + 4 + (6 + 0) = 12
- 12

### Call-by-need
- sum take 3 (evens_from 5 1)
- sum take 3 (2::(evens_from (5-1) (1+1))
- sum (2::take 2 (evens_from (5-1) (1+1)))
- 2 + sum take 2 (evens_from (5-1) (1+1))
- 2 + sum take 2 (evens_from 4 2)
- 2 + sum take 2 (2v::evens_from (4-1) (v+1)) (v = 1+1)
- 2 + sum 2v::take 1 (evens_from (4-1) (v+1)) (v= 1+1)
- 2 + (2v + sum take 1 (evens_from (4-1) (v+1)) (v= 1+1)
- 2 + (4 + sum take 1 (evens_from (4-1) (2+1))
- 2 + (4 + sum take 1 (2v::evens_from (3-1) (v+1))) (v = 2+1)
- 2 + (4 + sum 2v::take 0 (evens_from (3-1) (v+1))) (v = 2+1)
- 2 + (4 + 2v sum take 0 (evens_from (3-1) (v+1))) (v = 2+1)
- 2 + 4 + (6 sum take 0 (evens from (3-1) (3+1)))
- 2 + 4 + (6 sum take 0 (2v::evens_from (3-1) (v+1))) (v = 3+1)
- 2 + 4 + (6 + sum [])
- 2 + 4 + (6 + 0)
- 2 + 4 + 6 = 12