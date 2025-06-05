#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct ShoppingItem {
    string name;
    double price;
};

int main() {
    vector<ShoppingItem> shoppingList;
    string address;
    double totalCost = 0.0;
    int deliveryTimeInHours = 2; // Assuming 2 hours for delivery

    cout << "Enter your shopping list (type 'done' to finish):\n";
    while (true) {
        ShoppingItem item;
        cout << "Item name: ";
        cin >> item.name;

        if (item.name == "done") {
            break;
        }
        cout << "Item price: $";
        cin >> item.price;

        shoppingList.push_back(item);
        totalCost += item.price;
    }
    cout << "Enter your delivery address: ";
    cin.ignore(); // Clear input buffer
    getline(cin, address);

    double deliveryCost = totalCost * 0.1; // Assuming 10% delivery fee
    cout << "\nEstimated delivery time: " << deliveryTimeInHours << " hours\n";
    cout << "Total cost of items: $" << totalCost << endl;
    cout << "Delivery cost: $" << deliveryCost << endl;
    cout << "Delivery address: " << address << endl;
    cout << "---------------------------------\n";
    cout << "Total cost with delivery: $" << totalCost + deliveryCost << endl;
    return 0;
}
