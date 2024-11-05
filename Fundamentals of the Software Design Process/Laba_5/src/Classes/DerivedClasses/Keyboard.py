from src.Classes.BaseClasses.OfficeEquipment import OfficeEquipment
from enum import Enum

class KeyboardType(Enum):
    MEMBRANE = "MEMBRANE"
    DOMED = "DOMED"
    CAPACITIVE = "CAPACITIVE"

class Keyboard(OfficeEquipment):
    def __init__(self, price, company_name, k_type, connector_type):
        try:
            super().__init__(price, company_name)
            k_type = k_type.upper()
            if k_type not in KeyboardType.__members__:
                raise ValueError("Invalid keyboard type.")
            self.k_type = KeyboardType[k_type]
            self.connector_type = connector_type.upper()
        except ValueError as e:
            print(f"Error: {e}")
            raise

    def get_keyboard_type(self):
        return self.k_type.value

    def get_connector_type(self):
        return self.connector_type

    def cout_object(self):
        print(f"Object type - Keyboard, Company - {self.get_company_name()}, Price = {self.get_price()}, Keyboard type = {self.get_keyboard_type()}, Connector type = {self.get_connector_type()}")

