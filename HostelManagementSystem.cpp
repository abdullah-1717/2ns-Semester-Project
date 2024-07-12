#include <iostream>
#include <iomanip> 
#include <windows.h>
#include <fstream>
#include <sstream>
#include <limits>    

using namespace std;

class Hostel
{
    protected:
    string name, fatherName, CNIC, phoneNumber, address;
    public:
    Hostel()
    {  
    }
    void setName()
    {
        cout << "Enter Name: ";
        getline (cin, name);
    }
    string getName()
    {
        return name;
    }
    void setFatherName()
    {
        cout << "Enter Father Name: ";
        getline (cin, fatherName);
    }
    string getFatherName()
    {
        return fatherName;
    }
    void setCNIC()
    {
        cout << "Enter CNIC Number: ";
        getline (cin, CNIC);
    }
    string getCNIC()
    {
        return CNIC;
    }
    void setPhoneNumber()
    {
        cout << "Enter Contact Number: ";
        getline (cin, phoneNumber);
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    void setAddress()
    {
        cout << "Enter Address: ";
        getline (cin, address);
    }
    string getAddress()
    {
        return address;
    }
};
class Room:public Hostel
{
    protected:
    int room = 0, roomNumber = 0, roomCharges = 0;
    int roomSingle[5];
    int room2seat[5][2];
    int room4seat[5][4];
    string roomAllocation,floor;
    public:
    Room()
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                room2seat[i][j] = 0;
            }
            for (int k = 0; k < 4; k++)
            {
                room4seat[i][k] = 0;       
            }
            roomSingle[i] = 0;
        }
    }
    void roomInfo()
    {
        cout << "1. Single seater Room" << endl;
        cout << "2. Two seater Room" << endl;
        cout << "3. Four seater Room" << endl;
    }
    void roomPrice()
    {
        cout << "For Single seater Room Rs.10000" << endl;
        cout << "For Two seater Room Rs.8000/seat" << endl;
        cout << "For Four seater Room Rs.5000/seat" << endl;
    }
    int getRoomCharges()
    {
        return roomCharges;
    }
    string getFloor()
    {
        if(room==1)
        {
            floor = to_string(3);
            return floor;
        }
        else if (room==2)
        {
            floor = to_string(room);
            return floor;
        }
        else if (room==3)
        {
            floor = to_string(1);  
            return floor;
        }
    }
    string getRoom()
    {
        roomAllocation = to_string(roomNumber);
        return roomAllocation;
    }
    bool roomAvailible()
    { 
        bool roomChecking=false;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                if(room2seat[i][j] == 0)
                {
                    roomChecking = true;
                }
            }
            for (int k = 0; k < 4; k++)
            {
                if (room4seat[i][k] == 0) 
                {
                    roomChecking = true;
                }      
            }
            if (roomSingle[i] == 0)
            {
                roomChecking = true;
            }
        }
        return roomChecking;
    }
    void setRoom()
    {
        bool exitFunction=false;
        do
        { 
            bool roomFull=false, forOne=false;
            repeat:
            cout << endl << endl << "Select Room Option:" << endl;
            roomInfo();
            cin >> room;
            cin.ignore();
            if(room == 1)
            {
                for(int i = 0; i < 5; i++)
                {
                    if (forOne == false)
                    {
                        if(roomSingle[i] == 0)
                        {
                            roomSingle[i] = i+1;
                            roomNumber = i+1;
                            roomFull = true;
                            forOne = true;
                            exitFunction = true;
                        }
                    }
                }
                if (roomFull == false)
                {
                    cout << endl << "Single Room Full" << endl;
                    goto repeat;
                }
            }
            else if(room == 2)
            {
                for(int i = 0; i < 5; i++)
                {
                    for(int j =0;j < 2; j++)
                    {
                        if (forOne == false)
                        {
                            if(room2seat[i][j] == 0)
                            {
                                room2seat[i][j] = i+1;
                                roomNumber = i+1;
                                roomFull = true;
                                forOne = true;
                                exitFunction = true;
                            }
                        }
                    }
                }
                if (roomFull == false)
                {
                    cout << endl << "Two seater Room is Full:" << endl;
                    goto repeat;
                }
            }
            else if (room == 3)
            {
                for(int i = 0; i < 5; i++)
                {
                    for(int j = 0;j < 4; j++)
                    {
                        if (forOne == false)
                        {
                            if(room4seat[i][j] == 0)
                            {
                                room4seat[i][j] = i+1;
                                roomNumber = i+1;
                                roomFull = true;
                                forOne = true;
                                exitFunction = true;
                            }
                        }
                    }
                }
                if (roomFull == false)
                {
                    cout << endl << "Four seater Room is Full:" << endl;
                    goto repeat;
                }
            }
            else
            {
                cout << endl << "Invalid Choice:" << endl;
                goto repeat;
            }
        } while ( exitFunction == false);
    }
};
class Facilities: public Room
{
    private:
    bool messExit = false, laundryExit = false;
    int checkPrice = 0 ,messPrice = 0 ,LaundryCharges = 0;
    public:
    Facilities()
    {
    }
    void faciInfo()
    {
        cout << "Laundry" << endl;
        cout << "Mess" << endl;
        cout << "Wifi" << endl;
        cout <<"Cameras security" << endl;
    }
    void laundryPrice()
    {
        cout << "Laundry Price Rs.2000/Month" << endl;
    }
    void setLaundryCharges()
    {
        do
        {
            laundryExit = false;
            cout << endl << "Do you want to take laundry Rs.2000/Month" << endl ;
            cout << "1. For Yes:" << endl;
            cout << "2. For No: " ;
            cin >> LaundryCharges;
            cin.ignore();
            if (LaundryCharges == 1)
            {
                LaundryCharges = 2000;
                laundryExit = true;
            }
            else if (LaundryCharges == 2)
            {
                LaundryCharges = 0;
                laundryExit = true;
            }
            else 
            {
                cout << endl << "Invalid choice: " << endl;
            }
        } while (laundryExit != true);
    }
    int getLaundryCharges()
    {
        return LaundryCharges; 
    }
    void messCharges()
    {
        cout << "1. Breakfast Price Rs.2000/Month" << endl;
        cout << "2. Lunch Price Rs.2500/Month" << endl;
        cout << "3. Dinner Price Rs.2500/Month" << endl;
    }
    void setMessCharges()
    {
        do 
        {
            messExit = false;
            cout << endl;
        messCharges();
        cout<<"4. Breakfast, Lunch & Dinner Price Rs.6000/Month " << endl;
        cout << "5. For No Mess. ";
        cin>>messPrice;
        cin.ignore();
        if (messPrice == 1)
        {
            messPrice = 2000;
            messExit = true;
        }
        else if (messPrice == 2)
        {
            messPrice = 2500;
            messExit = true;
        }
        else if (messPrice == 3)
        {
            messPrice = 2500;
            messExit = true;
        }
        else if (messPrice == 4)
        {
            messPrice = 6000;
            messExit = true;
        }
        else if (messPrice == 5)
        {
            messPrice  = 0;
            messExit = true;
        }
        else 
        {
            cout << endl << "Invalid choice: " << endl;
        }
        }while (messExit != true);
    }
    int getMessPrice()
    {
        return messPrice;
    }
    void checkPrices()
    {
        do
        {
            cout << endl << "Chose Option:" << endl << endl;
            cout << "1. For Room Prices:" << endl;
            cout << "2. For Laundry Price:" << endl;
            cout << "3. For Mess:" << endl;
            cout << "4. For Main menu" << endl;
            cin >> checkPrice;
            cin.ignore();
            if (checkPrice == 1)
            {
                cout << endl << endl << "Room Prices:" << endl;
                roomPrice();
            }
            else if (checkPrice == 2)
            {
                cout << endl << endl << "Laundry Price:" << endl;
                laundryPrice();
            }
            else if (checkPrice == 3)
            {
                cout << endl << endl << "Mess Charges:" << endl;
                messCharges();
            }
            else if(checkPrice == 4)
            {
            }
            else 
            {
                cout << endl << "Invalid choice:" << endl;
            }
        }while (checkPrice!=4);
    }
    void display()
    {
        cout << "Name: " << getName() << endl;
        cout << "Father Name: " << getFatherName() << endl;
        cout << "CNIC: " << getCNIC() << endl;
        cout << "Phone Number: " << getPhoneNumber() << endl;
        cout << "Floor N0. " << getFloor() << endl;
        cout << "Room No. " << getRoom() << endl;
        cout << "Room Charges: ";
        if (room == 1)
        {
            roomCharges = 10000;
        }
        else if (room == 2)
        {
            roomCharges = 8000;
        }
        else if (room == 3)
        {
            roomCharges = 5000;
        }
        cout << getRoomCharges() << endl;
        cout << "Mess Charges: " << getMessPrice() << endl;
        cout << "Laundry Charges: " << getLaundryCharges() << endl;
        cout << "Total Charges: " << (getRoomCharges() + getMessPrice() + getLaundryCharges());
    }
    void storeFile(ofstream& Write)
    {
        Write<<getFloor()<<"  |  "<<getRoom()<<"  |  "<<getName()<<"  |  "<<getFatherName()<<"  |  "<<getCNIC()<<"  |  "<<getPhoneNumber()<<"  |  "<<getAddress()<<endl;
    }
};
class Admin: public Facilities
{
    private:
    ofstream WriteData;
    double adminPassword = 0;
    int option1 = 0, status = 0, floorStatus = 0, statusOption = 0;
    public:
    Admin()
    {
    ifstream Read("Storage.csv");
    string read;
    int i = 0, j = 0, k = 0, m = 0, n = 0; //these are loop indexes.
    while (getline(Read, read))
    {
        istringstream iss(read);
        getline(iss, floor , '|');
        getline(iss, roomAllocation , '|');
        getline(iss,  name, '|');
        getline(iss, fatherName, '|');
        getline(iss, CNIC, '|');
        getline(iss, phoneNumber, '|');
        getline(iss, address,'|');
        if (stoi(floor) == 3)
        {
            roomSingle[i]= stoi(roomAllocation);
            i++;
        }
        else if (stoi(floor) == 2)
        {
            room2seat[j][k] = stoi(roomAllocation);
            k++;
            if (k == 2)
            {
                k = j;
                j++;
            }
        }
        else if (stoi(floor) == 1)
        {
            room4seat[m][n] = stoi(roomAllocation);
            n++;
            if (n == 4)
            {
                n = 0;
                m++;
            }
        }
    }
    Read.close();
    }
    void menu()
    {
        repeat:
        do
        {
            // menu setting.
            cout << endl << endl << "Select Option Number:" << endl;
            cout << "1. For Room info." << endl;
            cout << "2. For Facilities. " << endl;
            cout << "3. For Check Prices." << endl;
            cout << "4. For Admission." << endl;
            cout << "5. For Admin." << endl;   
            cout << "6. For Exit. " ;
            cin >> option1;
            cin.ignore();
            if (option1 == 1)
            {
                //Room Information
                cout << endl << endl << "Available Room Types:" << endl;
                roomInfo();
            }
            else if (option1 == 2)
            {
                //Hostel Facilities
                cout << endl << endl << "Facilities:" << endl;
                faciInfo();
            }
            else if (option1 == 3)
            {
                cout << endl << endl << "Prices:" <<endl;
                checkPrices();
            }
            else if (option1 == 4)
            {
                Admission();
            }
            else if (option1 == 5)
            {
                admin();
            }
            else if (option1 == 6)
            {
                cout << endl << endl << "***************     Thanks For Using Program     ***************" << endl << endl;
                exit(6);
            }
            else 
            {
                cout << endl << "Invalid choice:" << endl;
                goto repeat;
            }
        } while (option1 != 6);
    }
    void Admission()
    {
        //check room availibility.
        if ((roomAvailible())==true)
        {
        //Admission process
        WriteData.open("Storage.csv",ios::app);
        cout << endl << endl << "For Addmission" << endl;
        setName();
        setFatherName();
        setCNIC();
        setPhoneNumber();
        setAddress();
        setRoom();
        setMessCharges();
        setLaundryCharges();
        display();
        // ofstream WriteData("Storage.txt");
        storeFile(WriteData);
        WriteData.close();
        }
        else
        {
            cout << endl << "Sorry, All Rooms are full:";
        }
    }
    void admin()
    {
        cout << endl << endl << "Only For Admin" << endl << endl;
        cout << "For Login:" << endl;
        login();
    }
    void login()
    {
        cout << endl << "Enter Password: ";
        cin >> adminPassword;
        cin.ignore();
        if (adminPassword == 222)
        {
            checkStatus();
        }
        else
        {
            cout << endl << "Wrong Password:" << endl;
            cout << "You are not Admin" << endl;   
        }
    }
    void checkStatus()
    {
        ifstream ReadData("Storage.csv");
        repeat:
        cout << endl << "1. To Check All Student Status:" << endl;
        cout << "2. To Floor Student Status: ";
        cin >> status; 
        cin.ignore();
        if (status == 1)
        {
            readFromFile(ReadData,0,0);
        }
        else if (status == 2)
        { 
            do
            {
                statusOption = 0;
                cout << endl << "Floor Status" << endl << endl;
                cout << "1. For 1st Floor:" << endl;
                cout << "2. For 2nd Floor:" << endl;
                cout << "3. For 3rd Floor:" << endl;
                cout << "4. For Exit Function: ";
                cin >> statusOption;
                if (statusOption == 1)
                {
                    do
                    {
                        floorStatus = 0;
                        cout << endl << "1st Floor:" << endl << endl;
                        rooms();
                        cin >> floorStatus;
                        cin.ignore();
                        if (floorStatus == 1)
                        {
                            cout << endl << "Room 01:" << endl;
                            readFromFile(ReadData, 1, 1);
                        }
                        else if (floorStatus == 2)
                        {
                            cout << endl << "Room 02:" << endl;
                            readFromFile(ReadData, 1, 2);
                        }
                        else if (floorStatus == 3)
                        {
                            cout << endl << "Room 03:" << endl;
                            readFromFile(ReadData, 1, 3);
                        }
                        else if (floorStatus == 4)
                        {
                            cout << endl << "Room 04:" << endl;
                            readFromFile(ReadData, 1, 4);
                        }
                        else if (floorStatus == 5)
                        {
                            cout << endl << "Room 05:" << endl;
                            readFromFile(ReadData, 1, 5);
                        }
                        else if (floorStatus == 6)
                        {
                            cout << endl << "1st Floor:" << endl;
                            readFromFile(ReadData, 1, 0);
                        }
                        else if (floorStatus == 7)
                        {
                            cout << endl << "Function exit:" << endl;
                        }
                        else
                        {
                            cout << endl << "Invalid choice:" << endl;
                        }
                    } while (floorStatus != 7);
                }
                else if (statusOption == 2)
                {
                    do
                    {
                        cout << endl << "2nd Floor:" << endl << endl;
                        rooms();
                        cin >> floorStatus;
                        cin.ignore();
                        if (floorStatus == 1)
                        {
                            cout << endl << "Room 01:" << endl;
                            readFromFile(ReadData, 2, 1);
                        }
                        else if (floorStatus == 2)
                        {
                            cout << endl << "Room 02:" << endl;
                            readFromFile(ReadData, 2, 2);
                        }
                        else if (floorStatus == 3)
                        {
                            cout << endl << "Room 03:" << endl;
                            readFromFile(ReadData, 2, 3);
                        }
                        else if (floorStatus == 4)
                        {
                            cout << endl << "Room 04:" << endl;
                            readFromFile(ReadData, 2, 4);
                        }
                        else if (floorStatus == 5)
                        {
                            cout << endl << "Room 05:" << endl;
                            readFromFile(ReadData, 2, 5);
                        }
                        else if (floorStatus == 6)
                        {
                            cout << endl << "2nd Floor:" << endl;
                            readFromFile(ReadData, 2, 0);
                        }
                        else if (floorStatus == 7)
                        {
                            cout << endl << "Function exit:" << endl;
                        }
                        else
                        {
                            cout << endl << "Invalid choice:" << endl;
                        }
                    } while (floorStatus != 7); 
                }
                else if (statusOption == 3)
                {
                    do
                    {
                        cout << endl << "3rd Floor:" << endl << endl;
                        rooms();
                        cin >> floorStatus;
                        cin.ignore();
                        if (floorStatus == 1)
                        {
                            cout << endl << "Room 01:" << endl;
                            readFromFile(ReadData, 3, 1);
                        }
                        else if (floorStatus == 2)
                        {
                            cout << endl << "Room 02:" << endl;
                            readFromFile(ReadData, 3, 2);
                        }
                        else if (floorStatus == 3)
                        {
                            cout << endl << "Room 03:" << endl;
                            readFromFile(ReadData, 3, 3);
                        }
                        else if (floorStatus == 4)
                        {
                            cout << endl << "Room 04:" << endl;
                            readFromFile(ReadData, 3, 4);
                        }
                        else if (floorStatus == 5)
                        {
                            cout << endl << "Room 05:" << endl;
                            readFromFile(ReadData, 3, 5);
                        }
                        else if (floorStatus == 6)
                        {
                            cout << endl << "3rd Floor:" << endl;
                            readFromFile(ReadData, 3, 0);
                        }
                        else if (floorStatus == 7)
                        {
                            cout << endl << "Function exit:" << endl;
                        }
                        else
                        {
                            cout << endl << "Invalid choice:" << endl;
                        }
                    } while (floorStatus != 7);
                }
                else if (statusOption == 4)
                {
                    cout << endl << "Function exit:" << endl;
                }
                else 
                {
                    cout << endl << "Invalid choice:" << endl;
                }
            } while (statusOption != 4);
        }
        else 
        {
            cout << endl << "Invalid choice:" << endl;
            goto repeat;
        }
    }
    void rooms()
    {
        cout << "1. For Room 01:" << endl;
        cout << "2. For Room 02:" << endl;
        cout << "3. For Room 03:" << endl;
        cout << "4. For Room 04:" << endl;
        cout << "5. For Room 05:" << endl;
        cout << "6. For Full Floor:" << endl;
        cout << "7. For Exit Function: ";
    }
    void readFromFile(ifstream& , int Floor, int Room)
    {
    ifstream Read("Storage.csv");
    string read;
    while (getline(Read, read))
    {
        istringstream iss(read);
        getline(iss, floor , '|');
        getline(iss, roomAllocation , '|');
        getline(iss,  name, '|');
        getline(iss, fatherName, '|');
        getline(iss, CNIC, '|');
        getline(iss, phoneNumber, '|');
        getline(iss, address,'|');
        if (Floor == 0 && Room == 0)
        {
            cout << "Name: " << name <<endl;
            cout << "Father Name: " << fatherName <<endl;
            cout << "CNIC: " << CNIC << endl;
            cout << "Phone: " << phoneNumber << endl;
            cout << "Address: " << address << endl;
            cout << "Floor No. " << floor << endl;
            cout << "Room No. " << roomAllocation << endl << endl;
        }
        else if (stoi(floor) == Floor && Room == 0)
        {
            cout << "Name: " << name <<endl;
            cout << "Father Name: " << fatherName <<endl;
            cout << "CNIC: " << CNIC << endl;
            cout << "Phone: " << phoneNumber << endl;
            cout << "Address: " << address << endl;
            cout << "Floor No. " << floor << endl;
            cout << "Room No. " << roomAllocation << endl << endl;
        }
        else if (stoi(floor) == Floor && stoi(roomAllocation) == Room)
        {
            cout << "Name: " << name <<endl;
            cout << "Father Name: " << fatherName <<endl;
            cout << "CNIC: " << CNIC << endl;
            cout << "Phone: " << phoneNumber << endl;
            cout << "Address: " << address << endl;
            cout << "Floor No. " << floor << endl;
            cout << "Room No. " << roomAllocation << endl << endl;
        }
    }
    Read.close();
    }
};
int main()
{
    Admin student;
    system("cls"); // Clearing the previous screen.

        // Welcome Screen.
        cout << setw(77) << "***********************************************" << endl;
        cout << setw(77) << "***********************************************" << endl;
        cout << setw(32) << "**" << setw(45) << "**" << endl;
        cout << setw(32) << "**" << setw(24) << "Welcome" << setw(21) << "**" << endl;
        cout << setw(32) << "**" << setw(45) << "**" << endl;
        cout << setw(77) << "***********************************************" << endl;
        cout << setw(77) << "***********************************************" << endl
             << endl;
        cout << setw(65) << "Hostel Management System" << endl
             << endl;
        cout << setw(77) << "***********************************************" << endl;
        cout << setw(31) << "*" << setw(46) << "*" << endl;
        cout << setw(31) << "*" << setw(25) << "Developed by:-" << setw(21) << "*" << endl;
        cout << setw(31) << "*" << setw(23) << "JAWARIA ASIF" << setw(23) << "*" << endl;
        cout << setw(31) << "*" << setw(28) << "MUHAMMAD ABDULLAH" << setw(18) << "*" << endl;
        cout << setw(31) << "*" << setw(29) << "RANA HAIDER SULTAN" << setw(17) << "*" << endl;
        cout << setw(31) << "*" << setw(46) << "*" << endl;
        cout << setw(77) << "***********************************************" << endl<< endl;

        Sleep(2000); // Holding the screen for 2 seconds.

        system("cls");
    student.menu();
}