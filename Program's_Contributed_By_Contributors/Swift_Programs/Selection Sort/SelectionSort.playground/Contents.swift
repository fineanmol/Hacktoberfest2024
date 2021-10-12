import UIKit

public func selectionSort<T: Comparable>(_ array: [T], _ isOrderedBefore: (T, T) -> Bool) -> [T] {
    var a = array
    guard array.count > 1 else { return array }

    for x in 0 ..< a.count - 1 {

        // print out the lowest value of the array
        var lowest = x
        for y in x + 1 ..< a.count {
            if isOrderedBefore(a[y], a[lowest]) {
                lowest = y
            }
        }

        // swap lowest value with index
        if x != lowest {
            a.swapAt(x, lowest)
        }
    }
    return a
}
let list = [ 2, -1, 11, 6, 5, 1, 0, 22, 1, 4, 8, 43 ]
selectionSort(list, <)
selectionSort(list, >)
