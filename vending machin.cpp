#include <iostream>   // Include the input/output stream library for cin and cout
#include <iomanip>    // Include library for formatting output (like setprecision)
using namespace std;  // Use the standard namespace to avoid writing std::

// Constants
const int ITEM_COUNT = 6;  // Number of items in the vending machine

// Item data stored in arrays
string codes[ITEM_COUNT] = {"D1", "D2", "D3", "S1", "S2", "S3"}; // Codes for each item
string names[ITEM_COUNT] = { "Cola", "Water", "Orange Juice",
                             "Crisps", "Biscuits", "Chocolate"}; // Names of each item
double prices[ITEM_COUNT] = {1.50, 1.00, 1.50, 0.75, 1.75, 1.25}; // Prices of each item
int stock[ITEM_COUNT] = {5, 5, 5, 5, 5, 5};                        // Initial stock for each item

// Function to display the vending machine menu
void displayMenu()
{
    cout << "\n===== VENDING MACHINE MENU =====\n"; // Header
    cout << "DRINKS:\n";                             // Drinks section
    cout << "D1 - Cola (£1.50) | Stock: " << stock[0] << endl;  // Show code, name, price, stock
    cout << "D2 - Water (£1.00) | Stock: " << stock[1] << endl;
    cout << "D3 - Orange Juice (£1.50) | Stock: " << stock[2] << endl;

    cout << "\nSNACKS:\n";                          // Snacks section
    cout << "S1 - Crisps (£0.75) | Stock: " << stock[3] << endl;
    cout << "S2 - Biscuits (£1.75) | Stock: " << stock[4] << endl;
    cout << "S3 - Chocolate (£1.25) | Stock: " << stock[5] << endl;
    cout << "================================\n";     // Footer
}

// Function to find the index of an item based on its code
int getItemIndex(string code)
{
    for (int i = 0; i < ITEM_COUNT; i++)   // Loop through all item codes
    {
        if (codes[i] == code)              // If code matches
            return i;                      // Return the index of the item
    }
    return -1; // Not found
}
// Function to handle a purchase
void processPurchase(int index)
{
    double moneyInserted; // Variable to store the money user inserts

    if (stock[index] <= 0)  // Check if item is out of stock
    {
        cout << "Sorry, " << names[index] << " is out of stock.\n";
        return;             // Exit the function
    }

    cout << "Insert money (£): "; // Ask user to insert money
    cin >> moneyInserted;

    if (moneyInserted < prices[index])  // Check if inserted money is enough
    {
        cout << "Insufficient funds. Money refunded: £"
             << fixed << setprecision(2) << moneyInserted << endl; // Show refunded money
        return;  // Exit function
    }

    stock[index]--;                     // Decrease stock by 1
    double change = moneyInserted - prices[index]; // Calculate change

    cout << "Dispensing " << names[index] << "...\n"; // Dispense item
    cout << "Change returned: £"
         << fixed << setprecision(2) << change << endl; // Show change

    // Provide suggestions based on the type of item bought
    if (index <= 2)   // If a drink was bought
        cout << "Suggestion: Would you like some Crisps or Chocolate?\n";
    else              // If a snack was bought
        cout << "Suggestion: Why not try a drink next?\n";

    cout << "Thank you for your purchase!\n"; // Thank the user
}

// Main function
int main()
{
    string code;  // Variable to store item code entered by user
    char choice;  // Variable to store whether user wants to continue

    do  // Loop to allow multiple purchases
    {
        displayMenu();  // Show the menu

        cout << "Enter the item code: "; // Ask for item code
        cin >> code;

        int index = getItemIndex(code); // Get the item index from code

        if (index == -1)  // If code is invalid
        {
            cout << "Invalid code. Please try again.\n";
            continue;    // Go back to start of loop
        }

        processPurchase(index);  // Process the purchase

        cout << "\nWould you like to buy another item? (Y/N): "; // Ask to continue
        cin >> choice;

    } while (choice == 'Y' || choice == 'y'); // Repeat if user says yes

    cout << "Thank you for using snackco!\n"; // Exit message
    return 0;  // Exit program
}

