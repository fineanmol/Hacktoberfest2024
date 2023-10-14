def tower_of_hanoi(n, source_rod, auxiliary_rod, target_rod):
    if n == 1:
        # If there's only one disk, move it from the source rod to the target rod.
        print(f"Move disk 1 from {source_rod} to {target_rod}")
        return

    # Move n-1 disks from the source rod to the auxiliary rod using the target rod as the auxiliary.
    tower_of_hanoi(n - 1, source_rod, target_rod, auxiliary_rod)

    # Move the nth disk from the source rod to the target rod.
    print(f"Move disk {n} from {source_rod} to {target_rod}")

    # Move the n-1 disks from the auxiliary rod to the target rod using the source rod as the auxiliary.
    tower_of_hanoi(n - 1, auxiliary_rod, source_rod, target_rod)

if __name__ == "__main__":
    number_of_disks = 5  # Change this to the desired number of disks.
    tower_of_hanoi(number_of_disks, 'A', 'B', 'C')