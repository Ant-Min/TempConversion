/* TempConversion is a class that reads in a file of cities' F temperatures and converts them to C
   @author Anthony Minunni
   @date 3/28/21 */

#include <iostream>
#include <iomanip> //for setprecision
#include <fstream> //to utilize input and output file reading/writing
#include <string>
using namespace std;

int main() {
	ifstream inFS; //ifstream to read into text document "FahrenheitTemperature"
	ofstream outFS; //ofstream to ouput to new document
	string city; //string for name of city
	string hold; //placeholder for fTemp before it is converted to in
	int fTemp; //was told to assume fTemp is int
	double cTemp;

	inFS.open("FahrenheitTemperature.txt"); //reads specified document
	outFS.open("CelciusConvert.txt"); //writes to specified document
	
	//while loop to read into the text file then write to a new one
	while (bool one = true) {
		if (!(inFS >> city >> hold)) { //this conditional statement helps the loop break before it writes the final line a second time
			break;
		}
		else {
			outFS << city << " ";
			fTemp = stoi(hold);
			cTemp = (fTemp - 32.0) * (5.0 / 9.0);
			outFS << setprecision(2) << cTemp << endl;
		}
	}

	inFS.close();
	outFS.close();
}