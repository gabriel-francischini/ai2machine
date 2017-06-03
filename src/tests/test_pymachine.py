import unittest
import pymachine
import cProfile
import pstats
import sys
import random
from random import randint
random.seed()

class TestPyMachineUsability(unittest.TestCase):

    def testCreation(self):
        # Test multiple times for certainity
        for i in range(1000):
            # Up to 2M of ram+registers
            machine = pymachine.Machine(randint(0, 2**20), randint(0, 2**20))
        for i in range(100):
            # Edge case
            machine = pymachine.Machine(0, 0)

    def testGetTicket(self):
        for i in range(1000):
            # Up to 1k of registers and 1k of ram
            machine = pymachine.Machine(randint(0, 2**10), randint(0, 2**10))
            # Between 1k and 128k
            tickets = randint(2**10, 2**17)
            machine.getTicket(tickets)
        # Edge case:
        machine = pymachine.Machine(0, 0)
        machine.getTicket(1024)

    def testGetters(self):
        ram = None
        registers = None
        ram_size = None
        registers_amount = None
        for i in range(1000):
            # Up to 1k of registers and 1k of ram
            machine = pymachine.Machine(randint(0, 2**10), randint(0, 2**10))

            # Tests the get attribute
            ram_size = machine.ram_size
            registers_amount = machine.registers_amount
            ram = machine.ram
            registers = machine.registers

            # Verify if refcounting is somewhat working
            ram_size += 1
            registers_amount += 1
            ram = ram + (1, )
            registers = registers + (1, )

    def testSetters(self):
        for i in range(1000):
            # Up to 1k of registers and 1k of ram
            machine = pymachine.Machine(randint(0, 2**10), randint(0, 2**10))

            # Random assign valid and unvalid values for the memory
            ram = tuple()
            for i in range(machine.ram_size):
                ram = ram + (randint(-2**16, 2**16), )
            machine.ram = ram

            registers = tuple()
            for i in range(machine.registers_amount):
                registers = registers + (randint(-2**16, 2**16), )


class Benchmark_PyMachine:
    def __init__(self):
        self.each = 100000
        self.machine = pymachine.Machine(randint(2**5, 2**10),
                                         randint(2**5, 2**10))

        # For assignment benchmarking:
        self.ram = tuple()
        for i in range(self.machine.ram_size):
            self.ram = self.ram + (randint(-2**16, 2**16), )
        self.registers = tuple()
        for i in range(self.machine.registers_amount):
            self.registers = self.registers + (randint(-2**16, 2**16), )

    def test_getRam(self):
        self.machine.__getattribute__('ram')

    def test_getRegisters(self):
        self.machine.__getattribute__('registers')

    def test_getRamSize(self):
        self.machine.__getattribute__('ram_size')

    def test_getRegistersAmount(self):
        self.machine.__getattribute__('registers_amount')

    def test_getTicket_1000(self):
        self.machine.getTicket(1000)

    def test_clear(self):
        self.machine.clear()

    def test_setRam(self):
        self.machine.ram = self.ram

    def test_setRegisters(self):
        self.machine.registers = self.registers

    def all(self):
        tests = [method for method in dir(self) if 'test' in method]
        for i in range(len(tests) * self.each):
            self.__getattribute__(random.choice(tests))()


if __name__ == "__main__":
    if len(sys.argv) > 1:
        benchmark = Benchmark_PyMachine()
        cProfile.run('benchmark.all()', 'profile_stats.pyc')
        stats = pstats.Stats('profile_stats.pyc')
        stats.sort_stats('calls', 'cumulative').print_stats('pymachine')
    else:
        unittest.main()
