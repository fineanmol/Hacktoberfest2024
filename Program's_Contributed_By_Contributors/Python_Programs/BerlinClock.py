from abc import ABCMeta
import copy
import sys
import re


class Parser:
    PATTERN = "(\d{2})::(\d{2}):(\d{2})"

    def parse(self, time):
        reg = re.search(self.PATTERN, time)
        if (reg):
            return Time(reg.group(1), reg.group(2), reg.group(3))
        else:
            raise ValueError("time: " + time + " doesn't match to pattern: " + self.PATTERN)


class BerlinClock:
    TIME_UNIT_DELIMITER = " "

    def displayTime(self, input):
        t = Parser().parse(input)
        return Seconds().display(t.s) + self.TIME_UNIT_DELIMITER + \
               Hours().display(t.h) + self.TIME_UNIT_DELIMITER + \
               Minutes().display(t.m);


class Precondition:
    def __init__(self, unitsPredicate, errorMessage):
        self.unitsPredicate = unitsPredicate
        self.errorMessage = errorMessage

    def validate(self, units):
        if self.unitsPredicate(units) is False:
            raise ValueError(self.errorMessage)


class Time:
    def __init__(self, h, m, s):
        self.h = int(h)
        self.m = int(m)
        self.s = int(s)
        self.TIME_TO_STRING_SEPARATOR = ":"

    def __str__(self):
        return str(self.h) + self.TIME_TO_STRING_SEPARATOR + str(self.m) + self.TIME_TO_STRING_SEPARATOR + str(
            self.s)

    def __eq__(self, other):
        return self.__dict__ == other.__dict__


class Color:
    YELLOW = "Y"
    RED = "R"


class Lamp:
    def __init__(self, color):
        self.switch = False
        self.color = color
        self.SWITCH_OFF_COLOR = "O"

    def switchOn(self):
        self.switch = True

    def switchOff(self):
        self.switch = False

    def __str__(self):
        return self.color.__str__() if self.switch else self.SWITCH_OFF_COLOR


class AbsTimeUnit:
    __metaclass__ = ABCMeta

    def display(self, units):
        self.precondition.validate(units)
        return " ".join(timeUnit.display(units) for timeUnit in self.timeUnits)


class Hours(AbsTimeUnit):
    def __init__(self):
        self.precondition = Precondition(lambda units: (units >= 1 and units <= 24),
                                         "Hour units must be in range: units >= 1 && units <= 24")
        self.timeUnits = HoursFactory().createParts()


class Minutes(AbsTimeUnit):
    def __init__(self):
        self.precondition = Precondition(lambda units: (units >= 0 and units <= 59),
                                         "Minute units must be in range: units >= 0 && units <= 59")
        self.timeUnits = MinutesFactory().createParts()


class Seconds(AbsTimeUnit):
    def __init__(self):
        self.precondition = Precondition(lambda units: (units >= 0 and units <= 59),
                                         "Second units must be in range: units >= 0 && units <= 59")
        self.timeUnits = SecondsFactory().createParts()


class TimeUnitPart:
    def __init__(self, lampsFunction, lampsList):
        self.lampsFunction = lampsFunction
        self.lampsList = lampsList

    def display(self, units):
        listClone = copy.deepcopy(self.lampsList)
        for i in range(0, self.lampsFunction(units)):
            listClone[i].switchOn()

        return "".join(str(lamp) for lamp in listClone)

    def calc(self, units):
        return self.lampsFunction(units)


class SecondsFactory:
    def createPart(self):
        return TimeUnitPart(lambda units: (abs((units % 2) - 1)), [Lamp(Color.YELLOW)])

    def createParts(self):
        return [self.createPart()]


class MinutesFactory:
    def createTopPart(self):
        return TimeUnitPart(lambda units: (units / 5),
                            [
                                Lamp(Color.YELLOW), Lamp(Color.YELLOW), Lamp(Color.RED),
                                Lamp(Color.YELLOW), Lamp(Color.YELLOW), Lamp(Color.RED),
                                Lamp(Color.YELLOW), Lamp(Color.YELLOW), Lamp(Color.RED),
                                Lamp(Color.YELLOW), Lamp(Color.YELLOW)
                            ])

    def createBottomPart(self):
        return TimeUnitPart(lambda units: (units % 5),
                            [
                                Lamp(Color.YELLOW), Lamp(Color.YELLOW), Lamp(Color.YELLOW), Lamp(Color.YELLOW)
                            ])

    def createParts(self):
        return [self.createTopPart(), self.createBottomPart()]


class HoursFactory:
    def createTopPart(self):
        return TimeUnitPart(lambda units: (units / 5),
                            [
                                Lamp(Color.RED), Lamp(Color.RED), Lamp(Color.RED), Lamp(Color.RED)
                            ])

    def createBottomPart(self):
        return TimeUnitPart(lambda units: (units % 5),
                            [
                                Lamp(Color.RED), Lamp(Color.RED), Lamp(Color.RED), Lamp(Color.RED)
                            ])

    def createParts(self):
        return [self.createTopPart(), self.createBottomPart()]
