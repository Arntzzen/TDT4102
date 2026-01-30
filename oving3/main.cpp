#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void menu() {
	while (1) {
		std::cout << "Menu\n"
			<< "0.\t Quit\n"
			<< "1.\t Farta i y-retning etter hhv. 2.5s og 5s.\n"
			<< "2.\t Posisjonen i x- og y-retning etter hhv. 2.5s og 5s.\n"
            << "3.\t Tester om feilen er innenfor marginen. \n"
			<< "4.\t Få fart i x- og y-retning. \n"
			<< "5.\t Få den horisontale hastigheten kula har reist. \n"
			<< "6.\t Få avviket mellom kula og målskiva \n";
			
		int menu_choice;
		std::cin >> menu_choice;
		
		switch (menu_choice)
		{
		case 1:
			cout << "Farten i y-retning etter 2.5s: " << velY(25, 2.5)
			<< " og etter 5s: " << velY(25, 5) << endl;
			break;
        case 2:
            cout << "Posisjonen i x- og y-retning etter 2.5s: " << "x: " << posX(0, 50, 2.5) << setw(5) << " " << "y: "
			<< posY(0, 25, 2.5) << " og etter 5s: " << "x: " << posX(0, 50, 5) << setw(5) << " " << "y: " << posY(0, 25, 5) << endl;
            break;
        case 3:
            testDeviation(posX(0.0,50.0,5.0), 250.0, 0.0001, "posX(0.0,50.0,5.0)");
            break;
        case 4: {
            double theta;
			double startfart;
			cout << "Skriv inn vinkel og start hastighet: ";
			cin >> theta >> startfart;
			cout << "Fart i x- og y-retning: " << getVelocityVector(theta, startfart)[0]
			<< setw(5) << " " << getVelocityVector(theta, startfart)[1] << endl;
            break;
		}
        case 5: {
			double theta;
			double startfart;
			cout << "Skriv inn vinkel og start hastighet: ";
			cin >> theta >> startfart;
            double xPos = getDistanceTraveled(getVelocityVector(theta, startfart)[0], getVelocityVector(theta, startfart)[1]);
			cout << "Posisjonen i x-retning etter " << xPos << endl;
            break;
		}
		case 6: {
			double distanceToTarget;
			double initVelX;
			double initVelY;
			cout << "Skriv inn avstanden til målet, startfart x-retning og startfart y-retning: ";
			cin >> distanceToTarget >> initVelX >> initVelY;
			double error = targetPractice(distanceToTarget, initVelX, initVelY);
			cout << "Avviket fra kula til målet er " << error << " meter." << endl;
			break;
		}
		default:
			return; // quit program
			break;
		}
	}
}


int main()
{
	//menu();
	//randomWithLimits(0, 10);
	playTargetPractice();
	return 0;
}