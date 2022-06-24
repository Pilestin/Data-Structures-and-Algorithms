print("---------------------")
l1 = [1,2,3,4,5]
l2 = []
# shallow copy  ( sığ kopyalama ) : pointerlar kullanılır ve bir dizide yapılan değişiklik diğerini etkiler. 
l2 = l1
print("l1 ->",l1)
print("l1 = l2      shallow copy")
print("l2 ->",l2)
print("---------------------")

l1.append(10)
print("\nl1.append(10) ->",l1)
print("           l2 ->",l2 , "     # l1 e eklediğimiz halde l2 de değişti ")

# deep copy ( derin kopyalama ) : ikiside farklı dizilerdir ve bağımsızdırlar.
l3 = l1.copy()
print("\nl3 = l1.copy()     deep copy")
print("l3  ->",l3)