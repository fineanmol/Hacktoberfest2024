fibonacci :: [Int]
fibonacci = 0 : 1 : zipWith (+) fibonacci (tail fibonacci)

main = do
  putStrLn "Enter the number of elements:"
  input <- getLine
  print (take (read input :: Int) fibonacci)
