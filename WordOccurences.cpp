//HARISH SUNDARAKUMAR
//IMPLEMENTATION OF WORD OCCURENCES

//slightly altered version from hw
#include <bits/stdc++.h>

using namespace std;


//Will verify that the word only contains the alphabet and contains no special characters like periods, commas, etc...
bool verify(string s1){
    if(s1.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos){
        return false;
    }else{
        return true;
    }
}


//Specialized comparision operator where it will compare from higesht value to lowest if boht values arent the same, then if it is the same, from alphabetical order
bool cmp(const pair<string, int> &p1, const pair<string, int> &p2){
    if(p1.second!=p2.second){
        return p1.second > p2.second;
        return p1.first > p2.first;
    }else{
        if(p1.first != p2.first){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
}


int main(){
    //Variable delcaration
    string s1;
    vector<string> words;
    map<string,int> occur;
    vector<pair<string,int>> vect;


    //Will grab each word and push it into the words vector
    while(cin >> s1){
        words.push_back(s1);
    }


    vector<string> :: iterator iter;
    //Will traverse the vector words and places them into a map with recorded occurences
    //If the word is already in the map, we increase the value by 1, else a new key will be created with that word and the default value set at 1
    for(auto& iter : words){
        if(verify(iter) == true){
            if(occur.find(iter)== occur.end()){
                occur.insert(make_pair(iter,1));
            }else{
                occur[iter]++;
            }
        }
    }


    //Since a map cannot be sorted, we transfer the values of the map into a vector with a pair of a string and integer type
    for( auto&it : occur){
        vect.push_back(make_pair(it.first,it.second));
    }

    //We call the sort function, with specialized parameters where highest occurences first, then if the occurences have the same value then it has to be sorted alphabetically
    sort(vect.begin(),vect.end(),cmp);

    //displays the vector with pairs
    for( auto&mit : vect){
        cout << mit.first << " " << mit.second << endl;
    }

}

    
