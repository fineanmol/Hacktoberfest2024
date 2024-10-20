import random
import math

#Particle Swarm Optimization 
class Particle:
    def __init__(self, dimensions):
        self.position = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.velocity = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.best_position = self.position[:]
        self.best_score = float('inf')

    def update_velocity(self, global_best_position, inertia, cognitive, social):
        for i in range(len(self.velocity)):
            cognitive_velocity = cognitive * random.random() * (self.best_position[i] - self.position[i])
            social_velocity = social * random.random() * (global_best_position[i] - self.position[i])
            self.velocity[i] = inertia * self.velocity[i] + cognitive_velocity + social_velocity

    def update_position(self):
        for i in range(len(self.position)):
            self.position[i] += self.velocity[i]
            if self.position[i] > 1:
                self.position[i] = 1
            elif self.position[i] < -1:
                self.position[i] = -1

class Swarm:
    def __init__(self, num_particles, dimensions, inertia, cognitive, social):
        self.particles = [Particle(dimensions) for _ in range(num_particles)]
        self.global_best_position = [random.uniform(-1, 1) for _ in range(dimensions)]
        self.global_best_score = float('inf')
        self.inertia = inertia
        self.cognitive = cognitive
        self.social = social

    def optimize(self, fitness_func, iterations):
        for _ in range(iterations):
            for particle in self.particles:
                score = fitness_func(particle.position)
                if score < particle.best_score:
                    particle.best_score = score
                    particle.best_position = particle.position[:]
                if score < self.global_best_score:
                    self.global_best_score = score
                    self.global_best_position = particle.position[:]
            for particle in self.particles:
                particle.update_velocity(self.global_best_position, self.inertia, self.cognitive, self.social)
                particle.update_position()

def fitness_function(position):
    return sum([x ** 2 for x in position])

swarm = Swarm(num_particles=30, dimensions=5, inertia=0.7, cognitive=1.4, social=1.4)
swarm.optimize(fitness_func=fitness_function, iterations=100)

print("Best position:", swarm.global_best_position)
print("Best score:", swarm.global_best_score)
