-- Further information available at: https://en.wikipedia.org/wiki/Collatz_conjecture
-- Author: Nathalia Araújo (@nathaliafab)

collatzConjecture :: Int -> [Int]
collatzConjecture 1 = [1]
collatzConjecture n | even n    = n : collatzConjecture (n `div` 2)
                    | otherwise = n : collatzConjecture (3 * n + 1)

main = do
  putStr "Choose a number to start the sequence: "
  num <- readLn
  let result = collatzConjecture num
  print result