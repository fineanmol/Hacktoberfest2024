import cmath

def calculate_roots(a, b, c):
    # Calculate the discriminant
    discriminant = cmath.sqrt(b**2 - 4*a*c)

    # Calculate the two roots
    root1 = (-b + discriminant) / (2*a)
    root2 = (-b - discriminant) / (2*a)

    return root1, root2

def main():
    # Get coefficients from the user
    a = float(input("Enter the coefficient a: "))
    b = float(input("Enter the coefficient b: "))
    c = float(input("Enter the coefficient c: "))

    # Calculate roots
    roots = calculate_roots(a, b, c)

    # Display the roots
    print(f"The roots are: {roots}")

if __name__ == "__main__":
    main()
