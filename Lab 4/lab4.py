num_users = int(input("Enter number of users: "))

user_data = {}
all_items_list = []

for i in range(num_users):
    username = input("Enter username: ")
    num_items = int(input("How many items? "))

    items = []
    for j in range(num_items):
        item = input(f"Item {j + 1}: ")
        items.append(item)
        all_items_list.append(item)

    user_data[username] = items

common_items = set()
unique_items = set()

for item in set(all_items_list):
    if all_items_list.count(item) > 1:
        common_items.add(item)
    else:
        unique_items.add(item)

print("\nUSER DATA:")
for user, items in user_data.items():
    print(f"{user} -> {items}")

print("\nCOMMON ITEMS:")
for item in common_items:
    print(item)

print("\nUNIQUE ITEMS:")
for item in unique_items:
    print(item)

most_popular = ""
max_count = 0
for item in set(all_items_list):
    if all_items_list.count(item) > max_count:
        max_count = all_items_list.count(item)
        most_popular = item

print("\nMOST POPULAR ITEM:")
print(most_popular)