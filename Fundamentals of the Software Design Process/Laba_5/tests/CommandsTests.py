import unittest
from src.Classes.DerivedClasses.Monitor import Monitor
from src.Classes.DerivedClasses.Keyboard import Keyboard
from src.Classes.DerivedClasses.ComputerMouse import ComputerMouse
from src.Lists.List import List
from src.Commands.Commands import Commands

class CommandsTest(unittest.TestCase):
    def setUp(self):
        self.commands = Commands()
        self.list = List()

    def test_add(self):
        self.commands.add(self.list, "MONITOR", 1500, 'Samsung', 24, 18)
        self.assertEqual(self.list.count, 1)

        # Проверка на корректность добавленного объекта
        first_added = self.list.head.data
        self.assertIsInstance(first_added, Monitor)
        self.assertEqual(first_added.get_price(), 1500)

    def test_remove(self):
        self.commands.add(self.list, "KEYBOARD", 500, 'Logitech', 'MEMBRANE', 'USB')
        self.commands.add(self.list, "CMOUSE", 300, 'Razer', 'LASER', 3)
        self.assertEqual(self.list.count, 2)

        # Удаление всех элементов с ценой больше 400
        self.commands.remove(self.list, "PRICE", ">", "400")
        self.assertEqual(self.list.count, 1)

        remaining_item = self.list.head.data
        self.assertIsInstance(remaining_item, ComputerMouse)

    def test_print_list(self):
        # Проверка метода print_list может быть непростой, так как он в основном выводит информацию
        # Вместо этого можно проверить, что метод не вызывает ошибок и возвращает список
        self.commands.add(self.list, "CMOUSE", 300, 'Razer', 'LASER', 3)
        returned_list = self.commands.print_list(self.list)
        self.assertEqual(returned_list, self.list)

if __name__ == '__main__':
    unittest.main()
