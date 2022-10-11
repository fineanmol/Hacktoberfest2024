-- PROBLEM: https://leetcode.com/problems/trapping-rain-water/
-- Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
-- Author: Nathalia Araújo (@nathaliafab)

-- len > 0: on 1st iteration, arr = p2end, which means len = 0 (ml would get max from an empty list! Ofc we don't want that)
-- ml > p: the max value in the left of p must be higher than p, or else there's no trapped water
-- mr > p: same for the right
trappingRainWater :: [Int] -> [Int] -> Int
trappingRainWater [] _  = 0
trappingRainWater _ [x] = 0
trappingRainWater arr p2end@(p:ps)  | len > 0 && ml > p && mr > p = min ml mr - p + trappingRainWater arr ps
                                    | otherwise                   = trappingRainWater arr ps
	where
		ml  = foldl1 (max) [x | x <- take len arr]
		mr  = foldl1 (max) [x | x <- ps]
		len = length arr - length p2end

main = do
  putStr "Enter array: "
  a <- getLine
  let arr     = read a :: [Int]
  let result  = trappingRainWater arr arr
  print result
