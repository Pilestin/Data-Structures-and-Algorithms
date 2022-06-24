liste = [1,2,3,4,5]

print("ojinal listem      ->",liste)  

liste.append(10)    # listeye sondan verilen sayıyı ekler 
print("liste.append(10)   ->",liste)

liste.insert(0,-5)  # verilen indise , verilen sayıyı ekler 
print("liste.insert(0,-5) ->",liste)

liste.remove(2)     # ilk bulduğu -verilen sayıyı- siler.
print("liste.remove(2)    ->",liste)

liste.pop()
print("liste.pop()        ->",liste)  # listedeki son elemanı sile (LİFO)

liste.append(0)
print("liste.append(0)    ->",liste)

liste.sort()
print("liste.sort()       ->",liste)  # listeyi sıralar


liste2 = [10,13,18]
print("\nliste2               ->",liste2)

liste.append(liste2)
print("liste.append(liste2) ->",liste)  # append ile yeni listeyi orjinal listenin sonuna bir elemanmış gibi ekler.

liste.extend(liste2) 
print("liste.extend(liste2) ->",liste)  # extend ile yeni liste elemanlarını tek tek orjinal listeye ekler.

