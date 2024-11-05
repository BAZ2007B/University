from src.Classes.DerivedClasses.Monitor import Monitor
from src.Classes.DerivedClasses.Keyboard import Keyboard
from src.Classes.DerivedClasses.ComputerMouse import ComputerMouse

class Commands:
    def add(self, my_list, data0, data1, data2, data3, data4):
        equipment = None
        try:
            data0 = data0.upper()

            if data0 == "KEYBOARD":
                equipment = Keyboard(data1, data2, data3, data4)
            elif data0 == "CMOUSE":
                equipment = ComputerMouse(data1, data2, data3, data4)
            elif data0 == "MONITOR":
                equipment = Monitor(data1, data2, data3, data4)
            else:
                raise ValueError("Invalid device type")

            my_list.add(equipment)
        except Exception as e:
            print(f"Exception caught: {e}")

        return my_list

    def remove(self, my_list, data0, data1, data2):
        my_list.delete_conditional(lambda obj: obj.condition_matches(data0, data1, data2))
        return my_list

    def print_list(self, my_list):
        print("\n===============Elements list===============")
        my_list.traverse(lambda obj: obj.cout_object())
        print("===========================================\n")
        return my_list