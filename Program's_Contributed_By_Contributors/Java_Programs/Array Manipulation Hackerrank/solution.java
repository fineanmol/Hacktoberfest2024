import Foundation

/// Source: https://www.hackerrank.com/challenges/crush/problem
struct Solution {

    /// For each operation add a value to each of the array elements between two given
    /// indices, inclusive. Once all operations have been performed, return the maximum
    /// value in your array.
    ///
    /// - Parameters:
    ///   - n: The number of elements in the array.
    ///   - queries: A two dimensional array of queries where each queries[i] contains
    ///     three integers, the left index, right index, and summand.
    /// - Returns: The integer maximum value in the finished array.
    ///
    /// - Complexity:
    ///   - time: O(max(n, m)), where n is the number of elements in the array, and m is the
    ///   length of the queries.
    ///   - space: O(n), where n is the number of elements in the array.
    func arrayManipulation(_ n: Int, _ queries: [[Int]]) -> Int {
        var tmp = [Int](repeating: 0, count: n+1)

        for i in 0..<queries.count {
            tmp[queries[i][0] - 1] += queries[i][2]
            tmp[queries[i][1]] -= queries[i][2]
        }

        var ans = Int.min
        var sum = 0
        for t in tmp {
            sum += t
            ans = max(ans, sum)
        }

        return ans
    }

}

let nm = readLine()!.split(separator: " ").compactMap { Int($0) }

let n = nm[0]
let m = nm[1]
var queries = [[Int]]()

for _ in 0..<m {
    queries.append(readLine()!.split(separator: " ").compactMap { Int($0) })
}

let solution = Solution()
let ans = solution.arrayManipulation(n, queries)
print(ans)
