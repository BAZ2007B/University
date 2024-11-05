from src.Classes.BaseClasses.OfficeEquipment import OfficeEquipment
from enum import Enum

class MouseType(Enum):
    BALL = "BALL"
    LASER = "LASER"

class ComputerMouse(OfficeEquipment):
    def __init__(self, price, company_name, m_type, button_count):
        try:
            super().__init__(price, company_name)
            m_type = m_type.upper()
            if m_type not in MouseType.__members__:
                raise ValueError("Invalid mouse type.")
            self.m_type = MouseType[m_type]
            self.button_count = int(button_count)

            if self.button_count <= 0:
                raise ValueError("Button count cannot be less 1.")
        except ValueError as e:
            print(f"Error: {e}")
            raise

    def get_mouse_type(self):
        return self.m_type.value

    def get_button_count(self):
        return self.button_count

    def cout_object(self):
        print(f"Object type - Computer Mouse, Company - {self.get_company_name()}, Price = {self.get_price()}, Mouse type = {self.get_mouse_type()}, Buttons count = {self.get_button_count()}")
