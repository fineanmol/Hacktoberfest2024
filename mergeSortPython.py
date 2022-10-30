def mergeSort(list):
    if len(list) > 1:
        #sorteer lijst in 2 helften
        mid = len(list) // 2
        links = list[:mid]
        rechts = list[mid:]
        #sorteer linker helft
        mergeSort(links)
        #sorteer rechter helft
        mergeSort(rechts)

        #variabelen bepalen
        lenLinks = len(links)
        lenRechts = len(rechts)
        linksIter = 0
        rechtsIter= 0
        mainlistIterator= 0
        
        #kopiert data van Linker en Rechter list
        while linksIter < lenLinks and rechtsIter < lenRechts:
            if links[linksIter] < rechts[rechtsIter]:
                list[mainlistIterator] = links[linksIter]
                linksIter += 1
            else:
                list[mainlistIterator] = rechts[rechtsIter]
                rechtsIter += 1
            mainlistIterator += 1

        #checkt of er variabnele over zijn
        while linksIter < lenLinks:
            list[mainlistIterator] = links[linksIter]
            linksIter += 1
            mainlistIterator += 1

        while rechtsIter < lenRechts:
            list[mainlistIterator] = rechts[rechtsIter]
            rechtsIter += 1
            mainlistIterator += 1
    return list
