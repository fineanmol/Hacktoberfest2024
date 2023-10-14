from itertools import permutations

def calculate_total_distance(points, order):
    total_distance = 0
    for i in range(len(order) - 1):
        total_distance += distance(points[order[i]], points[order[i + 1]])
    total_distance += distance(points[order[-1]], points[order[0]])  # Return to the starting point
    return total_distance

def distance(point1, point2):
    return ((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2) ** 0.5

def tsp_bruteforce(points):
    num_points = len(points)
    if num_points < 2:
        return points, 0

    best_order = None
    best_distance = float('inf')

    for order in permutations(range(num_points)):
        current_distance = calculate_total_distance(points, order)
        if current_distance < best_distance:
            best_distance = current_distance
            best_order = order

    best_path = [points[i] for i in best_order]
    return best_path, best_distance

def main():
    num_points = int(input("Enter the number of points: "))
    points = []
    for i in range(num_points):
        x, y = map(float, input(f"Enter the coordinates for point {i+1} (x y): ").split())
        points.append((x, y))

    best_path, best_distance = tsp_bruteforce(points)
    print("Best Path:", best_path)
    print("Total Distance:", best_distance)

if __name__ == '__main__':
    main()






#### Code Explanation

- The code begins by importing the `permutations` function from the `itertools` library, which is used to generate all possible permutations of points.

- `calculate_total_distance` is a function that calculates the total distance of a given order of points in the TSP.

- The `distance` function calculates the Euclidean distance between two points.

- The `tsp_bruteforce` function is the main TSP solver, which finds the best path and its total distance using a brute-force approach.

- The `main` function is the entry point of the program. It takes user input for the number of points and their coordinates, then calls the TSP solver to find the best path and distance.

- Finally, if the script is run directly (not imported as a module), it calls the `main` function to start the TSP solving process.

