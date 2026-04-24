class Vehicle:
    def __init__(self, vid: str, model: str, year: int):
        self.vid = vid
        self.model = model
        self.year = year

    def __str__(self):
        return f"VID: {self.vid} | {self.model} ({self.year})"

    def __eq__(self, other):
        if isinstance(other, Vehicle):
            return self.vid == other.vid
        return False

    def is_new(self, n):
        return 2026 - self.year <= n


class Car(Vehicle):
    def __init__(self, vid, model, year, fuel_type, doors):
        super().__init__(vid, model, year)
        self.fuel_type = fuel_type
        self.doors = int(doors)

    def __str__(self):
        return f"[Car]        {super().__str__()} | Fuel: {self.fuel_type} | {self.doors} Doors"


class Motorcycle(Vehicle):
    def __init__(self, vid, model, year, engine_cc, type):
        super().__init__(vid, model, year)
        self.engine_cc = int(engine_cc)
        self.type = type

    def __str__(self):
        return f"[Motorcycle] {super().__str__()} | Eng: {self.engine_cc}cc | Type: {self.type}"

class Truck(Vehicle):
    def __init__(self, vid, model, year, max_load, axles):
        super().__init__(vid, model, year)
        self.max_load = int(max_load)
        self.axles = int(axles)

    def __str__(self):
        return f"[Truck]      {super().__str__()} | Load: {self.max_load}kg | {self.axles} Axles"

def save_fleet_to_file(vehicles, filename):
    with open(filename, "w") as file:
        for vehicle in vehicles:
            if isinstance(vehicle, Car):
                line = f"Car, {vehicle.vid}, {vehicle.model}, {vehicle.year}, {vehicle.fuel_type}, {vehicle.doors}"
            elif isinstance(vehicle, Truck):
                line = f"Truck, {vehicle.vid}, {vehicle.model}, {vehicle.year}, {vehicle.max_load}, {vehicle.axles}"
            elif isinstance(vehicle, Motorcycle):
                line = f"Motorcycle, {vehicle.vid}, {vehicle.model}, {vehicle.year}, {vehicle.engine_cc}, {vehicle.type}"
            else:
                line = f"Vehicle, {vehicle.vid}, {vehicle.model}, {vehicle.year}"

            file.write(line + "\n")


def load_fleet_from_file(filename):
    vehicles = []

    with open(filename, "r") as file:
        for line in file:
            parts = line.strip().split(", ")
            vehicle_type = parts[0]

            if vehicle_type == "Car":
                vehicle = Car(parts[1], parts[2], int(parts[3]), parts[4], int(parts[5]))
            elif vehicle_type == "Truck":
                vehicle = Truck(parts[1], parts[2], int(parts[3]), int(parts[4]), int(parts[5]))
            elif vehicle_type == "Motorcycle":
                vehicle = Motorcycle(parts[1], parts[2], int(parts[3]), int(parts[4]), parts[5])
            else:
                vehicle = Vehicle(parts[1], parts[2], int(parts[3]))

            vehicles.append(vehicle)

    return vehicles


vehicles = [
    Car("V001", "Tesla Model 3", 2023, "Electric", 4),
    Truck("T101", "Volvo FH16", 2019, 25000, 6),
    Motorcycle("M301", "Yamaha R1", 2024, 998, "Sport"),
    Car("V002", "Toyota Corolla", 2018, "Petrol", 4),
    Truck("T102", "Mercedes Actros", 2021, 18000, 4),
    Motorcycle("M302", "Harley Davidson", 2015, 1200, "Cruiser")
]

save_fleet_to_file(vehicles, "fleet.txt")
print("Loading fleet data from 'fleet.txt'...")
loaded_vehicles = load_fleet_from_file("fleet.txt")
print(f"{len(loaded_vehicles)} vehicles loaded successfully.")

print("\n--- All Vehicles ---")
for vehicle in loaded_vehicles:
    print(vehicle)

print("\n--- Recent Vehicles (Last 4 Years) ---")
for vehicle in loaded_vehicles:
    if vehicle.is_new(4):
        print(vehicle)

print("\n--- Electric Cars Only ---")
for vehicle in loaded_vehicles:
    if isinstance(vehicle, Car) and vehicle.fuel_type == "Electric":
        print(vehicle)
