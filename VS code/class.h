#include <iostream>
#include <vector>//Library for the vectors created bellow
#include <algorithm>//For functions emplace_back,push_back
#include <fstream>//For writing the requests,offers,properties and Customers in txt files

using namespace std;

class RealEstateAgency {
private:
    struct Property {
        string type;
        int rooms;
        string area;
        double price;
        string customerName;

        Property(const string& t, int r, const string& a, double p, const string& name)
            : type(t), rooms(r), area(a), price(p), customerName(name) {}
    };
    //Vectors for properties,requests,offers and LoyalCustomers
    vector<Property> properties;
    vector<Property> requests;
    vector<Property> offers;
    vector<string> loyalCustomers;

public:
    void addProperty(const string& type, int rooms, const string& area, double price) {
        properties.emplace_back(type, rooms, area, price, "");//adding in vector,emplace_back is used in the functions addProperty, addRequest, and addOffer because these functions are constructing the objects (Property instances) directly within the vector using the provided arguments
        writePropertiesToFile();  // Write properties to txt
    }

    void addRequest(const string& type, int rooms, const string& area, double maxPrice, const string& customerName) {
        requests.emplace_back(type, rooms, area, maxPrice, customerName);//adding in vector
        writeRequestsToFile();  // Write requests to txt
    }

    void addOffer(const string& type, int rooms, const string& area, double minPrice) {
        offers.emplace_back(type, rooms, area, minPrice, "");//adding in vector
        writeOffersToFile();  // Write offers to txt
    }

    void addLoyalCustomer(const string& customerName) {
        loyalCustomers.push_back(customerName);//adding in vector,push_back is used because in this case, the function receives an already constructed customerName string as an argument
        writeCustomerToFile();//Write Customers to txt
    }

    void processTransactions() {
        for (auto& request : requests) { //auto&=syntax is used to deduce the type of the loop variable request.
            auto matchingOffer = findMatchingOffer(request);//"auto"-the compiler determines the appropriate type based on the expression on the right side of the assignment
            if (matchingOffer != offers.end()) {
                double commission = calculateCommission(matchingOffer->price);
                if (isLoyalCustomer(request)) {
                    commission *= 0.5; // 50% discount for loyal customers
                }
                cout << "Transaction completed:\n";
                cout << "    Request: " << request.type << " with " << request.rooms << " rooms in " << request.area << " area\n";
                cout << "    Offer: " << matchingOffer->type << " with " << matchingOffer->rooms << " rooms in " << matchingOffer->area << " area\n";
                cout << "    Customer: " << request.customerName << endl; // Display customer name
                cout << "    Commission: " << commission << " USD\n";
                cout << "-------------------------------------------\n";
                // Remove the matched offer
                offers.erase(matchingOffer);
            }
            else {
                cout << "No matching offer found for the request:\n";
                cout << "    Request: " << request.type << " with " << request.rooms << " rooms in " << request.area << " area\n";
                cout << "    Customer: " << request.customerName << endl; // Display customer name
                cout << "-------------------------------------------\n";
            }
        }
    }

private:
    vector<Property>::iterator findMatchingOffer(const Property& request) {
        return find_if(offers.begin(), offers.end(), [&](const Property& offer) { //The function uses the find_if algorithm from the <algorithm> library to search for a matching offer. find_if searches for the first element in a range for which a given predicate function returns true.
            return offer.type == request.type &&
                offer.area == request.area &&
                offer.price <= request.price;
        });
    }

    bool isLoyalCustomer(const Property& request) {
        return find(loyalCustomers.begin(), loyalCustomers.end(), request.area) != loyalCustomers.end();
    }


    double calculateCommission(double price) {
        return price * 0.05; // 5% commission as a percentage of the transaction level
    }

    void writeCustomerToFile()//Functions for writing in Files
{
    ofstream outputFile("customers.txt");
    if(!outputFile)
    {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const auto& customer : loyalCustomers) {
        outputFile << "Customer Name: " << customer << endl;
        outputFile << "-------------------------------------------\n";
    }

    outputFile.close();
    cout << "Loyal customers written to file: customers.txt" << endl;
}

    void writePropertiesToFile() {
        ofstream outputFile("properties.txt");//The ofstream class is used for writing data to files. If the file doesn't exist, it will be created. If the file already exists, its contents will be overwritten.
        if (!outputFile) { //Checks if the txt file is opened
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }

        for (const auto& property : properties) { //const auto&: This declares a constant reference variable named property that will be used to iterate over the elements in the properties vector. The auto keyword allows the compiler to automatically deduce the type of the elements in the vector, while const specifies that the elements should not be modified within the loop.
            outputFile << "Type: " << property.type << endl;
            outputFile << "Rooms: " << property.rooms << endl;
            outputFile << "Area: " << property.area << endl;
            outputFile << "Price: " << property.price << endl;
            outputFile << "-------------------------------------------\n";
        }

        outputFile.close();
        cout << "Properties written to file: properties.txt" << endl;
    }

    void writeRequestsToFile() {
        ofstream outputFile("requests.txt");
        if (!outputFile) {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }

        for (const auto& request : requests) {
            outputFile << "Type: " << request.type << endl;
            outputFile << "Rooms: " << request.rooms << endl;
            outputFile << "Area: " << request.area << endl;
            outputFile << "Max Price: " << request.price << endl;
            outputFile << "-------------------------------------------\n";
        }

        outputFile.close();
        cout << "Requests written to file: requests.txt" << endl;
    }

    void writeOffersToFile() {
        ofstream outputFile("offers.txt");
        if (!outputFile) {
            cout << "Error: Unable to open file for writing." << endl;
            return;
        }
    for (const auto& offer : offers) {
            outputFile << "Type: " << offer.type << endl;
            outputFile << "Rooms: " << offer.rooms << endl;
            outputFile << "Area: " << offer.area << endl;
            outputFile << "Min Price: " << offer.price << endl;
            outputFile << "-------------------------------------------\n";
        }

        outputFile.close();
        cout << "Offers written to file: offers.txt" << endl;
    }

};
