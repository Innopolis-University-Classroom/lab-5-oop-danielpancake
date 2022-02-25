//
//  landlord.cpp
//  Landlord
//
//  Created by Gbrigens on 1/11/22.
//

//landlord.cpp
//models the finances for an apartment building
#include "landlord.h" //for class declarations, etc.

void getaLine(string& inStr) {
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n');
    inStr = temp;
}

char getaChar() {
    char ch = cin.get();
    cin.ignore(80, '\n');
    return ch;
}

bool operator < (const tenant& t1, const tenant& t2){ return t1.name < t2.name; }

userInterface::userInterface() {
    ptrTenantList = new tenantList();
};

userInterface::~userInterface() {
    //delete ptrTenantList;
    //delete ptrTenantInputScreen;
    //delete ptrRentRecord;
    //delete ptrRentInputScreen;
    //delete ptrExpenseRecord;
    //delete ptrExpenseInputScreen;
    //delete ptrAnnualReport;
};

/**
 * @brief Inmplementatino of the input shell
 */
enum State { IDLE, INPUT, DISPLAY };
std::string message(State state) {
    std::string line = "Enter ";
    std::string off  = "      ";

    switch (state) {
        case IDLE:
            line += "\"i\" to input data,\n";
            line += off + "\"d\" to dispay a report,\n";
            line += off + "\"q\" to quit program: ";
        break;

        case INPUT:        
            line += "\"t\" to add tenant,\n";
            line += off + "\"r\" to record rent payment,\n";
            line += off + "\"e\" to record expense: ";
        break;

        case DISPLAY:        
            line += "\"t\" to display ternants,\n";
            line += off + "\"r\" to display reports,\n";
            line += off + "\"e\" to display expenses,\n";
            line += off + "\"a\" to display annual reports: ";
        break;
    }
    return line;
}

void userInterface::interact() {
    State state = State::IDLE;

    while (true) {
        std::cout << message(state);

        switch(state) {
            case State::IDLE:
                switch (getaChar()) {
                    case 'i': state = State::INPUT; break;
                    case 'd': state = State::DISPLAY; break;
                    case 'q': return;
                    default: break;
                }
            break;
            default:
                switch (getaChar()) {
                    /**/
                }
                state = State::IDLE;
            break;
        }
    }
};
