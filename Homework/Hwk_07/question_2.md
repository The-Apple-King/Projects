# definitions
```
foldr f [] v = v
foldr f (x::xs) v = f x (foldr f xs v)

foldl f v [] = v
foldl f v (x::xs) = foldl f (f v x) xs

and b1 b2 = if b1 then b2 else false

andl l = foldl and true l
andr l = foldr and l true
```

# Evaluate
## andl (true::false::true::true::[])

### call by value
- fold l and true l
- accum = true
- and = if accum = true then (true::restl) else false
- accum = true
- and true (false::restl)
- and = if accum = true then (false::restl) else false
- accum = false
- and false (true::restl)
- and = if accum = true then true::restl else false
- and false true
- and = if accum = true then true else false
- false

### call by name
fold l and true l
- accum = true
- and = if accum = true then (true::restl) else false
- accum = true
- and true (false::restl)
- and = if accum = true then (false::restl) else false
- accum = false
- false
<br>
and b1 b2 = if b1 then b2 else false 

## andr (true::false::true::true::[])

### call by value
foldr and l true
- and l true = if l then true else false
- accum =true
- if (true::restl) then accum else false
- restl = (false::restl) & accum = true
- if (false::restl) = true then accum else false
- restl = (true::restl) & accum = false
- if (true::restl) = true then accum else false
- restl = (true::[]) accum = false
- if true::[] = true then accum else false
- foldr accum = false
- false

### call by name
foldr and l true
- and l true = if l then true else false
- accum =true
- if (true::restl) then accum else false
- restl = (false::restl) & accum = true
- if (false::restl) = true then accum else false
- restl = (true::restl) & accum = false
- foldr [] accum = false
- false