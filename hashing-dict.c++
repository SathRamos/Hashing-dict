#include <string.h>
#include <iostream>
using namespace std;
#define FOLD_SIZE 3

class Association{
    string key;
    int type;
    void *value;
    Association *prox;
};

class Dictionary{
    Association data[17];
};

Dictionary dict;

bool isNumeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false; //retorna falso quando um valor não numérico é encontrado
      return true;
}

string shift_folding(string key){
    int size = key.size();
    string subB = "0";
    int lastFoldSize;

    if(size>FOLD_SIZE){
        for(int i = 0; i < size; i+=(FOLD_SIZE)){
            string subA;
            if(i+(FOLD_SIZE) > (size-1)){
                cout<<"subA = ("<<i<<", "<<size-1<<")";
                subA = key.substr(i, size-1);//substring A recebe a última porção da chave
            }
            else{
                cout<<"subA = ("<<i<<", "<<i+FOLD_SIZE-1<<")";
                subA = key.substr(i, (FOLD_SIZE));//substring A recebe a próxima porção de "FOLD-SIZE" caracteres da chave
            } 
            cout<<"\nSubstring: "<<subA<<"\n";
            subB = to_string(stoi(subA)+stoi(subB));//soma cumulativa do valor das porções
        }
        return subB;
    }
    else return key;

}

int main(){
    string k = "a";
    while(!isNumeric(k)){
        cout<<"Insira uma chave numérica\n";
        cin>>k;
    }
    cout<<"Shift Folding (fold = 3) da chave: "<<shift_folding(k);


    return 0;
}