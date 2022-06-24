# map , list ve lambda kavramları işlenecek.
# 
# list metodu : listeye çevirir.
# map  metodu : tüm elemanlara aynı işlemi uygular. listeye çevrilmesi gerekir.
# lambda func : kısa yoldan fonksiyon tanımlamak gibidir. 

def f(x):
    return x+5 

lst = [3,5,7]


print(list(map( f , lst )))             # f fonksiyonuna, lst listesinin elemanlarını verir ve gelen değerleri listeye çevirir.

result = list(map(lambda x : x+5,lst))  # f fonksiyonu yerine lambda ile aynı işlemi yapan fonksiyonumuzu tanımlayabiliriz.
print(result)
print(type(result))