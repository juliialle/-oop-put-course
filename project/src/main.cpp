#include <iostream>
#include "clothes.h"
#include "accessories.h"
#include "cart.h"
#include "order.h"
#include "exception.h"

using namespace std;

int NR = 1;

int main() {
    Clothes tshirt1("Golden State Warriors", "T-Shirt - Blue - Stephen Curry", 31, 1, 100, 'S', "Women");
    Clothes tshirt2("Golden State Warriors", "T-Shirt - Blue - Stephen Curry", 31, 2, 100, 'M', "Women");
    Clothes tshirt3("Golden State Warriors", "T-Shirt - Blue - Stephen Curry", 31, 3, 100, 'L', "Women");
    Clothes tshirt4("Golden State Warriors", "T-Shirt - Blue - Stephen Curry", 31, 4, 100, 'S', "Men");
    Clothes tshirt5("Golden State Warriors", "T-Shirt - Blue - Stephen Curry", 31, 5, 100, 'M', "Men");
    Clothes tshirt6("Golden State Warriors", "T-Shirt - Blue - Stephen Curry", 31, 6, 100, 'L', "Men");
    Clothes tshirt7("Golden State Warriors", "T-Shirt - Blue - Stephen Curry - Unisex", 20, 7, 100, 'U', "Kids");

    Accessories basketball1("Golden State Warriors", "Wilson NBA Team Composite Basketball - Size 7", 48, 28, 50);
    Accessories basketball2("NBA", "NBA Wilson Authentic Official Game Ball - Size 7", 279, 29, 20);

    int outerChoice, innerChoice;
    int add, select, how;
    bool exitOuterMenu = false;
    bool exitInnerMenu = false;
    Cart guestcart;
    Order *order = nullptr;

    while (!exitOuterMenu) {
        cout << "Menu:" << endl;
        cout << "1. Show products" << endl;
        cout << "2. Add to Cart" << endl;
        cout << "3. Go to Cart" << endl;
        cout << "4. Exit" << endl;

        try {
            cout << "Enter your choice: ";
            cin >> outerChoice;

            if (cin.fail()) {
                throw Exception();
            }

            switch (outerChoice) {
                case 1:
                    cout << tshirt1.GetDescription() << endl;
                    cout << tshirt2.GetDescription() << endl;
                    cout << tshirt3.GetDescription() << endl;
                    cout << tshirt4.GetDescription() << endl;
                    cout << tshirt5.GetDescription() << endl;
                    cout << tshirt6.GetDescription() << endl;
                    cout << tshirt7.GetDescription() << endl;
                    cout << basketball1.GetDescription() << endl;
                    cout << basketball2.GetDescription() << endl;
                    break;

                case 2:
                    cout << "Enter ID of product that you want to add to your cart: ";
                    cin >> add;

                    if (add == 1) {
                        if (tshirt1.ShowAvailability() != 0) {
                            guestcart.AddCloth(tshirt1);
                            tshirt1.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 2) {
                        if (tshirt2.ShowAvailability() != 0) {
                            guestcart.AddCloth(tshirt2);
                            tshirt2.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 3) {
                        if (tshirt3.ShowAvailability() != 0) {
                            guestcart.AddCloth(tshirt3);
                            tshirt3.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 4) {
                        if (tshirt4.ShowAvailability() != 0) {
                            guestcart.AddCloth(tshirt4);
                            tshirt4.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 5) {
                        if (tshirt5.ShowAvailability() != 0) {
                            guestcart.AddCloth(tshirt5);
                            tshirt5.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 6) {
                        if (tshirt6.ShowAvailability() != 0) {
                            guestcart.AddCloth(tshirt6);
                            tshirt6.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 7) {
                        if (tshirt7.ShowAvailability() != 0) {
                            guestcart.AddCloth(tshirt7);
                            tshirt7.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 28) {
                        if (basketball1.ShowAvailability() != 0) {
                            guestcart.AddAccessory(basketball1);
                            basketball1.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    } else if (add == 29) {
                        if (basketball2.ShowAvailability() != 0) {
                            guestcart.AddAccessory(basketball2);
                            basketball2.StockUpdate();
                        } else
                            cout << "Out of stock!" << endl;
                    }
                    break;

                case 3:
                    exitInnerMenu = false;
                    while (!exitInnerMenu) {
                        cout << "My cart:" << endl;
                        cout << "1. Show my products" << endl;
                        cout << "2. Make an order" << endl;
                        cout << "3. Go back to main menu" << endl;
                        try {
                            cout << "Enter your choice: ";
                            cin >> innerChoice;

                            if (cin.fail()) {
                                throw Exception();
                            }

                            switch (innerChoice) {
                                case 1:
                                    Cart::ShowCart(guestcart);
                                    break;
                                case 2:
                                    Cart::ShowCart(guestcart);
                                    order = new Order(NR++, 0);
                                    try {
                                        cout << "How many products would you like to add to your order?" << endl;
                                        cin >> how;
                                        cout << endl;
                                        if (cin.fail()) {
                                            throw Exception();
                                        }
                                        for (int i = 0; i < how; i++) {
                                            cout << "Enter ID of product from your cart that you want to add to your order: ";
                                            cin >> select;
                                            cout << endl;
                                            if (0 < select && select < 8)
                                                order->MakeOrder(guestcart, select, 1);
                                            else if (select == 28 || select == 29)
                                                order->MakeOrder(guestcart, select, 2);
                                            else
                                                cout << "This ID doesn't exist or is invalid." << endl;
                                        }
                                        order->ShowOrder();
                                        order->OrderDetails();
                                    }
                                    catch (const Exception &e) {
                                        cout << "Error: " << e.what() << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    break;
                                case 3:
                                    exitInnerMenu = true;
                                    break;
                                default:
                                    cout << "Invalid choice!" << endl;
                                    break;
                            }
                        }
                        catch (const Exception &e) {
                            cout << "Error: " << e.what() << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                    }
                    break;
                case 4:
                    exitOuterMenu = true;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        }
        catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
    delete order;
    return 0;
}