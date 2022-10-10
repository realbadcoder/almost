// Code to help calculate electric bills for users depending on what TDU provider and total EFL charges for a user specified amount of time.

#include <iostream> 
#include <iomanip> // including necesarry libraries since we have set precision we need iomanip
using namespace std;

	// decalaring variables that will be used throught the program to calculate TDU and EFL costs and charges.
	// variables included also hold the name on the bill and if the user wishes to run the program again.
	int currentTDU;
	double TDUCharge, TDUPerKwh, eflCost;
	int totalMonths;
	string nameOnBill, userContinue;
	double totalBill, billedTDUcharges, billedEFLcharges;
	bool should_repeat = true, repeat;
	int runAgain;

	int main()

{
		// while loop to allow the user to repeat the program with different information.
		while (should_repeat) {

		// asking user for the name on the bill 
		cout << "Please enter name of the person on the bill: \n";

		//allowing user to input name of person on the bill
		cin >> nameOnBill;

		//asking user the amount of months they want to calculate
		cout << "How many months worth of data do you want to enter (up to 12): ";

		// a loop ensuring that they enter valid data that is able to be caluclated
		while (totalMonths <= 0 || totalMonths > 12) {

			// allows user to input amount of months on bill
			cin >> totalMonths;

			// the conditional statement that makes sure the months are integers and not characters or strings
			//using clear and ignore to make sure the program can progress pass a fail state then an oupt prompting user to enter valid number
			if (totalMonths <= 0 || totalMonths > 12) {
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Enter valid number up to 12" << endl;

			}

		}


		// a loop used to allow the user to easily select thier TDU by showing all options rather than asking for user wo write out thier TDU provider
		do {

			cout << "Please enter a number 1-5 to choose your current TDU provider from the provided list: \n";

			cout << "1. ONCOR ENERGY\n";

			cout << "2. CENTERPOINT ENERGY\n";

			cout << "3. AEP TEXAS CENTRAL\n";

			cout << "4. AEP TEXAS NORTH\n";

			cout << "5. TEXAS - NEW MEXICO POWER\n";

			// alows user to input a number 1-5 to select thier TDU provider
			cin >> currentTDU;

			// conditional statement ensuring user selects a valid option with a clear of fail state and an error message

			if (currentTDU <= 0 || currentTDU >= 6)
			{

				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Please select a valid option from the list provided\n " << endl;

			}
		}

		// condition of the do while loop used to make sure number is between 1-5
		while (currentTDU <= 0 || currentTDU >= 6);

		//declaring variables for the TDU side of calculations 
		int kwh;
		double TotalTDUCharges;

		int i;
		i = 1;

		// for loop that increases adjacent with the amount of months selected
		for (i = 1; i <= totalMonths; i++) {



			// asking user to input their kwh used for every month and will loop until all months' data have been entered
			cout << "Enter your KWH used for month " << i << ": ";
			cin >> kwh;

			// output letting user know current charges for the specific month
			cout << "Hello " << nameOnBill << "! " << "Your current charges for month " << i << " are the following : " << endl;


			// conditional statements based off user selection in line 48 that calcualtes their total TDU charges based off provider
			if (currentTDU == 1)
			{
				TotalTDUCharges = 3.42 + (0.0384470 * kwh);
			}
			else if (currentTDU == 2)
			{
				TotalTDUCharges = 5.47 + (0.0403120 * kwh);
			}

			else if (currentTDU == 3)
			{
				TotalTDUCharges = 9.00 + (0.0448460 * kwh);
			}

			else if (currentTDU == 4)
			{
				TotalTDUCharges = 10.53 + (0.0401990 * kwh);
			}

			else
			{
				TotalTDUCharges = 7.85 + (0.0483210 * kwh);
			}

			// using setprecision becasue we are dealing with money so its good to set 2 decimal places for output
			cout << fixed << setprecision(2);

			// output of total TDU charges	
			cout << "The Total amount of TDU Charges for month " << i << " are: $" << TotalTDUCharges << endl;

			// variables for EFL tiers and the different costs when you have surpassed usage in the specific tier
			double tier1Limit, tier2Limit, tier1cost, tier2cost, tier3cost;

			double tier1Rate, tier2Rate, tier3Rate;

			double tier1Usage, tier2Usage, tier3Usage;

			// variables for the different rates of the EFL tiers
			tier1Rate = 7.30;
			tier2Rate = 3.70;
			tier3Rate = 7.70;

			tier1Limit = 1200;
			tier2Limit = 2000;


			// conditional statements that help calculate the EFL costs depending on the tiers
			// first statement is for tier 1 limist
			if (kwh <= tier1Limit)
			{

				tier1Usage = kwh;
				tier2Usage = 0;
				tier3Usage = 0;

			}
			//conditional statement for user surpassing tier 1 usage and entering tier 2
			else if (kwh <= tier2Limit)
			{
				tier1Usage = tier1Limit;
				tier2Usage = kwh - tier1Limit;
				tier3Usage = 0;
			}
			//conditional statement for user surpassing tier 1 and 2 usage and entering tier 3
			else {

				tier1Usage = tier1Limit;
				tier2Usage = tier2Limit - tier1Limit;
				tier3Usage = kwh - tier2Limit;
			}

			// variables and calculations for costs of EFL based on usage and rates
			tier1cost = tier1Usage * tier1Rate;
			tier2cost = tier2Usage * tier2Rate;
			tier3cost = tier3Usage * tier3Rate;


			// calculation of the total EFL cost then adding the 9.95 fee applied to all bills
			eflCost = (tier1cost + tier2cost + tier3cost) / 100 + 9.95;

			// conditional statment that ensures the extra 15 discount is applied if 1200 or more kwh are used
			if (kwh >= 1200)
			{
				eflCost = eflCost - 15.0;
			}

			// output of the total EFL charges for the month
			cout << "The Total amount of EFL Charges for month " << i << " are: $" << eflCost << endl;

			// defining then implementing varibale of total combined cost of EFL and TDU charges
			double total;

			total = eflCost + TotalTDUCharges;

			//output of the EFL and TDU charges combined 
			cout << "The total combined charges for month " << i << " is : $" << total << endl << endl;


			billedEFLcharges = billedEFLcharges + eflCost;

			billedTDUcharges = billedTDUcharges + TotalTDUCharges;

			totalBill = totalBill + total;



		}
		// output of all EFL and TDU charges for all months combined
		cout << nameOnBill << " your total charges for " << i - 1 << " month(s) is/are : $" << totalBill << endl;

		cout << "Your total TDU charges for " << i - 1 << " month(s) is/are : $" << billedTDUcharges << endl;

		cout << "Your total EFL charges for " << i - 1 << " month(s) is/are :  $" << billedEFLcharges << endl << endl;

		// outputs asking if user would like to run the program again and giving them the option of 1 for yes and 2 for no
		cout << "Would you like to calculate another bill? " << endl;

		cout << "Press 1 for YES  " << endl;

		cout << "Press 2 for NO  " << endl;
		
		// allowing user to input either 1 for true or 2 for false on running program again.
		cin >> runAgain;

		// conditional statement only allowing 1 or 2 and saving from a fail state with ignore and clear		
		if (runAgain <= 0 || runAgain > 2) {
				cin.clear();
				cin.ignore(100000, '\n');
				cout << "Please enter 1 for yes or 2 for no. " << endl;
		
		// conditional statement that allows user to repeat program if they so chose
		if (runAgain == 2) {
				should_repeat = false;

				return 0;

			}
	
		}


	}

}