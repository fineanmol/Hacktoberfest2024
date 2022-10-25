import math
import random

class City:
    def __init__(self, x=None, y=None):
        self.x = None
        self.y = None
        if x is not None:
            self.x = x
        else:
            self.x = int(random.random() * 200)
        if y is not None:
            self.y = y
        else:
            self.y = int(random.random() * 200)

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def distanceTo(self, city):
        xdistance = abs(self.getX() - city.getX())
        ydistance = abs(self.getY() - city.getY())
        distance = math.sqrt((xdistance * xdistance) + (ydistance * ydistance))
        return distance

    def __repr__(self):
        return str(self.getX()) + ", " + str(self.getY())


class AdmTravel:
    destination = []

    def addCity(self, city):
        self.destination.append(city)

    def getCity(self, index):
        return self.destination[index]

    def cityQuantity(self):
        return len(self.destination)


class Travel:
    def __init__(self, admTravel, travel=None):
        self.admTravel = admTravel
        self.travel = []
        self.fitness = 0.0
        self.distance = 0
        if travel is not None:
            self.travel = travel
        else:
            for i in range(0, self.admTravel.cityQuantity()):
                self.travel.append(None)

    def __len__(self):
        return len(self.travel)

    def __getitem__(self, index):
        return self.travel[index]

    def __setitem__(self, key, value):
        self.travel[key] = value

    def __repr__(self):
        geneString = "|"
        for i in range(0, self.travelSize()):
            geneString += str(self.getCity(i)) + "|"
        return geneString

    def generateIndividual(self):
        for cityIndex in range(0, self.admTravel.cityQuantity()):
            self.setCity(cityIndex, self.admTravel.getCity(cityIndex))
        random.shuffle(self.travel)

    def getCity(self, travelPosition):
        return self.travel[travelPosition]

    def setCity(self, travelPosition, city):
        self.travel[travelPosition] = city
        self.fitness = 0.0
        self.distance = 0

    def getFitness(self):
        if self.fitness == 0:
            self.fitness = 1 / float(self.getDistance())
        return self.fitness

    def getDistance(self):
        if self.distance == 0:
            traveldistance = 0
            for cityIndex in range(0, self.travelSize()):
                fromCity = self.getCity(cityIndex)
                cityDestination = None
                if cityIndex + 1 < self.travelSize():
                    cityDestination = self.getCity(cityIndex + 1)
                else:
                    cityDestination = self.getCity(0)
                traveldistance += fromCity.distanceTo(cityDestination)
            self.distance = traveldistance
        return self.distance

    def travelSize(self):
        return len(self.travel)

    def containsCity(self, city):
        return city in self.travel


class Population:
    def __init__(self, admTravel, populationSize, initialise):
        self.travels = []
        for i in range(0, populationSize):
            self.travels.append(None)

        if initialise:
            for i in range(0, populationSize):
                newTravel = Travel(admTravel)
                newTravel.generateIndividual()
                self.saveTravel(i, newTravel)

    def __setitem__(self, key, value):
        self.travels[key] = value

    def __getitem__(self, index):
        return self.travels[index]

    def saveTravel(self, index, travel):
        self.travels[index] = travel

    def getTravel(self, index):
        return self.travels[index]

    def getFitTest(self):
        fitTest = self.travels[0]
        for i in range(0, self.populationSize()):
            if fitTest.getFitness() <= self.getTravel(i).getFitness():
                fitTest = self.getTravel(i)
        return fitTest

    def populationSize(self):
        return len(self.travels)


class AG:
    def __init__(self, admTravel):
        self.admTravel = admTravel
        self.mutationRate = 0.015
        self.travelSize = 5
        self.elitism = True

    def agPopulation(self, pop):
        newPopulation = Population(self.admTravel, pop.populationSize(), False)
        elitismOffset = 0
        if self.elitism:
            newPopulation.saveTravel(0, pop.getFitTest())
            elitismOffset = 1

        for i in range(elitismOffset, newPopulation.populationSize()):
            parent1 = self.selection(pop)
            parent2 = self.selection(pop)
            child = self.crossover(parent1, parent2)
            newPopulation.saveTravel(i, child)

        for i in range(elitismOffset, newPopulation.populationSize()):
            self.mutation(newPopulation.getTravel(i))

        return newPopulation

    def crossover(self, parent1, parent2):
        child = Travel(self.admTravel)

        initialPosition = int(random.random() * parent1.travelSize())
        finalPosition = int(random.random() * parent1.travelSize())

        for i in range(0, child.travelSize()):
            if initialPosition < finalPosition and i > initialPosition and i < finalPosition:
                child.setCity(i, parent1.getCity(i))
            elif initialPosition > finalPosition:
                if not (i < initialPosition and i > finalPosition):
                    child.setCity(i, parent1.getCity(i))

        for i in range(0, parent2.travelSize()):
            if not child.containsCity(parent2.getCity(i)):
                for ii in range(0, child.travelSize()):
                    if child.getCity(ii) == None:
                        child.setCity(ii, parent2.getCity(i))
                        break

        return child

    def mutation(self, travel):
        for travelPos1 in range(0, travel.travelSize()):
            if random.random() < self.mutationRate:
                travelPos2 = int(travel.travelSize() * random.random())

                city1 = travel.getCity(travelPos1)
                city2 = travel.getCity(travelPos2)

                travel.setCity(travelPos2, city1)
                travel.setCity(travelPos1, city2)

    def selection(self, pop):
        travel = Population(self.admTravel, self.travelSize, False)
        for i in range(0, self.travelSize):
            randomId = int(random.random() * pop.populationSize())
            travel.saveTravel(i, pop.getTravel(randomId))
        fitTest = travel.getFitTest()
        return fitTest


if __name__ == '__main__':

    admTravel = AdmTravel()

    city = City(60, 200)
    admTravel.addCity(city)
    city2 = City(180, 200)
    admTravel.addCity(city2)
    city3 = City(80, 180)
    admTravel.addCity(city3)
    city4 = City(140, 180)
    admTravel.addCity(city4)
    city5 = City(20, 160)
    admTravel.addCity(city5)
    city6 = City(100, 160)
    admTravel.addCity(city6)
    city7 = City(200, 160)
    admTravel.addCity(city7)
    city8 = City(140, 140)
    admTravel.addCity(city8)
    city9 = City(40, 120)
    admTravel.addCity(city9)
    city10 = City(100, 120)
    admTravel.addCity(city10)
    city11 = City(180, 100)
    admTravel.addCity(city11)
    city12 = City(60, 80)
    admTravel.addCity(city12)
    city13 = City(120, 80)
    admTravel.addCity(city13)
    city14 = City(180, 60)
    admTravel.addCity(city14)
    city15 = City(20, 40)
    admTravel.addCity(city15)
    city16 = City(100, 40)
    admTravel.addCity(city16)
    city17 = City(200, 40)
    admTravel.addCity(city17)
    city18 = City(20, 20)
    admTravel.addCity(city18)
    city19 = City(60, 20)
    admTravel.addCity(city19)
    city20 = City(160, 20)
    admTravel.addCity(city20)

    # Initialize population
    pop = Population(admTravel, 50, True);
    print
    "Initial Distance: " + str(pop.getFitTest().getDistance())

    ag = AG(admTravel)
    pop = ag.agPopulation(pop)
    for i in range(0, 100):
        pop = ag.agPopulation(pop)

    print
    "Final distance: " + str(pop.getFitTest().getDistance())
    print
    "Solution:"
    print
    pop.getFitTest()
