import unittest
import tempfile
import os
from src.MainFunctions.Mainwork import Mainwork
from src.Classes.DerivedClasses.Monitor import Monitor
from src.Classes.DerivedClasses.Keyboard import Keyboard
from src.Classes.DerivedClasses.ComputerMouse import ComputerMouse

class MainworkTest1(unittest.TestCase):
    def setUp(self):
        # Создание временного файла для теста
        self.test_file = tempfile.NamedTemporaryFile(delete=False, mode='w+t')
        self.mainwork = Mainwork()

    def tearDown(self):
        # Удаление временного файла после теста
        self.test_file.close()
        os.unlink(self.test_file.name)

    def test_file_work(self):
        # Запись команд во временный файл
        commands = [
            "ADD MONITOR 1500 Samsung 24 18",
            "ADD KEYBOARD 500 Logitech MEMBRANE USB",
            "ADD CMOUSE 300 Razer LASER 3",
            "REM PRICE > 1000",
            "PRINT",
            "ADD CMOUSE 200 Logitech BALL 2",
            "ADD CMOUSE 200 RAZER BALL 2",
            "REM COMPANY == RAZER",
            "PRINT"
        ]
        for cmd in commands:
            self.test_file.write(cmd + '\n')
        self.test_file.seek(0)

        # Выполнение команд из файла
        self.mainwork.file_work(self.test_file.name)

        # Проверка: после выполнения всех команд в списке должно остаться два элемента
        self.assertEqual(self.mainwork.my_list.count, 2)

        # Дополнительная проверка на типы оставшихся элементов
        remaining_items = []
        remaining_items = []
        self.mainwork.my_list.traverse(lambda obj: remaining_items.append(obj))
        self.assertIsInstance(remaining_items[0], Keyboard)
        self.assertIsInstance(remaining_items[1], ComputerMouse)
        self.assertEqual(remaining_items[0].get_keyboard_type(), "MEMBRANE")
        self.assertEqual(remaining_items[0].get_connector_type(), "USB")
        self.assertEqual(remaining_items[1].get_mouse_type(), "BALL")
        self.assertEqual(remaining_items[1].get_button_count(), 2)


class MainworkTest2(unittest.TestCase):
    def setUp(self):
        # Создание временного файла для теста
        self.test_file = tempfile.NamedTemporaryFile(delete=False, mode='w+t')
        self.mainwork = Mainwork()

    def tearDown(self):
        # Удаление временного файла после теста
        self.test_file.close()
        os.unlink(self.test_file.name)

    def test_file_work(self):
        # Запись команд во временный файл
        commands = [
            "ADD MONITOR 1500 Samsung 24 18",
            "ADD KEYBOARD 500 Logitech MEMBRANE USB",
            "ADD CMOUSE 300 Logitech LASER 3",
            "ADD MONITOR 500 Logitech 1920 1080",
            "REM PRICE > 1000",
            "PRINT",
            "ADD CMOUSE 200 Logitech BALL 2",
            "ADD CMOUSE 200 RAZER BALL 2",
            "REM COMPANY == RAZER",
            "PRINT"
        ]
        for cmd in commands:
            self.test_file.write(cmd + '\n')
        self.test_file.seek(0)

        # Выполнение команд из файла
        self.mainwork.file_work(self.test_file.name)

        # Проверка: после выполнения всех команд в списке должно остаться два элемента
        self.assertEqual(self.mainwork.my_list.count, 4)

        # Дополнительная проверка на типы оставшихся элементов
        remaining_items = []
        remaining_items = []
        self.mainwork.my_list.traverse(lambda obj: remaining_items.append(obj))
        self.assertIsInstance(remaining_items[0], Keyboard)
        self.assertIsInstance(remaining_items[1], ComputerMouse)
        self.assertIsInstance(remaining_items[2], Monitor)
        self.assertIsInstance(remaining_items[3], ComputerMouse)
        self.assertEqual(remaining_items[0].get_keyboard_type(), "MEMBRANE")
        self.assertEqual(remaining_items[0].get_connector_type(), "USB")
        self.assertEqual(remaining_items[1].get_mouse_type(), "LASER")
        self.assertEqual(remaining_items[1].get_button_count(), 3)
        self.assertEqual(remaining_items[2].get_width(), 1920)
        self.assertEqual(remaining_items[2].get_height(), 1080)
        self.assertEqual(remaining_items[3].get_mouse_type(), "BALL")
        self.assertEqual(remaining_items[3].get_button_count(), 2)

if __name__ == '__main__':
    unittest.main()