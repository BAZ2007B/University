from src.Classes.BaseClasses.OfficeEquipment import OfficeEquipment

class Monitor(OfficeEquipment):
    def __init__(self, price, company_name, width, height):
        try:
            super().__init__(price, company_name)
            self.width = int(width)
            self.height = int(height)

            if self.width <= 0 or self.height <= 0:
                raise ValueError("Width or height cannot be negative.")
        except ValueError as e:
            print(f"Error: {e}")
            raise

    def get_width(self):
        return self.width

    def get_height(self):
        return self.height

    def cout_object(self):
        print(f"Object type - Monitor, Company - {self.get_company_name()}, Price = {self.get_price()}, Width = {self.get_width()}, Height = {self.get_height()}")
