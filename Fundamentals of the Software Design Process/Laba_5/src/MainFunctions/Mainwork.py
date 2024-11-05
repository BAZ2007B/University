from src.Lists.List import List
from src.Commands.Commands import Commands

class Mainwork:
    def __init__(self):
        self.my_list = List()
        self.command = Commands()

    def string_line_correct(self, line):
        words = line.upper().split()
        if words:
            first_word = words[0]
            if first_word in ["PRINT", "ADD", "REM"]:
                return first_word
        return "ERROR"

    def string_works(self, line):
        data = line.split()
        command = data[0].upper()

        match command:
            case "ADD":
                while len(data) < 6:
                    data.append("")
                self.my_list = self.command.add(self.my_list, *data[1:6])
            case "REM":
                while len(data) < 4:
                    data.append("")
                self.my_list = self.command.remove(self.my_list, *data[1:4])
            case "PRINT":
                self.my_list = self.command.print_list(self.my_list)
            case _:
                print("Wrong Line:", line)

    def file_work(self, filename):
        try:
            with open(filename, 'r') as file:
                for line in file:
                    self.string_works(line.strip())
        except FileNotFoundError:
            print("File opening error! Check the presence of the file or its name.")