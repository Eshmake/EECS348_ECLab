
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


double extractNumeric(const string& str){
    double result;
    int check = 0;
    bool neg = true;

    for(int i = 0; i <= str.length()-1; i++){
        if((str[i] >= '0' && str[i] <= '9') || str[i]  == '+' || str[i]  == '-' || str[i]  == '.'){
            if((str[i]  == '+' || str[i]  == '-') && i != 0){
                return -999999.99;
            }
            else if(str[i] == '.'){
                if(check == 0){
                    check++;
                    continue;
                }
                else{
                    return -999999.99;
                }
            }  
        }
        else{
            return -999999.99;
        }
    }

    if(str[0] != '-'){
        neg = false;
    }

    if(str.find('.') == std::string::npos){
        int place = 1;
        for(int i = str.length()-1; i >= 0; i--){
            if(str[i] == '+' || str[i] == '-'){
                continue;
            }

            char numChar = '0';
            int numInt = 0;


            while(str[i] != numChar){
                numChar++;
                numInt++;
            }

            result += numInt*place;
            place *= 10;
        }
    }
    else{
        double place = 1;
        int dec = str.find('.');

        for(int i = dec-1; i >= 0; i--){
            if(str[i] == '+' || str[i] == '-'){
                continue;
            }

            char numChar = '0';
            int numInt = 0;


            while(str[i] != numChar){
                numChar++;
                numInt++;
            }

            result += numInt*place;
            place *= 10;
        }

        place = 0.1;
        for(int i = dec+1; i <= str.length()-1; i++){
            char numChar = '0';
            int numInt = 0;


            while(str[i] != numChar){
                numChar++;
                numInt++;
            }

            result += numInt*place;
            place *= 0.1;
        }
        
    }

    if(neg){
        result *= -1;
    }

    return result;
}


int main(){

    string input;

    while (true){
       
       cout << "Enter a string (or 'END' to quit): " << endl;
       cin >> input;

       if(input == "END"){
            break;
       }

       double result = extractNumeric(input);

       if(result == -999999.99){
            cout << "The input is invalid. " << endl;
       }
       else{
            cout << "The input is: " << fixed << setprecision(4) << result << endl; 
       }

    }

    return 0;
}
    


