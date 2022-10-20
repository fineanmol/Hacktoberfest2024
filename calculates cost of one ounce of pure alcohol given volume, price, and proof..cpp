// calculates cost of one ounce of pure alcohol given volume, price, and proof.
// special calculations for beer and if converting from mL to Oz.

#include <iostream>
using namespace std;

// function prototypes
void myname();                                  // author info
int beerORliqour(int);                          // asks if beer or hard a
float mlTOoz(float, int);                       // converts mL to Oz
float containerVolume(float, int, int);         // calculate volume
int beer(int);                                  // calculate total case volume if beer
void conclusion(float, float, float, int, int); // outputs calculations

int main()
{
        char convertyn;                 // convert ml to oz? (y or n)
        float volume;                   // volume of container(s)
        int yn;                         // beer yes or no (1 or 2)
        int beercase;                   // number of beers in a case
        float proof, price;             // user inputs
        float content, worth;           // calculations

        beercase = 0;                   // set beercase and volume to 0, had
        volume = 0;                     // to do this to get program to work

        myname();

        yn = beerORliqour(yn);          // declare yn for use in other fucntions
        if (yn == 1)                    // only do if calculating for beer
        {
        cout << "Enter the number of beers in a case: ";
        cin >> beercase;                // input # beers in a case
        cout << endl;
        }

        volume = mlTOoz(volume, yn);    // run function to convert mL to Oz, if wanted.
                                        // if wanted, output volume. if not, volume
                                        // remains '0'.

        if (volume == 0)                // only run if volume has not been entered yet
        volume = containerVolume(volume, yn, beercase);
                                        // run function to figure out volume.

        cout << "Enter the proof (2x the listed alcohol content by %volume): ";
        cin >> proof;                   // user input proof
        cout << endl;

        cout << "Enter the price: $";
        cin >> price;                   // user input price
        cout << endl;

        conclusion(volume, proof, price, yn, beercase); // conclusion

        return 0;
}

int beerORliqour(int answer)
{
        cout << "Enter 1 for beer. Enter 2 for everything else. ";
        cin >> answer;          // input 1 for beer, 2 for anything else
        cout << endl;

        return(answer);         // returns user input to main. is called "yn" in main function
}
float mlTOoz(float v, int beeryn)
{
        char convertyn;                 // need help converting, y or n;
        float mL;                       // user input milliliters

        cout << "Volume input must be in ounces. Do you ";
        cout << "need help converting from milliliters ";
        cout << "to Oz? (Y or N) ";
        cin >> convertyn;
        cout << endl;

        switch (convertyn)
        {
                case 'Y': case 'y':
                        if (beeryn == 1)
                        cout << "Enter the volume of one can of beer: ";
                        else if (beeryn == 2)
                        cout << "Enter the volume: ";

                        cin >> mL;
                        cout << endl;

                        v = mL * 0.0338140226;
                        cout << mL << " milliliters is equal to " << v << " ounces." << endl;
                break;
                case 'N': case 'n':
                v = 0;                  // if no need to convert mL to Oz, volume remains
                                        // '0' for now. Will be changed with next function
        }

        return(v);                      // return v to main. is called "volume" in main function"
}
float containerVolume(float v, int beeryn, int beerc)
{
        float oz;                       // local float used for calculating volume
        if (beeryn == 1)                // run if beer
        {
        cout << "Enter the volume of one can of beer: ";
        cin >> oz;
        cout << endl;
        v = oz * beerc;                 // Oz must be multiplied by # cans in case to get total volume
        }
        else if (beeryn == 2)           // run if other
        {
        cout << "Enter the volume in ounces: ";
        cin >> v;
        cout << endl;
        }

        return(v);
}
void conclusion(float v, float prf, float prc, int beeryn, int cb)
{
        float costcan;                  // cost of one can of beer
        float contcan;                  // alcohol content of one can of beer
        float c;                        // content
        float w;                        // worth

        c = ((v) * ((prf) / 200));      // content = volume * (proof / 200)
                                        // units of Oz pure alcohol content
        w = ((prc) / (c));              // worth = price / content
                                        // units of $ per ounce of pure alcohol

        costcan = ((prc) / (cb));       // cost per can = price / # beers in case
        contcan = ((v) / (cb)) * ((prf) / 200); // contents of can = (volume / # beers in case) * (proof /200)

        cout << "beeryn is " << beeryn << endl;

        if (beeryn == 1)
        {
                cout << "There are " << c << " total ounces of pure alcohol present, ";
                cout << "which you are paying for at a rate of $" << w;
                cout << " per ounce of pure alcohol." << endl;
                cout << "Each can costs approximately $" << costcan << endl;
                cout << "Each can contains approximately " << contcan;
                cout << " ounces of pure alcohol" << endl;
        }
        if (beeryn == 2)
        {
                cout << "There are " << c << " total ounces of pure alcohol present, ";
                cout << "which you are paying for at a rate of $" << w;
                cout << " per ounce of pure alcohol." << endl;
                if (w < 1)
                cout << "WOW!!! That's cheap!" << endl;         // nested if statement
        }
}
void myname()
{
        cout << endl << endl << endl;
        cout << "***********************************************************" << endl;
        cout << "* This program calculates how much you are paying for an  *" << endl;
        cout << "* ounce of pure alcohol when you buy booze. This can be   *" << endl;
        cout << "* used as an effective way of comparing the value of one  *" << endl;
        cout << "* spirit versus another. Have fun and drink responsibly!  *" << endl;
        cout << "***********************************************************" << endl;
        cout << endl;
        cout << "          **************************************" << endl;
        cout << "          *              Created by            *" << endl;
        cout << "          *           Hamid Ali 110        *" << endl;
        cout << "          *   xxxxxxxxxxxx@xxxxxxxxxxxxxx.edu  *" << endl;
        cout << "          **************************************" << endl;
        cout << endl << endl << endl;

        return;
}
