#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> generatePerm(int length,const vector<string>& states){
    vector<vector<string>> ret;
    for(int i = 0; i < length; i++){
        vector<vector<string>> newret;
        if(i == 0){
            for(auto & state : states){
                newret.push_back({state});
            }
        }else{
            for(int j = 0; j < ret.size(); j++){
                for(auto & state : states){
                    vector<string> v = ret[j];
                    v.push_back(state);
                    newret.push_back(v);
                }
            }
        }
        ret = newret;
    }
    return ret;
}

vector<string> splitInput(const string& inputString){
    vector<string> returnVec;
    string currentString;
    for(char c : inputString){
        if(c == '(' or c == ')'){
            continue;
        }else if(c == ','){
            returnVec.push_back(currentString);
            currentString = "";
        }else{
            currentString+=(c);
        }
    }
    returnVec.push_back(currentString);
    return returnVec;
}

int main(int argc, char* argv[]) {
    if(argc != 3){
        cerr << "Error! Unexpected amount of parameters: got " << argc-1 << " but expected 2";
        return -1;
    }
    vector<string> states = splitInput(argv[1]);
    int permLength = stoi(argv[2]);
    vector<vector<string>> out = generatePerm(permLength,states);
    for(const auto& v : out){
        std::string outstr;
        outstr +=  "(";
        for(const auto& v2 : v){
            outstr += v2 + ",";
        }
        outstr.pop_back();
        outstr += ")  ";
        std::cout << outstr;
    }
    return 0;
}
