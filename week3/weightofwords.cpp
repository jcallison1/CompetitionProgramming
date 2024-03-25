#include <iostream>
#include <string>
using namespace std;

string findWord(int length, int word_weight);

int main() {
    int num_letters;
    int weight;
    std::string output;

    cin >> num_letters >> weight;
    
     if (num_letters * 26 < weight || weight < num_letters){
        cout << "impossible" << endl;
        return 0;
    }

    output = findWord(num_letters, weight);

    cout << output << endl;

}

string findWord(int length, int word_weight) 
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    std::string output;
    int full_length = length;

    for (int i = length; i > 0; i-- ){
            output += 'a';
            word_weight = (word_weight - 1);
    }

    for (int i = 0; i < length; i++){
    if (word_weight == 0){
        break;
    }
    if (word_weight >= 25){
        output[i] = 'z';
        word_weight = (word_weight - 25);
        continue;
    }
    output[i] = alphabet[word_weight];
    break;
    
}

    return output;
}



