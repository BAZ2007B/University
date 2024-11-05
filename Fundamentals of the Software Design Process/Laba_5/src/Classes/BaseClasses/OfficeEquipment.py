class OfficeEquipment:
    def __init__(self, price, company_name):
        try:
            self.price = int(price)
            if self.price < 0:
                raise ValueError("Price cannot be negative.")
        except ValueError as e:
            print(f"Error: {e}")
            raise

        self.company_name = company_name.upper()

    def get_price(self):
        return self.price

    def get_company_name(self):
        return self.company_name

    def condition_matches(self, var, comp, value):
        var = var.upper()
        if var == "PRICE":
            try:
                price_value = int(value)
                if price_value <= 0:
                    raise ValueError("Value must be a positive integer for PRICE.")

                comparisons = {
                    ">": self.price > price_value,
                    "<": self.price < price_value,
                    ">=": self.price >= price_value,
                    "<=": self.price <= price_value,
                    "==": self.price == price_value,
                    "!=": self.price != price_value
                }
                return comparisons.get(comp, False)
            except ValueError as e:
                print(f"Error: {e}")
                return False

        elif var == "COMPANY":
            value = value.upper()
            if comp == "==":
                return self.company_name == value
            elif comp == "!=":
                return self.company_name != value

        return False

    def cout_object(self):
        raise NotImplementedError("This method should be implemented by subclasses.")