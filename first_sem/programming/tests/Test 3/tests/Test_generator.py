import random

def generate_bike_line():
    bike_type = random.choice(["CHILD", "TEENAGER", "ROAD", "SPORT"])
    model = "Model" + str(random.randint(1, 1000))
    warranty_period = random.randint(180, 365)
    arrival_date = "2023-" + str(random.randint(1, 12)).zfill(2) + "-" + str(random.randint(1, 28)).zfill(2)
    quantity_in_stock = random.randint(5, 20)
    price = round(random.uniform(99.99, 499.99), 2)
    is_active = 1

    if bike_type == "CHILD":
        wheel_count = 3
        front_wheel_radius = random.randint(10, 15)
        rear_wheel_radius = random.randint(10, 15)
        bike_line = f"0 {model} {warranty_period} {arrival_date} {quantity_in_stock} {price} {is_active} {wheel_count} {front_wheel_radius} {rear_wheel_radius}"
    elif bike_type == "TEENAGER":
        wheel_radius = random.randint(15, 25)
        gears_count = random.randint(6, 21)
        bike_line = f"1 {model} {warranty_period} {arrival_date} {quantity_in_stock} {price} {is_active} {wheel_radius} {gears_count}"
    elif bike_type == "ROAD":
        has_suspension = random.choice([0, 1])
        has_hand_brake = random.choice([0, 1])
        bike_line = f"2 {model} {warranty_period} {arrival_date} {quantity_in_stock} {price} {is_active} {has_suspension} {has_hand_brake}"
    elif bike_type == "SPORT":
        weight = round(random.uniform(10.0, 20.0), 2)
        tire_width = round(random.uniform(1.0, 2.5), 2)
        frame_material = random.choice(["Aluminum", "Carbon", "Steel"])
        bike_line = f"3 {model} {warranty_period} {arrival_date} {quantity_in_stock} {price} {is_active} {weight} {tire_width} {frame_material}"

    return bike_line

def generate_test_file(file_path, num_bikes):
    with open(file_path, "w") as file:
        for _ in range(num_bikes):
            bike_line = generate_bike_line()
            file.write(bike_line + "\n")

generate_test_file("bikes_test.txt", 1000)
