# This is a sample Python script.
from src.MainFunctions.Mainwork import Mainwork

def main():
    filename = "./src/Commands/Commands.txt"
    equipment = Mainwork()
    equipment.file_work(filename)

if __name__ == "__main__":
    main()
