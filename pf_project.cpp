#include<iostream>
#include<stdlib.h> // Included for using the exit() function
#include<conio.h> // Included for using getch() function for pausing the screen
#include<string>
using namespace std;

// Structure to represent a bank account
struct bankmanagement
{
    int accno; // Account number
    string name, address; // Account holder's name and address
    char actype; // Account type (saving or current)
    float amount; // Account balance
    
    // Function declarations for various operations on bank accounts
    bool checkavailabilty(); // Check if the account slot is available
    bool searchaccount(int); // Search for an account by account number
    void newaccount(); // Create a new bank account
    void deposit(); // Deposit money into an account
    void withdraw(); // Withdraw money from an account
    void check_account(); // Display account details
    void modifyaccount(); // Modify account information
    void deleteaccount(); // Delete an account
    
    // Constructor to initialize account attributes
    bankmanagement()
    {
        accno=0;
        name="";
        address="";
        actype='\0';
        amount=0.0; 
    }
     
};

// Main function
int main()
{
    bankmanagement b[5]; // Array of bankmanagement objects to store bank accounts

    int x,an; // Variables for user input and account number
    bool check; // Boolean variable for checking account existence
    
    while(1)
    {   
        system("CLS"); // Clear the screen
        cout<<"             =================              "<<endl;
        cout<<"             |   Bank Menu   |              "<<endl;
        cout<<"=========================================="<<endl;
        cout<<" Enter 1 to create an new account.\n Enter 2 to Deposit.\n Enter 3 to Withdraw.\n Enter 4 to Check account.\n Enter 5 to Modify.\n Enter 6 to Delete.\n Enter 7 to show all accounts.\n Enter 8 to exit";
        cout<<"\n=========================================="<<endl;
        cout<<" Enter choice no: ";
        cin>>x; // Get user's choice
        
        // Switch statement to perform operations based on user input
        switch(x)
        {
            case 1: // Create a new account
            {
                check=false;
                for(int i=0; i<5; i++)
                {
                    if(b[i].checkavailabilty()) // Check if the account slot is available
                    {
                        check=true;
                        b[i].newaccount(); // Call function to create a new account
                        cout<<" working.";
                        break;
                    }   
                }
                
                if(check==false)
                    cout<<" Accounts exceeded."; // Notify if maximum accounts limit is reached
                    
                break;  
            }
            case 2: // Deposit money into an account
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an; // Get account number from user
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) // Search for the account
                    {
                        check=true;
                        b[i].deposit(); // Call function to deposit money
                        break;
                    }   
                }
                
                if(check==false)
                    cout<<" No account found ."; // Notify if account not found
                    
                break;
            }
            case 3: // Withdraw money from an account
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an; // Get account number from user
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) // Search for the account
                    {
                        check=true;
                        b[i].withdraw(); // Call function to withdraw money
                        break;
                    }   
                }
                
                if(check==false)
                    cout<<" No account found ."; // Notify if account not found
                    
                break;      
            }
            case 4: // Check account details
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an; // Get account number from user
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) // Search for the account
                    {
                        check=true;
                        b[i].check_account(); // Call function to display account details
                        break;
                    }   
                }
                
                if(check==false)
                    cout<<" No account found ."; // Notify if account not found
                    
                break;      
                
            }
            case 5: // Modify account information
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an; // Get account number from user
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) // Search for the account
                    {
                        check=true;
                        b[i].modifyaccount(); // Call function to modify account information
                        break;
                    }   
                }
                
                if(check==false)
                    cout<<" No account found ."; // Notify if account not found
                    
                break;      
            }
            case 6: // Delete an account
            {
                check=false;
                cout<<" Enter account no. : ";
                cin>>an; // Get account number from user
                for(int i=0; i<5; i++)
                {
                    if(b[i].searchaccount(an)) // Search for the account
                    {
                        check=true;
                        b[i].deleteaccount(); // Call function to delete the account
                        break;
                    }   
                }
                
                if(check==false)
                    cout<<" No account found ."; // Notify if account not found
                    
                break;      
            }
            case 7: // Show all accounts
            {
                check=false;
                for(int i=0; i<5; i++)
                {
                    if(!b[i].checkavailabilty()) // Check if the account is not empty
                    {
                        
                        check=true;
                        cout<<"\nAccount details of "<<i+1<<":\n ";
                        b[i].check_account(); // Call function to display account details
                        cout<<"\n==========================================\n";
                    }   
                }
                
                if(check==false)
                    cout<<" No account found ."; // Notify if no accounts are found
                    
                break;      
            }
            case 8: // Exit the program
            {
                exit(0); // Terminate the program
            }
            
        }
        getch(); // Pause the screen
    }
    
    return 0;
}

// Function to check if the account slot is available
bool bankmanagement::checkavailabilty()
{
    if(accno==0 && name=="" && address=="" && actype=='\0' && amount==0.0)
        return true;
    else
        return false;
}

// Function to search for an account by account number
bool bankmanagement::searchaccount(int a)
{
    
    if(accno==a )
        return true;
    else
        return false;
}

// Function to create a new account
void bankmanagement::newaccount()
{
    
    cout<< " Enter your account no: ";
    cin>> accno; // Get account number
    
    cout<< " Enter your full name: ";
    cin>> name; // Get account holder's name
    
    cout<< " Enter your address: ";
    cin>> address; // Get account holder's address
   
    cout<< " What type of account you want to open saving(s) or Current(c):";
    cin>> actype; // Get account type
   
    cout<< " Enter How much money you want to deposit: ";
    cin>> amount; // Get initial deposit amount
	    
    cout << " Account Created Successfully...";	    
}

// Function to deposit money into an account
void bankmanagement::deposit()
{
    float d;
    cout<<"\n Enter amount to Deposit = ";
    cin>>d; // Get amount to deposit
    amount += d; // Update account balance
    cout<<" Updated...New Amount = "<<amount; // Notify user about updated balance
}

// Function to withdraw money from an account
void bankmanagement::withdraw()
{
    int wd;
    cout<<"\n Enter amount to withdraw = ";
    cin>>wd; // Get amount to withdraw
    if(wd<=amount) // Check if withdrawal amount is less than or equal to account balance
    {
        amount -= wd; // Update account balance
        cout<<"\n Amount is withdrawed."; // Notify user about successful withdrawal
    }
    else
    {
        cout<<"\n You don't have enough amount in the bank."; // Notify user if insufficient balance
    }
    cout<<"\n Remaining amount: "<<amount; // Notify user about remaining balance
}

// Function to display account details
void bankmanagement::check_account()
{
    cout<< "\n Your name: "<<name; // Display account holder's name
    
    cout<< "\n Your address: "<<address; // Display account holder's address
   
    cout<< "\n Account type: "<<actype; // Display account type
   
    cout<< "\n Amount= "<<amount; // Display account balance
}

// Function to modify account information
void bankmanagement::modifyaccount()
{
    
    cout<<"\n Account No. : "<<accno; // Display account number
    
    cout<<"\n Modify Account Holder Name : ";
    cin>>name; // Get modified account holder's name
    
    cout<< "\n Modify your address: ";
    cin>> address; // Get modified account holder's address
    
    cout<<"\n Modify Type of Account: saving (s) or Current (c): ";
    cin>>actype; // Get modified account type
    
    cout<<"\n Account is modified."; // Notify user about successful modification
}

// Function to delete an account
void bankmanagement::deleteaccount()
{
    
    accno=0; // Reset account number
    name=""; // Reset account holder's name
    address=""; // Reset account holder's address
    actype='\0'; // Reset account type
    amount=0.0; // Reset account balance
    cout<<"\n Successfully deleted."; // Notify user about successful deletion
}
