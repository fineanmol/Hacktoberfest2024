#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
// A program to calcuate double digital price options
// read more here https://www.quantstart.com/articles/Double-digital-option-pricing-with-C-via-Monte-Carlo-methods/
using namespace std;

// random start
double getOneGaussianBySummation(){
    double result = 0;
    for(unsigned int j = 0; j < 12; j++) 
        result += rand()/static_cast<double>(RAND_MAX);

    result -= 6.0;

    return result;
}

double gaussian_box_muller() {
  double x = 0.0;
  double y = 0.0;
  double euclid_sq = 0.0;1
  do {
    x = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
    y = 2.0 * rand() / static_cast<double>(RAND_MAX)-1;
    euclid_sq = x*x + y*y;
  } while (euclid_sq >= 1.0);

  return x*sqrt(-2*log(euclid_sq)/euclid_sq);
}

void calc_path_spot_prices(
  std::vector<double>& spot_prices,
  const double& r, // risk free rate
  const double& v, // volatility
  const double& T  // Time
) {
  double dt = T/static_cast<double>(spot_prices.size());
  double drift = exp(dt*(r-0.5*v*v));
  double vol = sqrt(v*v*dt);

  for(int i = 1; i < spot_prices.size(); i++){
    double gauss_bm = gaussian_box_muller();
    spot_prices[i] = spot_prices[i-1] * drift * exp(vol*gauss_bm);
  }
}
// random end
// payoff start
class PayOff {
    public:
        PayOff(){};

        virtual double operator()(double Spot) const = 0;

        virtual PayOff* clone() const = 0;

        virtual ~PayOff(){}
    private:

};

class PayOffCall : public PayOff {
    private:
        double Strike;
    public:
        PayOffCall(double Strike_) : Strike(Strike_){};

        virtual double operator()(double Spot) const{
            return std::max(Spot - Strike, 0.0);
        };

        virtual ~PayOffCall(){}

        virtual PayOff* clone() const{
            return new PayOffCall(*this);
        };
};

class PayOffPut : public PayOff {
    private:
        double Strike;
    public:
        PayOffPut(double Strike_) : Strike(Strike_){};

        virtual double operator()(double Spot) const{
            return std::max(Strike-Spot, 0.0);
        };

        virtual ~PayOffPut(){}

        virtual PayOff* clone() const{
            return new PayOffPut(*this);
        };
};

// payoff end
// simple monte carlo start
double SimpleMonteCarlo(
    PayOff& thePayOff, 
    double Expiry,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths
    ){
        double variance = Vol*Vol*Expiry;
        double rootVariance = sqrt(variance);
        double itoCorrection = -0.5*variance;

        double movedSpot = Spot * exp(r*Expiry +itoCorrection);
        double thisSpot;
        double runningSum = 0.0;

        for(unsigned long i=0; i < NumberOfPaths; i++) {
            double thisGaussian = gaussian_box_muller();
            thisSpot = movedSpot * exp(rootVariance * thisGaussian);
            runningSum += thePayOff(thisSpot);
             
        }
        double mean = runningSum / NumberOfPaths;
        mean *= exp(-r*Expiry);
        return mean;
    }
// simple monte carlo end
// doubledigital start
class PODoubleDigital : public PayOff {
    private:
        double LowerLevel;
        double UpperLevel;
    public:
        PODoubleDigital(double _lowerLevel, double _upperLevel) 
            : LowerLevel(_lowerLevel), UpperLevel(_upperLevel){

            };

        virtual ~PODoubleDigital(){};

        virtual double operator()(double Spot) const {
             if(Spot <= LowerLevel)
                return 0;
            if(Spot >= UpperLevel)
                return 0;

            return 1;
        };

        virtual PayOff* clone() const {
             return new PODoubleDigital(*this);
        }
};
// doubledigital end
// main 
int main(){
    double Expiry;
    double Low, Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter Low\n";
    cin >> Low;
    cout << "\nEnter Up\n";
    cin >> Up;
    cout << "\nEnter Spot\n";
    cin >> Spot;
    cout << "\nEnter Vol\n";
    cin >> Vol;
    cout << "\nEnter r\n";
    cin >> r;
    cout << "\nEnter number of paths\n";
    cin >> NumberOfPaths;

    PODoubleDigital thePayOff(Low, Up);

    double result = SimpleMonteCarlo(
        thePayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths
    );

    cout << "\nThe price is " << result << "\n";
    double tmp;
    cin >> tmp;

    return 0;
}
