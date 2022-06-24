# ------------------------------------------------------------------------------------
liste = []
for i in range(1,11):
    liste.append(i**2) 

print("liste1 : ",liste)   
print(f"döngü değişkeni : {i}")
# -------------------------------------------------------------------------------------
# Burada bir yan etki var. Bu yan etki döngü değişkenine döngü dışından erişebilmektir.
# C syntax dillerde döngü elemanına dışardan erişilemez , çöp olur. (Java)
# python'da ise döngü değişkenine döngü bitse dahi erişebiliyoruz. 


# İşte bu yüzden lambda fonksiyonu kullanıyoruz. 
# ------------------------------------------------------------------------------------
liste2 = list(map(lambda x: x**2, range(1,11)))     # ilklemeye gerek kalmadı.
print("liste2 : ",liste2)
print("döngü değişkeni : erişilemez, hata verir")
# print(f"döngü değişkeni : {x}")      # --> hata verir. Çünkü x lambda fonksiyonu kullandığımız için dışarıdan erişilemezdir.Yan efekti yoktur.
# ------------------------------------------------------------------------------------

# Yan efekti olmayan bir yöntemimiz daha vardır. Bu yönteme List Comprehension denir.
# ------------------------------------------------------------------------------------
liste3 = [ y**2 for y in range(1,11)]
print("liste3 : ",liste3)
print("döngü değişkeni : erişilemez, hata verir")
# print("döngü değişkeni : ",y)       # --> hata verir. Dışarıdan erişilemez.
# ------------------------------------------------------------------------------------