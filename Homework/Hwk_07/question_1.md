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
evens_from n v = v+v :: evens_from (n-1) (v+1)
```

## evaluate
```
sum (take 3 (evens_from 5 1))
```
## Call-by-value

- ## even_from 5 1
- 1+1::evens_from 4 2
- 2::evens_from 4 2
- continues...
- 2::4::6::8::10
<br><br>
- ## take 3 [2::4::6::8::10]
- 2::take 2 [4::6::8::10]
- coninues...
- [2::4::6]
  <br><br>
- ## sum [2::4::6]
- 2+sum [4::6]
- coninues...
- ## 2+4+6= 12
- Final answer 12

### Call-by-name
- take 3 evens_from 5 1
- 2::take 2 evens_from 4 2
- 2::4::take 1 evens_from 3 3
- 2::4::6
- sum [2::4::6]
- 2+sum[4::6]
- 2+4+sum[6]
- 2+4+6 = 12

### Call-by-need
- sum take 3 evens_from 5 1
- sum take 3 [2::evens_from 4 2]
- sum [2::take 2 evens_from 4 2]
- 2 + sum take 2 evens_from 4 2
- 2 + sum take 2 [4::evens_from 3 3]
- 2 + sum [4::take 1 evens_from 3 3]
- 2 + 4 + sum take 1 evens_from 3 3
- 2 + 4 + sum take 1 [6::evens_from 2 4]
- 2 + 4 + sum 6::[]
- 2 + 4 + sum 6
- 2 + 4 + 6 = 12