import unittest
from src.Classes.DerivedClasses.Monitor import Monitor
from src.Classes.DerivedClasses.Keyboard import Keyboard
from src.Classes.DerivedClasses.ComputerMouse import ComputerMouse
from src.Lists.List import List


class ListTests(unittest.TestCase):

    def test_add_and_traverse(self):
        lst = List()
        monitor = Monitor(1500, 'Samsung', 24, 18)
        keyboard = Keyboard(500, 'Logitech', 'MEMBRANE', 'USB')
        mouse = ComputerMouse(300, 'Razer', 'LASER', 3)

        # Добавляем элементы в список
        lst.add(monitor)
        lst.add(keyboard)
        lst.add(mouse)

        # Список для хранения элементов при обходе
        elements = []
        def callback(data):
            elements.append(data)

        lst.traverse(callback)

        # Проверяем количество элементов и их порядок
        self.assertEqual(len(elements), 3)
        self.assertEqual(elements[0], monitor)
        self.assertEqual(elements[1], keyboard)
        self.assertEqual(elements[2], mouse)

    def test_delete_node(self):
        lst = List()
        monitor = Monitor(1500, 'Samsung', 24, 18)
        keyboard = Keyboard(500, 'Logitech', 'MEMBRANE', 'USB')

        lst.add(monitor)
        lst.add(keyboard)

        # Удаляем узел с монитором (он должен быть первым в списке, если add добавляет в конец)
        lst.delete_node(lst.head)
        self.assertEqual(lst.count, 1)

        elements = []
        lst.traverse(lambda data: elements.append(data))
        self.assertEqual(len(elements), 1)
        self.assertNotIn(monitor, elements)  # Проверяем, что монитора нет в списке
        self.assertIn(keyboard, elements)  # Проверяем, что клавиатура есть в списке

if __name__ == '__main__':
    unittest.main()