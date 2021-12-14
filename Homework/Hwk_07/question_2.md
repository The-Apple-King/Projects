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
- andl l = foldl and true l
- foldl and true (firstl::restl) (firstl = true)
- foldl and accum (firstl::restl) (firstl = true) (accum = true)
- foldl if accum = true then accum = firstl else accum = false (firstl = true) (accum = true)
- foldl and accum restl (accum = true)
- foldl and true restl
- foldl and accum (firstl::restl) (firstl = false) (accum = true)
- foldl if accum = true then accum = firstl else accum = false (firstl = false) (accum = true)
- foldl and false restl
- foldl and false (firstl::restl) (firstl = true)
- foldl and accum (firstl::restl) (firstl = true) (accum = false)
- foldl if accum = true then accum = firstl else accum = false (firstl = true) (accum = false)
- foldl and false restl
- foldl and false restl
- foldl and false (firstl::restl) (firstl = true)
- foldl and accum (firstl::restl) (firstl = true) (accum = false)
- foldl if accum = true then accum = firstl else accum = false (firstl = true) (accum = false)
- foldl and false []
- foldl = false
- andl l = false
- false

### call by name
- andl l = foldl and l true
- foldl and true l 
- foldl and accum (firstl::restl) (firstl = true) (accum = true)
- and = if accum = true then accum = firstl else accum = false (firstl = true) (accum = true)
- foldl and true restl
- foldl and accum (firstl::restl) (firstl = false) (accum = true)
- and = if accum = true then accum = firstl else accum = false (firstl = false) (accum = false)
- foldl and false restl
- foldl = false 
- andl l = false

## andr (true::false::true::true::[])
### call by value
- andr l = foldr and l true
- foldr and (firstl::restl) true (firstl = true)
- foldr and (firstl::restl) accum (firstl = true) (accum = true)
- foldr if firstl = true then accum = firstl else accum = false (firstl = true) (accum = true)
- foldr and restl accum (accum = true)
- foldr and restl true
- foldr and (firstl::restl) accum (firstl = false) (accum = true)
- foldr if firstl = true then accum = firstl else accum = false (firstl = false) (accum = true)
- foldr and restl false
- foldr and (firstl::restl) false  (firstl = true)
- foldr and (firstl::restl) accum (firstl = true) (accum = false)
- foldr if firstl = true then accum = firstl else accum = false (firstl = true) (accum = false)
- foldr and restl false
- foldr and (firstl::restl) false (firstl = true)
- foldr and (firstl::restl) accum (firstl = true) (accum = false)
- foldr if firstl = true then accum = firstl else accum = false (firstl = true) (accum = false)
- foldr and [] false
- foldr = false
- andl l = false
- false

### call by name
- andr l = foldr and true l
- foldr and l true
- foldr and (firstl::restl) accum (firstl = true) (accum = true)
- and = if firstl = true then accum = firstl else accum = false (firstl = true) (accum = true)
- foldr and restl true
- foldr and (firstl::restl) accum (firstl = false) (accum = true)
- and = if firstl = true then accum = firstl else accum = false (firstl = false) (accum = false)
- foldr and restl false
- foldr = false 
- andr l = false
- false