class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        # Initialize a 2D list 'tower' to represent the champagne distribution.
        # Each row has one more glass than the previous row.
        tower = [[0] * (i + 1) for i in range(query_row + 1)]
        
        # Pour the initial amount of champagne into the top glass.
        tower[0][0] = poured

        # Iterate through each row and each glass within the row.
        for row in range(query_row):
            for glass in range(len(tower[row])):
                # Calculate the excess champagne that flows to the two glasses below.
                excess = (tower[row][glass] - 1) / 2.0
                
                # If there's excess champagne, distribute it to the two glasses below in the next row.
                if excess > 0:
                    tower[row + 1][glass] += excess
                    tower[row + 1][glass + 1] += excess

        # Return the champagne quantity in the specified glass, capping it at 1.0.
        return min(1.0, tower[query_row][query_glass])
