persons = {"yamur":2007 , "yasin":2000}
# kisiler["yamur"] = 2007
# kisiler["yasin"] = 2000
#  for p in persons : "yamur" ve "yasin" verir.
ages = [(2021-persons[p] ) for p in persons]        
print(ages)

# ------------------------------------------------

l1 = [ (x,y) for x in [1,2,3] for y in [3,1,4] if x!= y]
print(l1)
# -----------------------------------------------
# (1,2,3,4)  
# (2,3,4,5)  
# (3,4,5,6)  
# (4,5,6,7)  

l2 = [ (x,x+1,x+2,x+3) for x in [1,2,3,4] ]
print(l2)
l3 = [ (x,y,z,t) for x in [1,2,3,4]  for y in [x+1] for z in [x+2] for t in [x+3]] 
print(l3)
l4 = [ (x,y,z,t) for x in [1,2,3,4] for y,z,t in [(2,3,4) , (3,4,5) , (4,5,6) , (5,6,7)] if x+1 == y]
print(l4)