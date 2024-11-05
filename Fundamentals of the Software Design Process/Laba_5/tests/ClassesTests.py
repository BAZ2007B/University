import unittest
from src.Classes.BaseClasses.OfficeEquipment import OfficeEquipment
from src.Classes.DerivedClasses.Monitor import Monitor
from src.Classes.DerivedClasses.Keyboard import Keyboard
from src.Classes.DerivedClasses.ComputerMouse import ComputerMouse

class OfficeEquipmentTest(unittest.TestCase):
    def test_office_equipment_creation(self):
        oe = OfficeEquipment(1000, 'Dell')
        self.assertEqual(oe.get_price(), 1000)
        self.assertEqual(oe.get_company_name(), 'DELL')

    def test_invalid_price(self):
        with self.assertRaises(ValueError):
            OfficeEquipment(-100, 'Dell')

    def test_condition_matches_price(self):
        oe = OfficeEquipment(1000, 'Dell')
        self.assertTrue(oe.condition_matches("price", ">", 500))
        self.assertFalse(oe.condition_matches("price", "<", 500))

    def test_condition_matches_company(self):
        oe = OfficeEquipment(1000, 'Dell')
        self.assertTrue(oe.condition_matches("company", "==", "dell"))
        self.assertFalse(oe.condition_matches("company", "!=", "DELL"))

class MonitorTest(unittest.TestCase):
    def test_monitor_creation(self):
        monitor = Monitor(1500, 'Samsung', 24, 18)
        self.assertEqual(monitor.get_price(), 1500)
        self.assertEqual(monitor.get_width(), 24)
        self.assertEqual(monitor.get_height(), 18)

    def test_invalid_dimensions(self):
        with self.assertRaises(ValueError):
            Monitor(1500, 'Samsung', -24, 18)

class KeyboardTest(unittest.TestCase):
    def test_keyboard_creation(self):
        keyboard = Keyboard(500, 'Logitech', 'MEMBRANE', 'USB')
        self.assertEqual(keyboard.get_keyboard_type(), 'MEMBRANE')
        self.assertEqual(keyboard.get_connector_type(), 'USB')

    def test_invalid_keyboard_type(self):
        with self.assertRaises(ValueError):
            Keyboard(500, 'Logitech', 'INVALID', 'USB')

class ComputerMouseTest(unittest.TestCase):
    def test_computer_mouse_creation(self):
        mouse = ComputerMouse(300, 'Razer', 'LASER', 3)
        self.assertEqual(mouse.get_mouse_type(), 'LASER')
        self.assertEqual(mouse.get_button_count(), 3)

    def test_invalid_button_count(self):
        with self.assertRaises(ValueError):
            ComputerMouse(300, 'Razer', 'LASER', 0)

if __name__ == '__main__':
    unittest.main()