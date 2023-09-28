import random

length = 5
generation = 4

def calculate_fitness(parents):
    fitness_score = []
    for parent in parents:
        score = 0
        for i,bit in enumerate(parent[::-1]):
            score += bit * (2 ** i)
        fitness_score.append(score ** 2 )
    fitness_score,parents = zip(*sorted(zip(fitness_score,parents), key = lambda x : -x[0]))
    print(parents)
    print(fitness_score)
    return list(fitness_score),list(parents)

def crossover(parents):
    parent1, parent2 = parents[:2]
    split = random.randint(0,length - 1)
    offspring = [
        parent1[:split] + parent2[split:],
        parent2[:split] + parent1[split:]
    ]
    return [parent1 , parent2] + offspring

def mutate(parents):
    for parent in parents:
        if random.choice([True,False]):
            idx = random.randint(0,length - 1)
            parent[idx] = 1 if parent[idx] == 0 else 0
    return parents

parents = [[random.choice([0,1]) for _ in range(length)] for _ in range(generation) ]
fitness,parents = calculate_fitness(parents)
parents = crossover(parents)
parents = mutate(parents)
print(fitness[0])