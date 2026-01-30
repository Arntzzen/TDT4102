#include "cannonball.h"
#include "cannonball_viz.h"
#include "utilities.h"
#include <cmath>

// BEGIN: 2a
// Implementer funksjonen acclY
double acclY() {
    return -gravity;
};
// END: 2a

// BEGIN: 2b
// Implementer funksjonen velY
double velY(double initVelocityY, double time) {
    return initVelocityY + acclY() * time;
};
// END: 2b

// BEGIN: 2c
// Implementer funksjonene posX og posY
double posX(double initPositionX, double initVelocityX, double time) {
    return initPositionX + initVelocityX * time;
};
double posY(double initPositionY, double initVelocityY, double time) {
    return initPositionY + initVelocityY * time + ((acclY() * pow(time, 2)) / 2);
};
// END: 2c

// BEGIN: 2d
// Implementer funksjonen printTime
void printTime(double sekunder){
    if (sekunder >= 0 && sekunder < 60) {
        cout << sekunder << " sekunder";
    } else if (sekunder >= 60 && sekunder < 3600) {
        int minutter = static_cast<int>(sekunder) / 60;
        int restSekunder = static_cast<int>(sekunder) % 60;
        cout << minutter << " minutter og " << restSekunder << " sekunder";
    } else if (sekunder >= 3600) {
        int timer = static_cast<int>(sekunder) / 3600;
        int minutter = (static_cast<int>(sekunder) % 3600) / 60;
        int restSekunder = static_cast<int>(sekunder) % 60;
        cout << timer << " timer, " << minutter << " minutter og " << restSekunder << " sekunder";
    } else {
        cout << "Negativ tid går ikke, du må få tiden til å bli positiv" << endl;
    }
};
// END: 2d

// BEGIN: 2e
// Implementer funksjonen flightTime
double flightTime(double initVelocityY) {
    return (-2 * initVelocityY) / acclY();
};
// END: 2e

// BEGIN: 3b
// Implementer funksjonen testDeviation
bool testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    double error = abs(compareOperand - toOperand);
    if (error <= maxError) {
        cout << name << " is valid!" << endl;
        return true;
    }
    cout << name << " is not valid! Expected " << toOperand << ", got " << compareOperand << endl;
    return false;
}
// END: 3b

// BEGIN: 4a
// Her skal du implementere ALLE funksjonene i oppgave 4a
double getUserInputTheta() {
    double theta;
    cout << "Skriv inn vinkelen i grader:";
    cin >> theta;
    return theta;
}
double getUserInputInitVelocity() {
    double initVelocity;
    cout << "Skriv inn startfarten:";
    cin >> initVelocity;
    return initVelocity;
}
double degToRad(double deg) {
    double rad = deg * (pi / 180);
    return rad;
}
double getVelocityX(double theta, double initVelocity) {
    double fartX = initVelocity * cos(degToRad(theta));
    return fartX;
}
double getVelocityY(double theta, double initVelocity) {
    double fartY = initVelocity * sin(degToRad(theta));
    return fartY;
}
vector<double> getVelocityVector(double theta, double initVelocity) {
    vector<double> velocity;
    double vx = getVelocityX(theta, initVelocity);
    double vy = getVelocityY(theta, initVelocity);
    velocity.push_back(vx);
    velocity.push_back(vy);
    return velocity;
}
// END: 4a

// BEGIN: 4b
double getDistanceTraveled(double velocityX, double velocityY) {
    double tid = flightTime(velocityY);
    double xPos = posX(0, velocityX, tid);
    return xPos;
}
// END: 4b
// BEGIN: 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double xPos = getDistanceTraveled(velocityX, velocityY);
    double error = abs(distanceToTarget - xPos);
    return error;
}
// END: 4c


// BEGIN: 5b
void playTargetPractice() {
    // plasser blink tilfeldig mellom 100 og 1000 meter en gang
    int targetDist = randomWithLimits(100, 1000);
    double theta;
    double startfart;
    cout << "Skriv inn utskytningsvinkel i grader og startfart.\n";
    // Spiller får 10 forsøk
    for (int i = 0; i < 10; i++) {
        while (true) {
        // Spiller må oppgi vinkel og startfart
            cout << "Utskytningsvinkel: ";
            cin >> theta;
            cout << "Startfart: ";
            cin >> startfart;
            if (!cin) {
                cout << "Utskytningsvinkel og startfart må være tall\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else if (theta <= 0 || startfart <= 0) {
                cout << "Du må skrive inn positive tall større enn null\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else {
                break;
            }
        };
        // For hvert forsøk skal avstanden oppgis, og om det var for langt eller for kort.
        double velX = getVelocityVector(theta, startfart)[0];
        double velY = getVelocityVector(theta, startfart)[1];
        double xPos = getDistanceTraveled(velX, velY);
        double error = targetPractice(targetDist, velX, velY);
        double time = flightTime(velY);

        cannonBallViz(targetDist, 1000, velX, velY, 100);

        cout << "Kula brukte ";
        printTime(time);
        cout << " i lufta og" << endl;
        cout << "landet " << (abs(error - 5)) << " meter unna målet";
        if ((xPos - targetDist) <= -5) {
            cout << " og gikk ikke langt nok.\n" << endl;
        } else if ((xPos - targetDist) >= 5) {
            cout << " og gikk for langt.\n" << endl;
        } else {
            cout << ". Dette er innenfor. Gratulerer, du har vunnet!!!" << endl;
            return;
        }
        if (i <= 8) {
            cout << "Du har brukt " << i+1 << " forsøk og har " << 9-i << " forsøk igjen." << endl;
        } else {
            break;
        }
    }   
    cout << "Du har brukt opp forsøkene dine og tapte dessverre spillet. Bedre lykke neste gang!" << endl;
    
// Tida kula har brukt skal også oppgis, leselig for mennesker - time-funksjonen.
};
// END: 5b